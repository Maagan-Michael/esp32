# pub.py
import time
from umqtt.simple import MQTTClient

server_address="z6b1d2f6.ala.us-east-1.emqxsl.com"
ClientID = f'esp32-pub{time.time_ns()}'
user = "MaaganmHub"
password = "Mm12345!"
topic = "esp32/mqtt"
msg = b'{"msg":"hello"}'
ssl_params = {"server_hostname": server_address}


def connect():
    client = MQTTClient(ClientID, server_address, 8883, user, password,0,True,ssl_params=ssl_params)
    client.connect()
    print('Connected to MQTT Broker "%s"' % (server_address))
    return client

def reconnect():
    print('Failed to connect to MQTT broker, Reconnecting...')
    time.sleep(5)
    client.reconnect()

try:
    client = connect()
except OSError as e:
    print(e)
    reconnect()

while True:
  print('send message %s on topic %s' % (msg, topic))
  client.publish(topic, msg, qos=0)
  time.sleep(1)
