#pragma once
/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file    utils.hpp
 *  @author  Nidhi Bhojak
 *  @author  Nalin Das 
 *  @date    10/19/2020
 *
 *  @brief Utils class implementation
 *
 *  @section DESCRIPTION
 *
 *  Header file for Utils class.
 *
 */
#include <string>
#include <opencv2/opencv.hpp>

namespace mtp {
class Utils {
 private:
    /**
     * @brief YOLOv3 model configuration
     * **/
    std::string modelConfiguration;
    /**
     * @brief YOLOv3 model weights
     * **/
    std::string modelWeights;

 public:
    /**
     * @brief Getter for model configuration
     * @param None 
     * @return Model configuration
     * **/
    std::string getModelConfig();

    /**
     * @brief Setter for model configuration
     * @param  config_value Model Configuration 
     * @return None
     * **/
    void setModelConfig(std::string config_value);

    /**
     * @brief Getter for model weights
     * @param None
     * @return Model weights
     * **/
    std::string getModelWeights();

    /**
     * @brief Setter for model weights
     * @param weight_value Model weights 
     * @return None
     * **/
    void setModelWeights(std::string weight_value);
   
   /**
     * @brief Draws bounding box for the given coordinates
     * @param frame Image frame
     * @param class_id Class Id
     * @param confidence Prediction confidence
     * @param left Left corner of box
     * @param top Top corner of box
     * @param right Right corner of box
     * @param bottom Bottom corner of box
     * @return None
     * **/
    void drawBoundingBox(const cv::Mat &frame,
                         int class_id,
                         double confidence,
                         int left,
                         int top,
                         int right, 
                         int bottom);

    /**
     * @brief Constructor
     * @param None
     * @return None
     * **/

    Utils();

    /**
     * @brief Destructor
     * @param None
     * @return None
     * **/
    ~Utils();
};
}  // namespace mtp
