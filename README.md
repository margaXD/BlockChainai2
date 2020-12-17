BlockChainai2
V 0.1
Šioje versijoje sukurta primityvi blokų grandinės programa.
Tekstiniuose failuose transactions ir users sugeneruota transakcijos ir vartotojai pagal užduoties formuluotę.
Kode sukurtos 4 struktūros (users, transactions, block ir blockchain) ir panaudota hashavimo funkcija iš pirmos užduoties.
Kode taip pat sukurtos 2 šių struktūrų funkcijos, viena MerkleRootHash funkcija ir ProofOfWork funkcija.
2 struktūrų funkcijos naudojamos užpildyti userių ir transakcijų struktūras.
Proof Of Work funckija ieško bloko atitinkančio reikalavimus(Nonce ir Difficulty Target) ir sukuria blokų grandinę.
MerkleRootHash, akivaizdu, randa Merkle Root Hashą.

0.1.2
Papildyta v0.1 versija.

V 0.2
Šioje versijoje MerkleRootHash funkcija pakeista į MerkleTree funkcija (MT).
Taip pat šioje versijoje realizuotas transakcijų verifikavimas - Balanso tikrinimas ir transakcijų hasho tikrinimas.
Patobulinta mining a.k.a ProofOfWork funckija.

V 0.3 panaudotas libbitcoin ir create_merkle funckija.
