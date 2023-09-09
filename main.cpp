#include "lib.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>

#define FMT_ENFORCE_COMPILE_STRING
#include <fmt/format.h>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}


int main()
{
    try
    {
        std::vector<ipv4_u> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            v = split(v.at(0), '.');
            ipv4_u ip;
            ip.byteView[0] = std::atoi(v[0].c_str());
            ip.byteView[1] = std::atoi(v[1].c_str());
            ip.byteView[2] = std::atoi(v[2].c_str());
            ip.byteView[3] = std::atoi(v[3].c_str());
            ip_pool.emplace_back(ip);
        }

        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(), ip_pool.end(), compareGreaterIPv4);
        

        for(const auto & ip : ip_pool) 
        {
            std::cout << fmt::format(FMT_STRING("{}.{}.{}.{}"), ip.byteView[0], ip.byteView[1], ip.byteView[2], ip.byteView[3]) << std::endl;
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output   
        // ip = filter(1)
        for(const auto & ip : ip_pool) 
        {
            if (ip.byteView[0] == 1){
                std::cout << fmt::format(FMT_STRING("{}.{}.{}.{}"), ip.byteView[0], ip.byteView[1], ip.byteView[2], ip.byteView[3]) << std::endl;
            }
        }

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
        for(const auto & ip : ip_pool) 
        {
            if (ip.byteView[0] == 46 && ip.byteView[1] == 70){
                std::cout << fmt::format(FMT_STRING("{}.{}.{}.{}"), ip.byteView[0], ip.byteView[1], ip.byteView[2], ip.byteView[3]) << std::endl;
            }
        }


        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)
        for(const auto & ip : ip_pool) 
        {
            #define BYTE_VALUE_TO_FIND 46 
            if (ip.byteView[0] == BYTE_VALUE_TO_FIND || ip.byteView[1] == BYTE_VALUE_TO_FIND || ip.byteView[2] == BYTE_VALUE_TO_FIND || ip.byteView[3] == BYTE_VALUE_TO_FIND){
                std::cout << fmt::format(FMT_STRING("{}.{}.{}.{}"), ip.byteView[0], ip.byteView[1], ip.byteView[2], ip.byteView[3]) << std::endl;
            }
        }

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
