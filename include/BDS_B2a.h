#include "Constellation.h"

constexpr int BEIDOU_B2A_WEIL_N_SECONDARY = 1021;
constexpr int BEIDOU_B2A_PRIMARY_CODE_LENGTH = 10230;  // Each primary code of Pilot/Data components has the length 10230 chips.
constexpr int BEIDOU_B2A_SECONDARY_CODE_LENGTH = 100;  // Each secondary code of Pilot component has the length 100 chips.

constexpr int BEIDOU_B2A_NUM_REGISTERS_IN_LFSR = 13; // Amount of registers in the B2a primary codes
constexpr int BEIDOU_B2A_PRIMARY_DATA_TAPS_G1 = 5137;
constexpr int BEIDOU_B2A_PRIMARY_DATA_TAPS_G2 = 7444;
constexpr int BEIDOU_B2A_PRIMARY_PILOT_TAPS_G1 = 4196;
constexpr int BEIDOU_B2A_PRIMARY_PILOT_TAPS_G2 = 6353;
constexpr int BEIDOU_B2A_LFSR_RESET_POSITION = 8190;

constexpr int BEIDOU_B2A_NUMBER_OF_SATS = 63;		      //Total number of satellites

class BDS_B2a : public Constellation{
public:
    BDS_B2a() {     // Constructor
        residue = residueCalculator(BEIDOU_B2A_WEIL_N_SECONDARY);
        legendre = generateLegendreSequence(BEIDOU_B2A_WEIL_N_SECONDARY, residue);
    }

    void generatePrimaryData(int prn);
    void generatePrimaryPilot(int prn);
    void generateSecondaryPilot(int prn);

private:

    std::string getConstellationName() override { return "BeiDou B2a"; }
    int getNumberOfSats() override { return BEIDOU_B2A_NUMBER_OF_SATS; }    

    std::vector<int> residue;
    std::vector<int> legendre;

    void generatePrimary(int prn, int g2Init, int tapsG1, int tapsG2);

    const std::unordered_map<int, int> g2_data_init = {
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
        { 61, 0x0402 }, { 62, 0x1BF5 }, { 63, 0x03D2 }
    };
    
    const std::unordered_map<int, int> g2_pilot_init = { // PRN 1 - 63
        {1, 0x1025 }, {2, 0x1034 }, {3, 0x10AD }, {4, 0x114F },
        {5, 0x1155 }, {6, 0x11AE }, {7, 0x11EE }, {8, 0x11FB },
        {9, 0x1329 }, {10, 0x13DA }, {11, 0x1435 }, {12, 0x1444 },
        {13, 0x1455 }, {14, 0x145B }, {15, 0x145C }, {16, 0x14A3 },
        {17, 0x14F7 }, {18, 0x1501 }, {19, 0x153E }, {20, 0x15AB },
        {21, 0x15B1 }, {22, 0x1653 }, {23, 0x1662 }, {24, 0x1698 },
        {25, 0x16B6 }, {26, 0x16F2 }, {27, 0x16FF }, {28, 0x1712 },
        {29, 0x173C }, {30, 0x17A1 }, {31, 0x17C8 }, {32, 0x17D4 },
        {33, 0x17EB }, {34, 0x17F3 }, {35, 0x1851 }, {36, 0x1894 },
        {37, 0x18B7 }, {38, 0x1911 }, {39, 0x1919 }, {40, 0x19AB },
        {41, 0x19B1 }, {42, 0x19D2 }, {43, 0x1A55 }, {44, 0x1A74 },
        {45, 0x1ACB }, {46, 0x1B57 }, {47, 0x1C34 }, {48, 0x1C83 },
        {49, 0x1C8B }, {50, 0x1CA3 }, {51, 0x1CA8 }, {52, 0x1D3B },
        {53, 0x1D97 }, {54, 0x1E48 }, {55, 0x1E94 }, {56, 0x1E99 },
        {57, 0x1EDA }, {58, 0x1EF8 }, {59, 0x1EFF }, {60, 0x1FB5 },
        {61, 0x1486 }, {62, 0x05F8 }, {63, 0x0355 }
    
    };

    //!===================================SECONDARY CODE PARAMETERS OF B2a PILOT COMPONENTS=============================================

    //Phase difference(w) table data for Pilot Component          	
    const int phaseDiff[BEIDOU_B2A_NUMBER_OF_SATS] = {
        123,   55,   40,  139,   31,  175,
        350,  450,  478,    8,   73,   97,
        213,  407,  476,    4,   15,   47,
        163,  280,  322,  353,  375,  510,
        332,    7,   13,   16,   18,   25,
        50 ,   81,  118,  127,  132,  134,
        164,  177,  208,  249,  276,  349,
        439,  477,  498,   88,  155,  330,
        3  ,   21,   84,  111,  128,  153,
        197,  199,  214,  256,  265,  291,
        324,  326,  340 };

    //Truncation Point(p) table data for Pilot Component        
    const int truncPoint[BEIDOU_B2A_NUMBER_OF_SATS] = {
        138,   570,  351,   77,  885,  247,
        413,   180,    3,   26,   17,  172,
        30 ,  1008,  646,  158,  170,   99,
        53 ,   179,  925,  114,   10,  584,
        60 ,     3,  684,  263,  545,   22,
        546,   190,  303,  234,   38,  822,
        57 ,   668,  697,   93,   18,   66,
        318,   133,   98,   70,  132,   26,
        354,    58,   41,  182,  944,  205,
        23 ,     1,  792,  641,   83,    7,
        111,    96,   92 };
       
   

};