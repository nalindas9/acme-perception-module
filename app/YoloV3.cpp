/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    YoloV3.cpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/19/2020
 *
 *  @brief YoloV3 class methods implementation
 *
 *  @section DESCRIPTION
 * 
 *  This source file implements the YoloV3 class methods
 */
#include "YoloV3.hpp"

void mtp::YoloV3::setConfThreshold(double conf_threshold_value) {}

double mtp::YoloV3::getConfThreshold() {
    return 0.25;
}

void mtp::YoloV3::setNmsThreshold(double nms_threshold_value) {}

double mtp::YoloV3::getNmsThreshold() {
    return 0.5;
}

void mtp::YoloV3::setInputHeight(int input_height_value) {}

int mtp::YoloV3::getInputHeight() {
    return 
}

void mtp::YoloV3::setInputWidth(int input_width_value);

int mtp::YoloV3::getInputWidth();

cv::Mat mtp::YoloV3::preProcess(const cv::Mat& frame);

cv::Mat mtp::YoloV3::postProcess(const cv::Mat& frame);

cv::Mat mtp::YoloV3::runInference(const cv::Mat& frame);

void mtp::YoloV3::YoloV3(double conf_threshold_value, 
                double nms_threshold_value,
                int input_width_value,
                int input_height_value); 