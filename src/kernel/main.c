// Edits by : Aditya, Rishabh, Senan and Nishant


//  Improvising the main.c for handling and creating interrupts
//  It now returns the state of the cpu after interrupt calls being handled

#include <stdint.h>
#include "stdio.h"
#include "memory.h"
#include <hal/hal.h>
#include <arch/i686/irq.h>
extern uint8_t __bss_start;
extern uint8_t __end;

void subzero();

void haddPaar();



//  Comment by :  Rishabh and Nishant
// Creating the printlion user-defined interrupt handler
void printLion(){
// Printing a lion on every call of the user-defined interrupt

    printf("    ,aodObo,\n");
    printf("        ,AMMMMP~~~~\n");
    printf("     ,MMMMMMMMA.\n");
    printf("   ,M;'     `YV'\n");
    printf("  AM' ,OMA,\n");
    printf(" AM|   `~VMM,.      .,ama,____,amma,..\n");
    printf(" MML      )MMMD   .AMMMMMMMMMMMMMMMMMMD.\n");
    printf(" VMMM    .AMMY'  ,AMMMMMMMMMMMMMMMMMMMMD\n");
    printf(" `VMM, AMMMV'  ,AMMMMMMMMMMMMMMMMMMMMMMM,                ,\n");
    printf("  VMMMmMMV'  ,AMY~~''  'MMMMMMMMMMMM' '~~             ,aMM\n");
    printf("  `YMMMM'   AMM'        `VMMMMMMMMP'_              A,aMMMM\n");
    printf("   AMMM'    VMMA. YVmmmMMMMMMMMMMML MmmmY          MMMMMMM\n");
    printf("  ,AMMA   _,HMMMMmdMMMMMMMMMMMMMMMML`VMV'         ,MMMMMMM\n");
    printf(" AMMMA _'MMMMMMMMMMMMMMMMMMMMMMMMMMA `'          MMMMMMMM\n");
    printf(" ,AMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMa      ,,,   `MMMMMMM\n");
    printf(" AMMMMMMMMM'~`YMMMMMMMMMMMMMMMMMMMMMMA    ,AMMV    MMMMMMM\n");
    printf(" VMV MMMMMV   `YMMMMMMMMMMMMMMMMMMMMMY   `VMMY'  adMMMMMMM\n");
    printf(" `V  MMMM'      `YMMMMMMMV.~~~~~~~~~,aado,`V''   MMMMMMMMM\n");
    printf("    aMMMMmv       `YMMMMMMMm,    ,/AMMMMMA,      YMMMMMMMM\n");
    printf("    VMMMMM,,v       YMMMMMMMMMo oMMMMMMMMM'    a, YMMMMMMM\n");
    printf("    `YMMMMMY'       `YMMMMMMMY' `YMMMMMMMY     MMmMMMMMMMM\n");
    printf("     AMMMMM  ,        ~~~~~,aooooa,~~~~~~      MMMMMMMMMMM\n");
    printf("       YMMMb,d'         dMMMMMMMMMMMMMD,   a,, AMMMMMMMMMM\n");
    printf("        YMMMMM, A       YMMMMMMMMMMMMMY   ,MMMMMMMMMMMMMMM\n");
    printf("       AMMMMMMMMM        `~~~~'  `~~~~'   AMMMMMMMMMMMMMMM\n");
    printf("       `VMMMMMM'  ,A,                  ,,AMMMMMMMMMMMMMMMM\n");
    printf("     ,AMMMMMMMMMMMMMMA,       ,aAMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("   ,AMMMMMMMMMMMMMMMMMMA,    AMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf(" ,AMMMMMMMMMMMMMMMMMMMMMA   AMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("AMMMMMMMMMMMMMMMMMMMMMMMMAaAMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("Handling MARN Interrupt\n");


    // Completed the function for handling user-defined interrupt
    // Final Edit by : Nishant

}











// Edit By : Aditya and Nishant

//  Creating the Overflow Interrupt handler
// Input arguments as regs
void Overflow(Registers* regs){
    // Output to the screen
    printf("Overflow exception \n");
    printf("Value in Register eax %u \n",regs->eax);
    // Printing the output registers for clarity and confirmation.
    regs->eax=0xffffffff;
    // Changing the values in the registers as a part of handling the interrupt scenario.
    printf("Interrupt handled as follows: \n");
    printf("Updated value in the register eax is now set to %u \n",regs->eax);
    
    


}
// Edit by Nishant
// Creating setBitNumber for Utility

int setBitNumber(int n)
{
    if (n == 0)
        return 0;
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
    return ( 32 - msb)/4;
}

// Edit By Aditya and Senan
void divByZero(Registers* regs)
{

    // Divide by zero error handler.
    uint32_t num2 = regs->eax;
    uint32_t num1 = regs->edx;
    // Getting the register values
    int k = setBitNumber(num2);
    char arr[256];
    // Searching for the '0' character
    for(int i=0;i<k;i++){
        arr[i]='0';
    }
    arr[k]='\0';
    // Handling the case
    // uint32_t numerator = regs->ds;
    printf("Division by zero error: Numerator = 0x%x%s%x\n", num1,arr, num2);
    // Creating an error yet again as a part of handling.
    regs->ebx = 2;
    regs->edx = 0;
    printf("Handled this error.\n ");
    // Returning  
    return ;
    // Final Edits: Rishabh and Nishant
    
}


// Comment By : Aditya
// Using the timer handler to create desired output 
// for every single call of the timer interrupt!

void timer(Registers* regs){
    printf(".");
    return;
}
// Adding comments: Aditya and Nishant

// Creating the Keyboard Interrupt: Defining the interrupt handler
void keyboard(Registers* regs) {
    printf("MARN -- Keyboard Interrupt");
    printf(".");
}

// Edit by : Senan and Rishabh
// entering the terminal/main screen
void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));
    // HAL initialization
    HAL_Initialize();
    // Clearing screen for convenience
    clrscr();
    // First output
    printf("Welcome to MARN OS!\n");
    // Calling the interrupts and handlers
    i686_ISR_RegisterHandler(0, divByZero);
    
    // i686_ISR_RegisterHandler(4, Overflow);
    i686_ISR_RegisterHandler(48, printLion);

    i686_IRQ_RegisterHandler(0,timer);
    i686_IRQ_RegisterHandler(1,keyboard);

    // __asm("int $0x30");
    // subzero();
    // haddPaar();


    
end:
    for (;;);
}
