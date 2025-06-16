#include "Constellation.h"

constexpr int NAVIC_L5S_PRIMARY_CODE_LENGTH = 1023;  // Each code of L5/S has the length 1023 chips.
constexpr int NAVIC_L5S_NUM_REGISTERS_IN_LFSR = 10;

constexpr int NAVIC_L5S_TAPS_G1 = 516;
constexpr int NAVIC_L5S_TAPS_G2 = 934;

constexpr int NAVIC_L5S_NUMBER_OF_SATS = 14;		      //Total number of satellites

class NAVIC_L5S : public Constellation{
public:
    NAVIC_L5S() {}
    virtual void generate(int prn) = 0;

private:
    std::string getConstellationName() override { return "NAVIC L5S"; }
    int getNumberOfSats() override { return NAVIC_L5S_NUMBER_OF_SATS; }

protected:
    void generatePrimary(int initG2);
};

class NAVIC_L5 : public NAVIC_L5S{
    public:
        NAVIC_L5() {}
        void generate(int prn) override;
    
    private:
        std::string getConstellationName() override { return "NAVIC L5"; }        
        const int L5_G2_Init[NAVIC_L5S_NUMBER_OF_SATS] = {
            0b1110100111, 0b0000100110, 0b1000110100, 0b0101110010, 0b1110110000,
            0b0001101011, 0b0000010100, 0b0100110000, 0b0010011000, 0b1101100100,
            0b0001001100, 0b1101111100, 0b1011010010, 0b0111101010
        };
};

class NAVIC_S : public NAVIC_L5S{
    public:
        NAVIC_S() {}
        void generate(int prn) override;
    
    private:
        std::string getConstellationName() override { return "NAVIC S"; }        
        const int S_G2_Init[NAVIC_L5S_NUMBER_OF_SATS] = {
            0b0011101111, 0b0101111101, 0b1000110001, 0b0010101011, 0b1010010001,
            0b0100101100, 0b0010001110, 0b0100100110, 0b1100001110, 0b1010111110,
            0b1110010001, 0b1101101001, 0b0101000101, 0b0100001101
        };
};