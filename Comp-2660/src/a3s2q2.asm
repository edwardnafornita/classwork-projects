TITLE A2 Section2 Q2
; Edward Nafornita
; Student ID: 110076381
; change text colours

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
message BYTE "Hello! This is A3Q2", 0

.code
main PROC
    mov ecx, 4                      ; initialise counter with the value 4
    mov eax, green                  ; we want the first text colour to be green
    call Clrscr                     ; clear the screen

    loopColours:
        call SetTextColor           ; invoke the function SetTextColor with the value in eax
        mov edx, offset message     ; initialise edx with the message
        call WriteString            ; write the message to the screen

        add eax, 5                  ; increment eax by 5 to produce a different colour
        call Crlf                   ; move the cursor to the next line
    loop loopColours                ; loop back to the top (this will happen 4 times due to ECX=4)

    mov eax, white                  ; we want to set text colour back to white
    call SetTextColor               ; invoke the function SetTextColour with the value in eax, now being white
    exit
main ENDP
END main
