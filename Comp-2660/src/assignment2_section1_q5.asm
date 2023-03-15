TITLE Section1Q5

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    val1 BYTE 10h
    val2 WORD 8000h
    val3 DWORD 0FFFFh
    val4 WORD 7FFFh

.code
main PROC
    mov eax, 0h
    mov ebx, 0h
    ;instruction to increment val2
    ;mov ax, val2
    ;inc ax
    ;mov val2, ax
    ; or can just increment the variable through this other instruction
    ;inc val2

    ;instruction to subtract val3 from EAX
    ;sub eax, val3
    
    ;instruction to subtract val4 from val2
    ;mov bx, val2
    ;sub bx, val4

    ;increment through ADD instruction
    ; Incrementing val2 you get CF=0 and SF=1
    ; Incrementing val4 you get OF=1 and SF=1
    ;mov ax, val2
    ;add ax, 1h
    ;mov bx, val4
    ;add bx, 1h
    
    call DumpRegs
    exit
main ENDP
END main
