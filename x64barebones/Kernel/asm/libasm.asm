GLOBAL cpuVendor
;GLOBAL getRTC
GLOBAL getSeconds
GLOBAL getMinutes
GLOBAL getHours
;GLOBAL getDays
;GLOBAL getMonth
;GLOBAL getYears
GLOBAL keyPressed
;GLOBAL keyboardActivated
;GLOBAL getPressedKey
;GLOBAL getRegInfo
;GLOBAL getSP
;EXTERN inforeg

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

;getRTC:
;	cli
;	mov al, 0x0B
;	out 70h, al
;	in al, 71h
;	or al, 4
;	out 71h, al
;
;	mov rax, rdi
;
;	out 70h, al
;	in al, 71h
;
;	sti
;	ret

getSeconds:
	push rbp
	mov rbp, rsp

	mov al, 0
	out 70h, al
	in al, 71h

	mov rsp, rbp
	pop rbp
	ret

getMinutes:
	push rbp
	mov rbp, rsp

	mov al, 0x02
	out 70h, al
	in al, 71h

	mov rsp, rbp
	pop rbp
	ret

getHours:
	push rbp
	mov rbp, rsp

	mov al, 0x04
	out 70h, al
	in al, 71h
	;sub al, 0x03 		;para el GMT-3

	mov rsp, rbp
	pop rbp
	ret

;getDays:
;	push rbp
;	mov rbp, rsp
;
;	mov al, 0x07
;	out 70h, al
;	in al, 71h
;
;	mov rsp, rbp
;	pop rbp
;	ret

;getMonth:
;	push rbp
;	mov rbp, rsp
;
;	mov al, 0x08
;	out 70h, al
;	in al, 71h
;
;	mov rsp, rbp
;	pop rbp
;	ret

;getYears:
;	push rbp
;	mov rbp, rsp
;
;	mov al, 0x09
;	out 70h, al
;	in al, 71h
;
;	mov rsp, rbp
;	pop rbp
;	ret

keyPressed:
	push rbp
	mov rbp, rsp

.loop:
    in al, 64h           ; Leer el registro de estado del controlador de teclado
    test al, 1           ; Comprobar si el bit 0 está en 1
    jz .loop             ; Esperar si no hay tecla disponible para leer

	in al, 60h           ; Leer la tecla del puerto de datos del controlador de teclado

	mov rsp, rbp
	pop rbp
	ret

;keyboardActivated:
;	mov rax, 0
;	in al, 64h
;	and al, 01h
;	ret

;getPressedKey:
;	mov rax, 0
;	in al, 60h
;	ret

;getRegInfo:
;    mov [buffer], rax                    ; Copiamos cada registro en el
;    mov [buffer + 1*8], rbx                ; buffer, para luego imprimirlos
;    mov [buffer + 2*8], rcx                ; llamando a la funcion de C
;    mov [buffer + 3*8], rdx                ; 'inforeg'. La misma se encuentra
;    mov [buffer + 4*8], rsi                ; en memory.c
;    mov [buffer + 5*8], rdi
;    mov [buffer + 6*8], rsp
;    mov [buffer + 7*8], r8
;    mov [buffer + 8*8], r9
;    mov [buffer + 9*8], r10
;    mov [buffer + 10*8], r11
;    mov [buffer + 11*8], r12
;    mov [buffer + 12*8], r13
;    mov [buffer + 13*8], r14
;    mov [buffer + 14*8], r15
;
;    mov rax, [rsp] ; RIP.
;    mov [buffer + 15*8], rax
;
;    mov rdi, buffer
;    call inforeg
;
;    ret

;getSP:
;    mov rax, rsp
;    ret

;section .bss
;	buffer: resb 128
