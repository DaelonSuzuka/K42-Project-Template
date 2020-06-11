#ifndef _PINS_H_
#define _PINS_H_

#include "peripherals/pps.h"
#include <stdbool.h>

/* ************************************************************************** */
/* [[[cog
    from codegen import pins, fmt
    cog.outl(fmt(pins.pin_declarations())) 
]]] */

// GPIO read functions
// none

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