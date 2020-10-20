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

std::string mtp::HumanTracker::getInputPath() {
    return "new_input_path";
}

void mtp::HumanTracker::setInputPath(std::string input_path) {
    inputPath = "new_input_path";
}

mtp::HumanTracker::HumanTracker(std::string robot_frame, 
                                std::string input_source,
                                std::string input_path) {
    robotFrame = robot_frame;
    inputSource = input_source;
    inputPath = input_path;
}

mtp::HumanTracker::HumanTracker() {};

mtp::HumanTracker::~HumanTracker() {};