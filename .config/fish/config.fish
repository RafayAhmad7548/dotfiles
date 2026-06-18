set -q MANPAGER; or set -x MANPAGER 'nvim +Man!'
set -x EDITOR 'nvim'

set -x SSH_AUTH_SOCK $XDG_RUNTIME_DIR/rbw/ssh-agent-socket
set -x CHROME_EXECUTABLE /usr/bin/chromium

set -x SUPPLY_JSON_KEY ~/.fastlane/read-maududi-app-b0b713a4a08b.json

fish_add_path /opt/android-sdk/platform-tools
fish_add_path /opt/android-sdk/emulator
fish_add_path /opt/android-sdk/cmdline-tools/latest/bin

fish_add_path $HOME/.cargo/bin
fish_add_path $HOME/.pyenv/shims

fnm env --use-on-cd --shell fish | source

source ~/.config/fish/aliases.fish

if status is-interactive
	set -U fish_greeting ""
	set -g fish_key_bindings fish_vi_key_bindings

	bind -M insert ctrl-r history-pager
	bind -M insert ctrl-f accept-autosuggestion
	bind -M insert ctrl-e forward-word
	bind -M insert ctrl-backspace backward-kill-word

	bind -M default j 'fish_vi_run_count backward-char-passive'
	bind -M default l 'fish_vi_run_count forward-char-passive'
	bind -M default i 'fish_vi_run_count up-or-search'
	bind -M default k 'fish_vi_run_count down-or-search'

	bind -M default '#' beginning-of-line

	bind -M default p fish_clipboard_paste
	bind -M visual -m default y fish_clipboard_copy end-selection repaint-mode

	function __ctrl_l
		if commandline -P
			commandline -f forward-char
		else if status test-terminal-feature scroll-content-up
			commandline -f scrollback-push
		else
			commandline -f clear-screen
		end
	end
	bind -M insert ctrl-l __ctrl_l

	function __ctrl_j
		if commandline -P
			commandline -f backward-char
		else
			commandline -f execute
		end
	end
	bind --preset -m insert ctrl-j __ctrl_j
end
starship init fish | source
