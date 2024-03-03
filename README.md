# mprpc —— C++ 分布式网络通信框架

**项目依赖：**

1. muduo (https://github.com/chenshuo/muduo)

   ```shell
   $ sudo apt install g++ cmake make libboost-dev
   $ git clone -b cpp11 git@github.com:chenshuo/muduo.git
   $ cd muduo
   $ vim CMakeLists.txt
     # option(MUDUO_BUILD_EXAMPLES "Build Muduo examples" ON) 注释该行，不编译样例
   $ ./build.sh
   $ ./build.sh install    # muduo 编译后头文件和库文件都不在系统路径下
   $ cd build/release-install-cpp11/include
   # 将 muduo 头文件拷贝到 mprpc 的 include 目录中
   $ cp -r muduo [your path]/mprpc/include/
   $ cd ../lib
   # 将本项目用到的 muduo 静态库文件拷贝到 mprpc 的 thirdparty 目录中
   $ cp libmuduo_base.a [your path]/mprpc/thirdparty/
   $ cp libmuduo_net.a [your path]mprpc/thirdparty/
   ```


2. protobuf (https://github.com/protocolbuffers/protobuf)

   ```shell
   $ sudo apt-get install autoconf automake libtool curl make g++
   ```

**mprpc 编译和测试**

```shell
$ git clone git@github.com:shuming1998/mprpc.git
$ cd mprpc
$ chmod +x autoBuild.sh
$ sudo ./autoBuild.sh
      
# 测试
$ cd bin
# rpc 服务提供方
$ ./provider -i ../example/example.conf
# rpc 服务调用方
$ ./consumer -i ../example/example.conf 
```



**使用异步日志**

日志文件命名格式: year-month-day-log.txt

```c++
#include "logger.h"
int a = 10l
std::string log = "hello, world!";

LOG_DEBUG("mprpc log debug: %d, %s", a, log);
LOG_INFO("mprpc log info: %d, %s", a, log);
LOG_ERROR("mprpc log error: %d, %s", a, log);
LOG_FATAL("mprpc log fatal: %d, %s", a, log);
```



**rpc服务调用过程**
![image-20230218012019296](image/mprpc.png)
