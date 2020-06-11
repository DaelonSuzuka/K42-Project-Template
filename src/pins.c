#include "pins.h"
#include "peripherals/pic_header.h"

/* ************************************************************************** */
/* [[[cog
    from codegen import pins, fmt
    cog.outl(fmt(pins.pin_definitions())) 
]]] */

// GPIO read functions
// none

// GPIO write functions
// none

// [[[end]]]

/* ************************************************************************** */
/* [[[cog
    from codegen import pins, fmt
    cog.outl(fmt(pins.pins_init())) 
]]] */

void pins_init(void) {
  // DEBUG_TX_PIN
  TRISBbits.TRISB0 = 0;

  // DEBUG_RX_PIN
  TRISBbits.TRISB1 = 1;
}
// [[[end]]]