#include "../include/GLO_L1OC.h"

void GLO_CDMA_L1::l1ocd(int prn) {
	prn_code.clear();
	std::vector<int> g1 = {0, 0, 1, 1, 0, 0, 1, 0, 0, 0};
	std::vector<int> g2 = dec2bin(prn, 10);

	for (int i = 0; i < 1023; i++) {
		prn_code.push_back(g1[9] ^ g2[9]);
		lfsr(g1, 576); // G1 register has 10 stages; XOR feedback is applied to registers 9, 6
		lfsr(g2, 836); // G2 register has 10 stages; XOR feedback is applied to registers 2, 6, 8, 9
	}
	return;
}

void GLO_CDMA_L1::l1ocp(int prn) {
	prn_code.clear();
	std::vector<int> g1 = {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1};
	std::vector<int> g2 = dec2bin(prn, 6);

	for (int i = 0; i < 4092; i++) {
		prn_code.push_back(g1[11] ^ g2[5]);
		lfsr(g1, 3232); // G1 register has 12 stages; XOR feedback is applied to registers 11, 10, 7, 5
		lfsr(g2, 33); // G2 register has 6 stages; XOR feedback is applied to registers 0, 5
	}
	return;
}


