#include<iostream>
#include"mprpcapplication.h"
#include"user.pb.h"
#include"mprpcchannel.h"

int main(int argc,char **argv)
{
    //整个程序启动以后想要mprpc框架来享受rpc服务调用，一定要先调用初始函数
    MprpcApplication::Init(argc,argv);

    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    //rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    //响应
    fixbug::LoginResponse response;



    //rpc方法的调用，同步的rpc调用过程
    stub.Login(nullptr,&request,&response,nullptr); //RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送
    
    //一次rpc调用完成，读调用的结果
    if(0==response.reslut().errcode())
    {
        std::cout<<"rpc login response success"<<response.success()<<std::endl;
    }
    else
    {
        std::cout<<"rpc login response err:"<<response.reslut().errmsg()<<std::endl;
    }

    
    //注册
    fixbug::RegisterRequest req;
    req.set_id(2000);
    req.set_name("mprpc");
    req.set_pwd("666666");
    fixbug::RegisterResponse rsp;
    
    //以同步的方式发起RPC请求，等待返回结果
    stub.RegisterR(nullptr,&req,&rsp,nullptr);

    //一次rpc调用完成，读取调用的结果
    if(0==rsp.reslut().errcode())
    {
        std::cout<<"rpc login response:"<<rsp.success()<<std::endl;
    }
    else
    {
        std::cout<<"rpc login response error:"<<rsp.reslut().errmsg()<<std::endl;
    }

    
    
    return 0 ;    
}