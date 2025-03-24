#include "../include/LUNANET.h"

void LunaNet::afs_i(int prn) {
	std::vector<int> g1 = afs_i_g1_init;

	std::vector<int> g2;
	if (g2Register.find(prn) != g2Register.end()) {
        int g2Init = g2Register[prn];
		bool msb_is_last_idx = true;
		g2 = dec2bin(g2Init, 11, true);
    }
	else {
        std::cout << "PRN " << prn << " not found in g2Register!\n";
    }

	generatePRN(prn, g1, g2, LUNANET_SPREAD_CODE_LENGTH, LUNANET_AFSI_TAPS_G1, LUNANET_AFSI_TAPS_G2);
	return;
}


