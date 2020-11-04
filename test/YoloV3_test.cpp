/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file YoloV3_test.cpp
 *  @author Nidhi Bhojak 
 *  @author Nalin Das 
 *  @date 10/20/2020
 *
 *  @brief YoloV3 Test file 
 *
 *  @section DESCRIPTION
 *
 *  Test file containing unit tests for YoloV3 class methods
 *
 */
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "../include/YoloV3.hpp"

/**
 * @brief Class initialization test
 * **/
TEST(YoloV3, ClassInitialization) {
  mtp::YoloV3 dummy_yolov3(0.6, 0.2, 32, 32);
  EXPECT_EQ(0.6, dummy_yolov3.getConfThreshold());
  EXPECT_EQ(0.2, dummy_yolov3.getNmsThreshold());
  EXPECT_EQ(32, dummy_yolov3.getInputHeight());
  EXPECT_EQ(32, dummy_yolov3.getInputWidth());
}

/**
 * @brief Preprocess method test to check for any fatal errors
 *        while preprocessing test image
 * **/
TEST(YoloV3, PreProcessMethod) {
  mtp::YoloV3 dummy_yolov3(0.6, 0.2, 32, 32);
  cv::Mat frame  = cv::imread("../test.jpg");
  EXPECT_NO_FATAL_FAILURE({dummy_yolov3.preProcess(frame);});
}

/**
 * @brief Postprocess method test to check for any fatal errors
 *        while postprocessing test image
 * **/
TEST(YoloV3, PostProcessMethod) {
  mtp::YoloV3 dummy_yolov3(0.6, 0.2, 32, 32);
  cv::Mat frame  = cv::imread("../test.jpg");
  std::vector<cv::Mat> predictions = dummy_yolov3.runInference(frame);
  EXPECT_NO_FATAL_FAILURE({dummy_yolov3.postProcess(frame, predictions);});
}

/**
 * @brief Run inference method test to check for any fatal
 *        errors while running inference on test image
 * **/
TEST(YoloV3, RunInferenceMethod) {
  mtp::YoloV3 dummy_yolov3(0.6, 0.2, 32, 32);
  cv::Mat frame  = cv::imread("../test.jpg");
  EXPECT_NO_FATAL_FAILURE({dummy_yolov3.runInference(frame);});
}

/**
 * @brief Setter methods test
 * **/
TEST(YoloV3, SetterMethods) {
  mtp::YoloV3 dummy_yolov3(0.6, 0.2, 32, 32);
  dummy_yolov3.setConfThreshold(0.6);
  dummy_yolov3.setNmsThreshold(0.2);
  dummy_yolov3.setInputHeight(32);
  dummy_yolov3.setInputWidth(32);
  EXPECT_EQ(0.6, dummy_yolov3.getConfThreshold());
  EXPECT_EQ(0.2, dummy_yolov3.getNmsThreshold());
  EXPECT_EQ(32, dummy_yolov3.getInputHeight());
  EXPECT_EQ(32, dummy_yolov3.getInputWidth());
}

/**
 * @brief Getter methods test
 * **/
TEST(YoloV3, GetterMethods) {
  mtp::YoloV3 dummy_yolov3(0.6, 0.2, 32, 32);
  EXPECT_EQ(0.6, dummy_yolov3.getConfThreshold());
  EXPECT_EQ(0.2, dummy_yolov3.getNmsThreshold());
  EXPECT_EQ(32, dummy_yolov3.getInputHeight());
  EXPECT_EQ(32, dummy_yolov3.getInputWidth());
}
