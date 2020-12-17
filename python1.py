from bitcoin.rpc import RawProxy 
p = RawProxy() 
In = 0 
Out = 0 
Hashas = raw_input("Hashas?") 
RawHash = p.getrawtransaction(Hashas) 
Decode = p.decoderawtransaction(RawHash) 
for input in Decode['vin']: 
vinHash = input['txid'] 
vinRaw = p.getrawtransaction(vinHash) 
vinDecode = p.decoderawtransaction(vinRaw) 
vinOutput = input['vouti] 
for output in vinDecode['vout']: 
if(vinOutput = output['n']): 
In += outputrvalue'l 
for output in Decode['vout']: 
Out += output['value'] 
print(In -Out) 