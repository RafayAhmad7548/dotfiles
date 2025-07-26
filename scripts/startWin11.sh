#!/bin/bash

systemctl start libvirtd || exit 1
virsh -c qemu:///system start win11

sleep 1

virt-viewer -c qemu:///system -f win11
