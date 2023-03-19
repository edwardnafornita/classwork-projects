TITLE Lab 6 Activity 2 A
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: Comparison of two signed integers

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
var1 sdword 4
var2 sdword 3
var3 sdword ?
var4 sdword ?

.code
main proc
    mov eax, var1       ; init eax with value of var1
    cmp eax, var2       ; cmp eax with var2
    jle cond            ; if (EAX <= var2) i.e., var1 <= var2 goto cond
    jmp cond2           ; else goto cond2

    cond:               ; if (EAX <= var2) 
        mov var3, 10    ; set var3 to 10d
        jmp endCond     ; goto end
    cond2:              ; if (EAX > var2)
        mov var3, 6     ; set var3 to 6d
        mov var4, 7     ; set var4 to 7d
        jmp endCond     ; goto end

    endCond:            ; print values to see the comparison
        xor eax, eax    ; init eax to zero
        xor ebx, ebx    ; init ebx to zero
        mov eax, var3   ; set eax to var3
        mov ebx, var4   ; set ebx to var4
        call DumpRegs   ; display the values of the registers
    exit                ; terminate the program
main endp
end main
