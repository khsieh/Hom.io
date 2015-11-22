#include <iostream>
#include <cassert>
#include <cstring>

#include "mraa.hpp"
#include "upm/grove.h"
#include "upm/groveloudness.h"
#include "upm/servo.h"
#include "mosquittopp.h"
#include "json/json.h"

#include "bluemix_client.h"

using namespace mraa;
using namespace std;
using namespace upm;
using namespace mosqpp;
using namespace Json;

Servo servo(5);
GroveLed led(3);
GroveTemp temp(0);
GroveLight light(3);
GroveLoudness sound(2);
FastWriter writer;
Value root(objectValue);

int main()
{
    root["d"] = Value(objectValue);
    FILE *f = fopen("device.cfg", "r");
    char broker[100];
    fscanf(f, "broker = %s\n", broker);
    char id[100];
    fscanf(f, "id = %s\n", id);
    char topic[100];
    fscanf(f, "topic = %s\n", topic);
    bluemix_client client(id, broker, 1883);
    while(true) {
        int res = client.loop();
        root["d"]["temp"] = temp.value();
        root["d"]["sound"] = sound.value();
	int light_level = light.value();
	float led_level = 1.0/(1+light_level);
        root["d"]["outdoor_light"] = light_level;
        root["d"]["indoor_light"] = led_level;
        led.write(led_level);
        string output = writer.write(root);
        cout << sound.value() << endl;
        //cout << output << endl;
        int error = client.publish(NULL, topic, output.size(), output.c_str());
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
        sleep(1);
    }
}

