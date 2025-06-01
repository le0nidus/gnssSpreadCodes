#ifndef CONSTELLATION_HEADER
#define CONSTELLATION_HEADER

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
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
    virtual std::string getConstellationName()  = 0;
    virtual int getNumberOfSats() = 0;

protected:
    bool checkValidPRN(int prn);
    
    void lfsr(std::vector<int> &reg, int taps);
    std::vector<int> dec2bin(int n, int numOfBits, bool msb_is_last = false);
    void generatePRN(std::vector<int> g1, std::vector<int> g2, int codeLen, int tapsG1, int tapsG2, int resetPosition = 0);

    std::vector<int> residueCalculator(int N);
    std::vector<int> generateLegendreSequence(int N, std::vector<int> residue);
    std::vector<int> generateWeilCode(int N, int w, std::vector<int> legendre);
    void generateTruncatedWeil(int prn, int weilN, int codeLength, int phaseDiff, int truncPoint, std::vector<int> legendreSequence);
    
};

#endif


