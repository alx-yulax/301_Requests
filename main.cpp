#include <iostream>
#include <cpr/cpr.h>
#include <assert.h>

void cpr_get() {
    cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"},
                               cpr::Parameters{{"hello", "world"}});
    std::cout << r.url << std::endl; // http://www.httpbin.org/get
    std::cout << r.status_code << std::endl; // 200
    std::cout << r.header["content-type"] << std::endl; // application/json
    std::cout << r.text << std::endl;
}

void cpr_post() {
    cpr::Response r = cpr::Post(cpr::Url{"http://www.httpbin.org/post"},
                                cpr::Payload{{"key", "value"}});
    std::cout << r.text << std::endl;
}

void cpr_put() {
    assert(cpr::Post(cpr::Url{"http://www.httpbin.org/put"},
                     cpr::Payload{{"key", "value"}}).status_code == 405);

    cpr::Response r = cpr::Put(cpr::Url{"http://www.httpbin.org/put"},
                               cpr::Payload{{"key", "value"}});
    std::cout << r.text << std::endl;
}

void cpr_delete() {
    cpr::Response delete_response = cpr::Delete(cpr::Url{"http://www.httpbin.org/delete"});
    std::cout << delete_response.text;
}

void cpr_patch() {
    cpr::Response r = cpr::Patch(cpr::Url{"http://www.httpbin.org/patch"},
                                 cpr::Payload{{"key", "value"}});
    std::cout << r.text << std::endl;
}

int main() {

    std::string command;
    do {
        std::cout << "input command (get,post,put,delete,patch or ext): ";
        std::cin >> command;

        if (command == "get") {
            cpr_get();
        } else if (command == "post") {
            cpr_post();
        } else if (command == "put") {
            cpr_put();
        } else if (command == "delete") {
            cpr_delete();
        } else if (command == "patch") {
            cpr_patch();
        }


    } while (command != "ext");

    return 0;
}
