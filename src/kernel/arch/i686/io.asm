

; Edits By Nishant And Aditya
global i686_outb
i686_outb:
    [bits 32]
    mov dx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret

global i686_inb
i686_inb:
    [bits 32]
    mov dx, [esp + 4]
    xor eax, eax
    in al, dx
    ret

global i686_Panic
i686_Panic:
    cli
    hlt

global i686_EnableInterrupts
i686_EnableInterrupts:
    sti
    ret

global i686_DisableInterrupts
i686_DisableInterrupts:
    cli
    ret


; Defining the function for creating an overflow
global haddPaar
haddPaar:
    ; Loading the largest number
    xor edx, edx
    mov eax, 0xFFFFFFFF; Load the value into the EAX register
    add eax, 1
    int 4   
    ret


; Defining the division by zero function for creating an interrupt
global subzero
subzero:
    xor edx, edx     ; Clear the EDX register (for the remainder)
    mov eax, 9       ; Set EAX to the dividend (9)
    mov ebx, 0       ; Set EBX to the divisor (4)
    div ebx          ; Divide EDX:EAX by EBX, quotient in EAX, remainder in EDX

    mov ebx, 1
    div ebx



    ret