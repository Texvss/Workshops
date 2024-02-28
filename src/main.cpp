#include "titanic.h"
#include "complexNum.cpp"

const std::string FILE_PATH = "../data/titanic.csv";
int main(){
    Complex num1{2, 2};
    Complex num2;
    std::cout << num1 + num2 << std::endl;
//    если мы хотим сложить complexNum с любыми другими,
//    то нужно будет перегрузить оператор и для них
//    Passenger pass1;
//    Passenger pass2:
//    pass1.value = 10;
//    pass2.value = 15;
//    std::cout << (pass1 < pass2) << "\n";

    matrix data = readCsv(FILE_PATH);
    // printMatrix(data);
    for (int i: {Columns::Age, Columns::Sex, Columns::Pclass}){
        fillNan(data, i);
    }
    printBoats(fillBoats(data, 10, 10));
}

