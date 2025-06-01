#include "../include/GPS_L1C.h"

void GPS_L1C::generateL1CP(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	generateWeilL1C(L1CP_weil_idx[prn - 1], L1CP_ins_idx[prn - 1]);
	return;
}

void GPS_L1C::generateL1CD(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	generateWeilL1C(L1CD_weil_idx[prn - 1], L1CD_ins_idx[prn - 1]);
	return;
}


void GPS_L1C::generateWeilL1C(int w, int p) {
	prn_code.clear();
    prn_code = generateWeilCode(GPS_L1C_WEIL_N, w, legendre);
	prn_code.insert(prn_code.begin() + (p) - 1, insertion_weilCode.begin(), insertion_weilCode.end());
	return;
}



