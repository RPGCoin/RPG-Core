# Copyright (c) 2013-2016 The Bitcoin Core developers
# Copyright (c) 2017 The Raven Core developers
# Copyright (c) 2018 The RPG Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS)
AM_CXXFLAGS = $(HARDENED_CXXFLAGS) $(ERROR_CXXFLAGS)
AM_CPPFLAGS = $(HARDENED_CPPFLAGS)
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

RPG_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

RPG_INCLUDES += -I$(srcdir)/secp256k1/include
RPG_INCLUDES += $(UNIVALUE_CFLAGS)

LIBRPG_SERVER=librpg_server.a
LIBRPG_COMMON=librpg_common.a
LIBRPG_CONSENSUS=librpg_consensus.a
LIBRPG_CLI=librpg_cli.a
LIBRPG_UTIL=librpg_util.a
LIBRPG_CRYPTO=crypto/librpg_crypto.a
LIBRPGQT=qt/librpgqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBRPG_ZMQ=librpg_zmq.a
endif
if BUILD_RPG_LIBS
LIBRPGCONSENSUS=librpgconsensus.la
endif
if ENABLE_WALLET
LIBRPG_WALLET=librpg_wallet.a
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBRPG_CRYPTO) \
  $(LIBRPG_UTIL) \
  $(LIBRPG_COMMON) \
  $(LIBRPG_CONSENSUS) \
  $(LIBRPG_SERVER) \
  $(LIBRPG_CLI) \
  $(LIBRPG_WALLET) \
  $(LIBRPG_ZMQ)

lib_LTLIBRARIES = $(LIBRPGCONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_RPGD
  bin_PROGRAMS += rpgd
endif

if BUILD_RPG_CLI
  bin_PROGRAMS += rpg-cli
endif

if BUILD_RPG_TX
  bin_PROGRAMS += rpg-tx
endif

.PHONY: FORCE check-symbols check-security
# rpg core #
RPG_CORE_H = \
  addrdb.h \
  addressindex.h \
  spentindex.h \
  timestampindex.h \
  addrman.h \
  assets/assets.h \
  assets/assetdb.h \
  assets/assettypes.h \
  base58.h \
  bloom.h \
  blockencodings.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  compat.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  indirectmap.h \
  init.h \
  key.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  net_processing.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  noui.h \
  policy/feerate.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
  pow.h \
  protocol.h \
  random.h \
  reverse_iterator.h \
  reverselock.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/mining.h \
  rpc/protocol.h \
  rpc/safemode.h \
  rpc/server.h \
  rpc/register.h \
  scheduler.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  script/ismine.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadsafety.h \
  threadinterrupt.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  undo.h \
  util.h \
  utilmoneystr.h \
  utiltime.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  wallet/coincontrol.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/init.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  algo/sph_groestl.h \
  algo/sph_types.h \
  algo/sph_blake.h \
  algo/sph_bmw.h \
  algo/sph_jh.h \
  algo/sph_keccak.h \
  algo/sph_skein.h \
  algo/sph_luffa.h \
  algo/sph_cubehash.h \
  algo/sph_simd.h \
  algo/sph_echo.h \
  algo/sph_shavite.h \
  algo/sph_fugue.h \
  algo/sph_hamsi.h \
  algo/sph_shabal.h \
  algo/sph_sha2.h \
  algo/sph_haval.h \
  algo/sph_tiger.h \
  algo/lyra2.h \
  algo/sponge.h \
  algo/gost_streebog.h \
  algo/SWIFFTX/SWIFFTX.h \
  algo/hashx21s.h \
  algo/groestl.c \
  algo/blake.c \
  algo/bmw.c \
  algo/cubehash.c \
  algo/echo.c \
  algo/aes_helper.c \
  algo/jh.c \
  algo/keccak.c \
  algo/luffa.c \
  algo/shavite.c \
  algo/simd.c \
  algo/skein.c \
  algo/hamsi.c \
  algo/hamsi_helper.c \
  algo/whirlpool.c \
  algo/shabal.c \
  algo/fugue.c \
  algo/sha2.c \
  algo/extra.c \
  algo/extra.h \
  algo/sph_sha2big.c \
  algo/haval.c \
  algo/tiger.cpp \
  algo/lyra2.cpp \
  algo/sponge.cpp \
  algo/sph_sha2.c \
  algo/gost_streebog.c \
  algo/SWIFFTX/SWIFFTX.c

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
librpg_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between rpgd and rpg-qt
librpg_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
librpg_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_server_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  bloom.cpp \
  blockencodings.cpp \
  chain.cpp \
  checkpoints.cpp \
  consensus/consensus.cpp \
  consensus/tx_verify.cpp \
  httprpc.cpp \
  httpserver.cpp \
  init.cpp \
  dbwrapper.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  net_processing.cpp \
  noui.cpp \
  assets/assets.cpp \
  assets/assetdb.cpp \
  assets/assettypes.cpp \
  policy/fees.cpp \
  policy/policy.cpp \
  policy/rbf.cpp \
  pow.cpp \
  rest.cpp \
  rpc/assets.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/safemode.cpp \
  rpc/server.cpp \
  script/sigcache.cpp \
  script/ismine.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  ui_interface.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(RPG_CORE_H)

if ENABLE_ZMQ
librpg_zmq_a_CPPFLAGS = $(RPG_INCLUDES) $(ZMQ_CFLAGS)
librpg_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp
endif


# wallet: shared between rpgd and rpg-qt, but only linked
# when wallet enabled
librpg_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
librpg_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_wallet_a_SOURCES = \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/init.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  $(RPG_CORE_H)

# crypto primitives library
crypto_librpg_crypto_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_librpg_crypto_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_librpg_crypto_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha20.cpp \
  crypto/chacha20.h \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h \
  crypto/sph_sha2.h \
  crypto/sph_types.h

if USE_ASM
crypto_librpg_crypto_a_SOURCES += crypto/sha256_sse4.cpp
endif

# consensus: shared between all executables that validate any consensus rules.
librpg_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
librpg_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  algo/hashx21s.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/rpgconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  support/cleanse.h \
  support/cleanse.cpp \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  version.h \
  $(RPG_CORE_H)

# common: shared between rpgd, and rpg-qt and non-server tools
librpg_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
librpg_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_common_a_SOURCES = \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  keystore.cpp \
  netaddress.cpp \
  netbase.cpp \
  policy/feerate.cpp \
  protocol.cpp \
  scheduler.cpp \
  script/sign.cpp \
  script/standard.cpp \
  warnings.cpp \
  $(RPG_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
librpg_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
librpg_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util.cpp \
  utilmoneystr.cpp \
  utilstrencodings.cpp \
  utiltime.cpp \
  $(RPG_CORE_H)

if GLIBC_BACK_COMPAT
librpg_util_a_SOURCES += compat/glibc_compat.cpp
AM_LDFLAGS += $(COMPAT_LDFLAGS)
endif

# cli: shared between rpg-cli and rpg-qt
librpg_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
librpg_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librpg_cli_a_SOURCES = \
  rpc/client.cpp \
  $(RPG_CORE_H)

nodist_librpg_util_a_SOURCES = $(srcdir)/obj/build.h
#

# rpgd binary #
rpgd_SOURCES = rpgd.cpp
rpgd_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
rpgd_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
rpgd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
rpgd_SOURCES += rpgd-res.rc
endif

rpgd_LDADD = \
  $(LIBRPG_SERVER) \
  $(LIBRPG_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBRPG_UTIL) \
  $(LIBRPG_WALLET) \
  $(LIBRPG_ZMQ) \
  $(LIBRPG_CONSENSUS) \
  $(LIBRPG_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

rpgd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# rpg-cli binary #
rpg_cli_SOURCES = rpg-cli.cpp
rpg_cli_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES) $(EVENT_CFLAGS)
rpg_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
rpg_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
rpg_cli_SOURCES += rpg-cli-res.rc
endif

rpg_cli_LDADD = \
  $(LIBRPG_CLI) \
  $(LIBUNIVALUE) \
  $(LIBRPG_UTIL) \
  $(LIBRPG_CRYPTO)

rpg_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# rpg-tx binary #
rpg_tx_SOURCES = rpg-tx.cpp
rpg_tx_CPPFLAGS = $(AM_CPPFLAGS) $(RPG_INCLUDES)
rpg_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
rpg_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
rpg_tx_SOURCES += rpg-tx-res.rc
endif

rpg_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBRPG_COMMON) \
  $(LIBRPG_UTIL) \
  $(LIBRPG_CONSENSUS) \
  $(LIBRPG_CRYPTO) \
  $(LIBSECP256K1)

rpg_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# rpgconsensus library #
if BUILD_RPG_LIBS
include_HEADERS = script/rpgconsensus.h
librpgconsensus_la_SOURCES = $(crypto_librpg_crypto_a_SOURCES) $(librpg_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  librpgconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

librpgconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
librpgconsensus_la_LIBADD = $(LIBSECP256K1)
librpgconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_RPG_INTERNAL
librpgconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/rpg-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/rpg-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/rpg-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/rpg-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
