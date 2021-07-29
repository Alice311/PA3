/*
* Filename: extractParts.s
 * Author: Sixian Cao
 * UserId: cs30s121ae
 * Date: 07/27/2021
 * Sources of help: Notes, TAs
 */

@ Hardware Description
	.arch	armv6
	.cpu    cortex-a53
	.syntax unified

	.global extractParts            


@ Text segment
	.text
	.type	extractParts, %function 
	.global extraParts


extractParts:
	
	push	{r4, r5, fp, lr}        
	add	fp, sp, FP_OFFSET       

        mov     r4, r0                  
        mov     r5, r1                  
     
        lsr     r0, r0, 31	      
        strb    r0, [r5]                

      
        mov     r0, r4                  
        lsr     r0, r0, 23	       
        and     r0, r0, 0xFF	        
        sub     r0, r0, 0x7F		
        strb    r0, [r5, 1]   		 

       
        mov     r0, r4                 
        lsl     r0, r0, 9	    
	lsr	r0,r0, 0x800000
        str     r0, [r5, 4]   		



done:
	
	mov	r0, 0		        
	sub	sp, fp, FP_OFFSET       
	pop	{r4, r5, fp, lr}        
	bx	lr                      
.end
