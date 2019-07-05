#pragma once

#include <string>
#include <memory>

class webcc {
public:
    webcc(std::string domain, std::string path); 
    std::pair<unsigned char*, int> received_shellcode(void);

private:
    std::string domain;
    std::string path;
};
