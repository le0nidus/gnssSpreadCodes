#include <Constellation.h>


void Constellation::printOneCode(std::vector<int> spreadCode, int size) {
    for (int j = 0; j < size; j++)
        std::cout << spreadCode[j];
    std::cout << std::endl;
    return;
}

void Constellation::printOneCode(std::vector<int> spreadCode, int size, std::string sep) {
    for (int j = 0; j < size; j++)
        std::cout << spreadCode[j] << sep;
    std::cout << std::endl;
    return;
}
