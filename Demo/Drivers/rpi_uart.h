#include "rpi_base.h"

#define RPI_UART_BASE		(RPI_BASE_ADDRESS + 0x20100)

typedef struct {
	volatile uint32_t UARTDR[1];
	volatile uint32_t UARTRSRECR[1];
	volatile uint32_t Reserved_1[4];
	volatile uint32_t UARTFR[1];
	volatile uint32_t UARTILPR[1];
	volatile uint32_t UARTIBRD[1];
	volatile uint32_t UARTFBRD[1];
	volatile uint32_t UARTLCRH[1];
	volatile uint32_t UARTCR[1];
	volatile uint32_t UARTIFLS[1];
	volatile uint32_t UARTIMSC[1];
	volatile uint32_t UARTRIS[1];
	volatile uint32_t UARTMIS[1];
	volatile uint32_t UARTDMACR[1];
	volatile uint32_t Reserved_2[9];
	volatile uint32_t UARTITIP[1];
	volatile uint32_t UARTITOP[1];
	volatile uint32_t UARTTDR[1];
} RPI_UART_t;
