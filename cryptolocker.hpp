#pragma once

#include <string>
#include <vector>
#include <iostream>

typedef unsigned long long int64;

class Cryptolocker {
public:
    Cryptolocker(int64 year, int64 month, int64 day):
        year(year), month(month), day(day)
    {
    }

    void
    generate_domain(int length=32)
    {
        std::string domain;
        for (int i = 0; i < length; i++) {
            year = ((year ^ 8 * year) >> 11) ^ ((year & 0xFFFFFFF0) << 17);
            month = ((month ^ 4 * month) >> 25) ^ 16 * (month & 0xFFFFFFF8);
            day = ((day ^ (day << 13)) >> 19) ^ ((day & 0xFFFFFFFE) << 12);
            unsigned char a = ((year ^ month ^ day) % 25) + 97 ;
            char buf[2] = {'\0'};
            sprintf(buf, "%c", a); 
            domain += std::string(buf);
        }
        std::cout << domain << std::endl;
    }
private:
    int64 year;
    int64 month;
    int64 day;
    std::vector<std::string> domains;
};
