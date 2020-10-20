/**
 *  Copyright 2020 Nidhi Bhojak, Nalin Das
 *  @file main.cpp
 *  @author Nidhi Bhojak 
 *  @author Nalin Das 
 *  @date 10/20/2020
 *
 *  @brief Main Test file 
 *
 *  @section DESCRIPTION
 *
 *  Test file containing main tests 
 *
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
