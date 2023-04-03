TITLE Lab 6 Activity 2 F
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: Short-circuit evaluation

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
holdEAX DWORD ?
X DWORD ?
message4 byte "Enter the value for EAX: ", 0
message3 byte "Enter the value for EBX: ", 0
message2 byte "Enter the value for ECX: ", 0
message1 byte "Enter the value for EDX: ", 0

.code
main proc
    xor eax, eax                ; init eax with zero
    xor ebx, ebx                ; init ebx with zero
    xor ecx, ecx                ; init ecx with zero
    xor edx, edx                ; init edx with zero

    mov edx, offset message4    ; init edx with message2
    call WriteString            ; write message2 to stdout
    call ReadInt                ; wait for user to input a number
    mov holdEAX, eax            ; store EAX's value in a register
    call Crlf                   ; move cursor to next line

    mov edx, offset message3    ; init edx with message2
    call WriteString            ; write message2 to stdout
    call ReadInt                ; wait for user to input a number
    mov ebx, eax                ; set val1 to user input2
    call Crlf                   ; move cursor to next line
    
    mov edx, offset message2    ; init edx with message2
    call WriteString            ; write message2 to stdout
    call ReadInt                ; wait for user to input a number
    mov ecx, eax                ; set val1 to user input2
    call Crlf                   ; move cursor to next line
    
    mov edx, offset message1    ; init edx with message1
    call WriteString            ; write message1 to stdout
    call ReadInt                ; wait for user to input a number
    mov edx, eax                ; set ebx to user input
    call Crlf                   ; move cursor to next line

    mov eax, holdEAX            ; bring back EAX's value

    cmp edx, eax
    ja con1

    cmp ebx, ecx
    ja con2
    jmp con3

    con1:
        mov X, 1
        jmp endcon
    con2:
        cmp ebx, edx
        ja con1
    con3:
        mov X, 2
    endcon:
        mov eax, X
        call DumpRegs
    exit
    
main endp
end main