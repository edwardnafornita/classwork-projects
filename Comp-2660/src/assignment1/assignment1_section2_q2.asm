TITLE Assignment 1 Section 2 Question 2

; Name: Edward Nafornita
; Date: January 19 2023
; ID: 110076381
; Description: Writing an assembly program to add two hexadecimal numbers then subtracts a value from the summation.

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    ; no data declarations here, using only mov/add/sub instructions to perform
    ;       (30000h + 20000h) - 10000h
.code
main PROC
	
	; code goes here
	mov		eax, 30000h	    ; initializing EAX to 30000h
	add		eax, 20000h		; adding 20000h to EAX
	sub     eax, 10000h	    ; subtracting 10000h from EAX
	call    DumpRegs        ; displays registers in console

	exit

main ENDP
END main
