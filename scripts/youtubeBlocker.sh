#!/usr/bin/bash 

is_valid_youtube_time() {
    now=$(date +%H%M)
    start=1000
    end=1800

    (( 10#$now >= start && 10#$now <= end ))
}

handle() {
    case $1 in
        activewindow*)
            echo $1
            if [[ $1 == *YouTube* ]] && ! is_valid_youtube_time; then
                hyprctl dispatch killactive
                notify-send "ENOUGH, LOCK IN"
            fi
    esac
}

socat -U - UNIX-CONNECT:$XDG_RUNTIME_DIR/hypr/$HYPRLAND_INSTANCE_SIGNATURE/.socket2.sock | while read -r line; do handle "$line"; done
