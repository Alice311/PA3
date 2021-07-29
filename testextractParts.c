/*
 * Filename: testextractParts.c
 * Author: Sixian Cao
 * UserId: cs30s121ae
 * Date: 07/29/2021
 * Sources of help: Notes, TAs
 */


#include "test.h"
#include "pa3.h"


int main(){
	fprintf(stderr, "testing extractParts...\n\n");
	ieeeParts_t number;	
	unsigned long hexIEEE;
	
	hexIEEE = 0xfa0000;		
	extractParts(hexIEEE, &number);	
	TEST(number.sign == 1);
	TEST(number.exp == 9);		
	TEST(number.mantissa == 3296329728); 
	
	hexIEEE = 0x0;		
	extractParts(hexIEEE, &number);	
	TEST(number.sign == 0); 
	TEST(number.exp == -127);
	TEST(number.mantissa == 0x800000);
        
	hexIEEE = 0x40000000;		
	extractParts(hexIEEE, &number);	
	TEST(number.sign == 0);
	TEST(number.exp == 1);
	TEST(number.mantissa == 0x800000);
	
	hexIEEE = 0xFFFFFFFF;		
	extractParts(hexIEEE, &number);  
	TEST(number.sign == 1);
	TEST(number.exp == -128);
	TEST(number.mantissa == 0xFFFFFF);

	fprintf(stderr, "\nDone running tests.\n");
	return 0;
}