#include <iostream>
#include "titanic.h"

const std::string FILE_PATH = "../data/titanic.csv";
int main(){
    matrix data = readCsv(FILE_PATH);
    printMatrix(data);
}
