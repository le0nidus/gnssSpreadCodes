#include "../include/LUNANET.h"

void LunaNet::afs_i(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	std::vector<int> g1 = afs_i_g1_init;

	std::vector<int> g2;
	int g2Init = g2RegisterInit.at(prn);
	bool msb_is_last_idx = true;
	g2 = dec2bin(g2Init, LUNANET_AFSI_NUM_REGISTERS_IN_G2, msb_is_last_idx);

	generatePRN(prn, g1, g2, LUNANET_AFSI_CODE_LENGTH, LUNANET_AFSI_TAPS_G1, LUNANET_AFSI_TAPS_G2);
	return;
}

void LunaNet::afs_q_primary(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	prn_code.clear();
    prn_code = generateWeilCode(LUNANET_PRIMARY_WEIL_N, afs_q_primary_weil_parameters.at(prn).first, legendrePrimary);
	prn_code.insert(prn_code.begin() + (afs_q_primary_weil_parameters.at(prn).second - 1), insertion_afs_q_primary.begin(), insertion_afs_q_primary.end());
	return;
}

void LunaNet::afs_q_trietary(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	prn_code.clear();
    prn_code = generateWeilCode(LUNANET_TRIETARY_WEIL_N, afs_q_trietary_weil_parameters.at(prn), legendreTrietary);
	prn_code.push_back(0);
	return;
}



