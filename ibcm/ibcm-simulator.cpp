/* A program that will simulate an IBCM program, and it has a number
 * of command line switches that control its execution.  This program
 * is useful for automating the execution of a number of IBCM programs
 * without having to load each one into the web interface.  It will
 * also print out traces of the entire program execution, if desired.
 * Run with the `-help` flag to see the full list of options.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

using namespace std;

int compState = 0;
int simState = 0;
int printState = 0;
int printStats = 0;
int dumpState = 0;
int verbose = 0;
unsigned int numinst = 0;
int printTicks = 0;
unsigned int maxticks = 0;
string outputFile = "ibcm.bin";
string inputFile;
uint16_t mem[4096];

void printHelp(char *name);
void checkEndian(void);
void compileCode (string infilename, string outfilename);
void simulateIBCM ();
void readBinaryIBCMFile (string infilename);
void dumpIBCMFile ();
char* decodeIBCMInstruction(uint16_t inst);

int main(int argc, char *argv[]) {
    int i = 1;
    checkEndian();
    assert (sizeof(short) == 2);
    ios::sync_with_stdio(); // Synchronize C++ and C I/O subsystems!
    while (i < argc) {
        if (strcmp(argv[i], "-comp")==0) {
            compState=1;
            inputFile=argv[i+1]; // TODO: check that this doesn't go past the array bounds
        } else if (strcmp(argv[i], "-sim")==0) {
            simState=1;
            inputFile=argv[i+1]; // TODO: check that this doesn't go past the array bounds
        } else if (strcmp(argv[i], "-dump")==0) {
            dumpState=1;
            inputFile=argv[i+1]; // TODO: check that this doesn't go past the array bounds
        } else if (strcmp(argv[i], "-o")==0) {
            outputFile=argv[i+1]; // TODO: check that this doesn't go past the array bounds
            i++;
        } else if (strcmp(argv[i], "-verbose")==0) {
            verbose++;
        } else if (strcmp(argv[i], "-help")==0) {
            printHelp(argv[0]);
        } else if (strcmp(argv[i], "-print")==0) {
            printState = 1;
        } else if (strcmp(argv[i], "-stats")==0) {
            printStats = 1;
        } else if (strcmp(argv[i], "-maxticks")==0) {
            maxticks = atoi(argv[++i]); // TODO: check the format of the int
        }
        i++;
    }
    //Check for proper combination of params
    if (simState==0 && compState==0 && inputFile=="") {
        //cerr << "No option specified..." << endl;
        printHelp(argv[0]);
        return 1;
    }
    if ( compState )
        compileCode (inputFile, outputFile);
    if ( simState ) {
        readBinaryIBCMFile (inputFile);
        if ( printState ) {
            dumpIBCMFile ();
            cout << endl << endl;
        }
        simulateIBCM();
        if ( printStats )
            cout << "Total of " << numinst << " instructions executed." << endl;
        if ( printState ) {
            cout << endl << endl;
            dumpIBCMFile ();
        }
    }
    if ( dumpState ) {
        readBinaryIBCMFile (inputFile);
        dumpIBCMFile ();
    }
    return 0;
}

void printHelp(char *name) {
    static bool helpPrinted; // Static values are initialized to 0 or 0-equivalent
    if(helpPrinted) return;

    helpPrinted = true;

    cout << "Usage: " << name << " [option] ..." << endl;
    cout << "Options:" << endl;
    cout << "\t[-comp <inputfile>]\tSignals the program to compile the IBCM file speicfied by <inputfile>" << endl;
    cout << "\t[-sim <inputfile>]\tSignals the program to simulate the IBCM program specified by <inputfile>" << endl;
    cout << "\t[-o <outfile>]\t\tSpecify the name of the outfile produced by compiling <inputfile>" << endl
         << "\t\t\t\tThe defaut value for <outfile> is \"ibcm.bin.\"" << endl;
    cout << "\t[-verbose]\t\tPrints useful debugging information while compiling and emulating" << endl
         << "\t\t\t\the specified IBCM program.";
    cout << " Specify twice for more output." << endl;
    cout << "\t[-dump <inputfile>]\tOutputs a binary IBCM file in text format.";
    cout << " Also specify -verbose for decompilation." << endl;
    cout << "\t[-print]\t\tPrints a listing of the program before and after the simulation." << endl;
    cout << "\t[-maxticks <n>]\t\tSet the maximum number of ticks." << endl;
    cout << "\t[-stats]\t\tPrints stats of the executed program, including the number of ticks." << endl;
    cout << "\t[-help]\t\t\tPrints this help message." << endl;
}

void checkEndian(void) {
    static int firsttime = 1;
    if (firsttime) {
        union {
            char charword[4];
            unsigned int intword;
        } check;
        check.charword[0] = 1;
        check.charword[1] = 2;
        check.charword[2] = 3;
        check.charword[3] = 4;
#ifdef IS_BIG_ENDIAN
        if (check.intword != 0x01020304) {  /* big */
            cerr << "ERROR: Host machine is not Big Endian.\nExiting." << endl;
            exit(205);
        }
#else
#ifdef IS_LITTLE_ENDIAN
        if (check.intword != 0x04030201) {  /* little */
            cerr << "ERROR: Host machine is not Little Endian.\nExiting." << endl;
            exit(206);
        }
#else
#error ERROR: must define either IS_LITTLE_ENDIAN or IS_BIG_ENDIAN
#endif // IS_LITTLE_ENDIAN
#endif // IS_BIG_ENDIAN
        firsttime = 0;
    }
}

bool ishexdigit (int c) {
    if ( isdigit(c) )
        return true;
    if ( (c >= 'a') && (c <= 'f') )
        return true;
    if ( (c >= 'A') && (c <= 'F') )
        return true;
    return false;
}

void dumpIBCMFile () {
    // find last command to not print
    int end;
    for ( end = 4095; end >= 0; end-- ) {
        if ( mem[end] != 0 )
            break;
    }
    for ( int i = 0; i <= end; i++ ) {
        printf ("%.4x\tpc = %.4x\t%s\n", mem[i], i,
                decodeIBCMInstruction(mem[i]));
    }
}


void compileCode (string infilename, string outfilename) {
    string line;
    int linenum = -1, outputlines = 0;
    // open input file
    ifstream infile(infilename.c_str());
    if ( !infile.is_open() ) {
        cerr << "Error: unable to open input file." << endl;
        exit(200);
    }
    // open output file
    ofstream outfile(outfilename.c_str());
    if ( !outfile.is_open() ) {
        cerr << "Error: unable to open output file." << endl;
        exit(201);
    }
    // read input file, write to output file
    while (!infile.eof()) {
        linenum++;
        getline (infile,line);
        // skip blank lines
        if ( line.size() == 0 )
            continue;
        if ( (line[0] == '/') && (line[1] == '/') )
            continue;
        // sanity check
        if ( !ishexdigit(line[0]) || !ishexdigit(line[1]) ||
                !ishexdigit(line[2]) || !ishexdigit(line[3]) ) {
            cerr << "Error on line " << linenum << ": invalid hex digits" << endl;
        }
        line[4] = 0;
        int hex;
        sscanf (line.c_str(), "%x", &hex);
#ifdef IS_LITTLE_ENDIAN
        char g = hex % 256;
        outfile.write(&g,1);
        g = hex / 256;
        outfile.write(&g,1);
#else
#error Not yet working for non-little-endian machines
#endif
        //cout << line[0] << line[1] << line[2] << line[3] << endl;
        outputlines++;
    }
    infile.close();
    // fill remaining space with 0's
    for (; outputlines < 4096; outputlines++ ) {
        char x = 0;
        //cout << "0000" << endl;
        outfile.write (&x,1);
        outfile.write (&x,1);
    }
    outfile.close();
}

void readBinaryIBCMFile (string infilename) {
    int cmdnum = 0;
    // open input file
    ifstream infile(infilename.c_str());
    if ( !infile.is_open() ) {
        cerr << "Error: unable to open input file." << endl;
        exit(202);
    }
    // load up file into array
    for ( int i = 0; i < 4096; i++ )
        mem[i] = 0;
    char buf[2];
    while (!infile.eof()) {
        infile.read(buf,2);
#ifdef IS_LITTLE_ENDIAN
        mem[cmdnum] = (buf[1] & 0x000000ff) * 256 + (buf[0] & 0x000000ff);
#else
#error Not yet working for non-little-endian machines
#endif
        cmdnum++;
    }
    //for ( int i = 0; i < 4096; i++ ) printf ("%.4x\n", mem[i] & 0x0000ffff);
}



union ibcm_instruction {
    uint16_t buf;
#ifdef IS_BIG_ENDIAN //The IBCM is big endian
    struct {
        unsigned char high, low;
    } bytes;
    struct {
        unsigned int op:4, unused:12;
    } halt;
    struct {
        unsigned int op:4, ioopt:2, unused:10;
    } io;
    struct {
        unsigned int op:4, shiftop:2, unused:5, shiftcount:5;
    } shifts;
    struct {
        unsigned int op:4, address:12;
    } others;
#else
#ifdef IS_LITTLE_ENDIAN //The IBCM is little endian
    struct {
        unsigned char low, high;
    } bytes;
    struct {
        unsigned int unused:12, op:4;
    } halt;
    struct {
        unsigned int unused:10, ioopt:2, op:4;
    } io;
    struct {
        unsigned int shiftcount:5, unused:5, shiftop:2, op:4;
    } shifts;
    struct {
        unsigned int address:12, op:4;
    } others;
#else
#error Must define BIG_ENDIAN or LITTLE_ENDIAN
#endif // LITTLE_ENDIAN
#endif // BIG_ENDIAN
} ir, ir2;


char* decodeIBCMInstruction(uint16_t inst) {
    static string instnames[] = {"halt", "I/O", "shifts", "load", "store", "add", "sub", "and",
                                 "or", "xor", "not", "nop", "jmp", "jmpe", "jmpl", "brl"
                                };
    static char buf[256], buf2[8];
    ir2.buf = inst;
    int op = ir2.others.op;
    buf[0] = 0;
    if ( (op <= 2) || (op == 10) || (op == 11) ) // halt, not, nop, I/O, and shift
        strcpy (buf, instnames[op].c_str());
    else if ( op >= 3 ) {
        strcpy (buf, instnames[ir2.others.op].c_str());
        strcat (buf, "\t");
        sprintf (buf2, "%.3x", ir2.others.address);
        strcat (buf, buf2);
    }
    return buf;
}


void simulateIBCM() {
    int acc = 0, pc = 0, incpc;
    string buf;
    while (1) {
        acc &= 0x0000ffff;
        incpc = 1;
        ir.buf = mem[pc];
        if ( verbose >= 2 )
            printf ("\npc = %.3x: ir = %.4x, ibcm = '%s'\n", pc, ir.buf, decodeIBCMInstruction(ir.buf));
        numinst++;
        switch (ir.others.op) {
            case 0: // halt
                if ( verbose >= 1 ) printf ("pc = %.3x: halt\n", pc);
                return;
                break;
            case 1: // I/O
                switch ( ir.io.ioopt ) {
                    case 0: // read hex
                        if ( verbose >= 1 ) printf ("pc = %.3x: I/O: read hex\n", pc);
                        printf ("Enter hex input: ");
                        fflush (stdout);
                        cin >> buf;
                        sscanf (buf.c_str(), "%x", &acc);
                        acc &= 0x0000ffff;
                        printf ("\n");
                        break;
                    case 1: // read ascii
                        if ( verbose >= 1 ) printf ("pc = %.3x: I/O: read ascii\n", pc);
                        printf ("Enter ascii input: ");
                        fflush (stdout);
                        cin >> buf;
                        acc = buf[0];
                        acc &= 0x0000ffff;
                        printf ("\n");
                        break;
                    case 2: // write hex
                        if ( verbose >= 1 ) printf ("pc = %.3x: I/O: write hex\n", pc);
                        if ( verbose >= 1 ) printf ("Hex output: ");
                        printf ("%.4x\n", acc);
                        break;
                    case 3: // write ascii
                        if ( verbose >= 1 ) printf ("pc = %.3x: I/O: write ascii\n", pc);
                        if ( verbose >= 1 ) printf ("Ascii output: ");
                        printf ("%c\n", acc & 0xff);
                        break;
                }
                break;
            case 2: // shifts
                switch ( ir.shifts.shiftop ) {
                    case 0: // shift left
                        acc = (acc << ir.shifts.shiftcount) & 0xffff;
                        acc &= 0x0000ffff;
                        if ( verbose >= 1 ) printf ("pc = %.3x: shift left by %d; result is %.4x\n", pc, ir.shifts.shiftop, acc);
                        break;
                    case 1: // shift right
                        acc = (acc >> ir.shifts.shiftcount) & (0xffff >> ir.shifts.shiftcount);
                        acc &= 0x0000ffff;
                        if ( verbose >= 1 ) printf ("pc = %.3x: shift right by %d; result is %.4x\n", pc, ir.shifts.shiftop, acc);
                        break;
                    case 2: // rotate left
                        acc = ((acc << ir.shifts.shiftcount) & 0xffff) |
                              ((acc >> (16-ir.shifts.shiftcount)) & (0xffff >> (16-ir.shifts.shiftcount)));
                        acc &= 0x0000ffff;
                        if ( verbose >= 1 ) printf ("pc = %.3x: rotate left by %d; result is %.4x\n", pc, ir.shifts.shiftop, acc);
                        break;
                    case 3: // rotate right
                        acc = ((acc >> ir.shifts.shiftcount) & (0xffff >> ir.shifts.shiftcount)) |
                              ((acc << (16-ir.shifts.shiftcount)) & 0xffff);
                        acc &= 0x0000ffff;
                        if ( verbose >= 1 ) printf ("pc = %.3x: rotate right by %d; result is %.4x\n", pc, ir.shifts.shiftop, acc);
                        break;
                }
                break;
            case 3: // load
                acc = mem[ir.others.address];
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: load result (@ %.3x) is %.4x\n", pc, ir.others.address, acc);
                break;
            case 4: // store
                acc &= 0x0000ffff;
                mem[ir.others.address] = acc;
                if ( verbose >= 1 ) printf ("pc = %.3x: store result (@ %.3x) is %.4x\n", pc, ir.others.address, mem[ir.others.address]);
                break;
            case 5: // add
                acc += mem[ir.others.address];
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: add result is %.4x\n", pc, acc);
                break;
            case 6: // sub
                acc -= mem[ir.others.address];
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: sub result is %.4x\n", pc, acc);
                break;
            case 7: // and
                acc &= mem[ir.others.address];
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: and result is %.4x\n", pc, acc);
                break;
            case 8: // or
                acc |= mem[ir.others.address];
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: or result is %.4x\n", pc, acc);
                break;
            case 9: // xor
                acc ^= mem[ir.others.address];
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: xor result is %.4x\n", pc, acc);
                break;
            case 10: // not
                acc = ~acc;
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: not result is %.4x\n", pc, acc);
                break;
            case 11: // nop
                // do nothing
                if ( verbose >= 1 ) printf ("pc = %.3x:  nop\n", pc);
                break;
            case 12: // jmp
                if ( verbose >= 1 ) printf ("pc = %.3x: jmp to %.4x\n", pc, ir.others.address);
                pc = ir.others.address;
                incpc = 0;
                break;
            case 13: // jmpe
                if ( verbose >= 1 ) printf ("pc = %.3x: jmpe to %.4x\n", pc, ir.others.address);
                if ( (acc & 0x0000ffff) == 0 ) {
                    pc = ir.others.address;
                    incpc = 0;
                }
                break;
            case 14: // jmpl
                if ( verbose >= 1 ) printf ("pc = %.3x: jmpl to %.3x\n", pc, ir.others.address);
                if ( (acc & 0x00008000) != 0 ) {
                    pc = ir.others.address;
                    incpc = 0;
                }
                break;
            case 15: // brl
                acc = pc+1;
                acc &= 0x0000ffff;
                if ( verbose >= 1 ) printf ("pc = %.3x: brl from %.3x to %.4x\n", pc, acc, ir.others.address);
                pc = ir.others.address;
                incpc = 0;
                break;
        }
        if ( incpc )
            pc++;
        if ( maxticks && (numinst >= maxticks) ) {
            cerr << "Simulation reached the maximum number of " << maxticks << " instructions to execute." << endl;
            cout << "Simulation reached the maximum number of " << maxticks << " instructions to execute." << endl;
            break;
        }
    }
}
