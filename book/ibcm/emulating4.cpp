// read in instruction into unsgined chars a and b
ibcm_instruction inst;
inst.high = a;
inst.low = b;
if ( inst.halt.op == 0 ) { // halt
} else if ( inst.io.op == 1 ) { // io
	cout << inst.io.ioopt << endl;
} else if ( inst.shifts.op == 2 ) { // shifts
	cout << inst.shifts.shiftop << endl;
	cout << inst.shifts.shiftcount << endl;
} else { // all others
	cout << inst.others.address << endl;
}
