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
#include <iterator>
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

void mtp::YoloV3::postProcess(const cv::Mat& frame,
                                 std::vector<cv::Mat>& predictions) {
    std::cout << "Performing NMS ...\n";
    // Perform Non max suppression
    std::vector<cv::Rect> nms_boxes;
    std::vector<cv::Mat>::iterator it1;
    std::vector<int> class_ids;
    std::vector<int>::iterator it2;
    std::vector<float> confidence_values;
    for (it1 = predictions.begin(); it1 < predictions.end(); it1++) {
        // std::cout << "Inside outer for loop...\n";
        std::cout << "Predictions size: " << predictions.size() << std::endl;
        std::vector<int> row_numbers;
        std::vector<int>::iterator row_numbers_it;
        float* matrix_data = reinterpret_cast<float*>((*it1).data);
        // std::cout << " before row_numbers.resize..\n";
        // std::cout << "Row size: " << (*it1).rows << std::endl;
        row_numbers.resize((*it1).rows);
        // std::cout << "row_numbers.resize..\n";
        int row = 0;
        for (row_numbers_it = row_numbers.begin();
             row_numbers_it < row_numbers.end();
             row_numbers_it++) {
            // std::cout << "Inside inner for loop...\n";
            cv::Point det_point;
            double confidences;
            matrix_data = matrix_data + (*it1).cols;
            cv::Mat scores = (*it1).row(row).colRange(5, (*it1).cols);
            cv::minMaxLoc(scores, 0, &confidences, 0, &det_point);
            // std::cout << "Checking for confidence above threshold ...\n";
            if (confidences > confThreshold) {
                int center_coordinate_x =
                static_cast<int>(matrix_data[0] * frame.cols);
                int center_coordinate_y =
                static_cast<int>(matrix_data[1] * frame.rows);

                int width = static_cast<int>(matrix_data[2] * frame.cols);
                int height = static_cast<int>(matrix_data[3] * frame.rows);
                int leftTop = center_coordinate_x - width / 2;
                int rightBottom = center_coordinate_y - height / 2;
                class_ids.push_back(det_point.x);
                confidence_values.push_back(static_cast<float>(confidences));
                nms_boxes.push_back(cv::Rect(leftTop,
                                rightBottom, width, height));
            }
            row = row + 1;
        }
        // std::cout << "Obtained NMSboxes ...\n";
        std::vector<int> indices;
        cv::dnn::NMSBoxes(nms_boxes,
                            confidence_values,
                            confThreshold,
                            nmsThreshold,
                            indices);
        for (it2 = indices.begin(); it2 < indices.end(); it2++) {
            cv::Rect box = nms_boxes[(*it2)];
            std::cout << "box.x: " << box.x << " box.y: " << box.y
                << " box.width: " << box.width << " box.height: "
                << box.height << std::endl;
            utils.drawBoundingBox(frame,
                                    class_ids[(*it2)],
                                    confidence_values[(*it2)],
                                    box.x,
                                    box.y,
                                    box.x + box.width,
                                    box.y + box.height);
            }
    }
}

std::vector<std::string> mtp::YoloV3::
    getOutputLayerNames(const cv::dnn::Net& network) {
    std::vector<std::string> output_names;
    std::vector<std::string> output_layer_names = network.getLayerNames();
    std::vector<int> output_layers = network.getUnconnectedOutLayers();
    std::vector<int>::iterator output_layer_it;
    for (output_layer_it = output_layers.begin();
         output_layer_it < output_layers.end();
         output_layer_it++) {
        output_names.push_back(output_layer_names[(*output_layer_it) - 1]);
    }
    return output_names;
}

std::vector<cv::Mat> mtp::YoloV3::runInference(const cv::Mat& frame) {
    std::vector<cv::Mat> predictions;
    cv::dnn::Net darknet = cv::dnn::readNetFromDarknet(utils.getModelConfig(),
                                                       utils.getModelWeights());
    std::cout << "Darknet initialized ...\n";
    // Pass blob as input to darknet
    darknet.setInput(frame);

    std::vector<std::string> output_layer_names = getOutputLayerNames(darknet);

    // Forward pass
    darknet.forward(predictions, output_layer_names);
    std::cout << "Forward pass completed ...\n";
    // Non Max Suppression to remove low confidence bounding boxes
    postProcess(frame, predictions);
    std::cout << "Non max suppression completed ...\n";
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
