#ifndef HEADER_H
#define HEADER_H

#include <cctype>
#include <cstdio>
#include <stdlib.h>

extern int symbols[52];

int symbolVal(char symbol);

void updateSymbolVal(char symbol, int val);

extern struct _IO_FILE *calc_in;

int calc_parse();

int calc_lex();

void calc_error (char *s);

#endif //HEADER_H