#!/bin/sh
#to be run on the device
wget https://github.com/flamaque/TurnPageRM2/archive/refs/tags/a.tar.gz -O - | tar xvf -
cp /home/root/touch.service /etc/systemd/system
systemctl enable touch
systemctl start touch
