#ifndef __RPI_INTERRUPT_H__
#define __RPI_INTERRUPT_H__

#define BCM2835_INTC_TOTAL_IRQ		(64 + 8)
#define BCM2835_BASE_INTC			(0x3f00B200)

typedef struct {
	unsigned long  IRQBasic;  // Pending 0
	unsigned long  Pending1;
	unsigned long  Pending2;
	unsigned long  FIQCtrl;
	unsigned long  Enable1;
	unsigned long  Enable2;
	unsigned long  EnableBasic;
	unsigned long  Disable1;
	unsigned long  Disable2;
	unsigned long  DisableBasic;
} BCM2835_INTC_REGS;

static volatile BCM2835_INTC_REGS * const pRegs = (BCM2835_INTC_REGS *) (BCM2835_BASE_INTC);

typedef void (*FN_INTERRUPT_HANDLER)(int nIRQ, void *pParam);

typedef struct {
	FN_INTERRUPT_HANDLER pfnHandler; ///< Function that handles this IRQn
	void *pParam; ///< A special parameter that the use can pass to the IRQ.
} INTERRUPT_VECTOR;

__attribute__((no_instrument_function))
int RegisterInterrupt(int nIRQ, FN_INTERRUPT_HANDLER pfnHandler, void *pParam);

__attribute__((no_instrument_function))
int EnableInterrupt(int nIRQ);

#endif
