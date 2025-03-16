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
	prn_code.clear();
	std::vector<int> g2 = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
	std::vector<int> g1g3 = dec2bin(prn + d_or_p, 7);

	for (int i = 0; i < GLO_CDMA_LENGTH; i++) {
		prn_code.push_back(g1g3.back() ^ g2.back());
		lfsr(g2, 12424); // G2 register has 14 stages; XOR feedback is applied to registers 13, 12, 7, 3
		lfsr(g1g3, 96); // G1/G3 register has 7 stages; XOR feedback is applied to registers 6, 5
	}
	return;
}





void GLO_CDMA_L2::l2ocp(int prn) {
	prn_code.clear();
	std::vector<int> g2 = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
	std::vector<int> g1g3 = dec2bin(prn + 64, 7);

	for (int i = 0; i < GLO_CDMA_LENGTH; i++) {
		prn_code.push_back(g1g3.back() ^ g2.back());
		lfsr(g2, 12424); // G2 register has 14 stages; XOR feedback is applied to registers 13, 12, 7, 3
		lfsr(g1g3, 96); // G1/G3 register has 7 stages; XOR feedback is applied to registers 6, 5
	}
	return;
}

