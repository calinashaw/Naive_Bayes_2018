//
// Created by cshaw on 3/8/2018.
//

#ifndef NAIVEBAYES_CSHAW16_NAIVEBAYES_H
#define NAIVEBAYES_CSHAW16_NAIVEBAYES_H

#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <fstream>
#include <map>
#include <ctgmath>
using namespace std;

class Images {
public:
    vector<vector<int>> image_vector_creator(string data);
};

map<vector<int>, int> training_label_assignment();


#endif //NAIVEBAYES_CSHAW16_NAIVEBAYES_H
