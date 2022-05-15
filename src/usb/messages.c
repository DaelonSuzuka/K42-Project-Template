#include "messages.h"
#include "os/judi/hash.h"
#include "os/judi/message_id.h"
#include "os/json/json_print.h"
#include "os/serial_port.h"
#include "system.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* ************************************************************************** */


/* 
    // adfads

*/

#define HASH(number) buf->tokens[number].hash

void print_message_structure(json_buffer_t *buf) {
    usb_print("{\"debug\":\"");
    for (uint8_t i = 0; i < buf->tokensParsed; i++) {
        switch (buf->tokens[i].type) {
        case jsmn_undefined:
            usb_print("{");
            usb_print("undefined");
            usb_print("}");
            break;
        case jsmn_object:
            usb_print("{");
            usb_print("object");
            usb_print("}");
            break;
        case jsmn_array:
            usb_print("{");
            usb_print("array");
            usb_print("}");
            break;
        case jsmn_string:
            usb_print("{");
            usb_print(TOKEN(i));
            usb_print("}");
            break;
        case jsmn_primitive:
            usb_print("{");
            usb_print("primitive");
            usb_print("}");
            break;
        }
    }
    usb_print("\"}");
}

void respond(json_buffer_t *buf) {
    for (uint8_t i = 0; i < buf->tokensParsed; i++) {
        switch (HASH(i)) {
        case hash_request:
            switch (HASH(++i)) {
            case hash_device_info:
                add_nodes(updatePreamble);
                add_nodes(deviceInfo);
                print_message(usb_print);
                break;
            }
            break;

        case hash_command:
            break;
        }
    }
}
