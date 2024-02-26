#include "titanic.h"

const std::string FILE_PATH = "../data/titanic.csv";
int main(){
    matrix data = readCsv(FILE_PATH);
    // printMatrix(data);
    for (int i: {Columns::Age, Columns::Sex, Columns::Pclass}){
        fillNan(data, i);
    }
    printBoats(fillBoats(data, 10, 10));
}
