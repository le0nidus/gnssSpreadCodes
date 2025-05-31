#include "GAL_E5.h"

constexpr int GALILEO_E5a_PRIMARY_TAPS_G1 = 040503 >> 1;
constexpr int GALILEO_E5a_PRIMARY_TAPS_G2 = 050661 >> 1;

class GAL_E5a : public GAL_E5{
public:
    GAL_E5a() {     // Constructor
    }

    void generatePrimaryE5aI(int prn) {
        if (!checkValidPRN(prn))
            return; //BAD PRN so we don't create it
        generatePrimary(prn, E5AI_g2_init[prn - 1] >> 1, GALILEO_E5a_PRIMARY_TAPS_G1, GALILEO_E5a_PRIMARY_TAPS_G2);
        return;
    }
    
    void generatePrimaryE5aQ(int prn) {
        if (!checkValidPRN(prn))
            return; //BAD PRN so we don't create it
        generatePrimary(prn, E5AQ_g2_init[prn - 1], GALILEO_E5a_PRIMARY_TAPS_G1, GALILEO_E5a_PRIMARY_TAPS_G2);
        return;
    }
    

private:

    std::string getConstellationName() override { return "Galileo E5a"; }

    const int E5AI_g2_init[GALILEO_E5_NUMBER_OF_CODES] = {
        030305, 014234, 027213, 020577, 023312, 033463, 015614, 012537,
        001527, 030236, 027344, 007272, 036377, 017046, 006434, 015405,
        024252, 011631, 024776, 000630, 011560, 017272, 027445, 031702,
        013012, 014401, 034727, 022627, 030623, 027256, 001520, 014211,
        031465, 022164, 033516, 002737, 021316, 035425, 035633, 024655,
        014054, 027027, 006604, 031455, 034465, 025273, 020763, 031721,
        017312, 013277
    };
    
    const int E5AQ_g2_init[GALILEO_E5_NUMBER_OF_CODES] = {
        025652, 005142, 024723, 031751, 027366, 024660, 033655, 027450,
        007626, 001705, 012717, 032122, 016075, 016644, 037556, 002477,
        002265, 006430, 025046, 012735, 004262, 011230, 000037, 006137,
        004312, 020606, 011162, 022252, 030533, 024614, 007767, 032705,
        005052, 027553, 003711, 002041, 034775, 005274, 037356, 016205,
        036270, 006600, 026773, 017375, 035267, 036255, 012044, 026442,
        021621, 025411
    };

};