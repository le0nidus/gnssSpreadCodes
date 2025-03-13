#include "../include/GLO_L3OC.h"

std::vector<int> GLO_CDMA_L3::dec2bin(int n) {
	std::vector<int> s;
	for (int i = 0; i <= 6; i++)
		s.push_back((n >> (6-i)) & 1);
	return s;
}

void GLO_CDMA_L3::shift_g2(std::vector<int> &g2) {
	g2.emplace(g2.begin(), g2[13] ^ g2[12] ^ g2[7] ^ g2[3]);
	g2.pop_back();
	return;
}

void GLO_CDMA_L3::shift_g1g3(std::vector<int> &g3) {
	g3.emplace(g3.begin(), g3[6] ^ g3[5]);
	g3.pop_back();
	return;
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
	for (int i = 0; i < GLO_CDMA_L3_LENGTH; i++) {
		prn_code.push_back(g1g3[6] ^ g2[13]);
		shift_g2(g2);
		shift_g1g3(g1g3);
	}
	return;
}

/*

  def make_l3ocd(n):
  g3 = seq(n)
  g2 = [0,0,1,1,0,1,0,0,1,1,1,0,0,0]
  x = np.zeros(code_length)
  for i in range(code_length):
    x[i] = g3[6]^g2[13]
    g3 = g3_shift(g3)
    g2 = g2_shift(g2)
  return x
*/
