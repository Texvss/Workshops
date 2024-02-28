#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "titanic.h"


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

void Passenger::setImportant(){
    value = getImportant(age, pclass, sex);
}

bool compP(const Passenger& first, const Passenger& second){
    return first.value > second.value;
}

bool Passenger::operator < (const Passenger& p) const {
    return value < p.value;
}

bool Passenger::operator > (const Passenger& p) const {
    return value > p.value;
}

boatVector fillBoats(const matrix& data, size_t nboats, size_t nseats){
    std::vector<Passenger> passengers;
    for (size_t i = 1; i < data.size(); i++){
        std::vector<std::string> row = data[i]; 
        Passenger p = {std::stoul(row[Columns::PassengerId]),
         row[Columns::Name],
          row[Columns::Sex],
           std::stoi(row[Columns::Pclass]),
           std::stoi(row[Columns::Age])};
        p.setImportant();
        passengers.push_back(p);
    }
//    std::sort(passengers.begin(), passengers.end(), compP);
    std::sort(passengers.begin(), passengers.end(), std::greater <Passenger>());
    boatVector boats;
    for (size_t i=0; i<nboats; i++){
        std::vector<Passenger> seats;
        for (size_t j=0; j<nseats; j++){
            seats.push_back(passengers[i*nseats+j]);
        }
        boats.push_back(seats);
    }
    return boats;
}

std::ostream& operator << (std::ostream& stream, const Passenger& passenger){
    stream << passenger.id << '\t' << passenger.name << '\t' << passenger.value;
    return stream;
}

void printBoats(const boatVector& boats){
    for (size_t i=0; i<boats.size(); i++){
        std::cout << i << '\n';
       std::vector<Passenger> passengers = boats[i];
       for (const Passenger& x: passengers){
//        std::cout << x.id << '\t' << x.name << '\t' << x.value << '\n';
            std::cout << x << '\n';
       }
    }
}
