RPGcoin Core
+AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQ-

Setup
---------------------
RPGcoin Core is the original RPGcoin client and it builds the backbone of the network. It downloads and, by default, stores the entire history of RPGcoin transactions+ADs- depending on the speed of your computer and network connection, the synchronization process is typically complete in under an hour.

To download compiled binaries of the RPGcoin Core and wallet, visit the +AFs-GitHub release page+AF0-(https://github.com/RPGCoin/RPG-Core/releases).

Running
---------------------
The following are some helpful notes on how to run RPGcoin on your native platform.

+ACMAIwAj- Linux

1) Download and extract binaries to desired folder.

2) Install distribution-specific dependencies listed below.

3) Run the GUI wallet or only the RPGcoin core deamon

   a. GUI wallet:
   
   +AGA-./rpg-qt+AGA-

   b. Core deamon:
   
   +AGA-./rpgd -deamon+AGA-

+ACMAIwAjACM- Ubuntu 16.04, 17.04/17.10 and 18.04

Update apt cache and install general dependencies:

+AGAAYABg-
sudo apt update
sudo apt install libevent-dev libboost-all-dev libminiupnpc10 libzmq5 software-properties-common
+AGAAYABg-

The wallet requires version 4.8 of the Berkeley DB. The easiest way to get it is from the bitcoin repository: 

+AGAAYABg-
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt update
sudo apt install libdb4.8-dev libdb4.8dev
+AGAAYABg-

The GUI wallet requires the QR Code encoding library. Install with:

+AGA-sudo apt install libqrencode3+AGA-

+ACMAIwAjACM- Fedora 27

Install general dependencies:

+AGA-sudo dnf install zeromq libevent boost libdb4-cxx miniupnpc+AGA-

The GUI wallet requires the QR Code encoding library and Google's data interchange format Protocol Buffers. Install with:

+AGA-sudo dnf install qrencode protobuf+AGA-

+ACMAIwAjACM- CentOS 7

Add the EPEL repository and install general depencencies:

+AGAAYABg-
sudo yum install https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
sudo yum install zeromq libevent boost libdb4-cxx miniupnpc
+AGAAYABg-

The GUI wallet requires the QR Code encoding library and Google's data interchange format Protocol Buffers. Install with:

+AGA-sudo yum install qrencode protobuf+AGA-

+ACMAIwAj- OS X

1) Download RPG-Qt.dmg.

2) Double click the DMG to mount it. 

3) Drag RPG Core icon to the Applications Folder

+ACEAWw-alt tag+AF0-(https://i.imgur.com/GLhBFUV.png)

4) Open the Applications folder and Launch RPG Core. The client will begin synchronizing with the network.

+ACEAWw-alt tag+AF0-(https://i.imgur.com/v3962qo.png)

Note: You may get the follow error on first launch:
+AGAAYABg-
Dyld Error Message:
  Library not loaded: +AEA-loader+AF8-path/libboost+AF8-system-mt.dylib
  Referenced from: /Applications/RPG-Qt.app/Contents/Frameworks/libboost+AF8-thread-mt.dylib
  Reason: image not found
+AGAAYABg-
To resolve, you will need to copy libboost+AF8-system.dylib to libboost+AF8-system-mt.dylib in the /Applications/RPG-Qt.app/Contents/Frameworks folder

+ACMAIwAj- Windows

1) Download windows-x86+AF8-64.zip and unpack executables to desired folder.

2) Double click the rpg-qt.exe to launch it.

+ACMAIwAj- Need Help?

- See the documentation at the +AFs-RPGcoin Wiki+AF0-(https://rpg.wiki/wiki/RPGcoin+AF8-Wiki)
for help and more information.
- Ask for help on +AFs-Discord+AF0-(https://discord.gg/DUkcBst), +AFs-Telegram+AF0-(https://t.me/RPGcoinDev) or +AFs-Reddit+AF0-(https://www.reddit.com/r/RPGcoin/).
- Ask for help on the +AFs-RPGcoinTalk+AF0-(https://www.rpgcointalk.org/) forums, in the +AFs-Development and Technical discussion board+AF0-(https://www.rpgcointalk.org/?forum+AD0-661517).

Building from source
---------------------
The following are developer notes on how to build the RPGcoin core software on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- +AFs-Dependencies+AF0-(https://github.com/RPGCoin/RPG-Core/tree/master/doc/dependencies.md)
- +AFs-OS X Build Notes+AF0-(https://github.com/RPGCoin/RPG-Core/tree/master/doc/build-osx.md)
- +AFs-Unix Build Notes+AF0-(https://github.com/RPGCoin/RPG-Core/tree/master/doc/build-unix.md)
- +AFs-Windows Build Notes+AF0-(https://github.com/RPGCoin/RPG-Core/tree/master/doc/build-windows.md)
- +AFs-OpenBSD Build Notes+AF0-(https://github.com/RPGCoin/RPG-Core/tree/master/doc/build-openbsd.md)
- +AFs-Gitian Building Guide+AF0-(https://github.com/RPGCoin/RPG-Core/tree/master/doc/gitian-building.md)

Development
---------------------
RPGcoin repo's +AFs-root README+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/README.md) contains relevant information on the development process and automated testing.

- +AFs-Developer Notes+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/developer-notes.md)
- +AFs-Release Notes+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/release-notes.md)
- +AFs-Release Process+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/release-process.md)
- +AFs-Source Code Documentation (External Link)+AF0-(https://dev.visucore.com/rpg/doxygen/) -- 2018-05-11 -- Broken link
- +AFs-Translation Process+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/translation+AF8-process.md)
- +AFs-Translation Strings Policy+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/translation+AF8-strings+AF8-policy.md)
- +AFs-Travis CI+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/travis-ci.md)
- +AFs-Unauthenticated REST Interface+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/REST-interface.md)
- +AFs-Shared Libraries+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/shared-libraries.md)
- +AFs-BIPS+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/bips.md)
- +AFs-Dnsseed Policy+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/dnsseed-policy.md)
- +AFs-Benchmarking+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/benchmarking.md)

+ACMAIwAj- Resources
- Discuss on the +AFs-RPGcoinTalk+AF0-(https://www.rpgcointalk.org/) forums, in the +AFs-Development +ACY- Technical Discussion board+AF0-(https://www.rpgcointalk.org/?forum+AD0-661517).
- Discuss on chat +AFs-Discord+AF0-(https://discord.gg/DUkcBst), +AFs-Telegram+AF0-(https://t.me/RPGcoinDev) or +AFs-Reddit+AF0-(https://www.reddit.com/r/RPGcoin/).
- Find out more on the +AFs-RPGcoin Wiki+AF0-(https://rpg.wiki/wiki/RPGcoin+AF8-Wiki)
- Visit the project home +AFs-RPGcoin.org+AF0-(https://rpgcoin.org)

+ACMAIwAj- Miscellaneous
- +AFs-Assets Attribution+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/assets-attribution.md)
- +AFs-Files+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/files.md)
- +AFs-Fuzz-testing+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/fuzzing.md)
- +AFs-Reduce Traffic+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/reduce-traffic.md)
- +AFs-Tor Support+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/tor.md)
- +AFs-Init Scripts (systemd/upstart/openrc)+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/init.md)
- +AFs-ZMQ+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/doc/zmq.md)

License
---------------------
Distributed under the +AFs-MIT software license+AF0-(https://github.com/RPGCoin/RPG-Core/blob/master/COPYING).
This product includes software developed by the OpenSSL Project for use in the +AFs-OpenSSL Toolkit+AF0-(https://www.openssl.org/). This product includes
cryptographic software written by Eric Young (+AFs-eay+AEA-cryptsoft.com+AF0-(mailto:eay+AEA-cryptsoft.com)), and UPnP software written by Thomas Bernard.
