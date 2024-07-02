#include <vector>
#include <fstream>
#include <iostream>
#include <B1C.h>
#include <GPS_L5.h>





int main() {
	std::vector<int> vec;
	int prn;
	B1C B1C_spreadCode;
	GPS_L5 gpsl5;
	std::cout << "/===========BeiDou B1C Code===========/\n";
	std::cout << "Secondary Pilot Code\n";
	for (prn = 1; prn < BEIDOU_B1C_NBR_SATS + 1; prn++) {
		std::cout << "PRN: " << prn << std::endl;
		vec = B1C_spreadCode.generateSecondaryPilot(prn);
		B1C_spreadCode.printOneCode(vec);
		std::cout << std::endl;
	}
	std::cout << "Primary Pilot Code\n";
	for (prn = 1; prn < BEIDOU_B1C_NBR_SATS + 1; prn++) {
		std::cout << "PRN: " << prn << std::endl;
		vec = B1C_spreadCode.generatePrimaryPilot(prn);
		B1C_spreadCode.printOneCode(vec);
		std::cout << std::endl;
	}
	std::cout << "Primary Data Code\n";
	for (prn = 1; prn < BEIDOU_B1C_NBR_SATS + 1; prn++) {
		std::cout << "PRN: " << prn << std::endl;
		vec = B1C_spreadCode.generatePrimaryData(prn);
		B1C_spreadCode.printOneCode(vec);
		std::cout << std::endl;
	}
    
	std::cout << std::endl;
	std::cout << "/===========GPS L5 Code===========/\n";
	std::cout << "L5Q CODE\n";
	for (prn = 1; prn < 64; prn++) {
		vec = gpsl5.generateL5Q(prn);
		std::cout << "PRN: " << prn << std::endl;
		gpsl5.printOneCode(vec, ",");
		std::cout << std::endl;
	}

	std::cout << "L5I CODE\n";
	for (prn = 1; prn < 64; prn++) {
		vec = gpsl5.generateL5I(prn);
		std::cout << "PRN: " << prn << std::endl;
		gpsl5.printOneCode(vec);
		std::cout << std::endl;
	}

    return 0;
}



