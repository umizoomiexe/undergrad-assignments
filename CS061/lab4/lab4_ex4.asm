;=================================================
; Name: Uma Akundi 
; Email: uakun001@ucr.edu
; 
; Lab: lab 4, ex 4
; Lab section: 021
; TA: Karan Bhogal 
; 
;=================================================

.ORIG x3000

LEA R1, ARRAY 
LD R5, SUB_FILL_ARRAY
JSRR R5 

LEA R1, ARRAY 
LD R5, SUB_CONVERT_ARRAY
JSRR R5 

LEA R1, ARRAY 
LD R5, SUB_PRINT_ARRAY
JSRR R5 

LEA R1, ARRAY 
LD R5, SUB_PRETTY_PRINT_ARRAY
JSRR R5 
HALT 

ARRAY   .BLKW #10
SUB_FILL_ARRAY  .FILL x3200
SUB_CONVERT_ARRAY .FILL x3400
SUB_PRINT_ARRAY   .FILL x3600
SUB_PRETTY_PRINT_ARRAY .FILL x3800
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

;------------------------------------------------------------------------
; Subroutine: SUB_CONVERT_ARRAY
; Parameter (R1): The starting address of the array. This should be
;unchanged at the end of the subroutine!
; Postcondition: Each element (number) in the array should be represented as
;a character. E.g. 0 -> ‘0’
; Return Value (None)
;-------------------------------------------------------------------------

.ORIG x3400
ADD R2, R2, #1
ADD R3, R3, #10
LD R4, ascii
DO_WHILE
    
    LDR R2, R1, #0
    
    ADD R2, R2, R4 ;increment value not memaddr
    
    STR R2, R1, #0
    
    ADD R1, R1, #1 ; INCREMEMVT MEM_ADD
    
    ADD R3, R3, #-1 ; decrncrement num10
    
    BRp DO_WHILE
END_DO_WHILE
RET
 
ascii  .FILL x30
.END

;------------------------------------------------------------------------
; Subroutine: SUB_PRINT_ARRAY
; Parameter (R1): The starting address of the array. This should be unchanged at the
; end of the subroutine!
; Postcondition: Each element (character) in the array is printed out to the
;console.
; Return Value (None)
;-------------------------------------------------------------------------
.ORIG x3600
ADD R3, R3, #10
DO_WHILE_2
    LDR R0, R1, #0
    OUT
    
    ADD R1, R1, #1 ; INCREMEMVT MEM_ADD
    
    ADD R3, R3, #-1 ; decrncrement num10
    BRp DO_WHILE_2
END_DO_WHILE_2
RET

.END

;------------------------------------------------------------------------
; Subroutine: SUB_PRETTY_PRINT_ARRAY
; Parameter (R1): The starting address of the array. This should be unchanged
; at the end of the subroutine!
; Postcondition: Prints out “=====” (5 equal signs), prints out the array,
; and after prints out “=====” again.
; Return Value (None)
;-------------------------------------------------------------------------
.ORIG x3800

LEA R0, equal
PUTS

LD R5, SUB_TEST
JSRR R5

LEA R0, equal ;keeps looping here 
PUTS
RET

equal .STRINGZ "=====" 
SUB_TEST .FILL x3600
.END