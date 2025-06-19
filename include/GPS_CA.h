#include <vector>
#include "Constellation.h"

constexpr int GPS_CA_CODE_LENGTH = 1023;

constexpr int GPS_CA_LFSR_REGISTER_SIZE = 10;
constexpr int GPS_CA_TAPS_G1 = 516;
constexpr int GPS_CA_TAPS_G2 = 934;

constexpr int GPS_CA_NUMBER_OF_SATS = 63;		      //Total number of satellites
constexpr int GPS_CA_NUMBER_OF_CODES = 210;		      //Total number of codes available in the ICD

class GPS_CA : public Constellation {
public:
	GPS_CA() {}
	void generate(int prn);

private:	
	std::string getConstellationName() override { return "GPS CA"; }
	int getNumberOfSats() override { return GPS_CA_NUMBER_OF_CODES; }
	
	const int L1CA_G2_delay[GPS_CA_NUMBER_OF_CODES] = { // PRN 1 - 210
		5,   6,   7,   8,  17,  18, 139, 140, 141, 251, 252, 254, 255, 256, 257,
	  258, 469, 470, 471, 472, 473, 474, 509, 512, 513, 514, 515, 516, 859, 860,
	  861, 862, 863, 950, 947, 948, 950,  67, 103,  91,  19, 679, 225, 625, 946,
	  638, 161,1001, 554, 280, 710, 709, 775, 864, 558, 220, 397,  55, 898, 759,
	  367, 299,1018, 729, 695, 780, 801, 788, 732,  34, 320, 327, 389, 407, 525,
	  405, 221, 761, 260, 326, 955, 653, 699, 422, 188, 438, 959, 539, 879, 677,
	  586, 153, 792, 814, 446, 264,1015, 278, 536, 819, 156, 957, 159, 712, 885,
	  461, 248, 713, 126, 807, 279, 122, 197, 693, 632, 771, 467, 647, 203, 145,
	  175,  52,  21, 237, 235, 886, 657, 634, 762, 355,1012, 176, 603, 130, 359,
	  595,  68, 386, 797, 456, 499, 883, 307, 127, 211, 121, 118, 163, 628, 853,
	  484, 289, 811, 202,1021, 463, 568, 904, 670, 230, 911, 684, 309, 644, 932,
	   12, 314, 891, 212, 185, 675, 503, 150, 395, 345, 846, 798, 992, 357, 995,
	  877, 112, 144, 476, 193, 109, 445, 291,  87, 399, 292, 901, 339, 208, 711,
	  189, 263, 537, 663, 942, 173, 900,  30, 500, 935, 556, 373,  85, 652, 310
 };

};




