//
// Created by cshaw on 3/8/2018.
//

#include "../h_files/pretraining.h"


vector<vector<int>> Images::image_vector_creator(string data) {

        fstream image;
        image.open(data);
        vector<vector<int>> image_vector;
        vector<int> line_vector;
        string character;
        int char_count = 0;

        while (getline(image, character)) {
            for (int i = 0; i < character.size(); i++) {
                if (character.at(i) != ' ') {
                    line_vector.push_back(1);
                    char_count++;
                } else {
                    line_vector.push_back(0);
                    char_count++;
                }
            }
            if (char_count == 784) {
                image_vector.push_back(line_vector);
                line_vector.clear();
                char_count = 0;
            }
        }
        return image_vector;
    }

map<vector<int>, int> training_label_assignment() {

    Images train_images;

    vector<vector<int>> training_image = train_images.image_vector_creator("../data/trainingimages");
    map<vector<int>, int> training_correspondence;
    fstream in_file;
    in_file.open("../data/traininglabels");
    vector<int> number_vector;
    int x = 0;

    while (in_file >> x) {
        number_vector.push_back(x);
    }
    for (int i = 0; i < 5000; i++) {
        training_correspondence.insert(pair<vector<int>, int>(training_image.at(i), number_vector.at(i)));
    }
    return training_correspondence;
}


