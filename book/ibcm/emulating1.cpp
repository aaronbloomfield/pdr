unsigned int opcode = (x >> 12) & 0x000f
unsigned int ioshiftop = (x >> 10) & 0x0003
unsigned int address = x & 0x0fff
unsigned int shiftcount = x & 0x000f
