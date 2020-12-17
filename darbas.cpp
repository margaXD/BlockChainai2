#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <time.h>
#include <streambuf>
#include <cmath>
using namespace std::chrono;
class hashas {

public:
    int Readingas(std::string raktas);
    std::string Hashavimas(long long int UniqueHashSeed, int skaitliukasSPACE, int maxValue, int charValue, int NumberOfLetterA, int NumberOfLetterE);
    std::string Hashavimas2(long long int UniqueHashSeed, int charValue, int NumberOfLetterA, int NumberOfLetterE);
    int Readingas2(std::string raktas);
    int Readingas3(std::string raktas);
};

struct transaction {
    std::string transactionID[10000];
    std::string receiver[10000];
    std::string deliverer[10000];
    int sum[10000];
};
struct users {
    std::string name[1000];
    std::string publicKey[1000];
    int sum[1000];
};
struct block {
    std::string tAction[100];
    std::string PBH;
    std::string timestamp;
    std::string version;
    std::string MRH[50];
    int nonce;
    std::string diffTarget;
};
struct blockChain {
    std::string Hash;
    std::string tAction[100];
};

transaction tAction(users Users);
users BeUsers();
std::string ProofOfWork(blockChain BlockChain[], int count, block Block[], int ccount);
void MT(block Block[], int count);
bc::hash_digest create_merkle(bc::hash_list& merkle)




int main() {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ ((std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
	/*Genesis Block Kurimas*/
	vector<Block>Blockchain;
	Block genesisBlock;
    genesisBlock.prevBlockHash = "None";
    genesisBlock.timeStamp = time(0);
    genesisBlock.version = "v0.2";
    genesisBlock.nonce = 0;
    genesisBlock.difficultyTarget = 3;
    Blockchain.push_back(genesisBlock);
    cout << "Sukurtas Genesis Blokas" << endl;
	/*Genesis Block Kurimas*/

	/*Transakciju ir useriu kurimas*/
    vector <User> users;
    std::uniform_int_distribution<unsigned> distrib(0, 1000);
    std::uniform_int_distribution<unsigned> distrib1(1, 200);
    for (int i = 0; i < 1000; i++) {
        User client;
        client.name = "user" + to_string(i);
        client.public_key = hash_function(hash_function(client.name + to_string(client.name.length()) + to_string(distrib(gen))));
        client.balance = distrib1(gen);
        users.push_back(client);
    }
    std::uniform_int_distribution<unsigned> distrib2(0, 500);
    vector<Transaction> transactionPool;
    int a = 0;
    for (int i = 0; i < 10000; i++) {
        Transaction trans;
        int x = distrib(gen);
        int y = distrib(gen);
        while (y != x)
            y = distrib(gen);
        trans.senderKey = users[x].public_key;
        trans.recipientKey = users[y].public_key;
        trans.sum = distrib2(gen);
        trans.transactionID = hash_function(trans.senderKey + trans.recipientKey + to_string(trans.sum));
        transactionPool.push_back(trans);
    }
	cout << "Sukurti useriai ir transakcijos" << endl;
	/*Transakciju ir useriu kurimas*/




    while (transactionPool.size() != 0) {
        vector<vector<Transaction>>takenTransactions;
        int TransactionID;
        vector<vector<Transaction>> fakeTransactionPool;
        for (int j = 0; j < 5; j++) {
            fakeTransactionPool.push_back(transactionPool);
            vector<Transaction>emptyTransaction;
            takenTransactions.push_back(emptyTransaction);
            for (int i = 0; i < 100; i++) {
                std::uniform_int_distribution<unsigned> distrib3(0, fakeTransactionPool[j].size());
                int randomID = distrib3(gen);
                takenTransactions[j].push_back(fakeTransactionPool[j][randomID]);
                fakeTransactionPool[j].erase(fakeTransactionPool[j].begin() + randomID);
            }
        }
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < 100; i++) {
                takenTransactions[j][i].completed = transactionConfirmation(takenTransactions[j][i], users);
            }
        }
        cout << "Ieskomi nauji blokai" << endl;
        Block newBlock = SearchForNextBlock(Blockchain.back(), takenTransactions, TransactionID);
        Blockchain.push_back(newBlock);
        transactionPool = fakeTransactionPool[TransactionID];
        cout << "Blokas pridetas" << endl;
        cout << "Nuskaiciuojamos transakcijos" << endl;
        for (int i = 0; i < 100; i++)
            if (transactionPool[i].completed)
                completeTransaction(transactionPool[i], users);
    }
    return 0;



	bc::hash_digest create_merkle(bc::hash_list & merkle)
	{
		// Stop if hash list is empty or contains one element
		if (merkle.empty())
			return bc::null_hash;
		else if (merkle.size() == 1)
			return merkle[0];
		// While there is more than 1 hash in the list, keep looping...
		while (merkle.size() > 1)
		{
			// If number of hashes is odd, duplicate last hash in the list.
			if (merkle.size() % 2 != 0)
				merkle.push_back(merkle.back());
			// List size is now even.
			assert(merkle.size() % 2 == 0);
			// New hash list.
			bc::hash_list new_merkle;
			// Loop through hashes 2 at a time.
			for (auto it = merkle.begin(); it != merkle.end(); it += 2)
			{
				// Join both current hashes together (concatenate).
				bc::data_chunk concat_data(bc::hash_size * 2);
				auto concat = bc::serializer<
					decltype(concat_data.begin())>(concat_data.begin());
				concat.write_hash(*it);
				concat.write_hash(*(it + 1));
				// Hash both of the hashes.
				bc::hash_digest new_root = bc::bitcoin_hash(concat_data);
				// Add this to the new list.
				new_merkle.push_back(new_root);
			}
			// This is the new list.
			merkle = new_merkle;
		}
		char GetChar(int cs, char cr)
		{
			switch (cs)
			{
			case 1: cr = 'A'; break;
			case 2: cr = 'a'; break;
			case 3: cr = 'B'; break;
			case 4: cr = 'b'; break;
			case 5: cr = 'C'; break;
			case 6: cr = 'c'; break;
			case 7: cr = 'D'; break;
			case 8: cr = 'd'; break;
			case 9: cr = 'E'; break;
			default: cr = 'F';
			}
			return cr;

		}
		std::string Hash(std::string line)
		{
			std::string pack, hash;
			int lngt, shw = 0, shw2 = 0, i, y, z = 0, cs;
			char cr = 'D';
			lngt = line.length();
			shw = line[0];
			y = 1;

			for (int i = 1; i < lngt; i++)
			{
				if (y == 0)
				{
					shw -= line[i];
					y++;
				}
				else
				{
					shw += line[i];
					y--;
				}
			}
			shw = abs(shw);

			for (i = 0; i < lngt; i++)
			{
				if (hash.length() >= 32)
					break;

				else
				{
					cs = (line[i] + shw2) % 10;
					hash += std::to_string(line[i] + shw2) + GetChar(cs, cr);
				}
				shw2++;
			}
			int shw3 = shw;
			int shw4 = shw;
			if (i == lngt)
			{
				while (hash.length() < 32)
				{
					shw2 = abs(shw2 * 2 - shw3 * 2);
					cs = shw2 % 10;
					hash += std::to_string(shw2) + GetChar(cs, cr);

					shw2 += 3;
					shw3 -= 3;
				}
			}
			else
			{
				for (int x = i; x < lngt; x++)
				{
					if (shw4 > 1000)
						shw4 %= 100;

					cs = (line[x] + shw4) % 10;
					pack = std::to_string(line[x] + shw4) + GetChar(cs, cr);

					if (z >= 32)
						z = 0;
					auto it1 = hash.begin() + z;
					auto it2 = hash.begin() + z + 3;
					hash.replace(it1, it2, pack);

					z += 3;

					if (x % 2 == 0)
						shw4 += 3;
					else
						shw4 -= 2;
				}
			}
			while (hash.length() > 32)
				hash.pop_back();

			return hash;
		}
		void  MT(block tActions[], int blocks)
		{
			int skaitliukas = 50;
			for (int i = 0; i < 100; i += 2) {
				tActions[blocks].MRH[i / 2] = Hash(tActions[blocks].tAction[i] + tActions[blocks].tAction[i + 1]);
			}
			while (skaitliukas != 1) {
				for (int i = 0; i < skaitliukas; i++) {
					tActions[blocks].MRH[i] = Hash(tActions[blocks].MRH[i] + tActions[blocks].MRH[i + 1]);
					for (int g = i++; g < skaitliukas - 1; g++) {
						tActions[blocks].MRH[g] = tActions[blocks].MRH[g + 1];
					}
					skaitliukas--;
				}
			}
		}

		void BeUser(users A[]) {
			for (auto i = 0; i < 1000; i++) {
				A[i].name = "User" + std::to_string(i);
				A[i].sum = rand() % 1000000 + 100;
				A[i].publicKey = Hash(A[i].name);
			}
		}

		transaction tActionFunc(users A[]) {
			transaction trss;
			for (int i = 0; i < 1000; i++) {
				trss.receiver[i] = A[rand() % 999].publicKey;
				trss.deliverer[i] = A[rand() % 999].publicKey;
				trss.sum[i] = rand() % 100;
				trss.tActionID[i] = Hash(trss.deliverer[i] + trss.receiver[i] + std::to_string(trss.sum[i]));
			}
			return trss;
		}
		string getBlockMerkelRootHash(const vector<Transaction>& t) {
			bc::hash_list tx_hashes;
			string zeros = "0000000000000000000000000";
			for (auto i : t) {
				char x[65];
				strcpy(x, (i.transactionID + zeros).c_str());
				tx_hashes.push_back(bc::hash_literal(x));
			}
			const bc::hash_digest merkle_root = create_merkle(tx_hashes);
			string merkleHash = bc::encode_base16(merkle_root);
			return merkleHash;
		}
		std::string ProofOfWork(block tActions[], blockchain bChain[], int blocks, int c, int& skaitliukas) {
			int x;
			std::string newhash;
			if (blocks == 0) {
				tActions[0].PBH = Hash("");
			}
			else {
				tActions[blocks].PBH = bChain[c - 1].Hash;
			}
			tActions[blocks].timestamp = std::time(nullptr);
			tActions[blocks].version = "v" + std::to_string(blocks + 1) + ".0";
			tActions[blocks].DiffTarget = "0";
			x = tActions[blocks].DiffTarget.size();
			cout << "Ieskomi nauji blokai" << endl;
			srand((unsigned)time(0));
			for (int i = 0; i < skaitliukas; i++)
			{
				tActions[blocks].nonce = rand() % 1000000;
				newhash = Hash(tActions[blocks].DiffTarget + tActions[blocks].MRH[0] + tActions[blocks].PBH + std::to_string(tActions[blocks].timestamp) + tActions[blocks].version + std::to_string(tActions[blocks].nonce));
				if (newhash.substr(1, x) == tActions[blocks].DiffTarget)
					return newhash;
			}
			cout << "Blokas pridetas" << endl;
			cout << "Nuskaiciuojamos transakcijos" << endl;
			return "0";
		}