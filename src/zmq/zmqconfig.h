// Copyright (c) 2014-2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The RPG Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RPG_ZMQ_ZMQCONFIG_H
#define RPG_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/rpg-config.h"
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"
#include "primitives/transaction.h"

void zmqError(const char *str);

#endif // RPG_ZMQ_ZMQCONFIG_H
