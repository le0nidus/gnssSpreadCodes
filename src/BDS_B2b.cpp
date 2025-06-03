#include "../include/BDS_B2b.h"


void BDS_B2b::generateCode(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it
    std::vector<int> g1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> g2;
    bool msb_is_last_idx = false;
    g2 = dec2bin(g2_init.at(prn), BEIDOU_B2B_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);
    generatePRN(g1, g2, BEIDOU_B2B_CODE_LENGTH, BEIDOU_B2B_TAPS_G1, BEIDOU_B2B_TAPS_G2, (BEIDOU_B2B_LFSR_RESET_POSITION - 1));
    return;
}


