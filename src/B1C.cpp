#include <B1C.h>

std::vector<int> B1C::residueCalculator(int N) {
    std::vector<int> residue;
    for (int i = 0; i < (N + 1) / 2; ++i) {
        int res = i * i % N;
        if (std::find(residue.begin(), residue.end(), res) == residue.end())
            residue.push_back(res);
    }
    return residue;
}

std::vector<int> B1C::generateLegendreSequence(int N, std::vector<int> residue) {
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

std::vector<int> B1C::generateWeilCode(int N, int w, std::vector<int> legendre) {
    std::vector<int> weil_code;
    for (int i = 0; i < N; ++i)
        weil_code.push_back((legendre[i] + legendre[(i + w) % N]) % 2);
    return weil_code;
}


std::vector<int> B1C::generatePrimaryData(int prn) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(BEIDOU_B1C_WEIL_N, dataPrimaryPhaseDiff[prn - 1], legendrePrimary);

    std::vector<int> weil_out;
    if ((BEIDOU_B1C_PRIMARY_CODE_LENGTH + dataPrimaryTruncPoint[prn - 1] - 2) < BEIDOU_B1C_WEIL_N)
        weil_out = std::vector<int>(weil_code.begin() + dataPrimaryTruncPoint[prn - 1] - 1, weil_code.begin() + dataPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH);
    else {
        weil_out = std::vector<int>(weil_code.begin() + dataPrimaryTruncPoint[prn - 1] - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (dataPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH) % BEIDOU_B1C_WEIL_N, std::back_inserter(weil_out));
    }
    return weil_out;
}

std::vector<int> B1C::generatePrimaryPilot(int prn) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(BEIDOU_B1C_WEIL_N, pilotPrimaryPhaseDiff[prn - 1], legendrePrimary);

    std::vector<int> weil_out;
    if ((BEIDOU_B1C_PRIMARY_CODE_LENGTH + pilotPrimaryTruncPoint[prn - 1] - 2) < BEIDOU_B1C_WEIL_N)
        weil_out = std::vector<int>(weil_code.begin() + pilotPrimaryTruncPoint[prn - 1] - 1, weil_code.begin() + pilotPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH);
    else {
        weil_out = std::vector<int>(weil_code.begin() + pilotPrimaryTruncPoint[prn - 1] - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (pilotPrimaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_PRIMARY_CODE_LENGTH) % BEIDOU_B1C_WEIL_N, std::back_inserter(weil_out));
    }
    return weil_out;
}

std::vector<int> B1C::generateSecondaryPilot(int prn) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(BEIDOU_B1C_WEIL_N_SECONDARY, pilotSecondaryPhaseDiff[prn - 1], legendreSecondary);

    std::vector<int> weil_out;
    if ((BEIDOU_B1C_SECONDARY_CODE_LENGTH + pilotSecondaryTruncPoint[prn - 1] - 2) < BEIDOU_B1C_WEIL_N_SECONDARY)
        weil_out = std::vector<int>(weil_code.begin() + pilotSecondaryTruncPoint[prn - 1] - 1, weil_code.begin() + pilotSecondaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_SECONDARY_CODE_LENGTH);
    else {
        weil_out = std::vector<int>(weil_code.begin() + pilotSecondaryTruncPoint[prn - 1] - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (pilotSecondaryTruncPoint[prn - 1] - 1 + BEIDOU_B1C_SECONDARY_CODE_LENGTH) % BEIDOU_B1C_WEIL_N_SECONDARY, std::back_inserter(weil_out));
    }
    return weil_out;
}
