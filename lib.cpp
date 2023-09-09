#include "lib.h"

bool compareGreaterIPv4(const ipv4_u &firstIP, const ipv4_u &secondIP)
{
    if (firstIP.byteView[0] > secondIP.byteView[0]) return true;
    if (firstIP.byteView[0] == secondIP.byteView[0]) {
        if (firstIP.byteView[1] > secondIP.byteView[1]) return true;
        if (firstIP.byteView[1] == secondIP.byteView[1]) {
            if (firstIP.byteView[2] > secondIP.byteView[2]) return true;
            if (firstIP.byteView[2] == secondIP.byteView[2]) {
                if (firstIP.byteView[3] > secondIP.byteView[3]) return true;
            }
        }
    }
    return false;
}

