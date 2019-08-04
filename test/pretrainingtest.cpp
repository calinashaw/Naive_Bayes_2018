//
// Created by cshaw on 3/11/2018.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../h_files/pretraining.h"


//makes sure no images were lost in translation
TEST_CASE("Image_vector_creator 5000 images") {
    Images image;
    vector<vector<int> > check = image.image_vector_creator("../data/trainingimages");
    REQUIRE(check.size() == 5000);
}

TEST_CASE("image_vector_creator is translating numbers correctly") {
    Images image;
    vector<vector<int> > check = image.image_vector_creator("../data/trainingimages");
    int pixel_check = check.at(0).at(158);
    REQUIRE(pixel_check == 1);
}

TEST_CASE("image_vector_creator is translating numbers to both 0s and 1s") {
    Images image;
    vector<vector<int> > check = image.image_vector_creator("../data/trainingimages");
    int pixel_check = check.at(0).at(0);
    REQUIRE(pixel_check == 0);
}

TEST_CASE("training_label_assignment maps one number per image") {
    map<vector<int>, int> map_check = training_label_assignment();
    REQUIRE(map_check.size() == 5000);
}
