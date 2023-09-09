#define BOOST_TEST_MODULE test_version

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    ipv4_u firstIP;
    firstIP.byteView[0] =  1;
    firstIP.byteView[1] =  2;
    firstIP.byteView[2] =  3;
    firstIP.byteView[3] =  4;
    ipv4_u secondIP;
    secondIP.byteView[0] = 1;
    secondIP.byteView[1] = 2;
    secondIP.byteView[2] = 3;
    secondIP.byteView[3] = 5;
    BOOST_CHECK(compareGreaterIPv4(firstIP, secondIP) == false);
    BOOST_CHECK(compareGreaterIPv4(secondIP, firstIP) == true);
    BOOST_CHECK(compareGreaterIPv4(secondIP, secondIP) == false);
}

BOOST_AUTO_TEST_SUITE_END()
