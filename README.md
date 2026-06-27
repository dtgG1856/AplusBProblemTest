# A+B Problem - 全栈在线评测雏形

一个简单的 A+B 在线计算器，展示前后端分离架构。

## 技术栈
- **后端**: C++ (cpp-httplib)
- **前端**: HTML + CSS + JavaScript
- **通信**: HTTP GET, JSON

## 如何运行
1. 下载 `httplib.h` 放到项目目录
   - 地址: https://github.com/yhirose/cpp-httplib
2. 编译后端: `g++ -std=c++17 -pthread -D_WIN32_WINNT=0x0A00 server.cpp -o server.exe -lws2_32`
3. 启动后端: `server.exe`
4. 浏览器打开 `index.html`

## 项目意义
这是 OJ 评测系统的最小化原型，验证了 C++ 作为 Web 后端的可行性。
后续计划扩展为完整的在线判题系统。
