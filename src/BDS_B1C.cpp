#include "../include/BDS_B1C.h"

void BDS_B1C::generatePrimaryData(int prn) {
    if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
    generateTruncatedWeil(prn, BEIDOU_B1C_WEIL_N, BEIDOU_B1C_PRIMARY_CODE_LENGTH, dataPrimaryPhaseDiff[prn - 1], dataPrimaryTruncPoint[prn - 1], legendrePrimary);
    return;
}

void BDS_B1C::generatePrimaryPilot(int prn) {
    if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
    generateTruncatedWeil(prn, BEIDOU_B1C_WEIL_N, BEIDOU_B1C_PRIMARY_CODE_LENGTH, pilotPrimaryPhaseDiff[prn - 1], pilotPrimaryTruncPoint[prn - 1], legendrePrimary);
    return;
}

void BDS_B1C::generateSecondaryPilot(int prn) {
    if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
    generateTruncatedWeil(prn, BEIDOU_B1C_WEIL_N_SECONDARY, BEIDOU_B1C_SECONDARY_CODE_LENGTH, pilotSecondaryPhaseDiff[prn - 1], pilotSecondaryTruncPoint[prn - 1], legendreSecondary);
    return;
}
