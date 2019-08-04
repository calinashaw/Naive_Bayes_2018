//
// Created by cshaw on 3/12/2018.
//
#include "../h_files/classification.h"

vector<double> probability_array_zero[10];
vector<double> probability_array_one[10];

// Creates vector of vectors of all training images
void test_vector_creator() {

    int every_number_check_zero = 0;
    int CHECK_FINISHED = 9;
    int every_number_check_one= 0;


    while(every_number_check_zero <= CHECK_FINISHED) {

        vector<double> probability_per_number = probability_calculator(every_number_check_zero, 0);
        probability_array_zero[every_number_check_zero] = probability_per_number;
        every_number_check_zero++;
    }

    while(every_number_check_one <= CHECK_FINISHED) {

        vector<double> probability_per_number_ones = probability_calculator(every_number_check_one, 1);
        probability_array_one[every_number_check_one] = probability_per_number_ones;
        every_number_check_one++;
    }
}

vector<int> classification() {

    vector<int> final_answers;
    Images test_image;
    vector<vector<int>> test_vector = test_image.image_vector_creator("../data/testimages");
    test_vector_creator();

    for (int i = 0; i < test_vector.size(); i++) {

        double posterior_probability[10];
        double posterior_calculator = 0.0;
        int class_ = 0;
        int class_nine = 10;

        while (class_ < class_nine) {

            for (int j = 0; j < test_vector.at(i).size(); j++) {
                if (test_vector.at(i).at(j) == 0) {
                    double calc = probability_array_zero[class_].at(j);
                    posterior_calculator += log(calc);
                }
                if (test_vector.at(i).at(j) == 1) {
                    double calc = probability_array_one[class_].at(j);
                    posterior_calculator += log(calc);
                }
            }
            posterior_probability[class_] = posterior_calculator;
            class_++;
            posterior_calculator = 0.0;
        }
        double temp = posterior_probability[0];
        int final_class = 0;
        for (int p_prob = 0; p_prob < class_nine; p_prob++) {
            if (posterior_probability[p_prob] > temp) {
                temp = posterior_probability[p_prob];
                final_class = p_prob;
            }
        }
        cout << final_class;
        cout << "\n";
        final_answers.push_back(final_class);
    }
    
    return final_answers;
}

double accuracy_calculator() {

    double accuracy;
    double counter;
    vector<int> results = classification();
    fstream in_file;
    in_file.open("../data/testlabels");
    vector<int> number_vector;
    int x = 0;

    while (in_file >> x) {
        number_vector.push_back(x);
    }

    for(int i = 0; i < 1000; i++) {
        if(number_vector.at(i) == results.at(i)) {
            counter++;
        }
    }
    accuracy = (counter/1000) * 100;
    cout << accuracy << "%" << endl;
    
    return accuracy;
}

