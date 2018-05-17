/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Derived from many drivers using generic_serial interface.
 *
 * Copyright (C) 2015 xuguo.wong <xuguo.wong@gmail.com>
 *
 * Serial driver for BCM2835 mini UART.
 *
 * Hardware flow control, Console support not implimented. Works only with
 * 115200 8N1 configuration. 
 */

#ifndef __RPI_RAW_IO_H__
#define __RPI_RAW_IO_H__

unsigned int __raw_readl(unsigned int addr);
void __raw_writel(unsigned int value, unsigned int addr);

#endif
