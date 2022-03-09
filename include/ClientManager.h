#ifndef __EASYHTTP_CLIENT_MANAGER_H__
#define __EASYHTTP_CLIENT_MANAGER_H__
#include<memory>
#include<map>
#include "Client.h"
#include "spdlog/spdlog.h"
using namespace std;
namespace LibUVEH{
  
  class ClientManager
  {
  private:
    map<int,Client*> clients;
  public:
    ClientManager(/* args */);
    ~ClientManager();

    void add(Client * client);
    void remove(int fd);
    // Client * get(int fd);
  };

  
  
}


#endif
