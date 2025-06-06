#include <stdint.h>
#include <stdbool.h>
#include "i2c.h" 

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/i2c.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"

#define MPU6050_ADDR 0x68

uint32_t gSysClock;  



static void delay_ms(uint32_t ms) {
    SysCtlDelay((gSysClock / 3 / 1000) * ms);
}

static void UART0_Init(void) {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0));
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTConfigSetExpClk(UART0_BASE, gSysClock, 9600,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    UARTEnable(UART0_BASE);
}

static void UART0_Print(const char *msg) {
    while (*msg) {
        UARTCharPut(UART0_BASE, *msg++);
    }
}

int main(void) {
    gSysClock = SysCtlClockFreqSet((SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);

    UART0_Init();
    I2C0_Init();

    UART0_Print("Booting...\r\n");

    delay_ms(100);
    I2C0_WriteRegister(MPU6050_ADDR, 0x6B, 0x00);  // Wake up sensor

    uint8_t id = I2C0_ReadRegister(MPU6050_ADDR, 0x75);  // WHO_AM_I

    if (id == 0x68) {
        UART0_Print("MPU6050 detected\r\n");
    } else {
        UART0_Print("MPU6050 not detected\r\n");
    }

    while (1) {
        delay_ms(500);
    }
}
