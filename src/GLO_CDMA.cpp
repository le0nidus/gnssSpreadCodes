#include "../include/GLO_CDMA.h"

/*
   Converts a decimal number to a binary representation with a specified number of bits.

   - The function extracts each bit from the most significant to the least significant position.
   - It shifts the input number `n` right and applies a bitwise AND with 1 to isolate each bit.
   - The resulting bits are stored in a vector in order from MSB to LSB.

   Parameters:
   - `n`: The decimal number to convert.
   - `numOfBits`: The number of bits in the output binary representation.

   Returns:
   - A vector of `numOfBits` integers (0s and 1s) representing the binary equivalent of `n`.
*/
std::vector<int> GLO_CDMA::dec2bin(int n, int numOfBits) {
  std::vector<int> s;
  for (int i = 0; i < numOfBits; i++)
      s.push_back((n >> (numOfBits - 1 - i)) & 1);
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
void GLO_CDMA::lfsr(std::vector<int> &reg, int taps) {
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
 * @brief Generates a Pseudo-Random Noise (PRN) code sequence for CDMA.
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
void GLO_CDMA::generatePRN(int prn, std::vector<int> g1, std::vector<int> g2, int codeLen, int tapsG1, int tapsG2) {
  prn_code.clear();  // Clear any previously stored PRN sequence

  for (int i = 0; i < codeLen; i++) {
      prn_code.push_back(g1.back() ^ g2.back()); // XOR last elements of g1 and g2
      lfsr(g1, tapsG1); // Update g1 using LFSR
      lfsr(g2, tapsG2); // Update g2 using LFSR
  }
}
