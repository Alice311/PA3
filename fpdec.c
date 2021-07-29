/* 
 * Filename: fpdec.c
 * Author: Sixian Cao
 * UserId: cs30s121ae
 * Date: 07/29/2021
 * Sources of help: Notes, TAs
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"

// success: 0, fail: 1

int main(int argc, char * argv[])
{
   
  
  int tf = 0;
 if(argc<3 )
	tf = 1;
 if(argc>3)
	tf = 1;

 if(tf == 1)
    {
        fprintf(stderr, "%s","%s", INVALID_ARGS, SHORT_USAGE);
        return 1;
    }

   
   int ch;
   
    char onHeap = 0;
    ieeeParts_t *ptd;

    while ((ch = getopt(argc, argv, "s:h:")) != -1)
    {
        switch (ch)
        {
            case 'h':
                ptd = malloc(sizeof(ieeeParts_t));
		if(ptd !=NULL)
                onHeap ++;
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
    unsigned long pm = parseNum(argv);
    extractParts(pm, ptd);

    printf(SIGN_STR, ptd->sign);
    printf(EXP_STR, ptd->exp);
    printf(MANTISSA_STR, ptd->mantissa);

    if(onHeap ==1)
        free(ptd);
    return 0;
}
