import requests
import os

esp32_ip = "insert_ip_address_for_esp32"

#Get the file list
print("Geeting file list from esp32")
response = requests.get("https//"+esp32_ip+"/files")
file_list = response.text.splitlines()

#download the files from esp32 to rpi
for file_name in file_list:
    #print("Downloading: "+file_name)
    response = requests.get("http://"+esp32_ip+"//"+file_name)
    with open(file_name, "wb") as f:
        f.write(response.content)
    #print(file_name+" downloaded")