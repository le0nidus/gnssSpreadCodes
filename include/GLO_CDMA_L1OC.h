#include <vector>
#include "GLO_CDMA.h"

#define GLO_CDMA_L1OCd_LENGTH 1023
#define GLO_CDMA_L1OCp_LENGTH 4092

#define GLO_CDMA_L1OCp_TAPS_G1 3232 // G1 register has 12 stages; XOR feedback is applied to registers 11, 10, 7, 5
#define GLO_CDMA_L1OCp_TAPS_G2 33 // G2 register has 6 stages; XOR feedback is applied to registers 0, 5
#define GLO_CDMA_L1OCd_TAPS_G1 576 // G1 register has 10 stages; XOR feedback is applied to registers 9, 6
#define GLO_CDMA_L1OCd_TAPS_G2 836 // G2 register has 10 stages; XOR feedback is applied to registers 2, 6, 8, 9

class GLO_CDMA_L1 : public GLO_CDMA {
public:
    GLO_CDMA_L1() {
		oneSizeConstellation = false;
	}
	void l1ocd(int prn);
	void l1ocp(int prn);

private:
	const std::vector<int> l1ocd_g1_init = {0, 0, 1, 1, 0, 0, 1, 0, 0, 0};
	const std::vector<int> l1ocp_g1_init = {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1};
	
	int getSpreadCodeSize() override { return GLO_CDMA_L1OCd_LENGTH; } //Length of L1OCd
	int getSpreadCodeSize2() override { return GLO_CDMA_L1OCp_LENGTH; } //Length of L1OCp
	std::string getConstellationName() override { return "GLONASS CDMA L1"; }

};




