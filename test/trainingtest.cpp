//
// Created by cshaw on 3/13/2018.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../h_files/training.h"
#include "../h_files/pretraining.h"

TEST_CASE("find_by_vector works") {
    vector<vector<int>> find_value = find_by_value(4);
    REQUIRE(find_value.size() == 535);
}
TEST_CASE("find_by_vector works for others") {
    vector<vector<int>> find_value = find_by_value(6);
    REQUIRE(find_value.size() == 501);
}

TEST_CASE("occurrence_calculator is accurate") {
    vector<vector<int>> find_value = find_by_value(6);
    double answer = occurrence_calculator(1, find_value, 10);
    REQUIRE(answer < 1);
    REQUIRE(answer > 0);
}

TEST_CASE("probability_calculator is returning non-null with correct dimensions") {
    vector<double> prob_calc = probability_calculator(3, 1);
    REQUIRE(prob_calc.size() == 784);
    REQUIRE(prob_calc.at(4) != 0);
}