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
std::vector<int> dec2bin(int n, int numOfBits) {
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
void lfsr(std::vector<int> &reg, int taps) {
	int xor_result = 0;
	for (int i = 0 ; i < reg.size(); i++) {
		xor_result ^= reg[i] * (taps & 1);
		taps = taps >> 1;
	}
	
  // Rotate right and place XOR result at the beginning
  std::rotate(reg.rbegin(), reg.rbegin() + 1, reg.rend());
  reg.front() = xor_result;
}
