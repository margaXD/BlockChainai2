# BlockChainai2
## V 0.1
Šioje versijoje sukurta primityvi blokų grandinės programa.<br>
Tekstiniuose failuose transactions ir users sugeneruota transakcijos ir vartotojai pagal užduoties formuluotę.<br>
Kode sukurtos 4 struktūros (users, transactions, block ir blockchain) ir panaudota hashavimo funkcija iš pirmos užduoties.<br>
Kode taip pat sukurtos 2 šių struktūrų funkcijos, viena MerkleRootHash funkcija ir ProofOfWork funkcija.<br>
2 struktūrų funkcijos naudojamos užpildyti userių ir transakcijų struktūras.<br>
Proof Of Work funckija ieško bloko atitinkančio reikalavimus(Nonce ir Difficulty Target) ir sukuria blokų grandinę.<br>
MerkleRootHash, akivaizdu, randa Merkle Root Hashą.<br>

# 0.1.2
Papildyta v0.1 versija.<br>

## V 0.2
Šioje versijoje MerkleRootHash funkcija pakeista į MerkleTree funkcija (MT).<br>
Taip pat šioje versijoje realizuotas transakcijų verifikavimas - Balanso tikrinimas ir transakcijų hasho tikrinimas.<br>
Patobulinta mining a.k.a ProofOfWork funckija.
