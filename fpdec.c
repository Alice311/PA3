/* 
 * Filename: fpdec.c
 * Author: Sixian Cao
 * UserId: cs30s121ae
 * Date: 07/27/2021
 * Sources of help: Notes, TAs
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"

/*
 * Name: main
 * Function Prototype: int main( int argc, char * argv[] );
 * Description: Main function to extract the parts of an IEEE-754 hexadecimal
 *              input.
 * Parameters:  number of arguments
 *              array of string arguments (-s or -h and a hexadecimal number)
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 if program exits successfully. 1 if there is an error.
 */
int main(int argc, char * argv[])
{

int tf = 0;
 if(argc<3 )
	tf = 1;
 if(argc>3)
	tf = 1;

 if(tf == 1)
    {
        fprintf(stderr, "%s", "%s", INVALID_ARGS, SHORT_USAGE);

        return 1;
    }


    int tf2 = 0;
    ieeeParts_t * ptd;
    int ch;

   while ((ch = getopt(argc, argv, "s:h:")) != -1)
    {
        switch (ch)
        {
            case 'h':
                ptd = malloc(sizeof(ieeeParts_t));
		if(ptd !=NULL)
                tf2++;
                break;

            case 's':
                ptd = &(ieeeParts_t){ '0', '0', 0 };
                break;

            default:
                fprintf(stderr, "%s", SHORT_USAGE);
                return 1;
                break;
        }
    }
   
    unsigned long pN = parseNum(argv);
   

    extractParts(PN, ptd);

    printf(SIGN_STR, ptd->sign);
    printf(EXP_STR, ptd->exp);
    printf(MANTISSA_STR, ptd->mantissa);
   if(tf2==1)
        free(ptd);

    return 0;
}
