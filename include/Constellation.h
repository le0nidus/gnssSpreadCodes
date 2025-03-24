#ifndef CONSTELLATION_HEADER
#define CONSTELLATION_HEADER

#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>

class Constellation {
public:
    virtual void printOneCode();
    virtual void printOneCode(std::string sep);
    void printConstellationHeader();

    std::vector<int> prn_code;

private:
    virtual int getSpreadCodeSize()  = 0;
    virtual int getSpreadCodeSize2()  = 0;
    virtual std::string getConstellationName()  = 0;
    virtual int getNumberOfSats() = 0;

protected:
    bool oneSizeConstellation = true;

    void lfsr(std::vector<int> &reg, int taps);
    std::vector<int> dec2bin(int n, int numOfBits, bool msb_is_last = false);
    void generatePRN(int prn, std::vector<int> g1, std::vector<int> g2, int codeLen, int tapsG1, int tapsG2);
};

#endif


