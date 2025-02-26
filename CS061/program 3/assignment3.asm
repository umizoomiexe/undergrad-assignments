;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Uma Akundi 
; Email: uakun001@ucr.edu
; 
; Assignment name: Program Assignment 3
; Lab section: 021
; TA: Karan Bhogal
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
LD R6, Value_ptr		; R6 <-- pointer to value to be displayed as binary
LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------

STR R1, R6, #0
LDR R1, R6, #0

LD R2, bitsub
NOT R2, R2
ADD R2, R2, #1

LD R5, printamt
ADD R7, R7, #4
ADD R3, R3, #3

LOOPFRONT
    AND R4, R4, #0
    ADD R4, R1, R4
    ADD R4, R2, R4
    BRn ZERO
    BRzp ONE
LOOPMIDDLE
    ADD R1, R1, R1
    ADD R5, R5, #-1
    BRzp LOOPFRONT
    BRn LOOPEND

ZERO
    LD R0, numzero
    OUT
    BR if_space
    
ONE
    LD R0, numone
    OUT
    BR if_space

if_space
    ADD R7, R7, #-1
    BRp LOOPMIDDLE
    ADD R3, R3, #-1
    BRn LOOPMIDDLE
    ADD R7, R7, #4
    LD R0, space
    OUT
    BRnzp LOOPMIDDLE
    
LOOPEND
LD R0, newline
OUT

HALT
;---------------	
;Data
;---------------
Value_ptr	.FILL xCA01	; The address where value to be displayed is stored
bitsub   .FILL #32768

printamt     .FILL #15

newline .FILL x0A
numzero    .FILL x30
numone     .FILL x31

space    .FILL x20
.END

.ORIG xCA01					; Remote data
Value .FILL xABCD			; <----!!!NUMBER TO BE DISPLAYED AS BINARY!!! Note: label is redundant.
;---------------	
;END of PROGRAM
;---------------	
.END


