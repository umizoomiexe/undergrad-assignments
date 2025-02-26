;=================================================
; Name: Uma Akundi
; Email: uakun001@ucr.edu
; 
; Lab: lab 5, ex 1
; Lab section: 021 
; TA: Karan Bhogal 
; 
;=================================================
.orig x3000
; Initialize the stack. Don't worry about what that means for now.
ld r6, top_stack_addr ; DO NOT MODIFY, AND DON'T USE R6, OTHER THAN FOR BACKUP/RESTORE
lea r1,string_array
ld r2,sub_get_string
jsrr r2


; your code goes here

; your local data goes here
string_array .blkw #100
top_stack_addr .fill xFE00 ; DO NOT MODIFY THIS LINE OF CODE
sub_get_string .fill x3200

.end

; your subroutines go below here
;------------------------------------------------------------------------
; Subroutine: SUB_GET_STRING
; Parameter (R1): The starting address of the character array
; Postcondition: The subroutine has prompted the user to input a string,
; terminated by the [ENTER] key (the "sentinel"), and has stored
; the received characters in an array of characters starting at (R1).
; the array is NULL-terminated; the sentinel character is NOT stored.
; Return Value (R5): The number of non-sentinel chars read from the user.
; R1 contains the starting address of the array unchanged.
;-------------------------------------------------------------------------
.orig x3200
add r6,r6,#-1
str r7,r6,#0
add r6,r6,#-1
str r1,r6,#0

and r5,r5,#0
lea r0,user_p
puts

loop
    getc
    out
    ld r2,enter
    add r3,r0,r2
    brz end_string
    str r0,r1,#0
    add r1,r1,#1
    add r5,r5,#1
    br loop

end_string
    and r0,r0,#0
    str r0,r1,#0
    ldr r1,r6,#0
    add r6,r6,#1
    ldr r7,r6,#0
    add r6,r6,#1
    ret

user_p .stringz "Enter any string followed by Enter\n"
enter .fill #-10

.end