#include <string>
#include <vector>
#include <iterator>
#include <Constellation.h>
#include <fstream>
#include <iostream>

void Constellation::printCode(std::vector<int> spreadCode, int size) {
    for (int j = 0; j < size; j++)
        std::cout << spreadCode[j];
    std::cout << std::endl;
    return;
}
