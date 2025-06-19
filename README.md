I wandered online and came to a conclusion that there is no repo that contains all of the PRN's.
I'll try to implement here as much as I can in my free time :)

Implemented:
- 🛰️ BeiDou:   B1C (B1CPp,B1CPs,B1CDp), B2a (DataPrimary, PilotPrimary, PilotSecondary), B2B_I (&B2B_I_PPP)
- 🛰️ Galileo:  E1B, E1C, E5 (E5aI, E5aQ, E5bI, E5bQ), E6B, E6C
- 🛰️ GPS:      CA, L1C (L1CD, L1CP, L1CO), L5 (L5I,L5Q)
- 🛰️ Glonass:  CDMA (L1OCp, L1OCd, L2OCp, L3OCp, L3OCd)
- 🛰️ Navic:    L1 (Data, Pilot, Overlay), S, L5
- 🛰️ LunaNet AFS-I, AFS-Q Primary, AFS-Q Trietary

TODO:
- Work on making main.cpp simpler, by adding a function in Constellation that prints all sats.
- Printing to file
- Add more codes! 🤓
