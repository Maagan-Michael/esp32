# sub.pysdafa
import time
from umqtt.simple import MQTTClient

SERVER="z6b1d2f6.ala.us-east-1.emqxsl.com"
ClientID = f'esp32-sub-{time.time_ns()}'
user = "aa"
password = "aa"
topic = "esp32/mqtt"
msg = b'{"msg":"hello"}'
ssl_params = {"server_hostname": SERVER}

def sub(topic, msg):
    print('received message %s on topic %s' % (msg, topic))

def main(server=SERVER):
    client = MQTTClient(ClientID, server, 8883, user, password,0,True,ssl_params=ssl_params)
    client.set_callback(sub)
    client.connect()
    print('Connected to MQTT Broker "%s"' % (server))
    client.subscribe(topic)
    while True:
        if True:
            client.wait_msg()
        else:
            client.check_msg()
            time.sleep(1)

if __name__ == "__main__":
    main()
