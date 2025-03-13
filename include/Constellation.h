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
};

#endif


