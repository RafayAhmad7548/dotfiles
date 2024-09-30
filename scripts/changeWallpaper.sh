#!/bin/bash

monitor="eDP-1"

currentWallpaper=$(hyprctl hyprpaper listactive)
currentWallpaper=${currentWallpaper:8}

echo "$currentWallpaper"

wallpapers=$(hyprctl hyprpaper listloaded)

set=false
for wallpaper in $wallpapers; do
	echo "$wallpaper"
	if $set; then
		hyprctl hyprpaper wallpaper "${monitor},${wallpaper}"
		set=false
	fi
	if [ "$wallpaper" = "$currentWallpaper" ]; then
		set=true
		echo yes
	fi
done

if $set; then
	hyprctl hyprpaper wallpaper "${monitor},/home/rafayahmad/dotfiles/bgs/1.png"
fi

