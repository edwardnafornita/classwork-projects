TITLE Assignment 1 Section 2 Question 1

; Name: Edward Nafornita
; Date: January 17 2023
; ID: 110076381
; Description: Writing an assembly program equivalent to the C++ statements: 
;				int Y;
;				X = (Y + 4) * 3

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
	; data declarations go here
    Y	DWORD 0d		; variable Y declared with the value 0d
	X	DWORD 0d		; variable X to be written with the value of (Y + 4) * 3

.code
main PROC
	
	; code goes here
	mov		eax, Y		; moving Y to the EAX register
	add		eax, 4		; adding 4 to the EAX to perform Y + 4 (EAX = 4d)
	imul	eax, 3		; multiplying EAX by 3 (EAX = 12d)
	mov		X, eax		; setting X = (Y + 4) * 3 the result of that arithmetic (X = EAX, and EAX = 12d)
	call    DumpRegs    ; displays registers in console

	exit

main ENDP
END main
