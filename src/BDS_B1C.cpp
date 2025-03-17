#include "../include/BDS_B1C.h"

std::vector<int> BDS_B1C::residueCalculator(int N) {
    // Create a set to efficiently store unique residues
    std::set<int> residues;

    // Generate a sequence from 0 to (N+1)/2 using iota (with +1 increments)
    std::vector<int> squares((N + 1) / 2);
    std::iota(squares.begin(), squares.end(), 0);

    // Calculate squares modulo N and insert into the set of residues
    std::transform(squares.begin(), squares.end(), std::inserter(residues, residues.end()),
        [N](int x) { return (x * x) % N; });

    // Convert the set to a vector for return
    return std::vector<int>(residues.begin(), residues.end());
}

std::vector<int> BDS_B1C::generateLegendreSequence(int N, std::vector<int> residue) {
    std::vector<int> legendre;
    legendre.push_back(0);
    for (int i = 1; i < N; ++i) {
        if (std::find(residue.begin(), residue.end(), i) != residue.end())
            legendre.push_back(1);
        else
            legendre.push_back(0);
    }
    return legendre;
}

std::vector<int> BDS_B1C::generateWeilCode(int N, int w, std::vector<int> legendre) {
    std::vector<int> weil_code(N);
    std::transform(legendre.begin(), legendre.end(), weil_code.begin(),
        [&legendre, N, w, i = 0](int value) mutable { return (value + legendre[(i++ + w) % N]) % 2; });
    return weil_code;
}


void BDS_B1C::generatePrimaryData(int prn) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(BEIDOU_B1C_WEIL_N, dataPrimaryPhaseDiff[prn - 1], legendrePrimary);

    prn_code.clear();
    if ((BEIDOU_B1C_PRIMARY_CODE_LENGTH + dataPrimaryTruncPoint[prn - 1] - 2) < BEIDOU_B1C_WEIL_N)
        prn_code = std::vector<int>(weil_code.begin() + dataPrimaryTruncPoint[prn - 1] - 1, weil_code.begin() + dataPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH);
    else {
        prn_code = std::vector<int>(weil_code.begin() + dataPrimaryTruncPoint[prn - 1] - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (dataPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH) % BEIDOU_B1C_WEIL_N, std::back_inserter(prn_code));
    }
    return;
}

void BDS_B1C::generatePrimaryPilot(int prn) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(BEIDOU_B1C_WEIL_N, pilotPrimaryPhaseDiff[prn - 1], legendrePrimary);

    prn_code.clear();
    if ((BEIDOU_B1C_PRIMARY_CODE_LENGTH + pilotPrimaryTruncPoint[prn - 1] - 2) < BEIDOU_B1C_WEIL_N)
        prn_code = std::vector<int>(weil_code.begin() + pilotPrimaryTruncPoint[prn - 1] - 1, weil_code.begin() + pilotPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH);
    else {
        prn_code = std::vector<int>(weil_code.begin() + pilotPrimaryTruncPoint[prn - 1] - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (pilotPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH) % BEIDOU_B1C_WEIL_N, std::back_inserter(prn_code));
    }
    return;
}

void BDS_B1C::generateSecondaryPilot(int prn) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(BEIDOU_B1C_WEIL_N_SECONDARY, pilotSecondaryPhaseDiff[prn - 1], legendreSecondary);

    prn_code.clear();
    if ((BEIDOU_B1C_SECONDARY_CODE_LENGTH + pilotSecondaryTruncPoint[prn - 1] - 2) < BEIDOU_B1C_WEIL_N_SECONDARY)
        prn_code = std::vector<int>(weil_code.begin() + pilotSecondaryTruncPoint[prn - 1] - 1, weil_code.begin() + pilotSecondaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_SECONDARY_CODE_LENGTH);
    else {
        prn_code = std::vector<int>(weil_code.begin() + pilotSecondaryTruncPoint[prn - 1] - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (pilotSecondaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_SECONDARY_CODE_LENGTH) % BEIDOU_B1C_WEIL_N_SECONDARY, std::back_inserter(prn_code));
    }
    return;
}
