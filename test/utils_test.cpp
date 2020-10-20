/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file utils_test.cpp
 *  @author Nidhi Bhojak 
 *  @author Nalin Das 
 *  @date 10/20/2020
 *
 *  @brief Utils Test file 
 *
 *  @section DESCRIPTION
 *
 *  Test file containing unit tests for Utils class methods
 */
#include <gtest/gtest.h>
#include "../include/utils.hpp"

/**
 * @brief Setter methods test
 * **/

TEST(Utils, SetterMethods) {
  mtp::Utils dummy_utils;
  dummy_utils.setModelConfig("test.cfg");
  dummy_utils.setModelWeights("test.weights");
  EXPECT_EQ("test.cfg", dummy_utils.getModelConfig());
  EXPECT_EQ("test.weights", dummy_utils.getModelWeights());
}


/**
 * @brief Getter methods test
 * **/
/*
TEST(Utils, GetterMethods) {
  mtp::Utils dummy_utils;
  EXPECT_EQ("model_config", dummy_utils.getModelConfig());
  EXPECT_EQ("model_weights", dummy_utils.getModelWeights());
}
*/
