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
