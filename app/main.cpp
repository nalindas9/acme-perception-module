/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    main.cpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/19/2020
 *
 *  @brief Main.cpp
 *
 *  @section DESCRIPTION
 * 
 *  This source file contains the main code
 */
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/HumanTracker.hpp"

/**
 * @brief Main function
 * @param None
 * @return 0
 * **/
int main(int argc, char** argv) {
    // Shows available command line arguments with usage
    const char* keys = "{help h usage ? | | Usage examples: \n\t\t."
                        "/human-tracker-module --image=human.jpg \n\t\t."
                        "/human-tracker-module --video=human.mp4}"
                        "{image i        |<none>| input image   }"
                        "{video v       |<none>| input video   }";
    
    // CommandlineParser object to parse i/p from user
    cv::CommandLineParser parser(argc, argv, keys);
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    mtp::HumanTracker human_tracker;

    int input = human_tracker.inputParser(parser);

    if (input == 0) {
        std::cout << "Image mode selected\n";
        human_tracker.runTrackerImage();
    } else if (input == 1) {
        std::cout << "Video mode selected\n";
        human_tracker.runTrackerVideo();
    } else if (input == 2) {
        std::cout << "Webcam mode selected\n";
        human_tracker.runTrackerWebcam();
    } else {
        std::cout << "Provide either an image or videopath.\n";
    }
    return 0;
}
