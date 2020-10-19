# C++ Boilerplate
[![Build Status](https://travis-ci.org/nalindas9/acme-perception-module.svg?branch=master)](https://travis-ci.org/github/nalindas9/acme-perception-module)
[![Coverage Status](https://coveralls.io/repos/github/nalindas9/acme-perception-module/badge.svg?branch=master)](https://coveralls.io/github/nalindas9/acme-perception-module)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://github.com/nalindas9/acme-perception-module/blob/feature/nalindas9/initialize-repository/LICENSE)
---

## Team Members
1. Nalin Das (nalindas9)
2. Nidhi Bhojak (nbhojak07)

## Overview

Since the beginning of the 21st century, development of autonomous robots has been booming. And one of the important modules in Autonomous Intelligent Systems is Obstacle Detection and Tracking. In order for an autonomous robot to function properly, it must be capable of gathering knowledge about its surroundings and make important decisions based on that. Vision based decision making is used widely to address this problem. Here, in this project, we plan to design and develop a human obstacle detector and tracker module for the perception stack of ACME Robotic’s AMR (Autonomous Mobile Robot) platform. Currently,the AMR fleet at ACME Robotics is capable of autonomously navigating the warehouse and moving packages.

However, we face a challenge. The workers in the warehouse can dynamically come infront of the robot, in which case we have two choices, either to stop, or to reroute the robot around the human. The second scenario is better since it saves time and effectively dodges the human without creating any disturbance in the environment.

We aim to solve this problem by integrating our human obstacle detector and tracker module to detect a human and output the humans location (x,y coordinates in camera frame) which can be transformed to the robot’s reference frame. It can be used directly by the planning stack working on the dynamic obstacle avoidance and rerouting algorithm.

We assume we will be provided with one monocular video camera, giving us nxn RGB image as input as well as we can also take an image or a video for an input.

## Technologies Used

We will be using Agile Development process and the quality will be ensured by unit testing and cppcheck. Test Driven Development will be used.
- Programming language - C++ 11/14
- Build System - CMake
- Operating System - Ubuntu 18.04
- Open source libraries - OpenCV (Apache License), YOLOv3 (MIT LICENSE)
- Automated unit testing - Travis CI
- Code coverage - Coveralls
- Version Control - Git & Github

## Probable Risks & Mitigation

- The lighting in the scene could vary, which can cause the predictions to be incorrect. We plan to apply some sort of intensity correction techniques like histogram equalization and adjusting the exposure.
- There could be some incorrect bounding boxes predicted in some intermediate frames in the camera feed. This can cause the tracking to be incorrect. In that case, we could apply averaging of bounding boxes over previous “n” frames to get a better estimate of the location.

## License 
- This module has been developed under the 3-Clause BSD License.
- Please go through the [LICENSE](https://github.com/nalindas9/acme-perception-module/blob/master/LICENSE) before cloning the repository. 

## AIP and Sprint Documents
- You can view the AIP Google Sheets [here](https://docs.google.com/spreadsheets/d/1oqgiFG7CPCP2yYUtMuwlLh8nGD6KBANpSUh5-Uhm9dw/edit?usp=sharing)
- You can view the spring review notes [here](https://docs.google.com/document/d/1hAAtv5MEF9csP_6ozN08iaaIumDudBxkSe3yPz_ZwQw/edit?usp=sharing)

## Install OpenCV
- The perception module utilizes OpenCV. Run the below commands to install OpenCV before cloning this repository.
#### System Update
```
sudo apt update 
sudo apt upgrade
```
#### Install OpenCV Dependencies
```
sudo apt install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt install python3.5-dev python3-numpy libtbb2 libtbb-dev
sudo apt install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
```

#### Install OpenCV
```
git clone https://github.com/opencv/opencv.git
cd opencv 
git checkout 3.3.0 
cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 3.3.0
cd ..
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D INSTALL_C_EXAMPLES=ON -D WITH_TBB=ON -D WITH_V4L=ON -D WITH_QT=ON -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules -D BUILD_EXAMPLES=ON ..
make -j$(nproc)
sudo make install
sudo /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
```
## YOLO Dependencies
```
wget https://pjreddie.com/media/files/yolov3.weights
wget https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg?raw=true -O ./yolov3.cfg
wget https://github.com/pjreddie/darknet/blob/master/data/coco.names?raw=true -O ./coco.names
```

## Standard install via command-line
Switch to the directory where you want to clone this repository and run the following command:
```
git clone --recursive https://github.com/nalindas9/acme-perception-module
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage 
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
## Access UML Diagrams
- Open the directory of the project
- Within the UML directory, access the initial and revised UML diagrams.
