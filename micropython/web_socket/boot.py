# Complete project details at https://RandomNerdTutorials.com



try:
  import usocket as socket
except:
  import socket


from machine import Pin
import network

import esp
esp.osdebug(None)

import gc
gc.collect()
def do_connect():
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect('Nuclear_Bunker_wifi', 'Bunker2023')
        while not sta_if.isconnected():
            pass
    print('network config:', sta_if.ifconfig())
    
do_connect()
led = Pin(32, Pin.OUT)
