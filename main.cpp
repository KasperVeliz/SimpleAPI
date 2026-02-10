#include <iostream>
#include <pistache/endpoint.h>
#include <pistache/http.h>

class HelloHandler : public Pistache::Http::Handler {
    public:
        HTTP_PROTOTYPE(HelloHandler);

        void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response) override {
        response.send(Pistache::Http::Code::Ok, "Hello, World\n");
    }
};

int main() {
    int port {8000};
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(port));
    auto opts = Pistache::Http::Endpoint::options().threads(1);

    std::cout << "Running on http://localhost:" << port << "/\n";

    Pistache::Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Pistache::Http::make_handler<HelloHandler>());
    server.serve();
}
