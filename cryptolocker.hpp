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

    std::string
    generate_domain(const std::string& tld, int length=32)
    {
        std::string domain;
        char prefix[length];
        for (int i = 0; i < length; i++) {
            year = ((year ^ 8 * year) >> 11) ^ ((year & 0xFFFFFFF0) << 17);
            month = ((month ^ 4 * month) >> 25) ^ 16 * (month & 0xFFFFFFF8);
            day = ((day ^ (day << 13)) >> 19) ^ ((day & 0xFFFFFFFE) << 12);
            char ch = ((year ^ month ^ day) % 25) + 97 ;
            prefix[i] = ch;
        }
        domain = std::string(prefix, length) + tld;      

        return domain;
    }

private:
    int64 year;
    int64 month;
    int64 day;
    std::vector<std::string> domains;
};
