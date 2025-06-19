#include "../include/GAL_E5.h"


void GAL_E5::generatePrimary(int prn, int g2Init, int tapsG1, int tapsG2) {
    std::vector<int> g1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> g2;
    bool msb_is_last_idx = true;
    g2 = dec2bin(g2Init, GALILEO_E5_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);
    generatePRN(g1, g2, GALILEO_E5_PRIMARY_CODE_LENGTH, tapsG1, tapsG2);
    return;
}


