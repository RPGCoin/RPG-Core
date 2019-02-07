// Copyright (c) 2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The RPG Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RPG_QT_RPGADDRESSVALIDATOR_H
#define RPG_QT_RPGADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class RPGAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit RPGAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** RPG address widget validator, checks for a valid rpg address.
 */
class RPGAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit RPGAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // RPG_QT_RPGADDRESSVALIDATOR_H
