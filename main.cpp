#include <string>
#include <iostream>
// #include "include/http.h"
#include "include/HttpServer.h"
using namespace LibUVEH;
int main(int argc,char** argv){
  LibUVEH::HttpServer * server=new LibUVEH::HttpServer();
  // HttpServer * server=new HttpServer();
  server->listen("0.0.0.0",8089);

  delete server;
  // std::cout<<"Starting http"<<std::endl;
  // http::Server hs([](http::Request &req, http::Response &res) {
  //   std::cout<<"Get http request "<<std::endl;
  //   res.setStatus(200);
  //   res.setHeader("Content-Type", "text/plain");
  //   res.setHeader("Connection", "keep-alive");
  //   res << req.method<<" " << req.url << std::endl;
  // });
  // std::cout<<"listen out: "<<10008<<std::endl;
  // // hs.listen("0.0.0.0", 10008);
  // hs.listen("172.31.103.161",10008);
  return 0;
}