#include <iostream>

#include "bluemix_client.h"

using namespace std;
using namespace mosqpp;

bluemix_client::bluemix_client(const char *id, const char *host, int port) : mosquittopp(id)
{
   lib_init();
   int keepalive = 12000;
   cout << "about to connect!" << endl;
   //username_pw_set("use-auth-token", "my-token");
   int error = connect(host, port, keepalive);
   cout << error << endl;
}

void bluemix_client::on_connect(int rc)
{
    cout << "connected!!" << endl;
    cout << rc << endl;
    if(rc == 0) {
        cout << "about to subscribe" << endl;
        //int error = subscribe(NULL, "/iot-2/cmd/+/fmt/json");
        //cout << error << endl;
    }
}

void bluemix_client::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    cout << "subscribed!!!" << endl;
}

void bluemix_client::on_message(const struct mosquitto_message *message)
{
   cout << "got a message!" << endl;
}

void bluemix_client::on_publish(int mid)
{
   cout << "published!" << endl;
}
