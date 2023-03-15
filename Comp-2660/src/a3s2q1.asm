TITLE A3 Section2 Question 1
; Name: Edward Nafornita
; Student ID: 110076381
; Using library procedures to clear the screen, locate the cursor position, prompts for user input and displays a sum.

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
message BYTE "Enter the first number: ", 0
message2 BYTE "Enter the second number: ", 0

.code
main PROC
    call Clrscr                 ; clear the screen

    mov dh, 12                  ; set x position
    mov dl, 68                  ; set y position
    call Gotoxy                 ; move cursor to the x and y position defined previously
    
    mov edx, OFFSET message     ; initialise edx with the first message
    call WriteString            ; write the first message to the screen
    call Readint                ; wait for the user to input a number
    mov ebx, eax                ; store the number in another register
    
    mov dh, 13                  ; set x position
    mov dl, 68                  ; set y position
    call Gotoxy                 ; move cursor to the x and y position defined previously

    mov edx, OFFSET message2    ; initialise edx with the second message
    call WriteString            ; write the second message to the screen
    call Readint                ; wait for the user to input another number
    add eax, ebx                ; add the previous number with the first number

    call DumpRegs               ; display the register values
    exit
main ENDP
END main
