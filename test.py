import requests

is_on = False

while True:
    input("LED is on: " + str(is_on))
    if is_on:
        requests.get("http://5.tcp.eu.ngrok.io:13076/?led=off")
        is_on = False
        
    else:
        requests.get("http://5.tcp.eu.ngrok.io:13076/?led=on")
        is_on = True

        

        