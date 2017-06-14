/*
   common.h - include at start of counts.c for CS 16 Project 2

   Use the constants, symbols, macros and functions herein to
   insure that your printed results accurately match our
   solution's results. Do not print by any other means.

   Do not change this file, and especially do not rely on any
   changes to it. You will not turn this file in.
*/

#ifndef COMMON_H
#define COMMON_H
#include <stdlib.h>

/* constants: number of different characters, and
              first and last printable characters */
#define NUM 128
#define FIRST '!'
#define LAST '~'

/* symbols for special characters, corresponding to codes 0 through FIRST-1 */
char *symbols[] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK",
    "BEL", "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1",
    "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC",
    "FS", "GS", "RS", "US", "SPC" };

/* symbol for DEL character, code LAST+1 (same as NUM-1) */
char *symbolDel = "DEL";

/* the following four functions must be used to print results */

/* use prHeader at the start to print header row (titles) */
void prHeader(FILE *out) {
    fprintf(out, "Code\tChar\tCount\n----\t----\t-----\n");
}

/* use prCountStr to print count for one of the special symbols */
void prCountStr(FILE *out, int code, char *str, int count) {
    fprintf(out, "%3d\t%s\t%5d\n", code, str, count);
}

/* use prCountChr to print count for one of the printable characters */
void prCountChr(FILE *out, int code, char chr, int count) {
    fprintf(out, "%3d\t%c\t%5d\n", code, chr, count);
}

/* use prTotal at the end to print total character count */
void prTotal(FILE *out, int count) {
    fprintf(out, "\t\t-----\nTotal\t\t%5d\n", count);
}

/* use the following three macros to print error messages for part 2
   {
       Beware: each macro executes two statements.
   }
   ignore these macros for part 1 */

/* use BADFILE(name) to exit if a file (name) cannot be opened */
#define BADFILE(name) fprintf(stderr, "bad file: %s\n", (name)); \
                      exit(1);

/* use BADOPTION(op) if an invalid option (not '-o') is on command line */
#define BADOPTION(op) fprintf(stderr, "bad option: %s\n", (op)); \
                      exit(2);

/* use MISSING (without parens) if output filename is missing */
#define MISSING fprintf(stderr, "missing output file\n"); \
                      exit(3);


#endif

