#include <vector>
#include <fstream>
#include <iostream>
#include "include/BDS_B1C.h"
#include "include/GPS_L5.h"
#include "include/GLO_CDMA_L1OC.h"
#include "include/GLO_CDMA_L2L3OC.h"


int main() {
	int prn;
	BDS_B1C B1C_spreadCode;
	GPS_L5 gpsl5;
	GLO_CDMA_L3 glo_l3oc;
	GLO_CDMA_L2 glo_l2oc;
	GLO_CDMA_L1 glo_l1oc;
	int n = 30;

	std::cout << "\nL1OCd\n";
	glo_l1oc.l1ocd(n); //L1OCd
	glo_l1oc.printOneCode();

	std::cout << "\n\n\nL1OCp\n";
	glo_l1oc.l1ocp(n); //L1OCp
	glo_l1oc.printOneCode();

	std::cout << "\n\n\nL2OCp\n";
	glo_l2oc.l2ocp(n); //L2OCp
	glo_l2oc.printOneCode();	

	std::cout << "\nL3OCd\n";
	glo_l3oc.l3ocd(n); //L3OCd
	glo_l3oc.printOneCode();

	std::cout << "\n\n\nL3OCp\n";
	glo_l3oc.l3ocp(n); //L3OCp
	glo_l3oc.printOneCode();	
	
	B1C_spreadCode.printConstellationHeader();
	std::cout << "Secondary Pilot Code\n";
	for (prn = 1; prn < BEIDOU_B1C_NUMBER_OF_SATS + 1; prn++) {
		std::cout << "PRN: " << prn << std::endl;
		B1C_spreadCode.generateSecondaryPilot(prn);
		B1C_spreadCode.printOneCode();
		std::cout << std::endl;
	}
	std::cout << "Primary Pilot Code\n";
	for (prn = 1; prn < BEIDOU_B1C_NUMBER_OF_SATS + 1; prn++) {
		std::cout << "PRN: " << prn << std::endl;
		B1C_spreadCode.generatePrimaryPilot(prn);
		B1C_spreadCode.printOneCode();
		std::cout << std::endl;
	}
	std::cout << "Primary Data Code\n";
	for (prn = 1; prn < BEIDOU_B1C_NUMBER_OF_SATS + 1; prn++) {
		std::cout << "PRN: " << prn << std::endl;
		B1C_spreadCode.generatePrimaryData(prn);
		B1C_spreadCode.printOneCode();
		std::cout << std::endl;
	}
    
	std::cout << std::endl;
	gpsl5.printConstellationHeader();
	std::cout << "L5Q CODE\n";
	for (prn = 1; prn < 64; prn++) {
		gpsl5.generateL5Q(prn);
		std::cout << "PRN: " << prn << std::endl;
		gpsl5.printOneCode(",");
		std::cout << std::endl;
	}

	std::cout << "L5I CODE\n";
	for (prn = 1; prn < 64; prn++) {
		gpsl5.generateL5I(prn);
		std::cout << "PRN: " << prn << std::endl;
		gpsl5.printOneCode();
		std::cout << std::endl;
	}

    return 0;
}



