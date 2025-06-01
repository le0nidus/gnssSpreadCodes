#include "../include/GPS_L1C.h"

void GPS_L1C::generateL1CP(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	generateWeilL1C(L1CP_weil_w[prn - 1], L1CP_idx_p[prn - 1]);
	return;
}

void GPS_L1C::generateL1CD(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	generateWeilL1C(L1CD_weil_w[prn - 1], L1CD_idx_p[prn - 1]);
	return;
}


void GPS_L1C::generateWeilL1C(int w, int p) {
	prn_code.clear();
    prn_code = generateWeilCode(GPS_L1C_WEIL_N, w, legendre);
	prn_code.insert(prn_code.begin() + (p) - 1, insertion_weilCode.begin(), insertion_weilCode.end());
	return;
}

void GPS_L1C::generatePRN(int prn, std::vector<int> s1, int s1Taps) {
    prn_code.clear();  // Clear any previously stored PRN sequence
	for (int i = 0; i < GPS_L1C_OVERLAY_CODE_LENGTH; i++) {
		prn_code.push_back(s1.back()); // XOR last elements of g1 and g2
		lfsr(s1, s1Taps); // Update g1 using LFSR
	}
	return;
}

void GPS_L1C::generateL1CO(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it

	bool msb_is_last_idx = true;
	std::vector<int> s1 = dec2bin(L1CO_S1_init[prn - 1], GPS_L1C_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);

	if (prn <= GPS_L1C_NUMBER_OF_SATS)
		generatePRN(prn, s1, L1CO_S1_poly[prn - 1] >> 1);
	else if (prn <= GPS_L1C_NUMBER_OF_CODES) {
    	std::vector<int> s2 = dec2bin(L1CO_S2_init[prn - 64], GPS_L1C_NUM_REGISTERS_IN_LFSR, msb_is_last_idx);
		Constellation::generatePRN(s1, s2, GPS_L1C_OVERLAY_CODE_LENGTH, L1CO_S1_poly[prn - 1] >> 1, GPS_L1C_TAPS_S2);
	}
	else
		return;
	
	return;
}



