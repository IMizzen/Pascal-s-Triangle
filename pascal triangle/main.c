#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void pascal (int n)
{
    int array[n];                       /* declare VLA */
    memset (array, 0, sizeof array);    /* zero elements */

    printf ("\n  PASCAL's TRIANGLE\n(binomial coefficients)\n\n"
            "  exponent: %d\n\n", n);

    for (int i = array[0] = 1; i <= n; ++i) {
        int j;
        printf ("%*s", (n - i)*3, "");
        for (j = i - 1; j > 0; --j)
            printf ("%-6d", array[j] += array[j - 1]);
        printf ("%-3d\n", array[j]);
    }
}

int main (int argc, char **argv)
{

    char *endptr;

    /* take n as 1st argument to program (default 5) */
    int n = (argc > 1) ? strtol (argv[1], &endptr, 0) : 5;/*<--- How many levels of Pascal's Triangle you would like to see just change this number */
    if (endptr == argv[1] || errno) {   /* vaidate conversion */
        fputs ("error: in argument conversion.\n", stderr);
        return 1;
    }

    pascal (n);
}
