//
// Created by cshaw on 3/26/2018.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../h_files/classification.h"

TEST_CASE("classification is retrieving all 1000 images") {
    vector<int> classified_images = classification();
    REQUIRE(classified_images.size() == 1000);
}

TEST_CASE("classification accuracy > 77%") {
    double accuracy = accuracy_calculator();
    REQUIRE(accuracy > 77);
}