TITLE

; Hunter Mailloux   
; March 9th, 2023
; 110063485
; COMP-2660 Assignment 4 Question 3 

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    
	; data declarations go here

.code
main PROC
	; Example 1
	mov eax, 0
    mov al, 61h ; moving lowercase 'a' into AL
    mov bl, al     ; put AL into BL for later
    and bl, 11011111b ; convert BL to uppercase
    cmp bl, al     ; compare uppercase BL with AL (original AL)
    jne done      ; if they're not equal, skip to done since al is lowercase
    add al, 20h ; if they're equal, that means you need to add 20h to make al uppercase
    done:
        call DumpRegs ; al is still lowercase 'a' (61)

    ; Example 2
    mov eax, 0
    mov al, 41h ; moving uppercase A into al    
    mov bl, al     
    and bl, 11011111b
    cmp bl, al 
    jne done2
    add al, 20h
    done2:
        call DumpRegs ; al is now lowercase 'a' (61)

    ; Example 3
    mov eax, 0
    mov al, 52h ; moving uppercase R into al
    mov bl, al
    and bl, 11011111b
    cmp bl, al
    jne done3
    add al, 20h
    done3:
        call DumpRegs ; al is now lowercase 'r' (72)

	exit

main ENDP
END main
