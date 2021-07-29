/*
 * Filename: testparseNum.c
 * Author: Sixian Cao
 * UserId: cs30s121ae
 * Date: 07/29/2021
 * Sources of help: Notes, TAs
 */


#include "test.h"
#include "pa3.h"


void parseNumTest(){	
	char * argv[2];
	argv[0] = "parseNum";			
	
	argv[1] = "0x41260000";			
	TEST( parseNum(argv) == 0x41260000 );   
	
	argv[1] = "0x00000000";			
	TEST( parseNum(argv) == 0x00000000 ); 	
	
	argv[1] = "0xc47a0000";			
	TEST( parseNum(argv) == 0xc47a0000 );   

	argv[1] = "0xbf800000";			
	TEST( parseNum(argv) == 0xbf800000 );

	argv[1] = "0xFFFFFFFF";			
	TEST( parseNum(argv) == 0xFFFFFFFF );   

}		


int main(){
	fprintf(stderr, "testing parseNum...\n\n");
	parseNumTest();
	fprintf(stderr, "\nDone running tests.\n");
	return 0;
}