set(GTEST_SHUFFLE 1)

add_executable(
    human-tracker-module-test
    main.cpp
    utils_test.cpp
    ../app/utils.cpp
    YoloV3_test.cpp
    ../app/YoloV3.cpp
    HumanTracker_test.cpp
    ../app/HumanTracker.cpp
)

target_include_directories(human-tracker-module-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(human-tracker-module-test PUBLIC gtest ${OpenCV_LIBS})
