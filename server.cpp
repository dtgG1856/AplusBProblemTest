#include <iostream>
#include <string>
#include "httplib.h"

int main() {
    httplib::Server svr;

    // 允许跨域访问
    svr.set_pre_routing_handler([](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        return httplib::Server::HandlerResponse::Unhandled;
    });

    // 处理 GET /api/add?a=10&b=20
    svr.Get("/api/add", [](const httplib::Request& req, httplib::Response& res) {
        try {
            std::string a_str = req.get_param_value("a");
            std::string b_str = req.get_param_value("b");

            if (a_str.empty() || b_str.empty()) {
                res.status = 400;
                res.set_content("{\"error\":\"Missing parameters\"}", "application/json");
                return;
            }

            long long a = std::stoll(a_str);
            long long b = std::stoll(b_str);
            long long result = a + b;

            std::string json = "{\"result\":" + std::to_string(result) + "}";
            res.set_content(json, "application/json");

        } catch (const std::exception&) {
            res.status = 400;
            res.set_content("{\"error\":\"Invalid input\"}", "application/json");
        }
    });

    std::cout << "C++ server running at http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}