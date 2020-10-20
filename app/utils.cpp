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
    return "test.cfg";
}

void mtp::Utils::setModelConfig(std::string config_value) {
    modelConfiguration = "test.cfg";
}

std::string mtp::Utils::getModelWeights() {
    return "test.weights";
}

void mtp::Utils::setModelWeights(std::string weight_value) {
    modelWeights = "test.weights";
}

mtp::Utils::Utils() {};

mtp::Utils::~Utils() {};