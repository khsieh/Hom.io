#include <iostream>
#include <cassert>
#include <cstring>

#include "mraa.hpp"
#include "upm/grove.h"
#include "mosquittopp.h"
#include "bluemix_client.h"

using namespace mraa;
using namespace std;
using namespace upm;
using namespace mosqpp;

GroveTemp *temp;

int main()
{
    Pwm led(3);
    GroveTemp temp(0);
    cout << temp.value() << endl;
    const char *broker = "quickstart.messaging.internetofthings.ibmcloud.com";
    const char *id = "d:quickstart:iotsample-galileo:020086ce860f";
    bluemix_client client(id, broker, 1883);
    while(true) {
        int res = client.loop();
        const char *data = "{d: 'test'}";
        int error = client.publish(NULL, "iot-2/evt/status/fmt/json", strlen(data), data);
        cout << error << endl;
        if(res) {
	    switch(res) {
		case MOSQ_ERR_INVAL:
		    cout << "inval" << endl;
		    break;
		case MOSQ_ERR_NOMEM:
		    cout << "nomem" << endl;
		    break;
		case MOSQ_ERR_NO_CONN:
		    cout << "no conn" << endl;
		    break;
		case MOSQ_ERR_CONN_LOST:
		    cout << "lost" << endl;
		    break;
		case MOSQ_ERR_PROTOCOL:
		    cout << "protocol" << endl;
		    break;
		case MOSQ_ERR_ERRNO:
		    cout << "errno" << endl;
		    break;
	    }
            client.reconnect();
        }
    }
}

