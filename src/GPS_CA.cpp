#include "../include/GPS_CA.h"

void GPS_CA::generate(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	prn_code.clear();

	std::vector<int> g1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	std::vector<int> g2 = g1;
	std::vector<int> G1, G2;

	for (int i = 0; i < GPS_CA_CODE_LENGTH; ++i) {
		G1.push_back(g1.back());
		G2.push_back(g2.back());
		lfsr(g1, GPS_CA_TAPS_G1); // Update g1 using LFSR
        lfsr(g2, GPS_CA_TAPS_G2); // Update g2 using LFSR
	}

	int delay_g2 = L1CA_G2_delay[prn - 1];
	std::rotate(G2.rbegin(), G2.rbegin() + delay_g2, G2.rend());

	for (int i = 0; i < GPS_CA_CODE_LENGTH; i++)
		prn_code.push_back(G1[i] ^ G2[i]);
	
	
	return;
}
