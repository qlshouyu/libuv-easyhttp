#ifndef __EASYHTTP_HTTP_SERVER_H__
#define __EASYHTTP_HTTP_SERVER_H__

#include "spdlog/spdlog.h"
#include <iostream>
#include <string>
#include <uv.h>
#define MAX_WRITE_HANDLES 1000
using namespace std;

namespace LibUVEH{
  class HttpServer
  {
  private:
    int port;
    std::string host;
    std::unique_ptr<uv_tcp_t>  serverPtr;
    void initUv();
  public:
    explicit HttpServer();

    void listen(string addr,int port);
    ~HttpServer();
  };

}



#endif