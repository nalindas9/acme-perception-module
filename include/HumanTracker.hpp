#pragma once
/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    HumanTracker.hpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/19/2020
 *
 *  @brief HumanTracker class implementation
 *
 *  @section DESCRIPTION
 *
 *  Header file for HumanTracker class.
 *
 */
#include <string>
#include "YoloV3.hpp"

namespace mtp {
class HumanTracker {
 private:
    /**
     * @brief YOLOv3 class object
     * **/
    mtp::YoloV3 yolov3;
    /**
     * @brief Robot frame to transform predictions to
     * **/
    std::string robotFrame;
    /**
     * @brief Input source - Image/Recorded Video/Capture Video
     * **/
    std::string inputSource;
    /**
     * @brief Path to Image or Recorded video
     * **/
    std::string inputPath;

 public:
    /**
     * @brief Getter for robot frame
     * @param None 
     * @return Robot frame
     * **/
    std::string getRobotFrame();
    /**
     * @brief Setter for robot frame
     * @param robot_frame Robot frame 
     * @return None
     * **/
    void setRobotFrame(std::string robot_frame);

    /**
     * @brief Getter for input source
     * @param None 
     * @return Input source
     * **/
    std::string getInputSource();

    /**
     * @brief Setter for input source
     * @param input_source Input source 
     * @return None
     * **/
    void setInputSource(std::string input_source);

    /**
     * @brief Getter for input source path
     * @param None 
     * @return Input source path
     * **/
    std::string getInputPath();

    /**
     * @brief Setter for input source path
     * @param input_path Path to input source 
     * @return None
     * **/
    void setInputPath(std::string input_path);

    /**
     * @brief Checks i/p source to run detector on
     * @param parser CommandLineParser object
     * @return 0 - image/1 - video/2 - webcam/-1 - None 
     * **/
    int inputParser(cv::CommandLineParser parser);

   /**
     * @brief Run Human Tracker on Image
     * @param None
     * @return None
     * **/
    void runTrackerImage();

    /**
     * @brief Run Human Tracker on Video
     * @param None
     * @return None
     * **/
    void runTrackerVideo();

    /**
     * @brief Run Human Tracker on Webcam
     * @param None
     * @return None
     * **/
    void runTrackerWebcam();

    /**
     * @brief Constructor
     * @param None
     * @return None
     * **/
    HumanTracker();

    /**
     * @brief Constructor
     * @param robot_frame Robot frame
     * @param input_source Input source - Image/Recorded Video/Capture Video
     * @param input_path Path to input source
     * @return None
     * **/
    HumanTracker(std::string robot_frame,
                 std::string input_source,
                 std::string input_path);

    /**
     * @brief Destructor
     * @param None
     * @return None
     * **/
    ~HumanTracker();
};
}  // namespace mtp
