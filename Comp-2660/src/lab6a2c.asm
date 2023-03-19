TITLE Lab 6 Activity 2 C
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: Conditionals

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
op1 sdword 10d
op2 sdword 20d
x sdword 30d
y sdword 40d
message1 byte "This is Routine1", 0
message2 byte "This is Routine2", 0
message3 byte "This is Routine3", 0

.code
main proc
    xor eax, eax
    xor ebx, ebx
    mov eax, op1
    mov ebx, x

    cmp eax, op2
    jne routine3
    jmp cond1

    cond1:
        cmp ebx, y
        jg routine1
    jmp routine2
    
    routine1:
        mov edx, offset message1
        call WriteString
    jmp endCon
    
    routine2:
        mov edx, offset message2
        call WriteString
    jmp endCon
    
    routine3:
        mov edx, offset message3
        call WriteString
    jmp endCon
    
    endCon:
    exit
main endp
end main