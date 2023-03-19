TITLE Lab 6 Activity 2 B
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: Comparison of two signed integers

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
op2 sdword ?
x sdword ?
message1 byte "Please enter a number: ", 0
message2 byte "Please enter another number: ", 0

.code
main proc
    xor eax, eax                ; init eax with zero
    mov edx, offset message1    ; init edx with message1
    call WriteString            ; write message1 to stdout
    call ReadInt                ; wait for user to input a number
    mov op2, eax                ; set op2 to user input
    call Crlf                   ; move cursor to next line
    mov edx, offset message2    ; init edx with message2
    call WriteString            ; write message2 to stdout
    call ReadInt                ; wait for user to input a number (EAX will be op1 here)
    call Crlf                   ; move cursor to next line

    cmp eax, op2                ; compare eax to op2 (i.e., comparing op1 and op2)
    je cond1                    ; if (op1 == op2) goto cond1
    jmp cond2                   ; else goto cond2

    cond1:                      ; if (op1 == op2)
        mov x, 1                ; set x to 1d
        jmp endCond             ; goto endCond
    cond2:                      ; if (op1 != op2)
        mov x, 2                ; set x to 2d
        jmp endCond             ; goto endCond
    endCond:                    
        xor eax, eax            ; init eax to zero
        mov eax, x              ; set eax to value of x
        call DumpRegs           ; display the values of the registers
    exit                        ; terminate the program
main endp
end main
