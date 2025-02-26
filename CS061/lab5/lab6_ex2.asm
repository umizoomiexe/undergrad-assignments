;=================================================
; Name: Uma Akundi 
; Email: uakun001@ucr.edu
; 
; Lab: lab 6, ex 1
; Lab section: 021
; TA: Karan Bhogal
; 
;=================================================

.ORIG x3000

GETC
OUT
ADD R1, R0, #0

LD R3, BASE
LD R4, MAX
LD R5, TOS
LD R6, REG_STACK
HALT 

SUB_STACK_PUSH  .FILL x3200
BASE .FILL xA000
MAX  .FILL xA005
TOS .FILL xA000 ;(i.e. stack starts out empty)
REG_STACK .FILL xFE00
.END 




;------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_PUSH
; Parameter (R1): The value to push onto the stack
; Parameter (R3): BASE: A pointer to the base (one less than the lowest available address) of the stack
; Parameter (R4): MAX: The "highest" available address in the stack
; Parameter (R5): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has pushed (R1) onto the stack (i.e to address TOS+1). 
;If the stack was already full (TOS = MAX), the subroutine has printed an
;overflow error message and terminated.
; Return Value: R5 ← updated TOS
;------------------------------------------------------------------------------------------

.ORIG x3200

;if curr-max =0, exit. else continue

STR R1, R5, #1
ADD R5, R5, #1

LOOP
    NOT R1, R1
    ADD R1, R1, #1
    BRnp LOOP

RET
.END

;------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_POP
; Parameter (R3): BASE: A pointer to the base (one less than the lowest available address) of the
;stack
; Parameter (R4): MAX: The "highest" available address in the stack
; Parameter (R5): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped MEM[TOS] off of the stack and copied it to R0.
; If the stack was already empty (TOS = BASE), the subroutine has printed
; an underflow error message and terminated.
; Return Values: R0 ← value popped off the stack
; R5 ← updated TOS
;------------------------------------------------------------------------------------------

.ORIG x3400


RET
.END
