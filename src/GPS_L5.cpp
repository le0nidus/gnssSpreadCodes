#include <GPS_L5.h>


std::vector<int> GPS_L5::xa_shift(std::vector<int> xa) {
	if (xa == xa_stop_vec)
		return xa_all_ones_vec;
	else {
		std::vector<int> result(xa.begin(), xa.end() - 1);
		result.insert(result.begin(), xa[12] ^ xa[11] ^ xa[9] ^ xa[8]);
		return result;
	}
}

std::vector<int> GPS_L5::xb_shift(std::vector<int> xb) {
	std::vector<int> result(xb.begin(), xb.end() - 1);
	result.insert(result.begin(), xb[12] ^ xb[11] ^ xb[7] ^ xb[6] ^ xb[5] ^ xb[3] ^ xb[2] ^ xb[0]);
	return result;
}

void GPS_L5::make_xa_xb(std::vector<int> &xa, std::vector<int>& xb) {
	std::vector<int> register_init_xa(GPS_L5_REGISTER_SIZE, 1);
	std::vector<int> register_init_xb(GPS_L5_REGISTER_SIZE, 1);
	for (int i = 0; i < GPS_L5_CODE_LENGTH; ++i) {
		xa.push_back(register_init_xa[GPS_L5_REGISTER_SIZE - 1]);
		xb.push_back(register_init_xb[GPS_L5_REGISTER_SIZE - 1]);
		register_init_xa = xa_shift(register_init_xa);
		register_init_xb = xb_shift(register_init_xb);
	}
	return;
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
