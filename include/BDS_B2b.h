#include "Constellation.h"

constexpr int BEIDOU_B2B_CODE_LENGTH = 10230;  // Each code has the length 10230 chips.

constexpr int BEIDOU_B2B_NUM_REGISTERS_IN_LFSR = 13; // Amount of registers in the B2b primary codes
constexpr int BEIDOU_B2B_TAPS_G1 = 4865;
constexpr int BEIDOU_B2B_TAPS_G2 = 6444;
constexpr int BEIDOU_B2B_LFSR_RESET_POSITION = 8190;

constexpr int BEIDOU_B2B_NUMBER_OF_SATS = 63;		      //Total number of satellites

class BDS_B2b : public Constellation{
public:
    BDS_B2b() {}

    void generateCode(int prn);

private:

    std::string getConstellationName() override { return "BeiDou B2b"; }
    int getNumberOfSats() override { return BEIDOU_B2B_NUMBER_OF_SATS; }    

    const std::unordered_map<int, int> g2_init = {
        { 1, 0x1025 }, { 2, 0x1034 }, { 3, 0x10AD }, { 4, 0x114F },
        { 5, 0x1155 }, { 6, 0x11AE }, { 7, 0x11EE }, { 8, 0x11FB },
        { 9, 0x1329 }, { 10, 0x13DA }, { 11, 0x1435 }, { 12, 0x1444 },
        { 13, 0x1455 }, { 14, 0x145B }, { 15, 0x145C }, { 16, 0x14A3 },
        { 17, 0x14F7 }, { 18, 0x1501 }, { 19, 0x153E }, { 20, 0x15AB },
        { 21, 0x15B1 }, { 22, 0x1653 }, { 23, 0x1662 }, { 24, 0x1698 },
        { 25, 0x16B6 }, { 26, 0x16F2 }, { 27, 0x16FF }, { 28, 0x1712 },
        { 29, 0x173C }, { 30, 0x17A1 }, { 31, 0x17C8 }, { 32, 0x17D4 },
        { 33, 0x17EB }, { 34, 0x17F3 }, { 35, 0x1851 }, { 36, 0x1894 },
        { 37, 0x18B7 }, { 38, 0x1911 }, { 39, 0x1919 }, { 40, 0x19AB },
        { 41, 0x19B1 }, { 42, 0x19D2 }, { 43, 0x1A55 }, { 44, 0x1A74 },
        { 45, 0x1ACB }, { 46, 0x1B57 }, { 47, 0x1C34 }, { 48, 0x1C83 },
        { 49, 0x1C8B }, { 50, 0x1CA3 }, { 51, 0x1CA8 }, { 52, 0x1D3B },
        { 53, 0x1D97 }, { 54, 0x1E48 }, { 55, 0x1E94 }, { 56, 0x1E99 },
        { 57, 0x1EDA }, { 58, 0x1EF8 }, { 59, 0x1EFF }, { 60, 0x1FB5 },
        { 61, 0x1FBD }, { 62, 0x0B85 }, { 63, 0x0B3B }
    };   

};