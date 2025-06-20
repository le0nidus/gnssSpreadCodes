#include <fstream>
#include <iostream>
#include "include/BDS_B1C.h"
#include "include/BDS_B2a.h"
#include "include/BDS_B2b.h"
#include "include/GAL_E1.h"
#include "include/GAL_E5b.h"
#include "include/GAL_E5a.h"
#include "include/GAL_E6.h"
#include "include/GPS_CA.h"
#include "include/GPS_L1C.h"
#include "include/GPS_L5.h"
#include "include/GLO_CDMA_L1OC.h"
#include "include/GLO_CDMA_L2OC.h"
#include "include/GLO_CDMA_L3OC.h"
#include "include/NAVIC_L1.h"
#include "include/NAVIC_L5S.h"
#include "include/LUNANET.h"


int main() {
	int prn;
	BDS_B1C B1C_spreadCode;
	BDS_B2a B2a_spreadCode;
	BDS_B2b B2b_spreadCode;
	GAL_E1 GalE1;
	GAL_E5b GalE5b;
	GAL_E5a GalE5a;
	GAL_E6 GalE6;
	GPS_CA gps_ca;
	GPS_L1C gpsl1c;
	GPS_L5 gpsl5;
	GLO_CDMA_L3 glo_l3oc;
	GLO_CDMA_L2 glo_l2oc;
	GLO_CDMA_L1 glo_l1oc;
	NAVIC_L1 navic_l1;
	NAVIC_S navic_s;
	NAVIC_L5 navic_l5;
	LunaNet lunaNet;
	int n = 13;

	std::cout << "\nGAL E1B\n";
	GalE1.generateE1B(n);
	GalE1.printOneCode();

	std::cout << "\nGAL E1C\n";
	GalE1.generateE1C(n);
	GalE1.printOneCode();

	std::cout << "\nGAL E6B\n";
	GalE6.generateE6B(n);
	GalE6.printOneCode();

	std::cout << "\nGAL E6C Primary\n";
	GalE6.generatePrimaryE6C(n);
	GalE6.printOneCode();

	std::cout << "\nGAL E6C Secondary\n";
	GalE6.generateSecondaryE6C(n);
	GalE6.printOneCode();

	std::cout << "\nGPS CA\n";
	gps_ca.generate(n);
	gps_ca.printOneCode();

	std::cout << "\nGPS CA\n";
	gps_ca.generate(n);
	gps_ca.printOneCode();

	std::cout << "\nNavic S\n";
	navic_s.generate(n);
	navic_s.printOneCode();

	std::cout << "\nNavic L5\n";
	navic_l5.generate(n);
	navic_l5.printOneCode();

	std::cout << "\nNavic L1 Primary Data\n";
	navic_l1.generateDataPrimary(n);
	navic_l1.printOneCode();

	std::cout << "\nNavic L1 Primary Pilot\n";
	navic_l1.generatePilotPrimary(n);
	navic_l1.printOneCode();

	std::cout << "\nNavic L1 Overlay Pilot\n";
	navic_l1.generatePilotOverlay(n);
	navic_l1.printOneCode();

	std::cout << "\nLunaNet AFS-Q Trietary\n";
	lunaNet.afs_q_trietary(n); //AFS-Q Trietary
	lunaNet.printOneCode();

	std::cout << "\nLunaNet AFS-I\n";
	lunaNet.afs_i(n); //AFS-I
	lunaNet.printOneCode();

	std::cout << "\nLunaNet AFS-Q Primary\n";
	lunaNet.afs_q_primary(n); //AFS-Q Primary
	lunaNet.printOneCode();

	std::cout << "\nL1OCd\n";
	glo_l1oc.l1ocd(n); //L1OCd
	glo_l1oc.printOneCode();

	std::cout << "\n\n\nL1OCp\n";
	glo_l1oc.l1ocp(n); //L1OCp
	glo_l1oc.printOneCode();

	std::cout << "\n\n\nL2OCp\n";
	glo_l2oc.l2ocp(n); //L2OCp
	glo_l2oc.printOneCode();	

	std::cout << "\nL3OCd\n";
	glo_l3oc.l3ocd(n); //L3OCd
	glo_l3oc.printOneCode();

	std::cout << "\n\n\nL3OCp\n";
	glo_l3oc.l3ocp(n); //L3OCp
	glo_l3oc.printOneCode();	
	
	B1C_spreadCode.printConstellationHeader();
	std::cout << "Secondary Pilot Code\n";
	std::cout << "PRN: " << n << std::endl;
	B1C_spreadCode.generateSecondaryPilot(n);
	B1C_spreadCode.printOneCode();
	std::cout << std::endl;
	
	std::cout << "Primary Pilot Code\n";
	std::cout << "PRN: " << n << std::endl;
	B1C_spreadCode.generatePrimaryPilot(n);
	B1C_spreadCode.printOneCode();
	std::cout << std::endl;
	
	std::cout << "Primary Data Code\n";
	std::cout << "PRN: " << prn << std::endl;
	B1C_spreadCode.generatePrimaryData(n);
	B1C_spreadCode.printOneCode();
	std::cout << std::endl;
    
	std::cout << "GPS L5Q Code\n";
	gpsl5.generateL5Q(prn);
	gpsl5.printOneCode("");

	std::cout << "GPS L5I Code\n";
	gpsl5.generateL5I(n);
	gpsl5.printOneCode();

	std::cout << "\nBeidou B2a Primary Data\n";
	B2a_spreadCode.generatePrimaryData(n); //AFS-Q Trietary
	B2a_spreadCode.printOneCode();

	std::cout << "\nBeidou B2a Primary Pilot\n";
	B2a_spreadCode.generatePrimaryPilot(n); //AFS-I
	B2a_spreadCode.printOneCode();

	std::cout << "\nBeidou B2a Secondary Pilot\n";
	B2a_spreadCode.generateSecondaryPilot(n); //AFS-Q Primary
	B2a_spreadCode.printOneCode();


	std::cout << "\nGalileo E5b_I Primary Code\n";
	GalE5b.generatePrimaryE5bI(n);
	GalE5b.printOneCode();

	std::cout << "\nGalileo E5b_Q Primary Code\n";
	GalE5b.generatePrimaryE5bQ(n);
	GalE5b.printOneCode();

	std::cout << "\nGalileo E5b_Q Secondary Code\n";
	GalE5b.generateSecondaryE5bQ(n);
	GalE5b.printOneCode();

	std::cout << "\nGalileo E5a_I Primary Code\n";
	GalE5a.generatePrimaryE5aI(n);
	GalE5a.printOneCode();

	std::cout << "\nGalileo E5a_Q Primary Code\n";
	GalE5a.generatePrimaryE5aQ(n);
	GalE5a.printOneCode();

	std::cout << "\nGalileo E5a_Q Secondary Code\n";
	GalE5a.generateSecondaryE5aQ(n);
	GalE5a.printOneCode();

	std::cout << "\nGPS L1C Pilot Code\n";
	gpsl1c.generateL1CP(n);
	gpsl1c.printOneCode();

	std::cout << "\nGPS L1C Data Code\n";
	gpsl1c.generateL1CD(n);
	gpsl1c.printOneCode();

	std::cout << "\nGPS L1C Overlay Code\n";
	gpsl1c.generateL1CO(30);
	gpsl1c.printOneCode();

	std::cout << "\nBeidou B2b Code\n";
	B2b_spreadCode.generateCode(30);
	B2b_spreadCode.printOneCode();

    return 0;
}



