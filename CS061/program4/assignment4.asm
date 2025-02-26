
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R4
;=================================================================================

.ORIG x3000		
;-------------
;Instructions
;-------------

start 

LD R0, introPromptPtr
PUTS 

LD R6, countr 

AND R5,R5, #0
AND R2,R2, #0
AND R3,R3, #0
AND R4,R4, #0
AND R7,R7, #0

GETC 
OUT
	
LD R2, newline
ADD R2, R0, R2
BRz  end

LD R2, pluscheck
ADD R2, R0, R2
BRz  aftercheck

LD R2, minuscheck
ADD R2, R0, R2
BRz aftercheckneg

BRnzp ifnum

aftercheckneg:

ADD R7, R7, #-1
aftercheck:
    GETC 
    OUT

ifnum:
LD R2, newline
ADD R2, R0, R2
BRz  end

;check if its a digit or not here 

LD R2, neg48
ADD R2, R0, R2
BRn  ERROR     

LD R2, neg57
ADD R2, R0, R2
BRp  ERROR      

LD R2, neg48
ADD R0, R0, R2


AND R5,R5, #0
LD R3, num10
multiplyloop
    ADD R5, R4, R5
    ADD R3, R3, #-1
    BRp multiplyloop
endmultiplyloop
ADD R4, R5, R0

ADD R6, R6, #-1

BRp aftercheck
BR end


ERROR: 
    LD R0, errorMessagePtr
    puts
BR start


end

ADD R7,R7, #1
BRz NEG
BRnp POS

NEG:
NOT R4, R4
ADD R4, R4, #1

POS:
HALT

;---------------	
; Program Data
;---------------

introPromptPtr  .FILL xB000
errorMessagePtr .FILL xB200
countr    .FILL   #5  
newline  .FILL  #-10
pluscheck .FILL #-43
minuscheck .FILL #-45
neg48 .FILL #-48
neg57 .FILL #-57
num10  .FILL #10
offset  .FILL x30
.END

;------------
; Remote data
;------------
.ORIG xB000	 ; intro prompt
.STRINGZ	 "Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

.END					
					
.ORIG xB200	 ; error message
.STRINGZ	 "ERROR: invalid input\n"

;---------------
; END of PROGRAM
;---------------
.END