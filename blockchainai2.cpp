#include "Header.h"
int main()
{
	int skaitliukas = 50;
	int skaitliukasSPACE = 1; // number of spaces in document + 1
	int maxValue = 1; // ASCII sum of all the characters in document + 1
	int charValue = 1; // Number of characters in document + 1
	int NumberOfLetterA = 1; // Number of letter a in document + 1
	int NumberOfLetterE = 1; // Number of number 1 in document + 1
	int value;
	hashas hashasX;
	std::string Hashed;
	std::string Hash;
	long long int UniqueHashSeed;
	std::ofstream ostream("doc.txt");
	int size = 10000;
	int count = 0;
	int ccount = 0;
	int x, y, z;
	std::string line, hash;
	users Users;
	transaction tAction1;
	Users = BeUsers();
	tAction1 = tAction(Users);
	block Block[5];
	blockChain BlockChain[100];
	while (size >= 100)
	{
		z = 0;
		srand((unsigned)time(0));
		for (int i = 0; i < 100; i++)
		{
			x = rand() % (size - 1);
			for (y = 0; y < 1000; y++) {
				if (tAction1.deliverer[x] == Users.publicKey[y])break;
			}
			Hashed = tAction1.deliverer[x] + tAction1.receiver[x] + std::to_string(tAction1.sum[x]);
			charValue = charValue + Hashed.length();
			value = hashasX.Readingas(Hashed);
			NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(Hashed);
			NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(Hashed);
			maxValue = maxValue + value;
			UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
			Hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
			if (tAction1.sum[x] >= Users.sum[y] && tAction1.transactionID[x] == Hash) {
				Block[count].tAction[z] = tAction1.transactionID[x];
				z++;
			}
			else {
				for (y = x; y < (size - 2); y++) {
					tAction1.transactionID[y] = tAction1.transactionID[y + 1];
					tAction1.deliverer[y] = tAction1.deliverer[y + 1];
					tAction1.receiver[y] = tAction1.receiver[y + 1];
					tAction1.sum[y] = tAction1.sum[y + 1];
				}
				i--;
				size--;
			}
		}
		MT(Block, count);
		BlockChain[ccount].Hash = ProofOfWork(BlockChain, count, Block, ccount);
		for (int i = 0; i < 100; i++) {
			int deliver = 0;
			int recieve = 0;
			for (int y = 0; y < size; y++) {
				if (tAction1.transactionID[y] == Block[count].tAction[i])break;
			}
			for (int l = 0; l < 1000; l++) {
				if (Users.publicKey[l] == tAction1.deliverer[y]) deliver = l;
				else if (Users.publicKey[l] == tAction1.receiver[y]) recieve = l;
				if (recieve != 0 && deliver != 0)break;
			}
			Users.sum[deliver] -= tAction1.sum[y];
			Users.sum[recieve] += tAction1.sum[y];
			for (int k = y; k < (size - 1); k++) {
				tAction1.transactionID[k] = tAction1.transactionID[k + 1];
				tAction1.receiver[k] = tAction1.receiver[k + 1];
				tAction1.deliverer[k] = tAction1.deliverer[k + 1];
				tAction1.sum[k] = tAction1.sum[k + 1];
			}
			size--;
		}
		for (int i = 0; i < 100; i++) {
			BlockChain[ccount].tAction[i] = Block[count].tAction[i];
		}
		ostream << BlockChain[ccount].Hash << std::endl;
		ccount++;
	}
	return 0;

}