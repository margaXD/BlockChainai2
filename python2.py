from bitcoin.rpc import RawProxy 
from hashlib import sha256 
import binascii 
import struct 
def hexify(value, type): 
return binascii.hexlify(struct.Struct(type.pack(value)) 
p = RawProxy() 
blockas = 100000 
kitasblockas = blockas + 1 
Hashas = p.getblockhash(blockas) 
block = p.getblock(Hashas) 
Versija = block['version'] 
HashPries = block['previousblockhash'] 
MRH = block['merklerooti] 
bits = block['bits'] 
timestamp = block['time'] 
nonce = block['nonce'] 

    header_hex = '{Versija}{HashPries}{MRH}{timestamp}(bits){nonce}'.format( 
Versija=hexify(Versija, '<L'), 
HashPries=binascii.hexlify(HashPries.decode('hex')[::-1]), 
MRH=binascii.hexlify(MRH.decode('hex')[::-1]), 
timestamp=hexify(timestamp, '<L'), 
bits=binascii.hexlify(bits.decode('hex')[::-1]), 
nonce=hexify(nonce, '<L') 

block = header_hex.decode('hex') 
hash = sha256(sha256(block).digest()).digest() 
block_hash = hash[::-1].encode('hex_codec1) 
blockhash = p.getblockhash(kitasblockal) 
block = p.getblock(blockhash) 
if(blockpreviousblockhashi] = block_hash): 
print(blokai sutampa hashe m+ block_hash) 
else: 
print(blokai nesutampa") 
