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
    void printConstellationHeader();

private:
    virtual int getSpreadCodeSize()  = 0;
    virtual int getSpreadCodeSize2()  = 0;
    virtual std::string getConstellationName()  = 0;
    virtual int getNumberOfSats() = 0;

protected:
    bool oneSizeConstellation = true;
};

#endif


