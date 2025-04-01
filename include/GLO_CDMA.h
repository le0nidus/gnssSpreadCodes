#ifndef GLO_CDMA_HEADER
#define GLO_CDMA_HEADER

#include "Constellation.h"

constexpr int GLO_CDMA_NUMBER_OF_SATS = 63;
constexpr int GLO_CDMA_L2L3_LENGTH = 10230;
constexpr int GLO_CDMA_L2L3_TAPS_G1G3 = 96; // G1/G3 register has 14 stages; XOR feedback is applied to registers 13, 12, 7, 3
constexpr int GLO_CDMA_L2L3_TAPS_G2 = 12424; // G2 register has 6 stages; XOR feedback is applied to registers 0, 5

class GLO_CDMA : public Constellation {
public:
    GLO_CDMA() {}

protected:
    
private:
    int getNumberOfSats() override { return GLO_CDMA_NUMBER_OF_SATS; }
    
};



#endif


