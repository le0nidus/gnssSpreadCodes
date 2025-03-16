#ifndef GLO_CDMA_HEADER
#define GLO_CDMA_HEADER

#include <algorithm>
#include <vector>
#include <iterator>
#include "Constellation.h"

#define GLO_CDMA_NUMBER_OF_SATS 63


class GLO_CDMA : public Constellation {
public:
    GLO_CDMA() {}

protected:
    std::vector<int> dec2bin(int n, int numOfBits);
    void lfsr(std::vector<int> &reg, int taps);
    void generatePRN(int prn, std::vector<int> g1, std::vector<int> g2, int codeLen, int tapsG1, int tapsG2);

private:
    
    int getNumberOfSats() override { return GLO_CDMA_NUMBER_OF_SATS; }
    
};



#endif


