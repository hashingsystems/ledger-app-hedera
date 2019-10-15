#pragma once

#include <stddef.h>
#include <stdint.h>

// The APDU protocol uses a single-byte instruction code (INS) to specify
// which command should be executed. We'll use this code to dispatch on a
// table of function pointers.

#define INS_GET_APP_CONFIGURATION 0x01
#define INS_GET_PUBLIC_KEY 0x02
#define INS_SIGN_TRANSACTION 0x03

typedef void handler_fn_t(
    uint8_t p1,
    uint8_t p2,
    uint8_t* buffer,
    uint16_t len,
    /* out */ volatile unsigned int* flags,
    /* out */ volatile unsigned int* tx
);

extern handler_fn_t handle_get_app_configuration;
extern handler_fn_t handle_get_public_key;
extern handler_fn_t handle_sign_transaction;

extern handler_fn_t* lookup_handler(uint8_t ins);