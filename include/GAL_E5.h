#ifndef GAL_E5_HEADER
#define GAL_E5_HEADER
#include "Constellation.h"

constexpr int GALILEO_E5_PRIMARY_CODE_LENGTH = 10230;  // Each primary code of Pilot/Data components has the length 10230 chips.
constexpr int GALILEO_E5_SECONDARY_CODE_LENGTH = 100;  // Each secondary code of Pilot component has the length 100 chips.

constexpr int GALILEO_E5_NUM_REGISTERS_IN_LFSR = 14; // Amount of registers in the B2a primary codes

constexpr int GALILEO_E5_NUMBER_OF_SATS = 36;		      //Total number of satellites
constexpr int GALILEO_E5_NUMBER_OF_CODES = 50;		      //Number of codes in the ICD

class GAL_E5 : public Constellation{
public:
    GAL_E5() {}

protected:
    void generatePrimary(int prn, int g2Init, int tapsG1, int tapsG2);
    void generateSecondaryQ(std::string hexCode);

private:

    std::string getConstellationName() override { return "Galileo E5"; }
    int getNumberOfSats() override { return GALILEO_E5_NUMBER_OF_SATS; }
   

};

#endif