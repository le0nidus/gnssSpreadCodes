#include <vector>
#include <fstream>
#include <iostream>
#include <B1C.h>
#include <GPS_L5.h>





int main() {
    /*
    std::ofstream myFile("secondaryCodePilot.txt");
    std::vector<int> secondaryCodePilot;
    std::vector<int> primaryCodePilot;
    std::vector<int> primaryCodeData;
    int j;
	*/
    /*
    B1C B1C_spreadCode;
    for (int prn = 1; prn < BEIDOU_B1C_NBR_SATS + 1; prn++) {
        secondaryCodePilot = B1C_spreadCode.generateSecondaryPilot(prn);
        for (j = 0; j < BEIDOU_B1C_SECONDARY_CODE_LENGTH; j++) {
            myFile << secondaryCodePilot[j];
        }
        myFile << std::endl;
    }
    */
	std::ofstream myfile;
	myfile.open("GPS_L5IQ.txt");
	int i, j;
	std::vector<int> vec;
	std::vector<int> result(13);
	GPS_L5 gpsl5;

	std::cout << "L5Q CODE\n";
	for (i = 1; i < 64; i++) {
		vec = gpsl5.generateL5Q(i);
		std::cout << "PRN: " << i << std::endl;
		gpsl5.print(vec, GPS_L5_CODE_LENGTH);
		std::cout << std::endl;
	}

	std::cout << "L5I CODE\n";
	for (i = 1; i < 64; i++) {
		vec = gpsl5.generateL5I(i);
		std::cout << "PRN: " << i << std::endl;
		gpsl5.print(vec, GPS_L5_CODE_LENGTH);
		std::cout << std::endl;
	}
	myfile.close();

    return 0;
}



