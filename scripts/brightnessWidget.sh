#!/bin/bash

while true; do
	while "$(cat /home/rafayahmad/dotfiles/.config/eww/brightnessShow)"; do

		activeWindows=$(/home/rafayahmad/eww/target/release/eww active-windows)
		if [[ "$activeWindows" != *"brightnessWin"* ]] ; then
			echo "opening"
			/home/rafayahmad/eww/target/release/eww open brightnessWin
		fi

		echo false > /home/rafayahmad/.config/eww/brightnessShow
		sleep 1
	done
	
	activeWindows=$(/home/rafayahmad/eww/target/release/eww active-windows)
	if [[ "$activeWindows" == *"brightnessWin"* ]] ; then
		echo "closing"
		/home/rafayahmad/eww/target/release/eww close brightnessWin
	fi

done
