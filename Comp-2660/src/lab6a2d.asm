TITLE Lab 6 Activity 2 D
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: While loop logic

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
val1 sdword ?
message1 byte "Please enter a number: ", 0
message2 byte "Please enter another number: ", 0

.code
main proc
    xor eax, eax                ; init eax with zero
    xor ebx, ebx                ; init ebx with zero
    mov edx, offset message1    ; init edx with message1
    call WriteString            ; write message1 to stdout
    call ReadInt                ; wait for user to input a number
    mov ebx, eax                ; set ebx to user input
    call Crlf                   ; move cursor to next line
    mov edx, offset message2    ; init edx with message2
    call WriteString            ; write message2 to stdout
    call ReadInt                ; wait for user to input a number
    mov val1, eax               ; set val1 to user input2
    call Crlf                   ; move cursor to next line

    whileLoop:
        add ebx, 5d             ; add 5d to EAX
        dec val1                ; decrement val1
        mov eax, val1           ; update EAX with the value of val1
        cmp ebx, val1           ; compare ebx to val1
    jle whileLoop               ; if (ebx <= val1) goto whileLoop
    
    call DumpRegs               ; display values in registers
    exit
main endp
end main