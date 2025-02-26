;=================================================
; Name: 
; Email: prog 3 
; 
; Lab: lab 8, ex 2
; Lab section: 
; TA: 
; 
;=================================================

; instead of hardcode, get input. also have a reg be a counter 
.orig x3000 
LD R6, top_stack_addr 
; Test harness 
;------------------------------------------------- 
LEA R0, checkprompt 
PUTS 
GETC 
OUT 

ADD R2, R0, #0 
AND R1, R1, #0 
ADD R1, R1, R0 
LD R5, PARITY_3600 
JSRR R5 
AND R0, R0, x0
ADD R0, R0, #10 
OUT
LEA R0, checkprompt1 
PUTS 
AND R0, R0, x0
ADD R0, R0, R1
OUT 
LEA R0, checkprompt2 
PUTS 
ADD R0, R3, #15 
ADD R0, R0, #15 
ADD R0, R0, #15 
ADD R0, R0, #3
OUT 
AND R0, R0, x0 
ADD R0, R0, #10 
OUT 
HALT ; Test harness local data 
;------------------------------------------------- 
top_stack_addr .fill xFE00 
checkprompt .STRINGZ "Input a character: " 
checkprompt1 .STRINGZ "The number of 1’s in '" 
checkprompt2 .STRINGZ "' is: " 
PARITY_3600 .fill x3600 
.END 
;================================================= 
; Subroutine: PARITY_CHECK_3600
; Parameter: // Fixme 
; Postcondition: // Fixme
; Return Value (R3): // Fixme 
;================================================= 
.orig x3600 
; Backup registers 
ADD R6, R6, #-1 
STR R7, R6, #0 
ADD R6, R6, #-1 
STR R5, R6, #0 
ADD R6, R6, #-1 
STR R4, R6, #0 
ADD R6, R6, #-1
STR R2, R6, #0 
ADD R6, R6, #-1
STR R1, R6, #0
; Code 
; R0 = R2 
LD R4, COUNTER16 
LD R3, COUNTER
ADD R2, R2, #0 
BRzp POSITIVE
BRn NEGATIVE 
POSITIVE: 
BR LOOP 

NEGATIVE:
;shifting left 
ADD R3, R3, #1 
BR LOOP 

LOOP 
ADD R4, R4, #-1 
BRz EXIT
ADD R2, R2, R2
BRzp POSITIVE 
BRn NEGATIVE 

EXIT 
; Restore registers 
LDR R1, R6, #0
ADD R6, R6, #1
LDR R2, R6, #0
ADD R6, R6, #1 
LDR R4, R6, #0 
ADD R6, R6, #1 
LDR R5, R6, #0 
ADD R6, R6, #1 
LDR R7, R6, #0
ADD R6, R6, #1
RET 
COUNTER16 .FILL #16
COUNTER .FILL #0 
.END