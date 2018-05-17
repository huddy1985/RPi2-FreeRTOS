#include "rpi_interrupt.h"

static INTERRUPT_VECTOR g_VectorTable[BCM2835_INTC_TOTAL_IRQ];

__attribute__((no_instrument_function))
static void irqDisable()
{
   __asm volatile("cpsid i" : : : "memory");
}

/**
 *  *| Enables all IRQ's in the CPU's CPSR register.
 *   **/
__attribute__((no_instrument_function))
static void irqEnable()
{
__asm volatile("cpsie i" : : : "memory");
}


__attribute__((no_instrument_function))
int RegisterInterrupt(int nIRQ, FN_INTERRUPT_HANDLER pfnHandler, void *pParam) 
{
   if(nIRQ<0 || nIRQ>71)
      	return -1;

   irqDisable();
   {
	 	g_VectorTable[nIRQ].pfnHandler = pfnHandler;
      	g_VectorTable[nIRQ].pParam    = pParam;
   }
   irqEnable();
   return 0;
}


__attribute__((no_instrument_function))
int EnableInterrupt(int nIRQ)
{
	/* Datasheet says "All other bits are unaffected", and I'm counting on that. */
   unsigned int mask=1<<(nIRQ%32);
   if(nIRQ >=0 && nIRQ <=31) {
	   pRegs->Enable1 = mask;
	} else if(nIRQ >=32 && nIRQ <=63){
		pRegs->Enable2 = mask;
	} else if(nIRQ >= 64 && nIRQ <= 71) { // Basic IRQ enables
		pRegs->EnableBasic = mask;
	} else
	   return -1;
	return 0;
}	

