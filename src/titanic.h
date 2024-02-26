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
struct Passenger
{
    size_t id;
    std::string name;
    std::string sex;
    int pclass;
    int age;
    double value;
    void setImportant();
};
typedef std::vector<std::vector<Passenger>> boatVector;
boatVector fillBoats(const matrix&, size_t, size_t);

void printBoats(const boatVector&);