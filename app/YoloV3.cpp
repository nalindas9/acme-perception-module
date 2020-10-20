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

void mtp::YoloV3::setConfThreshold(double conf_threshold_value) {
    confThreshold = 0.6;
}

double mtp::YoloV3::getConfThreshold() {
    return 0.6;
}

void mtp::YoloV3::setNmsThreshold(double nms_threshold_value) {
    nmsThreshold = 0.2;
}

double mtp::YoloV3::getNmsThreshold() {
    return 0.2;
}

void mtp::YoloV3::setInputHeight(int input_height_value) {
    inputHeight = 32;
}

int mtp::YoloV3::getInputHeight() {
    return 32;
}

void mtp::YoloV3::setInputWidth(int input_width_value) {
    inputWidth = 32;
}

int mtp::YoloV3::getInputWidth() {
    return 32;
}

cv::Mat mtp::YoloV3::preProcess(const cv::Mat& frame) {
    cv::Mat output_blob(416, 416, CV_8UC3, cv::Scalar(0, 0, 255));
    return output_blob;
}

cv::Mat mtp::YoloV3::postProcess(const cv::Mat& frame) {
    cv::Mat output_blob(416, 416, CV_8UC3, cv::Scalar(0, 0, 255));
    return output_blob;
}

cv::Mat mtp::YoloV3::runInference(const cv::Mat& frame) {
    cv::Mat output_blob(416, 416, CV_8UC3, cv::Scalar(0, 0, 255));
    return output_blob;
}

mtp::YoloV3::YoloV3(double conf_threshold_value,
                double nms_threshold_value,
                int input_width_value,
                int input_height_value) {
    confThreshold = conf_threshold_value;
    nmsThreshold = nms_threshold_value;
    inputHeight = input_height_value;
    inputWidth = input_width_value;
}

mtp::YoloV3::YoloV3() {}

mtp::YoloV3::~YoloV3() {}
