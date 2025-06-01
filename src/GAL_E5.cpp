#include "../include/GAL_E5.h"


void GAL_E5::generatePrimary(int prn, int g2Init, int tapsG1, int tapsG2) {
    std::vector<int> g1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> g2;
    bool msb_is_last_idx = true;
    g2 = dec2bin(g2Init, GALILEO_E5_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);
    generatePRN(g1, g2, GALILEO_E5_PRIMARY_CODE_LENGTH, tapsG1, tapsG2);
    return;
}

void GAL_E5::generateSecondaryQ(std::string hexCode) {
    prn_code.clear();  // Clear any previously stored PRN sequence
    for (char c : hexCode) {
        // Convert hex character to its 4-bit integer value
        uint8_t value = 0;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'A' && c <= 'F')
            value = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            value = c - 'a' + 10;
        else
            continue; // skip invalid characters

        // Extract 4 bits from most significant to least significant
        for (int bit = 3; bit >= 0; --bit) {
            prn_code.push_back((value >> bit) & 1);
        }
    }
    return;
}

