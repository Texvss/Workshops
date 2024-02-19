#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

typedef std::vector <std::vector<std::string>> matrix;
matrix readCsv(const std::string& path){
    std::ifstream file(path);
    std::string line;
    matrix data;
    if (!file.is_open()){
        std::cout << "File Not Found";
    }
    while (std::getline(file, line)){
        std::string cell;
        std::stringstream ss(line);
        std::vector <std::string> row;
        while(std::getline(ss, cell, '\t')){
            row.push_back(cell);
        }
        data.push_back(row);
    }
    return data;
}

void printMatrix(const matrix& data){
    for (size_t i=0; i<data.size(); i++){
        for (size_t j=0; j<data[i].size(); j++){
            std::cout << data[i][j] << ' ';
        }
        std::cout << '\n';
    }
}