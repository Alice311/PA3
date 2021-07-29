/*
* Filename: parseNums.s
* Author: Sixian Cao
* UserId: cs30s121ae
* Date:07/27/2021
* Sources of help:notes, TAs
*/

@ Hardware Description
	.arch	armv6
	.cpu    cortex-a53
	.syntax unified

@  List external functions called and #defines and “magic” numbers
	.extern strtoul			
	.global parseNum		


@ Text segment
	.text
	.type	parseNum, %function	@ indication that main is a function



parseNum:
	// put prologue here

	push	{fp, lr}                
	add	fp, sp, FP_OFFSET      

                                      
        ldr     r0, [r0, 4] 
                                        
                                        
	ldr	r1, 0	     
                                       
	ldr	r2, 16		        
	bl	strtoul                
                                        

done:
	
	sub	sp, fp, FP_OFFSET       
	pop	{fp, lr}                
	bx	lr                      
.end
