alias grep='grep --color=auto'

alias ll='eza -lgaah'
alias ls='eza --icons always'

alias cls='clear'
alias curl='curl -w "\n"'

alias vi='nvim'
alias svi='sudo -E nvim'
alias src='source ~/.bashrc'
alias zsrc='source ~/.zshrc'
alias fetch='fastfetch'

alias dug='sudo du -h --max-depth=1 | grep G'

alias fwknop_pserver='fwknop -n pserver --no-save-args --key-base64-rijndael=(rbw get Server --field "SPA Key Base64") --key-base64-hmac=(rbw get Server --field "SPA HMAC Key Base64") -p (rbw get Server --field "SPA Port")'

alias wifi-rescan='nmcli d wifi list --rescan yes'
alias hotspot-up='nmcli connection up Hotspot'
alias hotspot-down='nmcli connection down Hotspot'

alias hurl='hurl --variables-file .env'

alias awsec2-list="aws ec2 describe-instances --query 'Reservations[].Instances[].{Name:Tags[?Key==\`Name\`]|[0].Value, InstanceId:InstanceId, State:State.Name}' --output table"
alias ec2restart='aws ec2 stop-instances --instance-ids i-0a2b2499f654e7155 && \
aws ec2 wait instance-stopped --instance-ids i-0a2b2499f654e7155 && \
aws ec2 start-instances --instance-ids i-0a2b2499f654e7155 && \
aws ec2 wait instance-running --instance-ids i-0a2b2499f654e7155'
