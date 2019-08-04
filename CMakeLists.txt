cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes h_files/pretraining.h src/pretraining.cpp src/main.cpp src/training.cpp src/classification.cpp h_files/training.h h_files/classification.h)
add_executable(pre_training_test test/catch.hpp test/pretrainingtest.cpp h_files/pretraining.h src/pretraining.cpp)
add_executable(training_test test/catch.hpp test/trainingtest.cpp h_files/training.h src/pretraining.cpp src/training.cpp)
add_executable(classification_test test/catch.hpp test/classificationtest.cpp h_files/classification.h src/pretraining.cpp src/training.cpp src/classification.cpp)