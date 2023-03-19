TITLE Assignment4 Section2 Q3
; Name: Edward Nafornita
; Student ID: 110076381
; Converting uppercase characters to lowercase characters

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
message BYTE "Enter in a character: ", 0
resultMessage BYTE "Lowercase version of your character is: ", 0

.code
main PROC
    call ClrScr                     ; Clear the screen
    mov edx, offset message         ; get the prompt message
    call WriteString                ; write the prompt message
    call ReadChar                   ; read the character the user inputted
    call WriteChar                  ; write the character to the screen
    call Crlf                       ; move the cursor to the next line

    mov edx, offset resultMessage   ; get the result message
    call WriteString                ; write the result message
    or al, 20h                      ; convert to lowercase
    call WriteChar			; display the lowercase character

    call DumpRegs				; display the register values
    exit
main ENDP
END main