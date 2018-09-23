#!/bin/sh

sudo npm i -g vue-cli
sudo npm i -g quasar-cli
sudo npm i -g yarn

cd ../software/front && sudo yarn
cd ../server && sudo npm i
