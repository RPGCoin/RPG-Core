RASBERRY PI BUILD NOTES
====================
Origin: traysi.org/rpg_rpi.php

# Install necessary packages:
```
sudo apt-get install git
sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils python3
sudo apt-get install libboost-all-dev
sudo apt-get install software-properties-common
sudo apt-get update
sudo apt-get install libminiupnpc-dev
sudo apt-get install libzmq3-dev
```

# Increase your swap size:
```
sudo nano /etc/dphys-swapfile
- In this file, change CONF_SWAPSIZE=100 to CONF_SWAPSIZE=1000
sudo reboot
```

# Build Berkeley DB 4.8:
```
cd ~
mkdir build
cd build
wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
tar -xzvf db-4.8.30.NC.tar.gz
cd db-4.8.30.NC/build_unix/
../dist/configure --enable-cxx
make -j4 # If error, remove the -j4
sudo make install
```

# Build RPGcoin
```
cd ~/build/
git clone https://github.com/RPGCoin/RPG-Core
cd RPGcoin/
./autogen.sh
./configure --disable-tests --with-gui=no CPPFLAGS="-I/usr/local/BerkeleyDB.4.8/include -O2" LDFLAGS="-L/usr/local/BerkeleyDB.4.8/lib"
make
```
## Troubleshooting

If you receive an error such as the following during the make:

ccache: error: Failed to create temporary file for /home/YOURUSERNAME/.ccache/1/2/y3we5gwstrvw2qa43evrd-123174.o.tmp.stdout: Permission denied
you should run the following command before making

This is caused by ccache temp folders that got created by doing a build as root in the past (even if not RPG Coin but uses ccache) and the folders get owned by root, and so you can't write to them in the build without running it as sudo.  to avoid this, just take ownership of the .ccache folder then run the make again.

for example

sudo chown YOURUSERNAME:YOURUSERGROUP -R /home/YOURUSERNAME/.ccache 

---
