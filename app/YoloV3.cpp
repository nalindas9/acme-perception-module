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
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>

void mtp::YoloV3::setConfThreshold(double conf_threshold_value) {
    confThreshold = conf_threshold_value;
}

double mtp::YoloV3::getConfThreshold() {
    return confThreshold;
}

void mtp::YoloV3::setNmsThreshold(double nms_threshold_value) {
    nmsThreshold = nms_threshold_value;
}

double mtp::YoloV3::getNmsThreshold() {
    return nmsThreshold;
}

void mtp::YoloV3::setInputHeight(int input_height_value) {
    inputHeight = input_height_value;
}

int mtp::YoloV3::getInputHeight() {
    return inputHeight;
}

void mtp::YoloV3::setInputWidth(int input_width_value) {
    inputWidth = input_width_value;
}

int mtp::YoloV3::getInputWidth() {
    return inputWidth;
}

cv::Mat mtp::YoloV3::preProcess(const cv::Mat& frame) {
    cv::Mat output_blob;
    cv::dnn::blobFromImage(frame, 
                           output_blob, 
                           1/255.0,
                           cv::Size(inputWidth, inputHeight),
                           cv::Scalar(0, 0, 0),
                           true,
                           false);
    return output_blob;
}

cv::Mat mtp::YoloV3::postProcess(const cv::Mat& frame, 
                                 std::vector<cv::Mat>& predictions) {
    cv::Mat output_blob;

    return output_blob;
}

std::vector<cv::Mat> mtp::YoloV3::runInference(const cv::Mat& frame) {
    std::vector<cv::Mat> predictions;
    cv::dnn::Net darknet = cv::dnn::readNetFromDarknet(utils.getModelConfig(), 
                                                       utils.getModelWeights());
    std::cout << "Darknet initialized ...\n";
    // Pass blob as input to darknet 
    darknet.setInput(frame);

    std::vector<std::string> output_layer_names = darknet.getLayerNames();

    // Forward pass
    darknet.forward(predictions, output_layer_names);
    std::cout << "Forward pass completed ...\n";
    // Non Max Suppression to remove low confidence bounding boxes
    
    return predictions;
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

mtp::YoloV3::YoloV3() {
    confThreshold = 0.5;
    nmsThreshold = 0.4;
    inputWidth = 416;
    inputHeight = 416;
}

mtp::YoloV3::~YoloV3() {}
