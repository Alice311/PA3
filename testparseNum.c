/*
 * Filename: testextractParts.c
 * uthor:Sixian Cao
 * UserId: cs30s121ae
 * Description: Unit test program to test the function extractParts().
 * Date: 07/29/2021
 * Sources of help: TAs
 */

#include <string.h>
#include <stdlib.h>

#include "test.h" /* For TEST() macro and stdio.h */
#include "pa3.h"


void parseNumTest(){
	char *argv[] = {"./1","0xFFFFFFFF"};
	TEST( parseNum(argv) == 0xFFFFFFFF );

	char *argv[] = {"./1","0xc47a0000"};
	TEST( parseNum(argv) == 0xc47a0000 );

	char *argv[] = {"./1","0xbf800000"};
	TEST( parseNum(argv) == 0xbf800000 );

	char *argv[] = {"./1","0x40000000"};
	TEST( parseNum(argv) == 0x40000000 );
}


int main()
{
    fprintf(stderr, "Testing parseNum...\n\n");
    
    parseNumTest()
    fprintf(stderr, "\nDone running tests.\n");

    return 0;
}
