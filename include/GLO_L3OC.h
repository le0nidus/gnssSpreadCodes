#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Constellation.h"

#define GLO_CDMA_L3_LENGTH 10230
#define GLO_CDMA_NUMBER_OF_SATS 63

class GLO_CDMA_L3 : public Constellation {
public:
    GLO_CDMA_L3() {}
	void l3ocd(int prn);
	void l3ocp(int prn);

private:

	int getSpreadCodeSize() override { return GLO_CDMA_L3_LENGTH; }
	int getSpreadCodeSize2() override { return 0; }
	std::string getConstellationName() override { return "GLONASS CDMA L3"; }
	int getNumberOfSats() override { return GLO_CDMA_NUMBER_OF_SATS; }

	std::vector<int> dec2bin(int n);

	void l3oc(int prn, int d_or_p);
	void lfsr(std::vector<int> &reg, int regSize, int taps);
};




