#ifndef GLO_CDMA_HEADER
#define GLO_CDMA_HEADER

#include <algorithm>
#include <vector>
#include <iterator>
#include "Constellation.h"

#define GLO_CDMA_LENGTH 10230
#define GLO_CDMA_NUMBER_OF_SATS 63


class GLO_CDMA : public Constellation {
public:
    GLO_CDMA() {}

protected:
    std::vector<int> dec2bin(int n, int numOfBits);
    void lfsr(std::vector<int> &reg, int taps);
    
private:
    
    int getNumberOfSats() override { return GLO_CDMA_NUMBER_OF_SATS; }
    
};



#endif


