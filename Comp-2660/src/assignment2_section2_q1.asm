TITLE Assignment2 Section2 Question1
; Name: Edward Nafornita
; Student ID: 110076381
; Find the first seven fibonacci numbers

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    ; Fibonacci numbers generated will be 1,1,2,3,5,8,14 
    fibNums BYTE 1h, 1h, 0h, 0h, 0h, 0h, 0h

.code
main PROC
    mov eax, 0h                 ; reset EAX register to 0
    mov ecx, 5h                 ; set ECX to 5 as we want to loop 5 times

    mov esi, OFFSET fibNums     ; initialise ESI to the address of the first number in the array

    ; loop
    l1:
        mov eax, [esi]          ; set EAX to the first value of the array
        add eax, [esi + 1]      ; adding the second value in the array to EAX register
        mov [esi + 2], eax      ; indirectly storing the addition of the two values into the array
        inc esi                 ; moving the ESI pointer to the next element in the array
    loop l1

    mov eax, 0h                 ; resetting the EAX register to remove garbage values
    mov al, [fibNums + 6]       ; setting AL to the final value in the array so that the final value in the array is displayed well
    
    call DumpRegs               ; displaying the register values
    exit
main ENDP
END main
