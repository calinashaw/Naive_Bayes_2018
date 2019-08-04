//
// Created by cshaw on 3/15/2018.
//

#ifndef NAIVEBAYES_TRAINING_H
#define NAIVEBAYES_TRAINING_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "pretraining.h"
using namespace std;

vector<double> probability_calculator(int number, int zero_or_one);
vector<vector<int>> find_by_value(int value);
double occurrence_calculator(int element, vector<vector<int>> vectors_by_number, int element_placement_j);
void save_probability();

#endif //NAIVEBAYES_TRAINING_H
