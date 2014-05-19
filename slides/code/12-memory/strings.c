#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char **argv) {
    int i = 0;
    // allocate a space in memory for result
    char *result = (char *) malloc (sizeof (*result));
    *result = '\0';
    while (i < argc) {  // while there are still arguments
        char *s = (char *) malloc (sizeof (*s) *
                                   (strlen(result) + strlen(argv[i]) + 1));
        strcpy (s, result);
        // add "free(result); here...
        strcat (s, argv[i]);
        // ... or here
        result = s;
        i++;
    }
    printf ("Concatenation: %s\n", result);
    return 0;
}
