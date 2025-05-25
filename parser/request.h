#ifndef REQUEST_H
#define REQUEST_H
#include <map>
#include <string>
#include <utility>

using namespace std;

namespace request {

    class Request {

        private:
            struct httpMethod {
                string requestMethod;
                string requestUrl;
                string httpVersion;
            };
            httpMethod tmpHttpMethod;
            string host;

        public:
            void setHttpMethod(map<string, string> httpMethodFrom) {
                httpMethod tmpHttpMethod = {
                    .requestMethod = httpMethodFrom["requestMethod"],
                    .requestUrl = httpMethodFrom["requestUrl"],
                    .httpVersion = httpMethodFrom["httpVersion"]
                };
            }
            void setHost(string& hostFrom) {
                host = hostFrom;
            }

            httpMethod getHttpMethod() {
                return tmpHttpMethod;
            }

            string getHost() {
                return host;
            }
    };

} // request

#endif //REQUEST_H
