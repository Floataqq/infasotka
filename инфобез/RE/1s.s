%include "io.inc"

SECTION .text

GLOBAL CMAIN
CMAIN:
	GET_UDEC 4, EAX

	MOV EBX, EAX
	DEC EBX
	XOR EAX, EBX
	ADD EAX, 1
	RCR EAX, 1

	PRINT_UDEC 4, EAX
	NEWLINE

	XOR EAX, EAX
	RET
