TITLE Assignment4 Section2 Q2
; Name: Edward Nafornita
; Student ID: 110076381
; Comparing three unsigned integers

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
; edit this section to test the program
v1 WORD 2h
v2 WORD 1h
v3 WORD 3h

.code
main PROC
    ; setting eax, ebx and edx to zero for better accuracy
    mov eax, 0
    mov ebx, 0
    mov edx, 0

    mov ax, v1		; initialising ax with v1
    mov bx, v2		; initialising bx with v2
    mov dx, v3		; initialising dx with v3

    cmp ax, bx		; comparing ax and bx
    ja firstCon		; if ax > bx goto firstCon
    jbe secondCon		; if ax <= bx goto secondCon

    firstCon:		
        cmp bx, dx	; comparing bx and dx
        ja finalCon1	; if bx > dx goto finalCon1
        jbe finalCon2	; if bx <= dx goto finalCon2
    secondCon:	
        cmp ax, dx	; comparing ax and dx
        ja finalCon3	; if ax > dx goto finalCon3
        jbe endCon	; if ax <= dx goto endCon

    finalCon1:
        mov ax, dx	; set ax to v3
        jmp endCon	; goto end
    finalCon2:
        mov ax, bx	; set ax to v2
        jmp endCon	; goto end
    finalCon3:
        mov ax, dx	; set ax to v3
        jmp endCon	; goto end
    endCon:			; end the program if ax is the smallest element
    call DumpRegs
    exit
main ENDP
END main