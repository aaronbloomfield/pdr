#include <stdio.h>

long absolute_value(long x) {
    if (x<0)	// if x is negative
        x = -x;	// negate x
    return x;	// return x
}

int main() {
    long theValue=0;
    printf ("Enter a value: \n");
    scanf ("%ld", &theValue);
    long theResult = absolute_value(theValue);
    printf ("The result is: %ld\n", theResult);
    return 0;
}
