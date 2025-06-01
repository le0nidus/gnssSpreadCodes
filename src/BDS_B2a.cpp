#include "../include/BDS_B2a.h"

void BDS_B2a::generateSecondaryPilot(int prn) {
    if (!checkValidPRN(prn))
		  return; //BAD PRN so we don't create it
    generateTruncatedWeil(prn, BEIDOU_B2A_WEIL_N_SECONDARY, BEIDOU_B2A_SECONDARY_CODE_LENGTH, phaseDiff[prn - 1], truncPoint[prn - 1], legendre);
    return;
}

void BDS_B2a::generatePrimary(int g2Init, int tapsG1, int tapsG2) {
    std::vector<int> g1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> g2;
    bool msb_is_last_idx = false;
    g2 = dec2bin(g2Init, BEIDOU_B2A_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);
    generatePRN(g1, g2, BEIDOU_B2A_PRIMARY_CODE_LENGTH, tapsG1, tapsG2, (BEIDOU_B2A_LFSR_RESET_POSITION - 1));
    return;
}

void BDS_B2a::generatePrimaryData(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it
    generatePrimary(g2_data_init.at(prn), BEIDOU_B2A_PRIMARY_DATA_TAPS_G1, BEIDOU_B2A_PRIMARY_DATA_TAPS_G2);
    return;
}

void BDS_B2a::generatePrimaryPilot(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it
    generatePrimary(g2_pilot_init.at(prn), BEIDOU_B2A_PRIMARY_PILOT_TAPS_G1, BEIDOU_B2A_PRIMARY_PILOT_TAPS_G2);
    return;
}
