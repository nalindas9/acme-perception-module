#pragma once
/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    YoloV3.hpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/19/2020
 *
 *  @brief YoloV3 class implementation
 *
 *  @section DESCRIPTION
 *
 *  Header file for YoloV3 class.
 *
 */
#include "utils.hpp"
#include <opencv2/opencv.hpp>

namespace mtp {
/**
 * @brief YoloV3 class
 * **/
class YoloV3 {
 private:
    /**
     * @brief Utils class object
     * **/
    mtp::Utils utils;
    /**
     * @brief Confidence threshold
     * **/
    double confThreshold;
    /**
     * @brief NMS threshold
     * **/
    double nmsThreshold;
    /**
     * @brief Input width
     * **/
    double inputWidth;
    /**
     * @brief Input height
     * **/
    double inputHeight;
 public:
    /**
     * @brief Setter for confidence threshold
     * @param conf_threshold_value Confidence threshold value
     * @return None
     * **/
    void setConfThreshold(double conf_threshold_value);

     /**
     * @brief Getter for confidence threshold
     * @param None
     * @return Confidence threshold value
     * **/
    double getConfThreshold();

     /**
     * @brief Setter for NMS threshold
     * @param nms_threshold_value NMS threshold value
     * @return None
     * **/
    void setNmsThreshold(double nms_threshold_value);

     /**
     * @brief Getter for NMS threshold
     * @param None
     * @return NMS threshold value
     * **/
    double getNmsThreshold();

     /**
     * @brief Setter for input image height
     * @param inputHeight Input image height
     * @return None
     * **/
    void setInputHeight(int input_height_value);

     /**
     * @brief Getter for input image height
     * @param None
     * @return Input image height
     * **/
    int getInputHeight();

     /**
     * @brief Setter for input image width
     * @param input_width_value Input image width 
     * @return None
     * **/
    void setInputWidth(int input_width_value);

    /**
     * @brief Getter for input image width
     * @param input_width_value Input image width 
     * @return None
     * **/
    int getInputWidth();

    /**
     * @brief Preprocess the image
     * @param frame Image frame  
     * @return Preprocessed image frame
     * **/
    cv::Mat preProcess(const cv::Mat& frame);

    /**
     * @brief Postprocess the image
     * @param frame Image frame  
     * @return Postprocessed image frame
     * **/
    cv::Mat postProcess(const cv::Mat& frame);

    /**
     * @brief Run YOLOv3 model inference 
     * @param frame Image frame
     * @return Get image with bounding box predictions
     * **/
    cv::Mat runInference(const cv::Mat& frame);

    /**
     * @brief Constructor 
     * @param None
     * @return None
     * **/
    YoloV3();

    /**
     * @brief Constructor
     * @param None
     * @return None
     * **/
    YoloV3(double conf_threshold_value, 
                double nms_threshold_value,
                int input_width_value,
                int input_height_value);
   /**
     * @brief Destructor
     * @param None
     * @return None
     * **/
    ~ YoloV3();
};
} // namespace mtp