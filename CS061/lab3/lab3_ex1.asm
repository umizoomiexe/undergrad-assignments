;=================================================
; Name: Uma Akundi 
; Email:  uakun001@ucr.edu 
; 
; Lab: lab 3, ex 1
; Lab section: 021
; TA: Karan Bhogal 
; 
;=================================================

.ORIG x3000 

LD R5, DATA_PTR
LDR R6, R5, #1 

LDR R3, R5, #0
LDR R4, R6, #0

ADD R3, R3, #1
ADD R4, R4, #1

STR R3, R5, #0
STR R4, R6, #0

HALT

DATA_PTR .FILL x4000

.END

.ORIG x4000
DATA .FILL #65
DATA2 .FILL X41
.END
    