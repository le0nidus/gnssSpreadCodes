#include <algorithm>
#include <vector>
#include <iterator>

std::vector<int> residueCalculator(int N) {
    std::vector<int> residue;
    for (int i = 0; i < (N + 1) / 2; ++i) {
        int res = i * i % N;
        if (std::find(residue.begin(), residue.end(), res) == residue.end())
            residue.push_back(res);
    }
    return residue;
}

std::vector<int> generateLegendreSequence(int N, std::vector<int> residue) {
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

std::vector<int> generateWeilCode(int N, int w, std::vector<int> legendre) {
    std::vector<int> weil_code;
    for (int i = 0; i < N; ++i)
        weil_code.push_back((legendre[i] + legendre[(i + w) % N]) % 2);
    return weil_code;
}

std::vector<int> weil_code_generator(int N, int N0, int w, int p) {
    std::vector<int> residue;
    std::vector<int> legendre;
    std::vector<int> weil_code;
    residue = residueCalculator(N);
    legendre = generateLegendreSequence(N, residue);
    weil_code = generateWeilCode(N, w, legendre);

    std::vector<int> weil_out;
    if ((N0 + p - 2) < N)
        weil_out = std::vector<int>(weil_code.begin() + p - 1, weil_code.begin() + p - 1 + N0);
    else {
        weil_out = std::vector<int>(weil_code.begin() + p - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (p - 1 + N0) % N, std::back_inserter(weil_out));
    }

    return weil_out;
}