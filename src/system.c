#include "system.h"
#include "os/serial_port.h"
#include "os/stopwatch.h"
#include "os/system_clock.h"
#include "peripherals/device_information.h"
#include "peripherals/interrupt.h"
#include "peripherals/oscillator.h"
#include "peripherals/pic_header.h"
#include "peripherals/ports.h"
#include "peripherals/pps.h"
#include "peripherals/uart.h"
#include "pins.h"

/* ************************************************************************** */

static void system_init(void) {
    internal_oscillator_init();
    interrupt_init();
    port_init();
    pins_init();
    device_information_init();
}

static void OS_init(void) {
    uart_config_t config = UART_get_config(2);
    config.baud = _115200;
    config.txPin = PPS_DEBUG_TX_PIN;
    config.rxPin = PPS_DEBUG_RX_PIN;
    serial_port_init(UART_init(config));

    system_clock_init();
    stopwatch_init();
}

static void application_init(void) {
    // init functions for your modules go here
}

/* ************************************************************************** */

void startup(void) {
    system_init();
    OS_init();

    application_init();

    // Lock the Peripheral Pin Select before proceeding to application code
    pps_lock();
}