;=================================================
; Name: Uma Akundi 
; Email: uakun001@ucr.edu
; 
; Lab: lab 3, ex 2
; Lab section: 021
; TA: Karan Bhogal 
; 
;=================================================

.ORIG x3000

LEA R2, ARRAY ;starting address
LD R1, NUM_10


DO_WHILE_LOOP
    ;DO STUFF
    GETC
    OUT
    STR R0, R2, #0 
    
    ADD R2, R2, #1 ; INCREMEMVT MEM_ADDR
    
    ADD R1, R1, #-1
    BRp DO_WHILE_LOOP
END_DO_WHILE_LOOP


HALT 

ARRAY   .BLKW 10
NUM_10  .FILL #10
.END

