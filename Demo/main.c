#include <FreeRTOS.h>
#include <task.h>
#include <string.h>

#include "Drivers/rpi_gpio.h"
#include "Drivers/rpi_irq.h"
#include "Drivers/rpi_mini_uart.h"
#include "Drivers/rpi_interrupt.h"

const TickType_t xDelay = 500 * portTICK_PERIOD_MS;

char sz[4] = {'A', 'a', '\r', '\n'};

void task1(void *pParam) {
	int i = 0;
	while(1) {
		i++;
		hexstring(0x01);
		vTaskDelay(xDelay);

	}
}

void task2(void *pParam) {
	int i = 0;
	while(1) {
		i++;
		vTaskDelay(xDelay/2);
		rpi_gpio_set_val(47, 0);
		rpi_gpio_set_val(35, 1);
		vTaskDelay(xDelay/2);
		hexstring(0x02);
	}
}


/**
 *	This is the systems main entry, some call it a boot thread.
 *
 *	-- Absolutely nothing wrong with this being called main(), just it doesn't have
 *	-- the same prototype as you'd see in a linux program.
 **/
int main(void) {

	rpi_cpu_irq_disable();

	rpi_uart_init();
	rpi_gpio_sel_fun(47, 1);			// RDY led
	rpi_gpio_sel_fun(35, 1);			// RDY led

	xTaskCreate(task1, "LED_0", 128, NULL, 0, NULL);
	xTaskCreate(task2, "LED_1", 128, NULL, 0, NULL);

	vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1) {
		;
	}
}

