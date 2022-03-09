#ifndef __EASYHTTP_CLIENT_H__
#define __EASYHTTP_CLIENT_H__

#include<uv.h>
#include<string>
#include <memory>
#include "spdlog/spdlog.h"
using namespace std;
namespace LibUVEH{
  class Client
  {
  private:

  public:
    uv_tcp_t* handle;
  public:
    explicit Client();
    ~Client();
  };
}


#endif