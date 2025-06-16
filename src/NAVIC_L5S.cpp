#include "../include/NAVIC_L5S.h"


void NAVIC_L5S::generatePrimary(int initG2) {
    std::vector<int> g1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> g2;
    bool msb_is_last_idx = true;
    g2 = dec2bin(initG2, NAVIC_L5S_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);
    generatePRN(g1, g2, NAVIC_L5S_PRIMARY_CODE_LENGTH, NAVIC_L5S_TAPS_G1, NAVIC_L5S_TAPS_G2);
    return;
}


void NAVIC_L5::generate(int prn) {
    generatePrimary(L5_G2_Init[prn - 1]);
    return;
}

void NAVIC_S::generate(int prn) {
    generatePrimary(S_G2_Init[prn - 1]);
    return;
}