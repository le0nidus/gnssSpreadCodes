#include "../include/GAL_E6.h"


void GAL_E6::generateE6B(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it

    generateCodeFromString(E6B_prn_hex.at(prn), GALILEO_E6_PRIMARY_CODE_LENGTH);
    return;
}

void GAL_E6::generatePrimaryE6C(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it

    generateCodeFromString(E6C_prn_hex.at(prn), GALILEO_E6_PRIMARY_CODE_LENGTH);
    return;
}

void GAL_E6::generateSecondaryE6C(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it

    generateCodeFromString(secondaryE6C[prn - 1]);
    return;
}