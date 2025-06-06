#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "uart.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"

extern uint32_t gSysClock;

void UART0_Init(void) {
    // Enable UART0 and GPIOA
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0) ||
           !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    // Configure PA0 and PA1 for UART
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Configure UART: 9600 baud, 8N1
		UARTConfigSetExpClk(UART0_BASE, gSysClock, 9600, UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE);

    UARTEnable(UART0_BASE);
}

void UART0_Print(const char *msg) {
    while (*msg) {
        UARTCharPut(UART0_BASE, *msg++);
    }
}

void UART0_PrintInt(int32_t num) {
    char buf[12];
    snprintf(buf, sizeof(buf), "%d", num);
    UART0_Print(buf);
}

void UART0_PrintLn(void) {
    UART0_Print("\r\n");
}
