#include "../include/NAVIC_L1.h"


void NAVIC_L1::generatePrimary(ULL initR0, ULL initR1, int initC) {
	prn_code.clear();

	bool msb_is_last_idx = false;
	std::vector<int> R0 = dec2bin(initR0, GNAVIC_L1_PRIMARY_CODE_NUM_REGISTERS_R0R1, msb_is_last_idx);
	std::vector<int> R1 = dec2bin(initR1, GNAVIC_L1_PRIMARY_CODE_NUM_REGISTERS_R0R1, msb_is_last_idx);
	std::vector<int> C = dec2bin(initC, GNAVIC_L1_PRIMARY_CODE_NUM_REGISTERS_C, msb_is_last_idx);

	for (int i = 0; i < NAVIC_L1_PRIMARY_CODE_LENGTH; i++) {
		prn_code.push_back((C[0] ^ R1[0]) & 0x1);
		shiftPrimary(R0, R1, C);
	}
	return;
}

void NAVIC_L1::generateDataPrimary(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	generatePrimary(L1_DATA_R0_Init[prn - 1], L1_DATA_R1_Init[prn - 1], L1_DATA_C_Init[prn - 1]);
	return;
}

void NAVIC_L1::generatePilotPrimary(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	generatePrimary(L1_PILOT_R0_Init[prn - 1], L1_PILOT_R1_Init[prn - 1], L1_PILOT_C_Init[prn - 1]);
	return;
}


void NAVIC_L1::generatePilotOverlay(int prn) {
	if (!checkValidPRN(prn))
		return; //BAD PRN so we don't create it
	prn_code.clear();

	bool msb_is_last_idx = false;
	std::vector<int> R0 = dec2bin(L1_PILOT_Overlay_R0_Init[prn - 1], GNAVIC_L1_OVERLAY_CODE_NUM_REGISTERS_R0R1, msb_is_last_idx);
	std::vector<int> R1 = dec2bin(L1_PILOT_Overlay_R1_Init[prn - 1], GNAVIC_L1_OVERLAY_CODE_NUM_REGISTERS_R0R1, msb_is_last_idx);

	for (int i = 0; i < NAVIC_L1_SECONDARY_CODE_LENGTH; i++) {
		prn_code.push_back(R1[0] & 0x1);
		shiftOverlay(R0, R1);
	}
	return;
}

void NAVIC_L1::shiftPrimary(std::vector<int> &regR0, std::vector<int> &regR1, std::vector<int> &regC) {
	int xor_result_R0 = 0;
	int xor_result_R1 = 0;

	//Register R0
	xor_result_R0 = regR0[50] ^ regR0[45] ^ regR0[40] ^ regR0[20] ^ regR0[10] ^ regR0[5] ^ regR0[0];

	//Register R1
	int sigma_2A = (regR0[50] ^ regR0[45] ^ regR0[40]) & (regR0[20] ^ regR0[10] ^ regR0[5] ^ regR0[0]);
	int sigma_2B = ((regR0[50] ^ regR0[45]) & regR0[40]) ^ ((regR0[20] ^ regR0[10]) & (regR0[5] ^ regR0[0]));
	int sigma_2C = (regR0[50] & regR0[45]) ^ (regR0[20] & regR0[10]) ^ (regR0[5] & regR0[0]);
	int sigma_2 = sigma_2A ^ sigma_2B ^ sigma_2C;
	int R1A = sigma_2 ^ (regR0[40] ^ regR0[35] ^ regR0[30] ^ regR0[25] ^ regR0[15] ^ regR0[0]);
	int R1B = regR1[50] ^ regR1[45] ^ regR1[40] ^ regR1[20] ^ regR1[10] ^ regR1[5] ^ regR1[0];
	xor_result_R1 = R1A ^ R1B;	
	
	// Rotate right and place XOR result at the beginning
	std::rotate(regR0.begin(), regR0.begin() + 1, regR0.end());
	regR0.back() = xor_result_R0;
	
	std::rotate(regR1.begin(), regR1.begin() + 1, regR1.end());
	regR1.back() = xor_result_R1;

	int C_last_element = regC[0];
	std::rotate(regC.begin(), regC.begin() + 1, regC.end());
	regC.back() = C_last_element;
	return;
}

void NAVIC_L1::shiftOverlay(std::vector<int> &regR0, std::vector<int> &regR1) {
	int xor_result_R0 = 0;
	int xor_result_R1 = 0;

	//Register R0
	xor_result_R0 = regR0[5] ^ regR0[2] ^ regR0[1] ^ regR0[0];

	//Register R1
	int sigma_2A = (regR0[5] ^ regR0[2]) & (regR0[1] ^ regR0[0]);
	int sigma_2B = (regR0[5] & regR0[2]) ^ (regR0[1] & regR0[0]);
	int sigma_2C = (regR0[50] & regR0[45]) ^ (regR0[20] & regR0[10]) ^ (regR0[5] & regR0[0]);
	int sigma_2 = sigma_2A ^ sigma_2B;
	int R1A = sigma_2 ^ (regR0[6] ^ regR0[3] ^ regR0[2] ^ regR0[0]);
	int R1B = regR1[5] ^ regR1[2] ^ regR1[1] ^ regR1[0];
	xor_result_R1 = R1A ^ R1B;	
	
	// Rotate right and place XOR result at the beginning
	std::rotate(regR0.begin(), regR0.begin() + 1, regR0.end());
	regR0.back() = xor_result_R0;
	
	std::rotate(regR1.begin(), regR1.begin() + 1, regR1.end());
	regR1.back() = xor_result_R1;
	return;
}