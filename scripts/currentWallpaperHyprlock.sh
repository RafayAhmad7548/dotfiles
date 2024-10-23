#!/bin/bash
currentWallpaper=$(hyprctl hyprpaper listactive)
currentWallpaper=${currentWallpaper:8}
configFile=${currentWallpaper: -5:1}
configFile="/home/rafayahmad/.config/hypr/hyprlock/${configFile}.conf"
export currentWallpaper
echo "$configFile"
hyprlock -c "$configFile"
