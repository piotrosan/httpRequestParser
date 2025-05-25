#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H
#include "request.h"
#include <regex>

namespace ParserContainer {
    class RequestParser {

        private:
            request::Request *request = new request::Request();
            string requestBody;

        public:
            RequestParser(string strRequest) {
                requestBody = strRequest;
                regex self_regex(
                    "REGULAR EXPRESSIONS",
                    regex_constants::ECMAScript | regex_constants::icase
                );
            }

        private:
            void setHttpMethod() {
                smatch sm;
                const regex r(R"((POST)\S?\s?(\S+)+\S?\s?HTTP\/(\S+))");
                regex_match(requestBody, sm, r);
                map<string, string> HttpMethod = {
                    {"requestMethod", sm.str(1)},
                    {"requestUrl", sm.str(2)},
                    {"httpVersion", sm.str(3)},
                };

                if (!HttpMethod.empty()) {
                    request->setHttpMethod(HttpMethod);
                }
            }

            void setHost() {
                const regex r(R"(Host:\S?\s?(\S+))");
                smatch sm;
                regex_match(requestBody, sm, r);
                string host;
                try {
                    host = sm[1];
                } catch (exception& e) {
                    host = "";
                }
                if (!host.empty()) {
                    request->setHost(host);
                }
            }

        public:
            void buildRequest() {
                setHttpMethod();
                setHost();
            }

            request::Request getRequest() {
                return *request;
            }
    };
}
#endif //REQUEST_PARSER_H
