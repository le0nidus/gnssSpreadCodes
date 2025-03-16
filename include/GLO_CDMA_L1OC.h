#include <algorithm>
#include <vector>
#include <iterator>
#include "GLO_CDMA.h"

#define GLO_CDMA_L1OCd_LENGTH 1023
#define GLO_CDMA_L1OCp_LENGTH 4092

class GLO_CDMA_L1 : public GLO_CDMA {
public:
    GLO_CDMA_L1() {
		oneSizeConstellation = false;
	}
	void l1ocd(int prn);
	void l1ocp(int prn);

private:

	int getSpreadCodeSize() override { return GLO_CDMA_L1OCd_LENGTH; } //Length of L1OCd
	int getSpreadCodeSize2() override { return GLO_CDMA_L1OCp_LENGTH; } //Length of L1OCp
	std::string getConstellationName() override { return "GLONASS CDMA L1"; }

};




