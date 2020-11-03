/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    HumanTracker.cpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/20/2020
 *
 *  @brief HumanTracker class methods implementation
 *
 *  @section DESCRIPTION
 * 
 *  This source file implements the HumanTracker class methods
 */
#include "../include/HumanTracker.hpp"
#include <string>

std::string mtp::HumanTracker::getRobotFrame() {
    return "new_robot_frame";
}

void mtp::HumanTracker::setRobotFrame(std::string robot_frame) {
    robotFrame = "new_robot_frame";
}

std::string mtp::HumanTracker::getInputSource() {
    return "new_input_source";
}

void mtp::HumanTracker::setInputSource(std::string input_source) {
    inputSource = "new_input_source";
}

int mtp::HumanTracker::inputParser(cv::CommandLineParser parser) {
    if (parser.has("image")) {
        std::string image_path = parser.get<std::string>("image");
        setInputPath(image_path);
        return 0;
    } else if (parser.has("video")) {
        std::string video_path = parser.get<std::string>("video");
        setInputPath(video_path);
        return 1;
    } else if (parser.has("webcam")) {
        std::string webcam_path = parser.get<std::string>("webcam");
        setInputPath(webcam_path);
        return 1;
    } else {
        return -1;
    }
}

void mtp::HumanTracker::runTrackerImage() {
    try {
        // Read image
        cv::VideoCapture capture;
        capture.open(inputPath);
        std::cout << "Opened image ...\n";
        // Perform detection pipeline
        cv::Mat frame, input_blob;
        capture >> frame;
        input_blob = yolov3.preProcess(frame);
        std::cout << "Frame preprocessed ...\n";
        std::vector<cv::Mat> predictions = yolov3.runInference(input_blob);
        std::cout << "Performed object detection ...\n";
        // Write the frame
        cv::Mat output_frame;
        frame.convertTo(output_frame, CV_8U);
        std::string output_path = inputPath.replace(inputPath.end() - 4,
                                                    inputPath.end(), 
                                                    "_output.jpg");
        cv::imwrite(output_path, output_frame);
        std::cout << "Output file generated!\n";
        capture.release();
    } catch (...) {
        std::cout << "Image not provided or error in detection!\n";
    }
}

void mtp::HumanTracker::runTrackerVideo() {
    /*
    try {
        // Read image
        cv::VideoCapture capture;
        cv::VideoWriter output_video;
        capture.open(inputPath);
        output_video.open()
        std::cout << "Opened video ...\n";
        // Perform detection pipeline
        cv::Mat frame, input_blob;
        while (1) {
            capture >> frame;
            if (frame.empty())
                break;
            input_blob = yolov3.preProcess(frame);
            std::cout << "Frame preprocessed ...\n";
            std::vector<cv::Mat> predictions = yolov3.runInference(input_blob);
            std::cout << "Performed object detection ...\n";
            // Write the frame to video file
            cv::Mat output_frame;
            frame.convertTo(output_frame, CV_8U);
            std::string output_path = inputPath.replace(inputPath.end() - 4,
                                                        inputPath.end(), 
                                                        "_output.jpg");
            cv::imwrite(output_path, output_frame);
        }
        std::cout << "Output file generated!\n";
        capture.release();

    } catch (...) {
        std::cout << "Video file not provided or error in detection!\n";
    }
    */
}

void mtp::HumanTracker::runTrackerWebcam() {
    try {

    } catch (...) {
        
    }
}

std::string mtp::HumanTracker::getInputPath() {
    return inputPath;
}

void mtp::HumanTracker::setInputPath(std::string input_path) {
    inputPath = input_path;
}

mtp::HumanTracker::HumanTracker(std::string robot_frame,
                                std::string input_source,
                                std::string input_path) {
    robotFrame = robot_frame;
    inputSource = input_source;
    inputPath = input_path;
}

mtp::HumanTracker::HumanTracker() {}

mtp::HumanTracker::~HumanTracker() {}
