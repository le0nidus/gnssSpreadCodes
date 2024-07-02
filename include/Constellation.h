#ifndef CONSTELLATION_HEADER
#define CONSTELLATION_HEADER

#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>

class Constellation {
public:
    virtual void printOneCode(std::vector<int> spreadCode);
    virtual void printOneCode(std::vector<int> spreadCode, std::string sep);

private:
    virtual int getSpreadCodeSize() { return 1; }
    virtual int getSpreadCodeSize2() { return 2; }
    virtual std::string getConstellationName() { return "Constellation"; }
    virtual int getNumberOfSats() { return 1; }

protected:
    bool oneSizeConstellation = true;
};

#endif


