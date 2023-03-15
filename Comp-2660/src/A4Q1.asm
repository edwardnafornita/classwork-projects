TITLE

; Hunter Mailloux 
; March 9th, 2023
; 110063485
; COMP-2660 Assignment 4 Question 1

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    
	; data declarations go here

.code
main PROC
	
	mov eax, 12345d; code goes here
	mov ebx, 67890d; you can swap around the values within eax and ebx
    cmp eax, ebx ; compare the 2 registers
    jbe smaller; if eax is less than or equal to ebx, just to smaller
    mov edx, eax ; if not, that means eax is the larger number
    jmp done ; jump to the end to avoid moving ebx into edx
    smaller:
        mov edx, ebx ; ebx is the larger number
    done:
	    call DumpRegs ; displays registers in console

	exit

main ENDP
END main
