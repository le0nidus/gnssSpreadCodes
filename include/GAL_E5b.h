#include "GAL_E5.h"

constexpr int GALILEO_E5b_PRIMARY_TAPS_G1 = 064021 >> 1;
constexpr int GALILEO_E5bI_PRIMARY_TAPS_G2 = 051445 >> 1;
constexpr int GALILEO_E5bQ_PRIMARY_TAPS_G2 = 043143 >> 1;


constexpr int GALILEO_E5b_NUMBER_OF_SATS = 36;		      //Total number of satellites

class GAL_E5b : public GAL_E5{
public:
    GAL_E5b() {     // Constructor
    }

    void generatePrimaryE5bI(int prn) {
        if (!checkValidPRN(prn))
            return; //BAD PRN so we don't create it
        generatePrimary(prn, E5BI_g2_init[prn - 1], GALILEO_E5b_PRIMARY_TAPS_G1, GALILEO_E5bI_PRIMARY_TAPS_G2);
        return;
    }
    
    void generatePrimaryE5bQ(int prn) {
        if (!checkValidPRN(prn))
            return; //BAD PRN so we don't create it
        generatePrimary(prn, E5BQ_g2_init[prn - 1], GALILEO_E5b_PRIMARY_TAPS_G1, GALILEO_E5bQ_PRIMARY_TAPS_G2);
        return;
    }
    

private:

    std::string getConstellationName() override { return "Galileo E5b"; }
    
    const int E5BI_g2_init[GALILEO_E5_NUMBER_OF_CODES] = {
        007220, 026047, 000252, 017166, 014161, 002540, 001537, 026023,
        001725, 020637, 002364, 027731, 030640, 034174, 006464, 007676,
        032231, 010353, 000755, 026077, 011644, 011537, 035115, 020452,
        034645, 025664, 021403, 032253, 002337, 030777, 027122, 022377,
        036175, 033075, 033151, 013134, 007433, 010216, 035466, 002533,
        005351, 030121, 014010, 032576, 030326, 037433, 026022, 035770,
        006670, 012017
    };
    
    const int E5BQ_g2_init[GALILEO_E5_NUMBER_OF_CODES] = {
        003331, 006143, 025322, 023371, 000413, 036235, 017750, 004745,
        013005, 037140, 030155, 020237, 003461, 031662, 027146, 005547,
        002456, 030013, 000322, 010761, 026767, 036004, 030713, 007662,
        021610, 020134, 011262, 010706, 034143, 011051, 025460, 017665,
        032354, 021230, 020146, 011362, 037246, 016344, 015034, 025471,
        025646, 022157, 004336, 016356, 004075, 002626, 011706, 037011,
        027041, 031024
    };
   

};