
#include "spdlog/spdlog.h"
#include "../include/HttpServer.h"
#include <uv.h>
#include "../include/Client.h"
#include "../include/ClientManager.h"

namespace LibUVEH{
  uv_loop_t* loop={nullptr};
  ClientManager clientManager ;
  void onConnected(uv_stream_t* server, int status);
  HttpServer::HttpServer()
  {
    this->initUv();
  }
  void HttpServer::initUv(){
    loop=uv_default_loop();
    spdlog::info("uv_default_loop");
    
  }

  void HttpServer::listen(string addr,int port){
    spdlog::info("Starting listen {0}:{1:d}",addr,port);
    this->host=addr;
    this->port=port;
    uv_tcp_t* server=(uv_tcp_t*)malloc(sizeof(uv_tcp_t));
    int error= uv_tcp_init(loop, server);
    if(error){
      const char * strError= uv_strerror(error);
      spdlog::error("uv_tcp_init error:{}",strError);
      return;
    }
    this->serverPtr.reset(server);
    spdlog::info("uv_tcp_init successfully");
    sockaddr_in sockaddr;
    error= uv_ip4_addr(this->host.c_str(), this->port,&sockaddr);
    if(error){
      const char * strError= uv_strerror(error);
      spdlog::error("uv_ip4_addr error:{}",strError);
      return;
    }
    spdlog::info("uv_ip4_addr successfully");

    error= uv_tcp_bind(server, (const struct sockaddr*)&sockaddr, 0);
    if(error){
      const char * strError= uv_strerror(error);
      spdlog::error("uv_tcp_bind error:{}",strError);
      return;
    }
    spdlog::info("uv_tcp_bind successfully");
    error = uv_listen((uv_stream_t*) server, MAX_WRITE_HANDLES, [](uv_stream_t* server, int status){
      onConnected(server,status);
    });
    if (error) {
        const char * strError= uv_strerror(error);
        spdlog::error("Listen error:{}",strError);
        return;
    }
    error = uv_run(loop, UV_RUN_DEFAULT);
    if (error) {
        const char * strError= uv_strerror(error);
        spdlog::error("Listen error:{}",strError);
        return;
    }
  }

  HttpServer::~HttpServer()
  {
  }

  //
  //连接处理
  void onConnected(uv_stream_t* server, int status){
    spdlog::info("Connected:{0:d}",status);
    if (status < 0) {
      // fprintf(stderr, "New connection error %s\n", uv_strerror(status));
      spdlog::error("New connection error:{0}",uv_strerror(status));
      // error!
      return;
    }
    Client* client=new Client();
    int error= uv_tcp_init(loop, client->handle);
    if(error){
      spdlog::error("Client connect uv_tcp_init error:{0} ",uv_strerror(error));
      delete client;
      return;
    }
    error=uv_accept(server, (uv_stream_t*) client->handle);
    if (error) {
      spdlog::error("Client connect uv_accept error:{0} ",uv_strerror(error));
      delete client;
      return;
    }
    spdlog::info("uv_accept successfully:{0:d}",client->handle->io_watcher.fd);
    clientManager.add(client);
    clientManager.remove(client->handle->io_watcher.fd);
      // uv_read_start((uv_stream_t*) tcp, alloc_buffer, echo_read);
  }

  
}