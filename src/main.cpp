#include "titanic.h"

const std::string FILE_PATH = "../data/titanic.csv";
int main(){
    matrix data = readCsv(FILE_PATH);
    fillNan(data, Columns::Age);
    printMatrix(data);
    std::cout << getImportant(50, 2, "female") << std::endl;
    std::cout << Columns::Fare;
}
