cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(fmt REQUIRED)

add_executable(ip_filter main.cpp)
add_library(ipv4filter lib.cpp)
add_executable(test_ipfilter test_ipfilter.cpp)

set_target_properties(ip_filter ipv4filter test_ipfilter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(ipv4filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(test_ipfilter PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)


target_link_libraries(ipv4filter PRIVATE
    fmt
)
target_link_libraries(ip_filter PRIVATE
    ipv4filter
    fmt
)
target_link_libraries(test_ipfilter
    ${Boost_LIBRARIES}
    ipv4filter
)

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
    target_compile_options(ipv4filter PRIVATE
        /W4
    )
    target_compile_options(test_ipfilter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(ipv4filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_ipfilter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_ipfilter test_ipfilter)
