
Debian
====================
This directory contains files used to package rpgd/rpg-qt
for Debian-based Linux systems. If you compile rpgd/rpg-qt yourself, there are some useful files here.

## rpg: URI support ##


rpg-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install rpg-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your rpg-qt binary to `/usr/bin`
and the `../../share/pixmaps/rpg128.png` to `/usr/share/pixmaps`

rpg-qt.protocol (KDE)

