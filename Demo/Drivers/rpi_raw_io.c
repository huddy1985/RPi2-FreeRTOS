#include "rpi_raw_io.h"

extern void PUT32(unsigned int, unsigned int);
extern void PUT16 ( unsigned int, unsigned int );
extern void PUT8 ( unsigned int, unsigned int );
extern unsigned int GET32(unsigned int);

unsigned int __raw_readl(unsigned int addr)
{
	return GET32(addr);
}

void __raw_writel(unsigned int value, unsigned int addr)
{
	PUT32(addr, value);
}
