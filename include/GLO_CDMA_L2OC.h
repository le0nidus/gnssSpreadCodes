#include <vector>
#include "GLO_CDMA.h"


class GLO_CDMA_L2 : public GLO_CDMA {
public:
	GLO_CDMA_L2() {}
	void l2ocp(int prn);

private:
	const std::vector<int> g2_init = {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};

	std::string getConstellationName() override { return "GLONASS CDMA L2"; }
};




