#include <vector>
#include "GLO_CDMA.h"


class GLO_CDMA_L3 : public GLO_CDMA {
public:
    GLO_CDMA_L3() {}
	void l3ocd(int prn);
	void l3ocp(int prn);

private:
	const std::vector<int> g2_init = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
	
	std::string getConstellationName() override { return "GLONASS CDMA L3"; }

	void l3oc(int prn, int d_or_p);
};




