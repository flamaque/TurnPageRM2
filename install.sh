#!/bin/sh
#to be run on the device
wget https://github.com/flamaque/TurnPageRM2/archive/refs/tags/b.tar.gz -O - | tar xzvf -
cp /home/root/touch.service /etc/systemd/system
systemctl enable touch
systemctl start touch
