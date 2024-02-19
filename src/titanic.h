#include <string>
#include <iostream>
#include <vector>

typedef std::vector <std::vector<std::string>> matrix;
matrix readCsv(const std::string&);

void printMatrix(const matrix&);