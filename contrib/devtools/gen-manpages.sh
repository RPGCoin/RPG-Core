#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

RPGD=${RPGD:-$SRCDIR/rpgd}
RPGCLI=${RPGCLI:-$SRCDIR/rpg-cli}
RPGTX=${RPGTX:-$SRCDIR/rpg-tx}
RPGQT=${RPGQT:-$SRCDIR/qt/rpg-qt}

[ ! -x $RPGD ] && echo "$RPGD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
RPGVER=($($RPGCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for rpgd if --version-string is not set,
# but has different outcomes for rpg-qt and rpg-cli.
echo "[COPYRIGHT]" > footer.h2m
$RPGD --version | sed -n '1!p' >> footer.h2m

for cmd in $RPGD $RPGCLI $RPGTX $RPGQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${RPGVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${RPGVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
