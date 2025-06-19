#include "../include/GAL_E1.h"


void GAL_E1::generateE1B(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it

    generateCodeFromString(E1B_prn_hex.at(prn));
    return;
}

void GAL_E1::generateE1C(int prn) {
    if (!checkValidPRN(prn))
        return; //BAD PRN so we don't create it

    generateCodeFromString(E1C_prn_hex.at(prn));
    return;
}