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
            if [[ $1 == *YouTube*  || $1 == *Instagram* ]]; then
                hyprctl dispatch killactive
                notify-send "ENOUGH, LOCK IN" "GET BACK TO WORK" -u critical -i $HOME/dotfiles/scripts/discipline.png
                mpv $HOME/dotfiles/scripts/getbacktowork.mp3
            fi
    esac
}

socat -U - UNIX-CONNECT:$XDG_RUNTIME_DIR/hypr/$HYPRLAND_INSTANCE_SIGNATURE/.socket2.sock | while read -r line; do handle "$line"; done
