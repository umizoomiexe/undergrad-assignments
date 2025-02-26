;=================================================
; Name: uma a
; Email:uakun001@ucr.edu
;
; Lab: lab 5, ex 3
; Lab section:022
; TA:Karan Bhogal 
;
;=================================================
.orig x3000
; Initialize the stack. Don't worry about what that means for now.
ld r6, top_stack_addr ; DO NOT MODIFY, AND DON'T USE R6, OTHER THAN FOR BACKUP/RESTORE
lea r1,string_array
ld r2,sub_get_string
jsrr r2
ld r2,sub_is_palindrome
jsrr r2
add r4,r4,#0
brz print_not_palindrome
brp print_palindrome

print_palindrome
    lea r0,prompt_part1
    puts
    lea r0,string_array
    puts
    lea r0,propmt_part3_1
    puts
    halt
print_not_palindrome
    lea r0,prompt_part1
    puts
    lea r0,string_array
    puts
    lea r0,propmt_part3_2
    puts
    halt
; your code goes here

; your local data goes here
string_array .blkw #100
top_stack_addr .fill xFE00 ; DO NOT MODIFY THIS LINE OF CODE
sub_get_string .fill x3200
sub_is_palindrome .fill x3400
prompt_part1 .stringz "The string "
propmt_part3_1 .stringz " IS a palindrome\n"
propmt_part3_2 .stringz " IS NOT a palindrome\n"
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

;-------------------------------------------------------------------------
; Subroutine: SUB_IS_PALINDROME
; Parameter (R1): The starting address of a null-terminated string
; Parameter (R5): The number of characters in the array.
; Postcondition: The subroutine has determined whether the string at (R1)
; is a palindrome or not, and returned a flag to that effect.
; Return Value: R4 {1 if the string is a palindrome, 0 otherwise}
;-------------------------------------------------------------------------
.orig x3400
add r6,r6,#-1
str r7,r6,#0
add r6,r6,#-1
str r5,r6,#0
add r6,r6,#-1
str r1,r6,#0

ld r2,sub_to_upper
jsrr r2

and r2,r2,#0
and r7,r7,#0
and r3,r3,#0
add r4,r4,#1

add r2,r1,r5
add r2,r2,#-1

other_loop
    ldr r7,r1,#0
    ldr r3,r2,#0
    not r3,r3
    add r3,r3,#1
    add r7,r7,r3
    BRnp not_pal
    add r1,r1,#1
    add r2,r2,#-1
    add r5,r5,#-1
    BRnp other_loop
    Brz end_loop

not_pal
    and r4,r4,#0

end_loop
    ldr r1,r6,#0
    add r6,r6,#1  
    ldr r5,r6,#0
    add r6,r6,#1
    ldr r7,r6,#0
    add r6,r6,#1

ret

sub_to_upper .fill x3600

.end
;-------------------------------------------------------------------------
; Subroutine: SUB_TO_UPPER
; Parameter (R1): Starting address of a null-terminated string
; Postcondition: The subroutine has converted the string to upper-case
;     in-place i.e. the upper-case string has replaced the original string
; No return value, no output, but R1 still contains the array address, unchanged
;-------------------------------------------------------------------------
.orig x3600
add r6,r6,#-1
str r1,r6,#0
add r6,r6,#-1
str r7,r6,#0
ld r7, sub_addr

loop_to_upper
  ldr r2,r1,#0
  BRz DONE

  and r2,r2,r7
  str r2,r1,#0
  add r1,r1,#1
  br loop_to_upper

DONE
  ldr r7,r6,#0
  add r6,r6,#1
  ldr r1,r6,#0
  add r6,r6,#1
 
  ret
;==========
;Subroutine Data
;=========
sub_addr .fill x5F

.END
