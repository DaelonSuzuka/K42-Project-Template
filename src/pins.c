#include "pins.h"
#include "peripherals/pic_header.h"

/* ************************************************************************** */
/* [[[cog
    from codegen import fmt; import pins
    cog.outl(fmt(pins.pin_definitions()))
]]] */

// GPIO read functions
bool read_BUTTON_ONE_PIN(void) { return PORTAbits.RA0; }
bool read_BUTTON_TWO_PIN(void) { return PORTAbits.RA1; }

// Button stuff
// array of pointers to button reading functions
button_function_t buttonFunctions[NUMBER_OF_BUTTONS] = {
    read_BUTTON_ONE_PIN, //
    read_BUTTON_TWO_PIN, //
};

// GPIO write functions
// none

// GPIO direction functions
// none

// [[[end]]]

/* ************************************************************************** */
/* [[[cog
    from codegen import fmt; import pins
    cog.outl(fmt(pins.pins_init()))
]]] */

void pins_init(void) {
    // BUTTON_ONE_PIN
    TRISAbits.TRISA0 = 1;
    WPUAbits.WPUA0 = 1;

    // BUTTON_TWO_PIN
    TRISAbits.TRISA1 = 1;
    WPUAbits.WPUA1 = 1;

    // DEBUG_TX_PIN
    TRISBbits.TRISB0 = 0;

    // DEBUG_RX_PIN
    TRISBbits.TRISB1 = 1;
}
// [[[end]]]