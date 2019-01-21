<h1 align="center">
  RPGcoin: A Peer to Peer Electronic System for the Creation and Transfer of In-Game Assets<br>
</h1>


<p align="center">
FrostyRPG<br>
http://www.rpgcoin.gg<br>
23rd December 2018
</p>
<p align="center"><i>
RPGcoin is an indie game blockchain focused on the tokenization of in game assets.
</i></p>

> **Abstract**. RPGcoin is a blockchain and platform optimized for indie game developers for transferring in-game assets, such as tokens, virtual real estate, and unique items game items such as armor, weapons or anything game devs can imagen. RPGcoin is built on a fork of the Ravencoin code. Key changes include a block reward, a change in the number of coins issued, but not the weighted distribution schedule and the addition of asset creation and messaging capabilities. RPGcoin is free and open source. RPGcoin (RPG) can be mined publicly and transparently using Proof of Work (POW) using the x21s algorithm. 50 million from the maximum total supply of 21 billion RPG have been set aside for crowd funding, private investors, public bounties, founders, and developers.  

## 1. Introduction

<p align="center"><i>
"It’s dangerous to go alone, take this!"
– The Legend of Zelda
</i></p>
RPGcoin allows the client and RPC commands to protect games assets from being accidentally destroyed providing a single native client to create, issue, track, and transfer game assets.
As a cryptocurrency RPG provides a market value to game assets providing additional value for developers and players alike.  
  
**RPG Assets**  
Game Assets are crypto tokens that can be issued directly from the RPG wallet using either the gui wallet or cli commands. The game assets represented as tokens exist on the RPGcoin blockchain and are transferable by simply sending the token(s) to a valid RPG address. Assets created on the RPG protocol have several advantages over ERC20 and ERC721 tokens: they are easier to use, tightly integrated with a native coin, and secured with fair POW mining and open source code not run by a centralized organization.

**Uses for Game Assets**  
Game Assets or tokens can be used for anything the game developers can think up. The ideas presented here are a sampling.

**Representing a share of a game project or indie studio**
*  Securities tokens: stock or shares of a game studio where the shares are represented by a token
rather than a physical stock certificate
*  Securities or partnership interests with the built-in ability to pay rewards in RPG (legal in
many free market countries)
*  Tokens which represent a coop, limited partnership, royalty sharing or profit sharing platform
*  A token which represents a crowd-funded item with the ability to transfer or resell the item

**Representing in-game virtual goods**
*  Collectable items such as rare or unique skins.
*  Power your entire in-game economy.
*  In-game currency and items, transferable out of game to outside marketplaces.
*  Resources like metal and wood for real-time strategy games.
*  Rare or unique items like magic swords, armor, spells or other role-playing game items.
*  Loot boxes for any game type.
*  Virtual real-estate and other player 'ownable' items. 

**Representing a game licece or credit**
*  Game license.
*  DLC and season pass credits
*  Player reward points

## 2. RPGcoin Launch and Algorithm

RPGcoin was announced on January _, 2019 and released binaries for mining on January _, 2019 using the x21s mining algorithm. x21s is intended to prevent immediate dominance by NiceHash, ASIC and FPGA mining equipment.

## 3. Asset Issuance & Transfer

<p align="center"><i>
"Steel wins battles. Gold wins wars."
- Davion the Dragon Knight, DOTA 2
</i></p>
To issue a token the creator must first choose a unique name and check its availability. Once the token name is confirmed as being unique on the RPG blockchain the creator burns 500 RPG to generate the token(s).

The issuer determines the quantity issued, the number of decimal places, and whether they will be allowed to issue more of the same token in the future. An image of the asset can be saved on the IPFS and its hash can be embeded into the RPG blockchain along with the asset.

In addition, since the tokens can be made either unique, limited, or fungible by the creator, game project managers will be able to have categories of token holders such as “Class A Shareholders”, “Lifetime Season Pass members”, or “Holders of __ in game item”.

## 4. Rewards - In Development

Allow the payment of rewards in the native token. With a single command the reward, denominated in RPG, is automatically divided evenly and sent pro-rata to the holders of the asset.

Examples:

1) A game developer(s), could create a token that represents a game studio business. Suppose he or she creates 1,000,000 GAMESTUDIO tokens. These tokens could be used to raise funds for the studio at USD$1.00 per GAMESTUDIO token allowing him or her to raise $1 Million USD to build the business and develop their game. These tokens can be sold and transferred easily by the owners. Suppose the game studio does extraordinarily well because the community is involved and the game is a top seller on many marketplaces. Now the game studio can reward those who believed in their project. With a simple command, the studio can send profits - denominated in any value RPG may have - to GAMESTUIDO token holders.

2) Lets say a game developer wants to reward players. Upon signing up to play each player could be given a previously created COOL_GAME_TOKEN. The game developers now have an effective way of send players rewards any time they wish either manually or triggered by some in game event. Player have a incentive because the reward of RPG they have been given can be transferred out of game for P2P trading on crypto exchanges.

## 5. Unique Tokens

Unique tokens allow token holders to create unique assets. Like ERC721 tokens, unique tokens are guaranteed to be unique and only one will exist. Unique tokens can change ownership by sending the unique token to another user’s address.

Some examples of unique tokens:

*  Imagine a game developer issues the asset named ARMOR. The developer can then make unique ARMOR assets by attaching a name or a serialized number to each suit of armor. These unique tokens can be transferred or sold to the player. The tokens ARMOR:Golden and ARMOR:Silver are not fungible and represent distinct pieces of armor. Since Armor:Golden is 100% unique only 1 lucky player will be able to own that item.

*  A game developer can issue the asset with the name of their game COOL_GAME_TITLE, and then assign each COOL_GAME_TITLE token a unique id or license key. The game tokens could be transferred as the license transfers. Each token COOL_GAME_TITLE:80899 and COOL_GAME_TITLE:420365 are unique tokens.

These in game assets could then be kept, traded with other players via QR codes and wallets or traded with NPC merchants for other items or in-game currency.

## 6. Messaging Stakeholders

<p align="center"><i>
"What is a man but the sum of his memories? We are the stories we live! The tales we tell ourselves!" 
-Clay Kaczmarek, Assassin’s Creed Brotherhood
</i></p>
A common problem with tokens/assets is that the token issuer cannot communicate with the token holders. This must be handled very carefully because the token holders do not always wish to be identified. The communication should allow the token holder to opt-out at any time. The message system should only allow select parties to use the message channel so that it is not a spam conduit.


The messaging system uses unique tokens to allow communication on the main token channel. For example, the COMPANY token would have a ~COMPANY:Alert token which allows alerts to be sent to all holders of COMPANY.

Newsletters, game developers, non-profits, activist organizations, corporations and other entities will be able to issue tokens for specific users and then message those users but unlike email or other messaging services, the messaging itself will be enabled only for token holders, thereby making the token transferable.

Messaging to token holders by authorized senders will be layered on top of the unique assets. The unique assets will act as a "talking stick" allowing messages to be sent by the channel owner. The KAAAWWW Protocol will be published with more information on this separately.

## 7. Voting

One of the problems, among many, with the existing US financial system is that all the shares are held in street name. In this age of fast communication, this makes holding a vote ridiculously difficult. A public company that issues shares on Nasdaq, as an example, will have to pay a quasi-monopoly company just to get the mailing addresses of their own shareholders at a given point in time. Then, a physical (dead tree) mailing must be sent out to shareholders with information on how to vote along with a proxy voting form.

By using the messaging system, the holders of a token can be notified of the vote, and by automatically issuing a VOTE token to every holder of a token, the vote can be automated from the client or through a web or mobile interface using the protocol built into RPGcoin.

Tokens are created to represent votes. RPGcoin will create an exact number of VOTE tokens and distribute them 1:1 to the token holders. These votes can be sent via the protocol to addresses that tally the votes. Because the voting tokens move the same way as assets, delegation of votes - sometimes known as delegative or liquid democracy[1] - is possible.

## 8. Privacy

<p align="center"><i>
It's a community where the threat of violence is impotent because violence is impossible, and violence is impossible because its participants cannot be linked to their true names or physical locations. (Wei Dai)[2]
</i></p>  
Privacy is key in investments and tokens because financial systems function better when assets are fungible and can trade in a frictionless manner. The project should seek to strengthen privacy in any way possible as future technological improvements are made.

As capabilities like messaging, assets, and rewards are added, privacy will be preserved in the same way that UTXO based cryptocurrencies separate identity from public addresses.

“Since we desire privacy, we must ensure that each party to a transaction have knowledge only of that which is directly necessary for that transaction. Since any information can be spoken of, we must ensure that we reveal as little as possible. In most cases personal identity is not salient.  
... When my identity is revealed by the underlying mechanism of the transaction, I have no privacy. I cannot here selectively reveal myself; I must always reveal myself.  
“Therefore, privacy in an open society requires anonymous transaction systems. Until now, cash has been the primary such system. An anonymous transaction system is not a secret transaction system. An anonymous system empowers individuals to reveal their identity when desired and only when desired; this is the essence of privacy.” (E. Hughes)[3].

## 9. Conclusion

RPGcoin is a platform coin built on the UTXO[4] model of Bitcoin. Modifying Bitcoin code to add these capabilities is not practical, but RPGcoin is a platform built from a code fork and issuing newly mined RPG. RPGcoin will be adding assets, rewards, unique assets, messaging, and voting. The RPG protocol’s capabilities will be rolled out in phases which will be done as a planned hard fork upgrade. The code base is designed allow users and developers to maintain a secure, decentralized, and tamper resistant network.


---

References

[1] https://en.wikipedia.org/wiki/Delegative_democracy
[2] W. Dei, “B-Money” [http://www.weidai.com/bmoney.txt](http://www.weidai.com/bmoney.txt)  
[3] E. Hughes https://www.activism.net/cypherpunk/manifesto.html 
[4] https://bitcoin.org/en/glossary/unspent-transaction-output  
