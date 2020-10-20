/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file HumanTracker_test.cpp
 *  @author Nidhi Bhojak 
 *  @author Nalin Das 
 *  @date 10/20/2020
 *
 *  @brief Human Tracker Test file 
 *
 *  @section DESCRIPTION
 *
 *  Test file containing unit tests for HumanTracker class methods
 *
 */
#include <gtest/gtest.h>
#include "../include/HumanTracker.hpp"

/**
 * @brief Class initialization test
 * **/
TEST(HumanTracker, ClassInitialization) {
  mtp::HumanTracker dummy_humanTracker("new_robot_frame",
                                       "new_input_source",
                                       "new_input_path");
  EXPECT_EQ("new_robot_frame", dummy_humanTracker.getRobotFrame());
  EXPECT_EQ("new_input_source", dummy_humanTracker.getInputSource());
  EXPECT_EQ("new_input_path", dummy_humanTracker.getInputPath());
}

/**
 * @brief Setter methods test
 * **/
TEST(HumanTracker, SetterMethods) {
  mtp::HumanTracker dummy_humanTracker("new_robot_frame",
                                       "new_input_source",
                                       "new_input_path");
  dummy_humanTracker.setRobotFrame("new_robot_frame");
  dummy_humanTracker.setInputSource("new_input_source");
  dummy_humanTracker.setInputPath("new_input_path");
  EXPECT_EQ("new_robot_frame", dummy_humanTracker.getRobotFrame());
  EXPECT_EQ("new_input_source", dummy_humanTracker.getInputSource());
  EXPECT_EQ("new_input_path", dummy_humanTracker.getInputPath());
}

/**
 * @brief Getter methods test
 * **/
TEST(HumanTracker, GetterMethods) {
  mtp::HumanTracker dummy_humanTracker("new_robot_frame",
                                       "new_input_source",
                                       "new_input_path");
  EXPECT_EQ("new_robot_frame", dummy_humanTracker.getRobotFrame());
  EXPECT_EQ("new_input_source", dummy_humanTracker.getInputSource());
  EXPECT_EQ("new_input_path", dummy_humanTracker.getInputPath());
}
