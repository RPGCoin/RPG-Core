// Copyright (c) 2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The RPG Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RPG_RPGCONSENSUS_H
#define RPG_RPGCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_RPG_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/rpg-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBRPGCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define RPGCONSENSUS_API_VER 1

typedef enum rpgconsensus_error_t
{
    rpgconsensus_ERR_OK = 0,
    rpgconsensus_ERR_TX_INDEX,
    rpgconsensus_ERR_TX_SIZE_MISMATCH,
    rpgconsensus_ERR_TX_DESERIALIZE,
    rpgconsensus_ERR_AMOUNT_REQUIRED,
    rpgconsensus_ERR_INVALID_FLAGS,
} rpgconsensus_error;

/** Script verification flags */
enum
{
    rpgconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    rpgconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    rpgconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    rpgconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    rpgconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    rpgconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    rpgconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    rpgconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = rpgconsensus_SCRIPT_FLAGS_VERIFY_P2SH | rpgconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               rpgconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | rpgconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               rpgconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | rpgconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int rpgconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, rpgconsensus_error* err);

EXPORT_SYMBOL int rpgconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, rpgconsensus_error* err);

EXPORT_SYMBOL unsigned int rpgconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // RPG_RPGCONSENSUS_H
