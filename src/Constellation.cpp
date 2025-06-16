#include "../include/Constellation.h"

void Constellation::printConstellationHeader() {
	std::cout << "/=========== " << getConstellationName() << " Code ===========/\n";
}

void Constellation::printOneCode() {
    for (int j = 0; j < prn_code.size(); j++)
        std::cout << prn_code[j];
    std::cout << std::endl;
    return;
}

void Constellation::printOneCode(std::string sep) {
    for (int j = 0; j < prn_code.size(); j++)
        std::cout << prn_code[j] << sep;
    std::cout << std::endl;
    return;
}


/*
   Converts a decimal number to a binary representation with a specified number of bits.

   - The function extracts each bit from the most significant to the least significant position.
   - It shifts the input number `n` right and applies a bitwise AND with 1 to isolate each bit.
   - The resulting bits are stored in a vector in order from MSB to LSB.

   Parameters:
   - `n`: The decimal number to convert.
   - `numOfBits`: The number of bits in the output binary representation.
   - 'msb_is_last': If it's true, the first idx of the vector will be the LSB, last will be the MSB

   Returns:
   - A vector of `numOfBits` integers (0s and 1s) representing the binary equivalent of `n`.
*/
std::vector<int> Constellation::dec2bin(ULL n, int numOfBits, bool msb_is_last) {
	std::vector<int> s;
	if (msb_is_last) {
		for (int i = 0; i < numOfBits; i++)
			s.insert(s.begin(), (n >> (numOfBits - 1 - i)) & 1);
	}
	else {
		for (int i = 0; i < numOfBits; i++)
			s.push_back((n >> (numOfBits - 1 - i)) & 1);
	}
	
	return s;
}
  
  
/*
This function implements a Linear Feedback Shift Register (LFSR), 
commonly used for generating pseudo-random noise (PRN) codes.

- The LFSR consists of a series of `regSize` registers forming a shift register.
- The feedback mechanism uses XOR operations on specific register positions, 
determined by the `taps` input.
- Each bit in `taps` indicates whether the corresponding register value should 
be included in the XOR operation.
- The computed XOR result is inserted at the front of the register, 
while the last element is removed, simulating a shift.

Parameters:
- `reg`: A reference to a vector representing the shift register.
- `taps`: A bitmask indicating which registers contribute to the feedback XOR.

The function updates the shift register in place.
*/
void Constellation::lfsr(std::vector<int> &reg, int taps) {
	int xor_result = 0;
	for (int i = 0 ; i < reg.size(); i++) {
		xor_result ^= reg[i] * (taps & 1);
		taps = taps >> 1;
	}
	
	// Rotate right and place XOR result at the beginning
	std::rotate(reg.rbegin(), reg.rbegin() + 1, reg.rend());
	reg.front() = xor_result;
}


/**
 * @brief Generates a Pseudo-Random Noise (PRN) code sequence using LFSR.
 * 
 * This function generates a PRN sequence by performing a Linear Feedback Shift Register (LFSR) 
 * operation on two generator sequences (`g1` and `g2`). The PRN code is formed by XORing 
 * the last elements of `g1` and `g2` at each iteration.
 * 
 * @param prn      PRN identifier (not used in this function but likely relevant in the class).
 * @param g1       First generator sequence (vector representing an LFSR state).
 * @param g2       Second generator sequence (vector representing an LFSR state).
 * @param codeLen  Length of the PRN sequence to generate.
 * @param tapsG1   Taps configuration for `g1` (determines which registers participate in the LFSR feedback).
 * @param tapsG2   Taps configuration for `g2`.
 * 
 * @details 
 * - The function clears `prn_code` before generating a new sequence.
 * - It iterates `codeLen` times, computing each "new" PRN bit as `g1.back() ^ g2.back()`.
 * - The `lfsr` function is called to shift both `g1` and `g2` forward using their respective tap configurations.
 */
void Constellation::generatePRN(std::vector<int> g1, std::vector<int> g2, int codeLen, int tapsG1, int tapsG2, int resetPosition) {
    prn_code.clear();  // Clear any previously stored PRN sequence
    
    if (resetPosition == 0) {
        for (int i = 0; i < codeLen; i++) {
            prn_code.push_back(g1.back() ^ g2.back()); // XOR last elements of g1 and g2
            lfsr(g1, tapsG1); // Update g1 using LFSR
            lfsr(g2, tapsG2); // Update g2 using LFSR
        }
    }
    else {
        std::vector<int> initializationVec = g1;
        for (int i = 0; i < codeLen; i++) {
            prn_code.push_back(g1.back() ^ g2.back()); // XOR last elements of g1 and g2
            lfsr(g1, tapsG1); // Update g1 using LFSR
            lfsr(g2, tapsG2); // Update g2 using LFSR
            if (i == resetPosition)
                g1 = initializationVec;
        }
    }
    
}



/* Functions to use for PRN's that are generated with truncating weil codes */

std::vector<int> Constellation::residueCalculator(int N) {
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

std::vector<int> Constellation::generateLegendreSequence(int N, std::vector<int> residue) {
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

std::vector<int> Constellation::generateWeilCode(int N, int w, std::vector<int> legendre) {
    std::vector<int> weil_code(N);
    std::transform(legendre.begin(), legendre.end(), weil_code.begin(),
        [&legendre, N, w, i = 0](int value) mutable { return (value + legendre[(i++ + w) % N]) % 2; });
    return weil_code;
}

void Constellation::generateTruncatedWeil(int prn, int weilN, int codeLength, int phaseDiff, int truncPoint, std::vector<int> legendreSequence) {
    std::vector<int> weil_code;
    weil_code = generateWeilCode(weilN, phaseDiff, legendreSequence);

    prn_code.clear();
    if ((codeLength + truncPoint - 2) < weilN)
        prn_code = std::vector<int>(weil_code.begin() + truncPoint - 1, weil_code.begin() + truncPoint - 1 + codeLength);
    else {
        prn_code = std::vector<int>(weil_code.begin() + truncPoint - 1, weil_code.end());
        std::copy(weil_code.begin(), weil_code.begin() + (truncPoint - 1 + codeLength) % weilN, std::back_inserter(prn_code));
    }
    return;
}

bool Constellation::checkValidPRN(int prn) {
    int numOfSats = getNumberOfSats();
    if (prn <= 0 || prn > numOfSats) {
        std::cout << "PRN " << prn << " not is out of bounds!\n";
        prn_code.clear();
        return false;
    }
    return true;
}