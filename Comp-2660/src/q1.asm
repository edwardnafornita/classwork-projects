TITLE Assn2 Sec2 Q1

; Sarah Bellaire:
; Due February 3rd, 2023:
; 110076263: 
; This program calculates the first 7 fibonacci numbers using a loop and indirect 
; addressing using only 1 add instruction:

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
	fib_sequence BYTE 1, 1, 5 dup(0) ; first 7 fibonacci numbers
	fib1 BYTE 1 ; initial (n-1) sum
	fib2 BYTE 1 ; initial (n-2) sum

.code
main PROC
	xor ebx, ebx ; fib sum register = 0
	mov ecx, 5 ; loop counter register = 5 because we already have 1, 1
	mov eax, 2 ; sequence index register = 2
	
	top:
		mov bl, fib1 ; store (n-1) value to manipulate 
		add bl, fib2 ; add (n-2) value to (n-1) to get fib(n)
		mov dl, fib1 ; store now old (n-1) 
		mov fib2, dl ; old (n-1) is now (n-2)
		mov fib1, bl ; current value of fib(n) into fib (n-1)
		mov [fib_sequence + [eax]], bl ; store fib(n) into the array
		add eax, 1 ; index += 1 to move through fib_sequence

	loop top
	
	call DumpRegs ; displays registers in console

	exit

main ENDP
END main