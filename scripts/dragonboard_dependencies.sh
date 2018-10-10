#!/bin/sh

# lib mraa
sudo add-apt-repository ppa:mraa/mraa
sudo apt-get update
sudo apt-get install libmraa2 libmraa-dev libmraa-java python-mraa python3-mraa node-mraa mraa-tools

# lib libsoc
sudo apt-get install autoconf build-essential libtool-bin pkg-config python-dev python3-dev
git clone https://github.com/jackmitch/libsoc.git libsoc.git
cd libsoc.git
autoreconf -i
./configure
make
make install

# mongo
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install mongodb-server

# mosquitto broker
sudo apt-get install mosquitto mosquitto-clients -y

# mosquitto_sub -h localhost -t test
# mosquitto_pub -h localhost -t test -m "hello world"
