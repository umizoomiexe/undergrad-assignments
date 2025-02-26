;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Uma Akundi
; Email: uakun001@ucr.edu
; 
; Assignment name: Assignment 4
; Lab section: Karan Bhogal 
; TA: 021
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R4
;=================================================================================
.orig x3000 
LD R6, top_stack_addr 
; Test harness 
;------------------------------------------------- 
LD R2, FILL_VALUE_3200 
JSRR R2 
; input paramaters R1 through 4 ; decimal should go into R1 
; R4 goes to R5 which goes to an address with the rest of the values if theres more 
; increment R0 and put it into R1 ADD R1, R1, #1 
;prints decimal in R1 in second subroutine 
LD R2, OUTPUT_DEC_3400 
JSRR R2

HALT 
; Test harness local data 
;------------------------------------------------- 
top_stack_addr .fill xFE00 
FILL_VALUE_3200 .FILL x3200 
OUTPUT_DEC_3400 .FILL  x3400 
.end 
;================================================= 
; Subroutine: LOAD_FILL_VALUE_3200 ; Parameter: n/a 
; Postcondition: R1 gets decimal filled into it 
; Return Value: R1 --> returns decimal 
;================================================= 
; load decimal value 
.orig x3200 ; Backup registers 
ADD R6, R6, #-1 
STR R7, R6, #0 
; Code 
LD R1, VALUE ; Restore registers
LDR R7, R6, #0 
ADD R6, R6, #1 
RET
VALUE .FILL #-3
.end 
;================================================= 
; Subroutine: OUTPUT_AS_DECIMAL_3400 
;Parameter: incremented R1 
; Postcondition: R1 in chars 
; Return Value: n/a 
;================================================= 
; print decimal representation of the new val 
; try with 32767 --> what happens? 
.orig x3400 
; Backup registers 
ADD R6, R6, #-1 
STR R7, R6, #0 
ADD R6, R6, #-1 
STR R0, R6, #0 
ADD R6, R6, #-1 
STR R3, R6, #0 
ADD R6, R6, #-1 
STR R2, R6, #0 
ADD R6, R6, #-1 
STR R4, R6, #0 
ADD R6, R6, #-1 
STR R5, R6, #0 
ADD R6, R6, #-1
STR R1, R6, #0 
; Code 
ADD R1, R1, #0 
BRn negative 
BRnzp skipover 
negative 
AND R0, R0, #0
ADD R0, R0, #9 
ADD R0, R0, #9 
ADD R0, R0, #9 
ADD R0, R0, #9 
ADD R0, R0, #9 
OUT 
NOT R1, R1 
AND R5, R5, #0 
ADD R5, R5, #1 
skipover
LD R4, TENTHOUSAND 
AND R2, R2, #0
DO_WHILE    
ADD R3, R1, R4    
BRnz move     
ADD R2, R2, #1     
ADD R1, R3, #0     
BR DO_WHILE 
move 
ADD R0, R2, #0 
BRz skip2 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #3
OUT 
AND R2, R2, #0 
skip2
LD R4,ONETHOUSAND 
DO_WHILE_LOOP2    
ADD R3, R1, R4   
BRnz MOVE_FORWARD   
ADD R2, R2, #1     
ADD R1, R3, #0    
BR DO_WHILE_LOOP2 
MOVE_FORWARD 
ADD R0, R2, #0 
BRz skip3
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #3
OUT
AND R2, R2, #0 
skip3 
LD R4, ONEHUNDRED 
DO_WHILE_LOOP3     
ADD R3, R1, R4    
BRnz MOVE3   
ADD R2, R2, #1
ADD R1, R3, #0 
BR DO_WHILE_LOOP3 
MOVE3 
ADD R0, R2, #0 
BRz skip4 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #3 
OUT 
AND R2, R2, #0 
skip4 
AND R4, R4, #0
ADD R4, R4, #-10
Tens     
ADD R3, R1, R4   
BRnz skip5    
ADD R2, R2, #1   
ADD R1, R3, #0   
BRnzp Tens 

skip5 
ADD R0, R2, #0
BRz skip6
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #3 
OUT 

skip6
ADD R0, R1, #0 
ADD R5, R5, #0 
BRp ADD_ONE
BRnzp SKIP_1 
ADD_ONE 
ADD R0, R0, #1 
SKIP_1 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #3 
OUT ; Restore registers
LDR R1, R6, #0 
 ADD R6, R6, #1 
 LDR R5, R6, #0 
 ADD R6, R6, #1 
 LDR R4, R6, #0
 ADD R6, R6, #1  
 LDR R2, R6, #0 
 ADD R6, R6, #1 
 LDR R3, R6, #0 
 ADD R6, R6, #1 
 LDR R0, R6, #0 
  ADD R6, R6, #1
  LDR R7, R6, #0
  ADD R6, R6, #1
 RET 
 TENTHOUSAND .FILL #-10000
 ONETHOUSAND .FILL #-1000
 ONEHUNDRED  .FILL #-100 
 .end