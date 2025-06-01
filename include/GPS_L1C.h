#include "Constellation.h"

constexpr int GPS_L1C_WEIL_N = 10223;
constexpr int GPS_L1C_PRIMARY_CODE_LENGTH = 10230;  // Each primary code of Pilot/Data components has the length 10230 chips.
constexpr int GPS_L1C_OVERLAY_CODE_LENGTH = 100;  // Each secondary code of Pilot component has the length 100 chips.

constexpr int GPS_L1C_NUM_REGISTERS_IN_LFSR = 11; // Amount of registers in the B2a primary codes
constexpr int GPS_L1C_TAPS_G1 = 0;
constexpr int GPS_L1C_TAPS_G2 = 0;
constexpr int GPS_L1C_LFSR_RESET_POSITION = 0;

constexpr int GPS_L1C_NUMBER_OF_SATS = 63;		      //Total number of satellites

class GPS_L1C : public Constellation{
public:
    GPS_L1C() {     // Constructor
        residue = residueCalculator(GPS_L1C_WEIL_N);
        legendre = generateLegendreSequence(GPS_L1C_WEIL_N, residue);
    }

    void generateL1CD(int prn);
    void generateL1CP(int prn);
    void generateOverlayCode(int prn);

private:

    std::string getConstellationName() override { return "GPS L1C"; }
    int getNumberOfSats() override { return GPS_L1C_NUMBER_OF_SATS; }    

    std::vector<int> residue;
    std::vector<int> legendre;
    const std::vector<int> insertion_weilCode = {0, 1, 1, 0, 1, 0, 0};

    void generateWeilL1C(int w, int p);

    const int L1CP_weil_idx[GPS_L1C_NUMBER_OF_SATS] = { // PRN 1 - 63
        5111, 5109, 5108, 5106, 5103, 5101, 5100, 5098, 5095, 5094, 5093, 5091,
        5090, 5081, 5080, 5069, 5068, 5054, 5044, 5027, 5026, 5014, 5004, 4980,
        4915, 4909, 4893, 4885, 4832, 4824, 4591, 3706, 5092, 4986, 4965, 4920,
        4917, 4858, 4847, 4790, 4770, 4318, 4126, 3961, 3790, 4911, 4881, 4827,
        4795, 4789, 4725, 4675, 4539, 4535, 4458, 4197, 4096, 3484, 3481, 3393,
        3175, 2360, 1852
    };
    
    const int L1CP_ins_idx[GPS_L1C_NUMBER_OF_SATS] = { // PRN 1 - 63
         412,  161,    1,  303,  207, 4971, 4496,    5, 4557,  485,  253, 4676,
           1,   66, 4485,  282,  193, 5211,  729, 4848,  982, 5955, 9805,  670,
         464,   29,  429,  394,  616, 9457, 4429, 4771,  365, 9705, 9489, 4193,
        9947,  824,  864,  347,  677, 6544, 6312, 9804,  278, 9461,  444, 4839,
        4144, 9875,  197, 1156, 4674,10035, 4504,    5, 9937,  430,    5,  355,
         909, 1622, 6284
    };
    
    const int L1CD_weil_idx[GPS_L1C_NUMBER_OF_SATS] = { // PRN 1 - 63
        5097, 5110, 5079, 4403, 4121, 5043, 5042, 5104, 4940, 5035, 4372, 5064,
        5084, 5048, 4950, 5019, 5076, 3736, 4993, 5060, 5061, 5096, 4983, 4783,
        4991, 4815, 4443, 4769, 4879, 4894, 4985, 5056, 4921, 5036, 4812, 4838,
        4855, 4904, 4753, 4483, 4942, 4813, 4957, 4618, 4669, 4969, 5031, 5038,
        4740, 4073, 4843, 4979, 4867, 4964, 5025, 4579, 4390, 4763, 4612, 4784,
        3716, 4703, 4851
    };
    
    const int L1CD_ins_idx[GPS_L1C_NUMBER_OF_SATS] = { // PRN 1 - 63
         181,  359,   72, 1110, 1480, 5034, 4622,    1, 4547,  826, 6284, 4195,
         368,    1, 4796,  523,  151,  713, 9850, 5734,   34, 6142,  190,  644,
         467, 5384,  801,  594, 4450, 9437, 4307, 5906,  378, 9448, 9432, 5849,
        5547, 9546, 9132,  403, 3766,    3,  684, 9711,  333, 6124,10216, 4251,
        9893, 9884, 4627, 4449, 9798,  985, 4272,  126,10024,  434, 1029,  561,
         289,  638, 4353
    };
   

};