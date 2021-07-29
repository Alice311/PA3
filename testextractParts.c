/*
 * Filename: testextractParts.c
 * uthor: Sixian Cao
 * UserId: cs30s121ae
 * Description: Unit test program to test the function extractParts().
 * Date: 07/29/2021
 * Sources of help: TAs 
 */

#include <string.h>
#include <stdlib.h>

#include "test.h" /* For TEST() macro and stdio.h */
#include "pa3.h"

#define testingString "\n\nTesting 0x%lx:\n"




void extractParts()
{
    ieeeParts_t * structTwo;
    ieeeParts_t * myFuncStruct;
    ieeeParts_t * structOne = &(ieeeParts_t){ '0', '0', 0 };
 
    structTwo = &(ieeeParts_t){ 0, -127, 0x800000 };
    extractParts(0x0, structOne);
    TEST(structTwo->sign == structOne->sign);
    TEST(structTwo->exp == structOne->exp);
    TEST(structTwo->mantissa == structOne->mantissa);   

    structTwo = &(ieeeParts_t){ 0, -127, 0x800001 };
    extractParts(0x1, structOne);
    TEST(structTwo->sign == structOne->sign);
    TEST(structTwo->exp == structOne->exp);
    TEST(structTwo->mantissa == structOne->mantissa);   

   structTwo = &(ieeeParts_t){ 1, -128, 0xFFFFFF };
    extractParts(0xFFFFFFFF, structOne);
    TEST(structTwo->sign == structOne->sign);
    TEST(structTwo->exp == structOne->exp);
    TEST(structTwo->mantissa == structOne->mantissa);   

    structTwo = &(ieeeParts_t){ 0, 3, 0x41260000 };
    extractParts(0x41260000, structOne);
    TEST(structTwo->sign == structOne->sign);
    TEST(structTwo->exp == structOne->exp);
    TEST(structTwo->mantissa == structOne->mantissa);   

}



int main()
{
    fprintf(stderr, "Testing extractParts...\n");
 
  
    extractParts();

    fprintf(stderr, "\nDone running tests.\n");
	
    return 0;
}
