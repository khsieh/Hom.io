#ifndef BLUEMIX_CLIENT_H
#define BLUEMIX_CLIENT_H

#include "mosquittopp.h"

class bluemix_client : public mosqpp::mosquittopp
{
public:
   bluemix_client(const char *id, const char *host, int port);
   ~bluemix_client(){}
   void on_connect(int rc);
   void on_message(const struct mosquitto_message *message);
   void on_subscribe(int mid, int qos_cout, const int *granted_qos);
};

#endif
