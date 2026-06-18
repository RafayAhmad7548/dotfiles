hl.define_submap('disableOtherKeyBinds', function ()
    hl.bind('SUPER + ESCAPE', hl.dsp.submap('reset'))
end)

hl.bind('SUPER + F', hl.dsp.submap('disableOtherKeyBinds'))


-- Application Binds
hl.bind('ALT + T', hl.dsp.exec_cmd('kitty'))
hl.bind('ALT + E', hl.dsp.exec_cmd('nautilus'))
hl.bind('ALT + F', hl.dsp.exec_cmd('librewolf'))
hl.bind('ALT + V', hl.dsp.exec_cmd('code'))
hl.bind('ALT + Z', hl.dsp.exec_cmd('zeditor'))
hl.bind('ALT + M', hl.dsp.exec_cmd('prismlauncher'))
hl.bind('ALT + D', hl.dsp.exec_cmd('discord'))
hl.bind('ALT + W', hl.dsp.exec_cmd('flatpak run com.rtosta.zapzap'))
hl.bind('SUPER + SUPER_L', hl.dsp.exec_cmd('rofi -show drun -sort -matching fuzzy'))
hl.bind('SUPER + N', hl.dsp.exec_cmd('swaync-client -t -sw'))

-- Fullscreen
hl.bind('F11', hl.dsp.window.fullscreen({ mode = 'fullscreen', action = 'toggle' }))
hl.bind('SUPER + F11', hl.dsp.window.fullscreen({ mode = 'maximized', action = 'toggle' }))

-- Hyprlock
hl.bind('SUPER + CTRL + L', hl.dsp.exec_cmd('~/dotfiles/scripts/currentWallpaperHyprlock.sh'))

-- Waybar
hl.bind('SUPER + R', hl.dsp.exec_cmd('~/dotfiles/scripts/reloadwaybar'))
hl.bind('SUPER + CTRL + R', hl.dsp.exec_cmd('killall waybar'))

-- Screenshots
hl.bind('PRINT', hl.dsp.exec_cmd('grim -g "$(slurp)" - | wl-copy'))
hl.bind('SUPER + PRINT', hl.dsp.exec_cmd('grim - | wl-copy'))
hl.bind('CTRL + PRINT', hl.dsp.exec_cmd('grim -g "$(slurp)"'))
hl.bind('CTRL + SUPER + PRINT', hl.dsp.exec_cmd('grim'))

-- Clipboard
hl.bind('SUPER + SHIFT + V', hl.dsp.exec_cmd('kitty --class clipse -e clipse'))

-- Password Manager
hl.bind('SUPER + SHIFT + P', hl.dsp.exec_cmd('rofi-rbw'))

-- Color Picker
hl.bind('ALT + P', hl.dsp.exec_cmd('hyprpicker --format=hex -a'))

-- Audio Controls
hl.bind('code:123', hl.dsp.exec_cmd('wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+'), { repeating = true, locked = true })
hl.bind('code:122', hl.dsp.exec_cmd('wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-'), { repeating = true, locked = true })
hl.bind('code:121', hl.dsp.exec_cmd('wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle'), { repeating = true, locked = true })

-- Brightness Controls
hl.bind('code:233', hl.dsp.exec_cmd('brightnessctl s 1%+ && echo true > /home/rafayahmad/dotfiles/.config/eww/brightnessShow'), { repeating = true, locked = true })
hl.bind('code:232', hl.dsp.exec_cmd('brightnessctl s 1%- && echo true > /home/rafayahmad/dotfiles/.config/eww/brightnessShow'), { repeating = true, locked = true })


-- Window movement
hl.bind('SUPER + V', hl.dsp.window.float({ action = 'toggle' }))
hl.bind('SUPER + H', hl.dsp.layout('togglesplit'))
hl.bind('SUPER + C', hl.dsp.window.center())
hl.bind('CTRL + Q', hl.dsp.window.close())
hl.bind('ALT + TAB', hl.dsp.window.cycle_next())
hl.bind('SUPER + TAB', hl.dsp.window.swap({ next = true }))

-- Resize windows
hl.bind('ALT + L', hl.dsp.window.resize({ x = 50, y = 0, relative = true }), { repeating = true })
hl.bind('ALT + J', hl.dsp.window.resize({ x = -50, y = 0, relative = true }), { repeating = true })
hl.bind('ALT + I', hl.dsp.window.resize({ x = 0, y = 50, relative = true }), { repeating = true })
hl.bind('ALT + K', hl.dsp.window.resize({ x = 0, y = -50, relative = true }), { repeating = true })

-- Move focus
hl.bind('CTRL + ALT + L', hl.dsp.focus({ direction = 'right' }))
hl.bind('CTRL + ALT + J', hl.dsp.focus({ direction = 'left' }))
hl.bind('CTRL + ALT + I', hl.dsp.focus({ direction = 'up' }))
hl.bind('CTRL + ALT + K', hl.dsp.focus({ direction = 'down' }))

-- Move windows in tile
hl.bind('SUPER + L', hl.dsp.window.move({ direction = 'right' }))
hl.bind('SUPER + J', hl.dsp.window.move({ direction = 'left' }))
hl.bind('SUPER + I', hl.dsp.window.move({ direction = 'up' }))
hl.bind('SUPER + K', hl.dsp.window.move({ direction = 'down' }))

-- Switch workspaces with mainMod + [0-9]
hl.bind('SUPER + 1', hl.dsp.focus({ workspace = 1 }))
hl.bind('SUPER + 2', hl.dsp.focus({ workspace = 2 }))
hl.bind('SUPER + 3', hl.dsp.focus({ workspace = 3 }))
hl.bind('SUPER + Q', hl.dsp.focus({ workspace = 4 }))
hl.bind('SUPER + W', hl.dsp.focus({ workspace = 5 }))
hl.bind('SUPER + E', hl.dsp.focus({ workspace = 6 }))
hl.bind('SUPER + A', hl.dsp.focus({ workspace = 7 }))
hl.bind('SUPER + S', hl.dsp.focus({ workspace = 8 }))
hl.bind('SUPER + D', hl.dsp.focus({ workspace = 9 }))
hl.bind('SUPER + 0', hl.dsp.focus({ workspace = 10 }))
hl.bind('ALT + 1', hl.dsp.workspace.toggle_special('fluffychat'))
hl.bind('ALT + 2', hl.dsp.workspace.toggle_special('thunderbird'))

-- Move active window to a workspace and switch with mainMod + SHIFT + [0-9]
hl.bind('SUPER + SHIFT + 1', hl.dsp.window.move({ workspace = 1 }))
hl.bind('SUPER + SHIFT + 2', hl.dsp.window.move({ workspace = 2 }))
hl.bind('SUPER + SHIFT + 3', hl.dsp.window.move({ workspace = 3 }))
hl.bind('SUPER + SHIFT + Q', hl.dsp.window.move({ workspace = 4 }))
hl.bind('SUPER + SHIFT + W', hl.dsp.window.move({ workspace = 5 }))
hl.bind('SUPER + SHIFT + E', hl.dsp.window.move({ workspace = 6 }))
hl.bind('SUPER + SHIFT + A', hl.dsp.window.move({ workspace = 7 }))
hl.bind('SUPER + SHIFT + S', hl.dsp.window.move({ workspace = 8 }))
hl.bind('SUPER + SHIFT + D', hl.dsp.window.move({ workspace = 9 }))
hl.bind('SUPER + SHIFT + 0', hl.dsp.window.move({ workspace = 10 }))
hl.bind('ALT + SHIFT + 1', hl.dsp.window.move({ workspace = 'special:fluffychat' }))
hl.bind('ALT + SHIFT + 2', hl.dsp.window.move({ workspace = 'special:thunderbird' }))

-- Move active window to a workspace with mainMod + SHIFT + [0-9]
hl.bind('SUPER + CTRL + 1', hl.dsp.window.move({ workspace = 1, follow = false }))
hl.bind('SUPER + CTRL + 2', hl.dsp.window.move({ workspace = 2, follow = false }))
hl.bind('SUPER + CTRL + 3', hl.dsp.window.move({ workspace = 3, follow = false }))
hl.bind('SUPER + CTRL + Q', hl.dsp.window.move({ workspace = 4, follow = false }))
hl.bind('SUPER + CTRL + W', hl.dsp.window.move({ workspace = 5, follow = false }))
hl.bind('SUPER + CTRL + E', hl.dsp.window.move({ workspace = 6, follow = false }))
hl.bind('SUPER + CTRL + A', hl.dsp.window.move({ workspace = 7, follow = false }))
hl.bind('SUPER + CTRL + S', hl.dsp.window.move({ workspace = 8, follow = false }))
hl.bind('SUPER + CTRL + D', hl.dsp.window.move({ workspace = 9, follow = false }))
hl.bind('SUPER + CTRL + 0', hl.dsp.window.move({ workspace = 10, follow = false }))
hl.bind('ALT + CTRL + 1', hl.dsp.window.move({ workspace = 'special:fluffychat', follow = false }))
hl.bind('ALT + CTRL + 2', hl.dsp.window.move({ workspace = 'special:thunderbird', follow = false }))

-- Scroll through existing workspaces with mainMod + scroll
hl.bind('SUPER + mouse_down', hl.dsp.focus({ workspace = 'e-1' }))
hl.bind('SUPER + mouse_up', hl.dsp.focus({ workspace = 'e+1' }))

-- Move/resize windows with mainMod + LMB/RMB and dragging
hl.bind('SUPER + mouse:272', hl.dsp.window.drag(), { mouse = true })
hl.bind('ALT + mouse:272', hl.dsp.window.resize(), { mouse = true })

-- Shutdown/Reboot
hl.bind('SUPER + M', hl.dsp.exit)
hl.bind('CTRL + ALT + Z', hl.dsp.exec_cmd('reboot'))
hl.bind('CTRL + ALT + X', hl.dsp.exec_cmd('shutdown now'))
