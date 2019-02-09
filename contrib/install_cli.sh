 #!/usr/bin/env bash

 # Execute this file to install the rpg cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%RPG-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/RPG-Qt.app/Contents/MacOS/rpgd /usr/local/bin/rpgd
 sudo ln -s ${LOCATION}/RPG-Qt.app/Contents/MacOS/rpg-cli /usr/local/bin/rpg-cli
