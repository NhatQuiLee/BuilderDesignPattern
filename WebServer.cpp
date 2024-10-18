#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Product
class WebServer
{
    private:
        string host;
        int port;
        int maxConnection;
        bool sslEnabled;
        string sslCertPath;
        vector<string> middleware;
    public:
        void SetHost(string h)
        {
            host = h;
        }
        void SetPort(int p)
        {
            port = p;
        }
        void SetMaxConnection(int m)
        {
            maxConnection = m;
        }
        void SetSSLEnabled (bool ssl_e)
        {
            sslEnabled = ssl_e;
        }
        void SetSSLCertPath(string ssl_c)
        {
            sslCertPath = ssl_c;
        }
        void SetMiddleware(const vector<string>& mid)
        {
            middleware = mid;
        }
        string GetHost()
        {
            return host;
        }
        int GetPort()
        {
            return port;
        }
        int GetMaxConnection()
        {
            return maxConnection;
        }
        bool IsSSLEnabled()
        {
            return sslEnabled;
        }
        string GetSSLCertPath()
        {
            return sslCertPath;
        }
        const vector<string>& GetMiddleware()
        {
            return middleware;
        }
        void ShowConfiguration()
        {
            cout << "Web Server Configuration: " << endl;
            cout << "Host: " << host << endl;
            cout << "Port: " << port << endl;
            cout << "Max Connection: " << maxConnection << endl;
            cout << "SSL Enable: " << (sslEnabled ? "YES" : "NO") << endl;
            if (sslEnabled)
            {
                cout << "SSL Certificate Path: " << sslCertPath << endl;
            }
            cout << "Middleware: " << endl;
            for (const auto& mw : middleware)
            {
                cout << "- " << mw << endl;
            }
            cout << endl;
        }
};

class WebServerBuilder
{
    public: 
        virtual void SetWebServerHost(string host) = 0;
        virtual void SetWebServerPort(int port) = 0;
        virtual void SetWebServerMaxConnection(int maxConnection) = 0;
        virtual void EnabledSSL(bool sslEnabled) = 0;
        virtual void SetCertPath(string sslCertPath) = 0;
        virtual void AddMiddleware(const vector<string>& middleware) = 0;
        virtual WebServer* GetWebServer() = 0;
};

class WebServerConcreteBuilder : public WebServerBuilder
{   
    private:
        WebServer* webserver;
    public:
        WebServerConcreteBuilder()
        {
            webserver = new WebServer();
        }
        virtual void SetWebServerHost(string host) override
        {
            webserver->SetHost(host);
        }
        virtual void SetWebServerPort(int port) override
        {
            webserver->SetPort(port);
        }
        virtual void SetWebServerMaxConnection(int maxConnection) override
        {
            webserver->SetMaxConnection(maxConnection);
        }
        virtual void EnabledSSL(bool sslEnabled) override
        {
            webserver->SetSSLEnabled(sslEnabled);
        }
        virtual void SetCertPath(string sslCertPath) override
        {
            webserver->SetSSLCertPath(sslCertPath);
        }
        virtual void AddMiddleware(const vector<string>& middleware) override
        {
            webserver->SetMiddleware(middleware);
        }
        virtual WebServer* GetWebServer() override
        {
            return webserver;
        }
        
    
};

class WebServerDirector
{
    private:
        WebServerBuilder* webServer;
    public:
        void SetWebServer(WebServerBuilder* web)
        {
            webServer = web;
        }
        void ConstructBasicConfig()
        {
            webServer->SetWebServerHost("Localhost");
            webServer->SetWebServerPort(8080);
            webServer->SetWebServerMaxConnection(100);
            webServer->EnabledSSL(true);
            webServer->SetCertPath("/path/to/cert/ssl");
            webServer->AddMiddleware({"Authentication", "Logging", "Compression"});
        }
        void ConstructCustomConfig(const string host, int port, bool ssl_enabled)
        {
            webServer->SetWebServerHost(host);
            webServer->SetWebServerPort(port);
            webServer->SetWebServerMaxConnection(500);
            webServer->EnabledSSL(ssl_enabled);
            webServer->SetCertPath("custom/path/to/cert/ssl");
            webServer->AddMiddleware({"Authentication", "CustomeMiddleware"});
        }
};

int main()
{
    WebServerDirector director;
    WebServerConcreteBuilder WebServerConcreteBuilder;
    director.SetWebServer(&WebServerConcreteBuilder);

    director.ConstructBasicConfig();
    WebServer* basicConfig = WebServerConcreteBuilder.GetWebServer();
    cout << "Basic configuration: " << endl;
    basicConfig->ShowConfiguration();

    director.ConstructCustomConfig("example.com", 5000, false);
    WebServer* customConfig = WebServerConcreteBuilder.GetWebServer();
    cout << "Custom configuration: " << endl;
    customConfig->ShowConfiguration();

    delete basicConfig;
    delete customConfig;

    return 0;
}