add_executable(human-tracker-module main.cpp HumanTracker.cpp utils.cpp YoloV3.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries (human-tracker-module ${OpenCV_LIBS})