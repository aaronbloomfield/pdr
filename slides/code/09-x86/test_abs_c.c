#include <stdio.h>

int absolute_value(int x) {
    if (x<0)	// if x is negative
        x = -x;	// negate x
    return x;	// return x
}

int main() {
    int theValue=0;
    printf ("Enter a value: \n");
    scanf ("%d", &theValue);
    int theResult = absolute_value(theValue);
    printf ("The result is: %d\n", theResult);
    return 0;
}
