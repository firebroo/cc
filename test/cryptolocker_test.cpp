#include "../cryptolocker.hpp"
#include <iostream>

int
main(void)
{
    Cryptolocker c(2016, 1, 3);    
    std::cout << c.generate_domain(".firebroo.me") << std::endl;
    return 0;
}
