/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    utils.cpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/20/2020
 *
 *  @brief Utils class methods implementation
 *
 *  @section DESCRIPTION
 * 
 *  This source file implements the Utils class methods
 */
#include "utils.hpp"

std::string mtp::Utils::getModelConfig() {
    return modelConfiguration;
}

void mtp::Utils::setModelConfig(std::string config_value) {
    modelConfiguration = config_value;
}

std::string mtp::Utils::getModelWeights() {
    return modelWeights;
}

void mtp::Utils::setModelWeights(std::string weight_value) {
    modelWeights = weight_value;
}

void mtp::Utils::drawBoundingBox(const cv::Mat &frame,
                                 int class_id,
                                 double confidence,
                                 int left,
                                 int top,
                                 int right, 
                                 int bottom) {
    // Draw a rectangle in the image for the given coordinates
    std::cout << "left: " << left << " top: " << top << std::endl;
    std::cout << "right: " << right << " bottom: " << bottom << std::endl;
    cv::rectangle(frame, 
                  cv::Point(left, top),
                  cv::Point(right, bottom), 
                  cv::Scalar(0,128,0), 
                  3);
    std::cout << "Drawing bouding boxes ...\n";
    /*
    int base;
    cv::Size labelSize = cv::getTextSize(classLabel,
    cv::FONT_HERSHEY_DUPLEX, 0.5, 1, &base);
    top = std::max(top, labelSize.height);
    cv::rectangle(frame, cv::Point(left,
    top - round(1.5 * labelSize.height)),
    cv::Point(left + round(1.5 * labelSize.width), top + base),
    cv::Scalar(255, 255, 255), cv::FILLED);
    cv::putText(frame, classLabel,
    cv::Point(left, top), cv::FONT_HERSHEY_DUPLEX, 0.75,
    cv::Scalar(0, 0, 0), 1);
    */
}

mtp::Utils::Utils() {
    modelConfiguration = "../config/yolov3.cfg";
    modelWeights = "../weights/yolov3.weights";
}

mtp::Utils::~Utils() {}
