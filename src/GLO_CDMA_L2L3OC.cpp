#include "../include/GLO_CDMA_L2L3OC.h"

void GLO_CDMA_L3::l3ocd(int prn) {
	l3oc(prn, 0);
	return;
}

void GLO_CDMA_L3::l3ocp(int prn) {
	l3oc(prn, 64);
	return;
}

void GLO_CDMA_L3::l3oc(int prn, int d_or_p) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	std::vector<int> g2 = g2_init;
	std::vector<int> g1g3 = dec2bin(prn + d_or_p, 7);
	generatePRN(prn, g1g3, g2, GLO_CDMA_L2L3_LENGTH, GLO_CDMA_L2L3_TAPS_G1G3, GLO_CDMA_L2L3_TAPS_G2);
	return;
}





void GLO_CDMA_L2::l2ocp(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	std::vector<int> g2 = g2_init;
	std::vector<int> g1g3 = dec2bin(prn + 64, 7);
	generatePRN(prn, g1g3, g2, GLO_CDMA_L2L3_LENGTH, GLO_CDMA_L2L3_TAPS_G1G3, GLO_CDMA_L2L3_TAPS_G2);
	return;
}

