#pragma once

#include <stdint.h>
#include <vector>

union ipv4_u
{
    uint32_t fullView;
    uint8_t  byteView[4];
};

bool compareGreaterIPv4(const ipv4_u &, const ipv4_u &);
