TITLE Assignment2 Section2 Question3
; Name: Edward Nafornita
; Student ID: 110076381
; Summing up all values in an array

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    arr DWORD 10000h, 20000h, 30000h, 40000h
    i BYTE 1h
    result DWORD ?
    
.code
main PROC
    mov ecx, 4              ; 4 elements in arr, loop 4 times to sum up all values
    mov eax, 0              ; initialising EAX to zero for better clarity
    mov esi, OFFSET arr     ; setting ESI to first value in the Array 'arr'

    ; loop to access array elements and add them together
    loop1:
       add eax, [esi]       ; add value of ESI to EAX
       add esi, 4           ; move pointer to next value in arr
    loop loop1              ; loop until all values are summed together
       
    mov result, eax         ; setting the final value of EAX to result
    call DumpRegs
    exit
main ENDP
END main
