#ifndef _PINS_H_
#define _PINS_H_

#include "peripherals/pps.h"
#include <stdbool.h>

/* ************************************************************************** */
/* [[[cog
    from codegen import fmt; import pins
    cog.outl(fmt(pins.pin_declarations()))
]]] */

// GPIO read functions
extern bool read_BUTTON_ONE_PIN(void);
extern bool read_BUTTON_TWO_PIN(void);

// Button stuff
#define NUMBER_OF_BUTTONS 2

// array of pointers to button reading functions
typedef bool (*button_function_t)(void);
extern button_function_t buttonFunctions[NUMBER_OF_BUTTONS];

// enum of button names
enum {
    ONE,
    TWO,
} button_names;

// GPIO write functions
// none

// PPS initialization macros
#define PPS_DEBUG_TX_PIN PPS_OUTPUT(B, 0)
#define PPS_DEBUG_RX_PIN PPS_INPUT(B, 1)

// ADC Channel Select macros
// none

// [[[end]]]

/* ************************************************************************** */

extern void pins_init(void);

#endif /* _PINS_H_ */