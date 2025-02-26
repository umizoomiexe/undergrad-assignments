; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Uma Akundi 
; Email: uakun001@ucr.edu 
; 
; Assignment name: Assignment 5
; Lab section: 021
; TA: Karan Bhigal and Nick Santini
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
; PUT ALL YOUR CODE AFTER THE main LABEL
;=================================================================================
;NOTES: 
;use proper headers : the subroutine comments and other stuff too 
;---------------------------------------------------------------------------------
;  Initialize program by setting stack pointer and calling main subroutine
;---------------------------------------------------------------------------------
.ORIG x3000

; initialize the stack
ld r6, stack_addr
lea r1,user_string
; call main subroutine
lea r5, main
jsrr r5

;---------------------------------------------------------------------------------
; Main Subroutine
;---------------------------------------------------------------------------------
main

ld r2, get_user_string_addr
jsrr r2 

ld r2, strlen_addr
jsrr r2

;load r5 with length of input
add r5, r0, #0 

lea r0, result_string 
puts 

add r0, r5, #0
add r5, r5, #-1
lea r1, user_string
add r5, r1, r5

ld r2, palindrome_addr
jsrr r2

add r0,r0,#0

brz print_palindrome
brp print_not_palindrome

print_palindrome
    lea r0,final_string
    puts
    br jump
    ; halt
print_not_palindrome
    lea r0,not_string
    puts
    lea r0,final_string
    puts
    ; halt
; your code 
jump

HALT

;---------------------------------------------------------------------------------
; Required labels/addresses
;---------------------------------------------------------------------------------

; Stack address ** DO NOT CHANGE **
stack_addr           .FILL    xFE00

; Addresses of subroutines, other than main
get_user_string_addr .FILL    x3200
strlen_addr          .FILL    x3300
palindrome_addr      .FILL	  x3400


; Reserve memory for strings in the progrtam
; user_prompt          .STRINGZ "Enter a string: "
result_string        .STRINGZ "The string is "
not_string           .STRINGZ "not "
final_string         .STRINGZ	"a palindrome\n"

; Reserve memory for user input string
user_string          .BLKW	  100


.END


;---------------------------------------------------------------------------------
;subroutine: get_use_string
; Parameter (R1): The starting address of the character array
; Postcondition: The subroutine has prompted the user to input a string,
; terminated by the [ENTER] key (the "sentinel"), and has stored
; the received characters in an array of characters starting at (R1).
; the array is NULL-terminated; the sentinel character is NOT stored.
; Return Value (technically none, but R5): The number of non-sentinel chars read from the user.
; R1 contains the starting address of the array unchanged.
;-------------------------------------------------------------------------
.ORIG x3200
;do i store r5 in memory (size of input? )
add r6,r6,#-1
str r7,r6,#0
add r6,r6,#-1
str r1,r6,#0

and r5,r5,#0
; lea r3, strlen
lea r0,user_prompt 
puts
loop
    getc
    out
    ld r2,enter
    add r3,r0,r2
    brz end_string
    str r0,r1,#0
    add r1,r1,#1
    ; add r5,r5,#1
    br loop
    
end_string
    and r0,r0,#0
    str r0,r1,#0
    ; str r5, r3, #0 
    ldr r1,r6,#0
    add r6,r6,#1
    ldr r7,r6,#0
    add r6,r6,#1
ret
; strlen               .BLKW 10
user_prompt          .STRINGZ "Enter a string: "
enter                .fill #-10
.END
;----------------------------------------------------------------------------
; Subroutine: strlen
; Parameter (R5): The length of string calculated from last subroutine is stored in r5, this will be used 
; Postcondition: The subroutine will load the length of string in r0
;-------------------------------------------------------------------------
.orig x3300
add r6,r6,#-1
str r7,r6,#0
add r6,r6,#-1
str r1,r6,#0
add r6,r6,#-1
str r2,r6,#0

; lea r0, lengthstring
; puts 
and r0, r0, #0

    countloop   
    ldr R2, R1, #0
    add R2, R2, #0
    BRz stopcount 
    add r0, R0, #1
    add R1, R1, #1 
    BR countloop

stopcount

ldr r2,r6,#0
add r6,r6,#1
ldr r1,r6,#0
add r6,r6,#1
ldr r7,r6,#0
add r6,r6,#1

ret
; lengthstring .stringz "Length of input: "
.END

;--------------------------------------------------------------
; Subroutine: Palindrome 
; Parameter (R1, R5): takes the length of string from r5 and user string from r1 to use for postcondition 
; Postcondition: identify whether or not input is a palindrome in a recursive manner
;---------------------------------------------------------------------------------
.ORIG x3400
palindrome ; Hint, do not change this label and use for recursive alls
; ; Backup all used registers, R7 first, using proper stack discipline
add r6,r6,#-1
str r7,r6,#0
add r6,r6,#-1
str r1,r6,#0


    add r0, r0, #0
    brnz PALINDROME_REAL

recursivefunctionloop
    
    ldr r2, r5, #0 
    ldr r3, r1, #0 
    
    not r2, r2
    add r2, r2, #1 ;ascii 
    add r2, r2, r3 
    
    brnp not_a_alindrome ; exit recursive 
    
    add r5, r5, #-1 
    add r1, r1, #1  
    
    ; add r4, r1, #0 
    ; not r4, r4 
    ; add r4, r4, #1 
    ; add r4, r4, r5 
    add r0, r0, #-2
    ; brnz backuprestore ; exit recursion 
    ; ld r2, recursivefunctionloop
    ; jsrr r2
    jsr palindrome

; brnzp backuprestore
    BR LETSBOUNCE


not_a_alindrome
AND R0,R0,x0
add r0, r0, #1
br LETSBOUNCE

PALINDROME_REAL
AND R0, R0, x0
BR LETSBOUNCE

LETSBOUNCE


backuprestore
ldr r1,r6,#0
add r6,r6,#1
ldr r7,r6,#0
add r6,r6,#1
RET

;NOTES (do not grade pls this was for me) : 
; ; BACKUP EVERYTHING HERE 
; BASE CASES 

; CHECK IF IT IS A PALINDROME 
; ADD R5,R5, #0
; BRN, THEN IT IS A PALINDROME 

; JSR palindrome ;makes it recursive 

; ;add checks here 

; ;increment start and end address but it shld be on ur code alr 

; is_palindrome 
; br quit 

; not_palindrome 
; ; br quit 

; quit 

; PALINDROME CODE 

.END
