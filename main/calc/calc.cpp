#include <calc/calc.h>

int symbols[52];

static int computeSymbolIndex(char token)
{
    int idx = -1;
    if (islower(token)) {
        idx = token - 'a' + 26;
    } else if (isupper(token)) {
        idx = token - 'A';
    }
    return idx;
}

/* returns the value of a given symbol */
int symbolVal(char symbol)
{
    int bucket = computeSymbolIndex(symbol);
    return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
    int bucket = computeSymbolIndex(symbol);
    symbols[bucket] = val;
}

/**
 * Args: input file.
 */

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < 52; i++) {
        symbols[i] = 0;
    }
    calc_in = fopen(argv[1], "r");
    if (calc_in) {
        while (!feof(calc_in)) {
            calc_parse();
        }
    }
    return 0;
}

void calc_error(char *s)
{
    fprintf(stderr, "%s\n", s);
}