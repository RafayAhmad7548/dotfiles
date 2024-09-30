#!/bin/bash

while true; do

	batteryStatus=$(cat /sys/class/power_supply/BAT0/status)
	batteryLevel=$(cat /sys/class/power_supply/BAT0/capacity)
	currentPowerSetting=$(powerprofilesctl get)

	if [ "$batteryLevel" -le "25" ] && [ "$batteryStatus" == "Discharging" ]; then
		notify-send -u critical -i ~/Stuff/scripts/battery-alert.svg "Low Battery" "25% battery remaining"
	fi


	if [ "$batteryLevel" -le "40" ]; then
		if [ "$currentPowerSetting" != "power-saver" ]; then
			powerprofilesctl set power-saver
			notify-send -t 3000 "Battery Saver Turned On"
		fi
	elif [ "$batteryLevel" -ge "40" ] && [ "$batteryLevel" -le "75" ]; then
		if [ "$currentPowerSetting" != "balanced" ]; then
			powerprofilesctl set balanced
			notify-send -t 3000 "Battery Saver Turned Off"
		fi
	elif [ "$batteryLevel" -ge "75" ] && [ "$batteryStatus" == "Charging" ] || [ "$batteryStatus" == "Full" ]; then
		if [ "$currentPowerSetting" != "performance" ]; then
			powerprofilesctl set performance
			notify-send -t 3000 "Performance Mode Turned On"
		fi
	elif [ "$batteryLevel" -ge "75" ]; then
		if [ "$currentPowerSetting" != "balanced" ]; then
			powerprofilesctl set balanced
			notify-send -t 3000 "Performance Mode Turned Off"
		fi
	fi

	sleep 60
done
