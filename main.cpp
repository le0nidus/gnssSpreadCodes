#include <vector>
#include <fstream>
#include <iostream>
#include <B1C.h>





int main() {
    std::ofstream myFile("primaryCodeData.txt");
    std::vector<int> secondaryCodePilot;
    std::vector<int> primaryCodePilot;
    std::vector<int> primaryCodeData;
    int i, j;

    /*
    for (i = 1; i < BEIDOU_B1C_NBR_SATS + 1; i++) {
        secondaryCodePilot = weil_code_generator(BEIDOU_B1C_WEIL_N_SECONDARY, BEIDOU_B1C_SECONDARY_CODE_LENGTH, pilotSecondaryPhaseDiff[i - 1], pilotSecondaryTruncPoint[i - 1]);
        for (j = 0; j < BEIDOU_B1C_SECONDARY_CODE_LENGTH; j++) {
            myFile << secondaryCodePilot[j];
        }
        myFile << std::endl;
    }
    */
    /*
    for (i = 1; i < BEIDOU_B1C_NBR_SATS + 1; i++) {
        primaryCodePilot = weil_code_generator(BEIDOU_B1C_WEIL_N, BEIDOU_B1C_PRIMARY_CODE_LENGTH, pilotPrimaryPhaseDiff[i - 1], pilotPrimaryTruncPoint[i - 1]);
        for (j = 0; j < BEIDOU_B1C_PRIMARY_CODE_LENGTH; j++) {
            myFile << primaryCodePilot[j];
        }
        myFile << std::endl;
    }
    */
    for (i = 1; i < BEIDOU_B1C_NBR_SATS + 1; i++) {
        primaryCodeData = weil_code_generator(BEIDOU_B1C_WEIL_N, BEIDOU_B1C_PRIMARY_CODE_LENGTH, dataPrimaryPhaseDiff[i - 1], dataPrimaryTruncPoint[i - 1]);
        for (j = 0; j < BEIDOU_B1C_PRIMARY_CODE_LENGTH; j++) {
            myFile << primaryCodeData[j];
        }
        myFile << std::endl;
    }
    return 0;
}



