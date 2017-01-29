This contains two versions of the same program used in a fault-injection experiment for determining if bits have been flipped in a raspberry pi computer's SRAM.

The allocateOnes version of the code takes the number of bits of memory to be allocated as the only parameter. For experimentation purposes, this was the combined size of the L1 and L2 caches in the Raspberry Pi 3. This version of the code fills the designated amount of memory with ones.

The allocateZeros version of th code works in much the same way as the allocate ones program, however it fills the designated amount of memory with zeros.