//
// Created by cshaw on 3/11/2018.
//
#include "../h_files/training.h"


// sourced from
// http://thispointer.com/how-to-search-by-value-in-a-map-c/
vector<vector<int>> find_by_value(int value) {

    map<vector<int>, int> training_correspondence = training_label_assignment();
    auto it = training_correspondence.begin();
    vector<vector<int>> image_of_number;
    // Iterate through the map
    while(it != training_correspondence.end()) {
        // Check if value of this entry matches with given value
        if(it->second == value) {
            // Push the key in given map
            image_of_number.push_back(it->first);
        }
        // Go to next entry in map
        it++;
    }
    return image_of_number;
}
/**
 *
 * @param number_class a number 0 through 9
 * @param zero_or_one whichever number is at pixel
 * @return probability vector of one or zero being at each pixel in above number vector
 */
vector<double> probability_calculator(int number_class, int zero_or_one) {

    vector<vector<int>> vectors_by_number = find_by_value(number_class);
    vector<double> probability_fij(784, 0.0);

    for (int j = 0; j < probability_fij.size(); j++) {
            probability_fij.at(j) = occurrence_calculator(zero_or_one, vectors_by_number, j);
    }
       return probability_fij;
}
/**
 *
 * @param element AT pixel placement (0 or 1)
 * @param vectors_by_number vector of vectors for each number_class
 * @param element_placement_j element pixel placement j
 * @return
 */
double occurrence_calculator(int element, vector<vector<int>> vectors_by_number, int element_placement_j) {

    int probability_count = 0;

    for(int i = 0; i < vectors_by_number.size(); i++) {
        if (vectors_by_number.at(i).at(element_placement_j) == element) {
            probability_count++;
        }
    }
    // The smaller I make k the more accurate the results
    double k = .0000001;
    double divisor = vectors_by_number.size();
    divisor += (k*2);
    double training_equation_result = ((probability_count + k) / divisor);

    return training_equation_result;
}

// Saves probability to a text file
void save_probability() {

    int zero_check = 0;
    int CHECK_FINISHED = 9;
    int one_check = 0;

    ofstream save_file;
    save_file.open ("probabilityzero.txt");
    ofstream save_file_ones;
    save_file_ones.open ("probabilityone.txt");

    while(zero_check <= CHECK_FINISHED) {

        vector<double> probability_per_number = probability_calculator(zero_check, 0);

        for(int i = 0; i < probability_per_number.size(); i++) {
                save_file << probability_per_number[i];

        }
        zero_check++;
        save_file.close();
    }

    while(one_check <= CHECK_FINISHED) {

        vector<double> probability_per_number_ones = probability_calculator(one_check, 1);

        for(int i = 0; i < probability_per_number_ones.size(); i++) {
            for(int j = 0; j < probability_per_number_ones.size(); j++) {
                save_file_ones << probability_per_number_ones[i];
            }
        }
        one_check++;
        save_file_ones.close();
    }
}

