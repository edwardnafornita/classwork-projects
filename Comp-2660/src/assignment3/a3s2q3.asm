TITLE A2 Section2 Q3
; Edward Nafornita
; Student ID: 110076381
; loop through an array and display the summation of all elements in the array.

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
arr1 DWORD 5 DUP(1)        ; initialise an array of 5 elements which are double words, each containing the value 1

.code
main PROC
    mov esi, offset arr1   ; set esi to start of array
    mov ecx, 5             ; 5 elements in array, therefore, loop should run 5 times
    push esi               ; put esi on the stack
    push ecx               ; put ecx on the stack
    mov eax, 0             ; initialise eax to zero

    loop1: 
        add eax, [esi]     ; add the current value in esi to eax
        add esi, 4         ; move esi to next position in array
        dec ecx            ; decrement loop counter
        cmp ecx, 0         ; is loop counter 0?
    ja loop1               ; if not then loop back to start of loop

    pop ecx                ; remove ecx from the stack
    pop esi                ; remove esi from the stack

    call DumpRegs          ; display register values
    exit
main ENDP
END main
