// Copyright (c) 2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The RPG Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "consensus.h"
#include <validation.h>

unsigned int GetMaxBlockWeight()
{
        return MAX_BLOCK_WEIGHT_RIP2;
}

unsigned int GetMaxBlockSerializedSize()
{
        return MAX_BLOCK_SERIALIZED_SIZE_RIP2;
}
