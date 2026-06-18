hl.monitor({
    output = 'eDP-1',
    mode = '1920x1080@60',
    position = '0x0',
    scale = 1,
})

hl.monitor({
    output = 'HDMI-A-1',
    mode = '1920x1080@60',
    position = '0x0',
    scale = 1,
    mirror = 'eDP-1',
})

hl.on('hyprland.start', function ()
    hl.exec_cmd("systemctl --user start hyprland-session.target")

    hl.exec_cmd('hypridle')
    hl.exec_cmd('hyprpaper')
    hl.exec_cmd('waybar')
    hl.exec_cmd('clipse -listen')
    hl.exec_cmd('/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1')
    hl.exec_cmd('eww daemon')

    hl.exec_cmd('/home/rafayahmad/dotfiles/scripts/brightnessWidget.sh')
    hl.exec_cmd('~/dotfiles/scripts/battWarning.sh')
    hl.exec_cmd('~/dotfiles/scripts/youtubeBlocker.sh')

    hl.exec_cmd('GTK_CSD=0 /opt/fluffychat/fluffychat', { workspace = 'special:fluffychat' })
    hl.exec_cmd('thunderbird', { workspace = 'special:thunderbird' })
end)

hl.on('hyprland.shutdown', function ()
    os.execute("systemctl --user stop hyprland-session.target && sleep 0.1")
end)

require('hyprbinds')

hl.env('XCURSOR_SIZE', 24)
hl.env('XCURSOR_THEME', 'mytheme')
hl.env('QT_QPA_PLATFORMTHEME', 'qt5ct')
hl.env('GTK_THEME', 'Adwaita-dark')

hl.config({
    input = {
	kb_file = '/home/rafayahmad/.config/hypr/pauseMod3.xkb',
	numlock_by_default = true,

	follow_mouse = 1,

	sensitivity = 0.25, -- -1.0 - 1.0, 0 means no modification.
	repeat_rate = 30,
	repeat_delay = 200,

	touchpad = {
	    natural_scroll = true,
	}
    },

    general = {
	gaps_in = 5,
	gaps_out = 10,
	border_size = 2,

	col = {
	    active_border = {
		colors = {
		    'rgba(33ccffee)',
		    'rgba(00ff99ee)',
		},
		angle = 45,
	    },
	    inactive_border = 'rgba(595959aa)',
	},

	layout = 'dwindle',
    },

    decoration = {
	rounding = 10,
	inactive_opacity = 0.8,
	blur = {
	    enabled = true,
	    size = 4,
	    passes = 2,
	    ignore_opacity=true,
	}
    },

    animations = {
	enabled = true,
    },

    dwindle = {
	preserve_split = true,
    },

    misc = {
	force_default_wallpaper = 0,
	enable_anr_dialog = false,
    }
})


-- Animations

hl.curve('myBezier', { type = 'bezier', points = { {0.05, 0.9}, {0.1, 1.05} } })

hl.animation({ leaf = 'windows', enabled = true, speed = 7, bezier = 'myBezier'})
hl.animation({ leaf = 'windowsOut', enabled = true, speed = 7, bezier = 'default', style = 'popin 80%'})
hl.animation({ leaf = 'border', enabled = true, speed = 10, bezier = 'default'})
hl.animation({ leaf = 'borderangle', enabled = true, speed = 8, bezier = 'default'})
hl.animation({ leaf = 'fade', enabled = true, speed = 7, bezier = 'default'})
hl.animation({ leaf = 'workspaces', enabled = true, speed = 6, bezier = 'default'})
hl.animation({ leaf = 'specialWorkspace', enabled = true, speed = 7, bezier = 'myBezier', style = 'slidefadevert'})

-- Gestures

hl.gesture({
    fingers = 3,
    direction = 'horizontal',
    action = 'workspace',
})

-- Window Rules

hl.window_rule({
    name = 'clipse menu',
    match = {
	class = 'clipse'
    },
    float = true,
    size = {700, 600},
})

hl.window_rule({
    name = 'file picker',
    match = {
	class = '^(xdg-desktop-portal-gtk|gtk3-filechooser-dialog)$',
    },
    float = true,
    size = {900, 600},
})

hl.window_rule({
    name = 'calculator',
    match = {
	class = 'org.gnome.Calculator',
    },
    float = true,
    size = {500, 700},
})
