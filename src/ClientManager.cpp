#include "../include/ClientManager.h"


namespace LibUVEH{

  ClientManager::ClientManager(/* args */)
  {
  }
  
  ClientManager::~ClientManager()
  {
  }

  void ClientManager::add(Client * client){
    spdlog::info("Add client:{0:d}   {1:d}",client->handle->accepted_fd,client->handle->io_watcher.fd);
    this->clients.insert(pair<int,Client*>(client->handle->io_watcher.fd,client));
  }

  void ClientManager::remove(int client){
    spdlog::info("Remove client:{0:d}",client);
    map<int, Client*>::iterator iter= this->clients.find(client); 
    if(iter != this->clients.end()) {
      this->clients.erase(client);
      delete iter->second;
    }
    
    spdlog::info("clients size:{0:d}",this->clients.size());
  }
}