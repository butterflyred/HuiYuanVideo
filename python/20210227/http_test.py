#!/usr/bin/python3
import requests
import sys
import json

def tmp():
    url = 'http://127.0.0.1'
    r = requests.get(url)
    if r.ok :
        hdr = r.headers
        print("header type :" , type(hdr))
        print("--------------")
        for x in hdr:
            o_str= "%s \t \t -> %s " % (x,hdr[x])
            print(o_str)
        rj = r.json()
        print(" json type :", type(rj))
        print(json.dumps(rj,indent=4))

def web_page():
    url = 'https://github.com/butterflyred/HuiYuanVideo'
    r = requests.get(url)
    hdr = r.headers
    if r.ok :
        # print("request type :" , type(r))
        # print("request status :" , r.status_code)
        # print(help(r))
        # print(r.text)
        print("header type :" , type(hdr))
        for x in hdr:
            o_str= "%s \t \t -> %s " % (x,hdr[x])
            print(o_str)

        
if __name__ == "__main__":
    web_page()
    exit(0)