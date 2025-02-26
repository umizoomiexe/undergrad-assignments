;=================================================
; Name: Uma Akundi 
; Email: uakun001@ucr.edu
; 
; Lab: lab 4, ex 1
; Lab section: 021
; TA: Karan Bhogal 
; 
;=================================================

.ORIG x3000

LEA R1, ARRAY 


LD R5, SUB_FILL_ARRAY
JSRR R5 

LEA R1, ARRAY 

HALT 

ARRAY   .BLKW #10
SUB_FILL_ARRAY  .FILL x3200

.END



;------------------------------------------------------------------------
; Subroutine: SUB_FILL_ARRAY
; Parameter (R1): The starting address of the array. This should be unchanged at the end of the subroutine!
; Postcondition: The array has values from 0 through 9.
; Return Value (None)
;-------------------------------------------------------------------------

.ORIG x3200

ADD R2, R2, #1
ADD R3, R3, #9
DO_WHILE_LOOP

    STR R2, R1, #1 
    
    ADD R1, R1, #1 ; INCREMEMVT MEM_ADD
    
    ADD R2, R2, #1 ; increment num_0
    
    ADD R3, R3, #-1 ; decrncrement num10
    
    BRp DO_WHILE_LOOP
END_DO_WHILE_LOOP

RET

.END
