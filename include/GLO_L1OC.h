#include <algorithm>
#include <vector>
#include <iterator>
#include "Constellation.h"
#include "GLO_CDMA.h"

class GLO_CDMA_L1 : public Constellation {
public:
    GLO_CDMA_L1() {}
	void l1ocd(int prn);
	void l1ocp(int prn);

private:

	int getSpreadCodeSize() override { return GLO_CDMA_LENGTH; }
	int getSpreadCodeSize2() override { return 0; }
	std::string getConstellationName() override { return "GLONASS CDMA L1"; }
	int getNumberOfSats() override { return GLO_CDMA_NUMBER_OF_SATS; }

};




