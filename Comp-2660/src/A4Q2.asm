TITLE

; Hunter Mailloux
; March 9th, 2023
; 110063485
; COMP-2660 Assignment 4 Question 2

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
	v1 WORD 1100110010101010b; data declarations go here
    v2 WORD 1b
    v3 WORD 1111111111111110b

.code
main PROC
	mov eax, 0
    mov ebx, 0
    mov bx, v1
	cmp bx, v2 ; comparing v1 and v2
    jbe first ; if v1 is lower, jump to first to then compare v1 and v3
    mov bx, v2 ; if v1 is not lower, mov v2 to bx
    cmp bx, v3 ; comparing v2 and v3
    jbe veetwo ; if v2 is lower, jump to veetwo
    jmp veethree ; if v2 is greater, jump to veethree

    first:
        cmp bx, v3 ; comparing v1 and v3
        jbe veeone ; if v1 is lower, jump to veeone
        jmp veethree ; if v1 is greater, jump to veethree

    veeone:
        mov ax, v1 ; v1 is lowest
        jmp done
    veetwo:
        mov ax, v2 ; v2 is lowest
        jmp done
    veethree:
        mov ax, v3 ; v3 is lowest
    done:
	    call DumpRegs ; displays registers in console

	exit

main ENDP
END main
