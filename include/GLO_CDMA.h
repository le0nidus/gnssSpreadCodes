#ifndef GLO_CDMA_HEADER
#define GLO_CDMA_HEADER

#include "Constellation.h"

#define GLO_CDMA_NUMBER_OF_SATS 63


class GLO_CDMA : public Constellation {
public:
    GLO_CDMA() {}

protected:
    
private:
    int getNumberOfSats() override { return GLO_CDMA_NUMBER_OF_SATS; }
    
};



#endif


