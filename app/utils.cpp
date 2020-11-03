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

mtp::Utils::Utils() {
    modelConfiguration = "../config/yolov3.cfg";
    modelWeights = "../weights/yolov3.weights";
}

mtp::Utils::~Utils() {}
