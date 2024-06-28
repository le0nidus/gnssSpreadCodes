#include <algorithm>
#include <vector>
#include <iterator>
#include <GPS_L5.h>


std::vector<int> GPS_L5::xa_shift(std::vector<int>& xa) {
	if (xa == std::vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}) {
		return std::vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	}
	else {
		std::vector<int> result(xa.begin(), xa.end() - 1);
		result.insert(result.begin(), xa[12] ^ xa[11] ^ xa[9] ^ xa[8]);
		return result;
	}
}

std::vector<int> GPS_L5::xb_shift(std::vector<int>&xb) {
	std::vector<int> result(xb.begin(), xb.end() - 1);
	result.insert(result.begin(), xb[12] ^ xb[11] ^ xb[7] ^ xb[6] ^ xb[5] ^ xb[3] ^ xb[2] ^ xb[0]);
	return result;
}

std::vector<int> GPS_L5::make_xa() {
	std::vector<int> register_init(GPS_L5_REGISTER_SIZE, 1);
	std::vector<int> y(GPS_L5_CODE_LENGTH);
	for (int i = 0; i < GPS_L5_CODE_LENGTH; ++i) {
		y[i] = register_init[GPS_L5_REGISTER_SIZE - 1];
		register_init = xa_shift(register_init);
	}
	return y;
}

std::vector<int> GPS_L5::make_xb() {
	std::vector<int> register_init(GPS_L5_REGISTER_SIZE, 1);
	std::vector<int> y(GPS_L5_XB_SIZE);
	for (int i = 0; i < GPS_L5_XB_SIZE; ++i) {
		y[i] = register_init[GPS_L5_REGISTER_SIZE - 1];
		register_init = xb_shift(register_init);
	}
	return y;
}


std::vector<int> GPS_L5::generateL5I(int prn) {
	std::vector<int> code(GPS_L5_CODE_LENGTH);
	int xb_offset = 0;
	int xb_shift_i;

	xb_offset = l5i_init[prn];

	for (int i = 0; i < GPS_L5_CODE_LENGTH; ++i) {
		xb_shift_i = xb[(xb_offset + i) % GPS_L5_XB_SIZE];
		code[i] = (xa[i] ^ xb_shift_i);
	}
	return code;
}

std::vector<int> GPS_L5::generateL5Q(int prn) {
	std::vector<int> code(GPS_L5_CODE_LENGTH);
	int xb_offset = 0;
	int xb_shift_i;

	xb_offset = l5q_init[prn];

	for (int i = 0; i < GPS_L5_CODE_LENGTH; ++i) {
		xb_shift_i = xb[(xb_offset + i) % GPS_L5_XB_SIZE];
		code[i] = (xa[i] ^ xb_shift_i);
	}

	return code;
}