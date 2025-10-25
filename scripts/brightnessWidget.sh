#!/bin/bash

while true; do
	while "$(cat /home/rafayahmad/dotfiles/.config/eww/brightnessShow)"; do

		activeWindows=$(eww active-windows)
		if [[ "$activeWindows" != *"brightnessWin"* ]] ; then
			echo "opening"
			eww open brightnessWin
		fi

		echo false > /home/rafayahmad/.config/eww/brightnessShow
		sleep 1
	done
	
	activeWindows=$(eww active-windows)
	if [[ "$activeWindows" == *"brightnessWin"* ]] ; then
		echo "closing"
		eww close brightnessWin
	fi

done
