TITLE Assignment2 Section2 Question2
; Name: Edward Nafornita
; Student ID: 110076381
; Declaring datatypes in data section

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    byteDatatype BYTE 1
    sByteDatatype SBYTE -7
    wordDatatype WORD 1000
    sWordDatatype SWORD -2000
    dWordDatype DWORD 70000000
    sDWordDatatype SDWORD -80000000
    qWordDatatype QWORD 1000000020000000

.code
main PROC
    
    call DumpRegs
    exit
main ENDP
END main
