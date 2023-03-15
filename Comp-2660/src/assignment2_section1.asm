TITLE Section1

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    var1 SBYTE -4, -2, 3, 1
    var2 WORD 1000h, 2000h, 3000h, 4000h
    var3 SWORD -16, -42
    var4 DWORD 1, 2, 3, 4, 5

.code
main PROC
    ;question 1
    ;mov ax, var1
    ;mov ax, var2 - this line works
    ;mov eax, var3
    ;mov var2, var3
    ;movzx ax, var2
    ;movzx var2, al
    ;mov ds, ax - this line works
    ;mov ds, 1000h

    ;question 2
    ;mov eax, 0h
    ;mov al, var1 - hexadecimal value is FC
    ;mov ah, [var1 + 3] - hexadecimal value is 100h, after both lines value is 1FC
    
    ; question 3
    ;mov ax, var2
    ;mov ax, [var2 + 4]

    ;question 4
    mov edx, 0h
    mov edx, var4
    movzx edx, var2
    mov edx, [var4 + 4]
    movsx edx, var1
    call DumpRegs
    exit
main ENDP
END main
