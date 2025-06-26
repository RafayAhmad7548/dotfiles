#!/usr/bin/env python

from datetime import date
from datetime import datetime
import socket
import os
import time
from threading import Thread
import subprocess

date_format = "%Y-%m-%d"
youtube_focused = False

time_remaining = int(0)

def update_file():
    with open('/home/rafayahmad/dotfiles/scripts/youtubeData', 'w') as file:
        file.write(date.today().strftime(date_format))
        file.write('\n')
        file.write(time_remaining.__str__())

def read_file():
    global time_remaining
    with open('/home/rafayahmad/dotfiles/scripts/youtubeData') as file:
        date_t = file.readline().strip()
        date_t = datetime.strptime(date_t, date_format).date()
        time_remaining = int(file.readline())

    if date_t != date.today():
        print('differnt date, resetting')
        time_remaining = 60
        update_file()
    

sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
path = os.path.expandvars('$XDG_RUNTIME_DIR/hypr/$HYPRLAND_INSTANCE_SIGNATURE/.socket2.sock')
sock.connect(path)

def time_counter():
    while True:
        global time_remaining
        if youtube_focused:
            read_file()
            if time_remaining == 0:
                subprocess.run(['hyprctl', 'dispatch', 'killactive'])
                subprocess.run(['notify-send', 'time\'s up buddy'])
                time.sleep(1)
                continue
            time.sleep(60)
            time_remaining -= 1
            update_file()
            print('Remainng Youtube Time is: ', time_remaining)

Thread(target=time_counter).start()

while True:
    data = sock.recv(1024)
    lines = data.decode().split('\n')
    for line in lines:
        if line.startswith('activewindow>>'):
            print(line)
            if line.__contains__('YouTube'):
                youtube_focused = True
                print('youtube focused')
            else:
                youtube_focused = False
                print('youtube unfocused')
