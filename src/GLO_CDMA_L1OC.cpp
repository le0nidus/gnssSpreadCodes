#include "../include/GLO_CDMA_L1OC.h"

void GLO_CDMA_L1::l1ocd(int prn) {
	std::vector<int> g1 = l1ocd_g1_init;
	std::vector<int> g2 = dec2bin(prn, GLO_CDMA_L1OCd_NUM_REGISTERS_IN_G2);
	generatePRN(prn, g1, g2, GLO_CDMA_L1OCd_LENGTH, GLO_CDMA_L1OCd_TAPS_G1, GLO_CDMA_L1OCd_TAPS_G2);
	return;
}

void GLO_CDMA_L1::l1ocp(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	std::vector<int> g1 = l1ocp_g1_init;
	std::vector<int> g2 = dec2bin(prn, GLO_CDMA_L1OCp_NUM_REGISTERS_IN_G2);
	generatePRN(prn, g1, g2, GLO_CDMA_L1OCp_LENGTH, GLO_CDMA_L1OCp_TAPS_G1, GLO_CDMA_L1OCp_TAPS_G2);
	return;
}


