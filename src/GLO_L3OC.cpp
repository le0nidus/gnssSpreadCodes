#include "../include/GLO_L3OC.h"

std::vector<int> GLO_CDMA_L3::dec2bin(int n) {
	std::vector<int> s;
	for (int i = 0; i <= 6; i++)
		s.push_back((n >> (6-i)) & 1);
	return s;
}

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
	std::vector<int> g1g3 = dec2bin(prn + d_or_p);

	std::vector<int> prn_code_new;
	std::vector<int> g2new = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
	std::vector<int> g1g3new = dec2bin(prn + d_or_p);
	for (int i = 0; i < GLO_CDMA_L3_LENGTH; i++) {
		prn_code.push_back(g1g3[6] ^ g2[13]);
		lfsr(g2, 14, 12424); // G2 register has 14 stages; XOR feedback is applied to registers 13, 12, 7, 3
		lfsr(g1g3, 7, 96); // G1/G3 register has 7 stages; XOR feedback is applied to registers 6, 5
	}
	return;
}

/*
   This function implements a Linear Feedback Shift Register (LFSR), 
   commonly used for generating pseudo-random noise (PRN) codes.

   - The LFSR consists of a series of `regSize` registers forming a shift register.
   - The feedback mechanism uses XOR operations on specific register positions, 
     determined by the `taps` input.
   - Each bit in `taps` indicates whether the corresponding register value should 
     be included in the XOR operation.
   - The computed XOR result is inserted at the front of the register, 
     while the last element is removed, simulating a shift.

   Parameters:
   - `reg`: A reference to a vector representing the shift register.
   - `regSize`: The number of registers (length of the shift register).
   - `taps`: A bitmask indicating which registers contribute to the feedback XOR.

   The function updates the shift register in place.
*/
void GLO_CDMA_L3::lfsr(std::vector<int> &reg, int regSize, int taps) {
	int xor_result = 0;
	for (int i = 0 ; i < regSize; i++) {
		xor_result = reg[i] ^ (taps & 1);
		taps = taps >> 1;
	}
	reg.emplace(reg.begin(), xor_result);
	reg.pop_back();
}
