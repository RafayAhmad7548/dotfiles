#!/bin/bash
# currentWallpaper=$(hyprctl hyprpaper listactive)
# currentWallpaper=${currentWallpaper:8}
# configFile=${currentWallpaper: -5:1}
# configFile="/home/rafayahmad/.config/hypr/hyprlock/${configFile}.conf"
currentWallpaper=/home/rafayahmad/dotfiles/bgs/2.png
export currentWallpaper
# echo "$configFile"
hyprlock -c /home/rafayahmad/dotfiles/.config/hypr/hyprlock/2.conf
