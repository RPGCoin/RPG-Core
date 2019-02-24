#!/usr/bin/env python3
# Script to audit the assets
# Reads the asset (amount has all issuances)
# Reads the balances in every address for the asset.
# Compares the two numbers to checks that qty of all assets are accounted for

import subprocess
import json


#Set this to your rpg-cli program
cli = "rpg-cli"

mode =  "-testnet"
rpc_port = 17210
#mode =  "-regtest"
#rpc_port = 18210

#Set this information in your rpg.conf file (in datadir, not testnet3)
rpc_user = 'rpcuser'
rpc_pass = 'rpcpass555'

def listassets(filter):
    rpc_connection = get_rpc_connection()
    result = rpc_connection.listassets(filter, True)
    return(result) 

def listaddressesbyasset(asset, bool, num1, num2):
    rpc_connection = get_rpc_connection()
    result = rpc_connection.listaddressesbyasset(asset, bool, num1, num2)
    return(result) 

def rpc_call(params):
    process = subprocess.Popen([cli, mode, params], stdout=subprocess.PIPE)
    out, err = process.communicate()
    return(out)

def generate_blocks(n):
    rpc_connection = get_rpc_connection()
    hashes = rpc_connection.generate(n)
    return(hashes)

def get_rpc_connection():
    from bitcoinrpc.authproxy import AuthServiceProxy, JSONRPCException
    connection = "http://%s:%s@127.0.0.1:%s"%(rpc_user, rpc_pass, rpc_port)
    #print("Connection: " + connection)
    rpc_connection = AuthServiceProxy(connection)
    return(rpc_connection)

def audit(filter):
    assets = listassets(filter)
    print("Auditing: " + filter)
    #print(assets)
    print("Asset count: " + str(len(assets)))
    count = 0  
    max_dist_asset_name = ""
    max_dist_address_count = 0
    for asset, properties in assets.items():
        count=count+1
        total_issued = 0
        total_for_asset = 0

        print("Auditing asset (" + str(count) + "): " + asset)
        for key, value in properties.items():
            if (key == 'amount'):
                total_issued += value
                print("Total issued for " + asset + " is: " + str(value))

        loop = True
        nloop = 0
        naddresses = 0
        while loop:
            address_qtys = listaddressesbyasset(asset, False, 50000, nloop * 50000)
            naddresses += len(address_qtys)
            for address, qty in address_qtys.items():
                print(address + " -> " + str(qty))
                total_for_asset += qty
            if len(address_qtys < 50000)
                loop = False
            nloop += 1
        print("Total in addresses for asset " + asset + " is " + str(total_for_asset))

        #Calculate stats
        if naddresses > max_dist_address_count:
            max_dist_asset_name = asset
            max_dist_address_count = naddresses

        if (total_issued == total_for_asset):
            print("Audit PASSED for " + asset)
            print("")
        else:
            print("Audit FAILED for " + asset)
            exit()

        if len(assets) == count:
            print("All " + str(len(assets)) + " assets audited.")
            print("Stats:")
            print("  Max Distribed Asset: " + max_dist_asset_name + " with " + str(max_dist_address_count) + " addresses.")



if mode == "-regtest":  #If regtest then mine our own blocks
    import os
    os.system(cli + " " + mode + " generate 400")

audit("*")  #Set to "*" for all.
