#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

typedef std::vector<std::vector<std::string>> matrix;

matrix readCsv(const std::string &path) {
    std::ifstream file(path);
    std::string line;
    matrix data;
    if (!file.is_open()) {
        std::cout << "File Not Found";
    }
    while (std::getline(file, line)) {
        std::string cell;
        std::stringstream ss(line);
        std::vector<std::string> row;
        while (std::getline(ss, cell, '\t')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    return data;
}

void printMatrix(const matrix& data) {
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            std::cout << data[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

double importantWeights[] = {0.5, 0.25, 0.25};
double getImportant(int age, int Pclass, const std::string& sex) {
    int gender = sex == "female" ? 1 : 2;
    return importantWeights[0] * (1.0 / (age + 1)) + importantWeights[1] * (1.0 / Pclass) + importantWeights[2] * (1.0 / gender);
}


void fillNan(matrix& data, int c){
    std::vector<std::string> arr;
    for (size_t i = 1; i < data.size(); i++){
        if (!data[i][c].empty()){
            arr.push_back(data[i][c]);
        }
    }
    std::sort(arr.begin(), arr.end());
    std::string median = arr[arr.size() / 2];
    for (size_t i = 1; i < data.size(); i++){
        if (data[i][c].empty()) {
            data[i][c] = median;
        }
    }
}
