; we will now write an assembly program to perform the following
;   expression: Rval = -Xval + (Yval + Zval);

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    Rval SDWORD ?
    Xval SDWORD 26
    Yval SDWORD 30
    Zval SDWORD 40

.code
    main PROC
        mov eax, Xval
        neg eax
        mov ebx, Yval
        sub ebx, Zval
        add eax, ebx
        mov Rval, eax
        exit
    main ENDP
END main