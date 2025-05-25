#include <iostream>
#include "parser/parser.h"

using ParserContainer::RequestParser;
using namespace std;

int main() {

    string request = "POST /resource/123 HTTP/1.1 \n"\
                     "Host: example.com";

    auto *rp = new RequestParser(request);
    rp->buildRequest();
    request::Request req = rp->getRequest();
    cout << req.getHost() << endl;
    cout << req.getHttpMethod().httpVersion << req.getHttpMethod().requestMethod << req.getHttpMethod().requestUrl ;

    return 0;
}