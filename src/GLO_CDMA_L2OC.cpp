#include "../include/GLO_CDMA_L2OC.h"


void GLO_CDMA_L2::l2ocp(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	std::vector<int> g2 = g2_init;
	std::vector<int> g1g3 = dec2bin(prn + 64, 7);
	generatePRN(prn, g1g3, g2, GLO_CDMA_L2L3_LENGTH, GLO_CDMA_L2L3_TAPS_G1G3, GLO_CDMA_L2L3_TAPS_G2);
	return;
}

