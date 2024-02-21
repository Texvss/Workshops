#include <string>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<std::string>> matrix;

enum Columns {
    PassengerId, Survived, Pclass, Name, Sex, Age, SibSp, Parch, Ticket, Fare, Cabin, Embarked
};

matrix readCsv(const std::string &);

void printMatrix(const matrix &);

double getImportant(int, int, const std::string &);

void fillNan(matrix &, int);
