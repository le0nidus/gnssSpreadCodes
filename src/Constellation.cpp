#include "../include/Constellation.h"

void Constellation::printConstellationHeader() {
	std::cout << "/=========== " << getConstellationName() << " Code ===========/\n";
}

void Constellation::printOneCode() {
	int vecSize = (int)prn_code.size();
	if (oneSizeConstellation) {
		if (vecSize != getSpreadCodeSize()) {
			std::cout << "Error printing vector. Invalid " << getConstellationName() << " spread code.";
			return;
		}
	}	
	else {
		if (vecSize != getSpreadCodeSize() && vecSize != getSpreadCodeSize2()) {
			std::cout << "Error printing vector. Invalid " << getConstellationName() << " spread code.";
			return;
		}
	}
    for (int j = 0; j < vecSize; j++)
        std::cout << prn_code[j];
    std::cout << std::endl;
    return;
}

void Constellation::printOneCode(std::string sep) {
	int vecSize = (int)prn_code.size();
	if (oneSizeConstellation) {
		if (vecSize != getSpreadCodeSize()) {
			std::cout << "Error printing vector. Invalid " << getConstellationName() << " spread code.";
			return;
		}
	}
	else {
		if (vecSize != getSpreadCodeSize() && vecSize != getSpreadCodeSize2()) {
			std::cout << "Error printing vector. Invalid " << getConstellationName() << " spread code.";
			return;
		}
	}
    for (int j = 0; j < vecSize; j++)
        std::cout << prn_code[j] << sep;
    std::cout << std::endl;
    return;
}

