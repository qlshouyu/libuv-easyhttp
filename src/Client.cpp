#include "../include/Client.h"

namespace LibUVEH{
  Client::Client(){
    this->handle = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
  }
  
  void free_client(uv_handle_t *handle) {
    // auto *client = reinterpret_cast<Client*>(handle->data);
    // free(client);
  }
  Client::~Client(){
    spdlog::info("Destory client:{0:d}",this->handle->io_watcher.fd);
    uv_close((uv_handle_t*)this->handle,nullptr);
    delete this->handle;
  }

}