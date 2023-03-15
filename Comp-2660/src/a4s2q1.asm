TITLE Assignment4 Section2 Q1
; Name: Edward Nafornita
; Student ID: 110076381
; Comparing two unsigned integers

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
; edit this section to test the program
smallerValue DWORD 18h
biggerValue DWORD 21h

.code
main PROC
    ; setting eax, ebx and edx to zero for better accuracy
    mov eax, 0
    mov ebx, 0
    mov edx, 0

    mov eax, smallerValue         ; initialising eax with the value 21
    mov ebx, biggerValue          ; initialising ebx with the value 18
    cmp eax, ebx                  ; comparing if eax is greater than ebx
    ja cond1                      ; EAX > EBX goto Con1
    jbe cond2                     ; EAX <= EBX goto Con2

    ; updating edx with the largest value based on two conditions
    cond1:                        ; EAX > EBX
        mov edx, eax
        jmp endcon                ; goto end
    cond2:                        ; EAX < EBX
        mov edx, eax
        jmp endcon                ; goto end

    endcon:
        call DumpRegs             ; display the flags and values
    exit
main ENDP
END main