#include <vector>
#include "GLO_CDMA.h"

#define GLO_CDMA_L2L3_LENGTH 10230

#define GLO_CDMA_L2L3_TAPS_G1G3 96 // G1/G3 register has 14 stages; XOR feedback is applied to registers 13, 12, 7, 3
#define GLO_CDMA_L2L3_TAPS_G2 12424 // G2 register has 6 stages; XOR feedback is applied to registers 0, 5

class GLO_CDMA_L3 : public GLO_CDMA {
public:
    GLO_CDMA_L3() {}
	void l3ocd(int prn);
	void l3ocp(int prn);

private:
	const std::vector<int> g2_init = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
	
	int getSpreadCodeSize() override { return GLO_CDMA_L2L3_LENGTH; }
	int getSpreadCodeSize2() override { return 0; }
	std::string getConstellationName() override { return "GLONASS CDMA L3"; }

	void l3oc(int prn, int d_or_p);
};



class GLO_CDMA_L2 : public GLO_CDMA {
public:
	GLO_CDMA_L2() {}
	void l2ocp(int prn);

private:
	const std::vector<int> g2_init = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};

	int getSpreadCodeSize() override { return GLO_CDMA_L2L3_LENGTH; }
	int getSpreadCodeSize2() override { return 0; }
	std::string getConstellationName() override { return "GLONASS CDMA L2"; }
};




