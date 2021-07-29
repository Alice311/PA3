/*
* Filename: parseNums.s
 * Author: Sixian Cao
 * UserId: cs30s121ae
 * Date: 07/29/2021
 * Sources of help: Notes, TAs
 */


@ Describe the Hardware to the assembler
	.arch	armv6			@ armv6 instruction set
	.cpu    cortex-a53		@ cpu type
	.syntax unified			@ modern syntax for this file

@ Functions
	.extern strtoul			
	.global parseNum		

@ Constants
	.equ 	FP_OFFSET, 4           


@ Text segment
	.text
	.type	parseNum, %function	



parseNum:
	
	push	{fp, lr}                
	add	fp, sp, FP_OFFSET       


                                       
        ldr     r0, [r0, 8]   
                                        
                                      
	mov	r1, 0x0                                       
	mov	r2, 16       
	bl	strtoul                 
                                       

done:

	sub	sp, fp, FP_OFFSET       
	pop	{fp, lr}                
	bx	lr                      
.end
