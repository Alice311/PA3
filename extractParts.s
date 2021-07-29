/*
 * Filename: parseNum.s
* Author: Sixian Cap
* UserId: cs30s121ae
* Date: 07/22/2021
* Sources of help: Notes
*/




@ Describe the Hardware to the assembler
	.arch	armv6			@ armv6 instruction set
	.cpu    cortex-a53		@ cpu type
	.syntax unified			@ modern syntax for this file

@ List external functions
@.extern  			@ pre-defined putchar function
.equ     FP_OFFSET, 12		@ fp offset in frame


@ data segment
.section .rodata		

@ Text segment
.text				
.type	 extractParts, %function	
.global  extractParts			

extractParts:
push     {r4,fp,lr}		
add      fp,sp, FP_OFFSET	

lsr r4,r0,31			
strb r4,[r1,0]			

lsr  r4,r0,23			
sub  r4,r4,127			
strb r4,[r1,1]			

lsl  r4,r0,9			
lsr  r4,r4,9			
add	r4,r4, 0x800000		
str	r4,[r1,4]		

mov	 r0,0
sub	 sp,fp,FP_OFFSET
pop	 {r4,fp,lr}		
bx  	 lr			

.end


