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
    virtual std::string getConstellationName() { return "Constellation"; }
};

#endif


