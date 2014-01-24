union ibcm_instruction {
#ifdef BIG_ENDIAN // the IBCM is big endian
    struct { unsigned char high, low; } bytes;
#else
#ifdef LITTLE_ENDIAN
    struct { unsigned char low, high; } bytes;
#else
#error Must define BIG_ENDIAN or LITTLE_ENDIAN
#endif // LITTLE_ENDIAN
#endif // BIG_ENDIAN
    struct { unsigned int op:4, unused:12; } halt;
    struct { unsigned int op:4, ioopt:2, unused:10 } io;
    struct { unsigned int op:4, shiftop: 2, 
        unused:5, shiftcout:5; } shifts;
    struct { unsigned int op:4, address:12; } others;
};
