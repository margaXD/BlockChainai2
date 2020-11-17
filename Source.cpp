#include "Header.h"

int hashas::Readingas(std::string raktas) {
	int ASCIIValue = 0;
	int ilgis = raktas.length();

	std::string zodis;
	for (int i = 0; i < raktas.length(); i++)
	{
		ASCIIValue = ASCIIValue + (int)raktas[i];
	}
	return ASCIIValue;
}
int hashas::Readingas2(std::string raktas) {
	int NumberOfLetterA = 0;
	for (int i = 0; i < raktas.length(); i++)
	{
		if (raktas[i] == 'A' || raktas[i] == 'a') NumberOfLetterA++;
	}
	return NumberOfLetterA;
}
int hashas::Readingas3(std::string raktas) {
	int NumberOfLetterE = 0;
	for (int i = 0; i < raktas.length(); i++)
	{
		if (raktas[i] == 'E' || raktas[i] == 'e') NumberOfLetterE++;
	}
	return NumberOfLetterE;
}
std::string hashas::Hashavimas(long long int UniqueHashSeed, int skaitliukasSPACE, int maxValue, int charValue, int NumberOfLetterA, int NumberOfNumber1) {
	std::string GalutinisHashas = "";
	std::string Hashavimas[8];
	std::stringstream HexStream;
	HexStream << std::hex << UniqueHashSeed;
	Hashavimas[0] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 154800;
	Hashavimas[1] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 595200;
	Hashavimas[2] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 981004;
	Hashavimas[3] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 855002;
	Hashavimas[4] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 999009;
	Hashavimas[5] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 1000002;
	Hashavimas[6] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 9508;
	Hashavimas[7] = HexStream.str();
	for (int i = 0; i < 8; i++)
	{
		GalutinisHashas = GalutinisHashas + Hashavimas[i];
	}
	if (GalutinisHashas.length() > 64) {
		GalutinisHashas = GalutinisHashas.erase(64, GalutinisHashas.length());
	}
	return GalutinisHashas;

}
transaction tAction(users Users) {
	transaction tAction1;
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
	srand((unsigned)time(0));
	for (int i = 0; i < 10000; i++) {
		tAction1.deliverer[i] = Users.sum[rand() % 999];
		tAction1.receiver[i] = Users.sum[rand() % 999];
		tAction1.sum[i] = (rand() % 100) + 1;
		Hashed = tAction1.deliverer[i] + tAction1.receiver[i] + std::to_string(tAction1.sum[i]);
		charValue = charValue + Hashed.length();
		value = hashasX.Readingas(Hashed);
		NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(Hashed);
		NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(Hashed);
		maxValue = maxValue + value;
		UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
		Hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
		tAction1.transactionID[i] = Hash;
	}
	return tAction1;
}
users BeUsers() {
	users users1;
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
	const int MAX = 26;
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
					  'h', 'i', 'j', 'k', 'l', 'm', 'n',
					  'o', 'p', 'q', 'r', 's', 't', 'u',
					  'v', 'w', 'x', 'y', 'z' };
	std::string name;
	srand((unsigned)time(0));
	for (int i = 0; i < 1000; i++) {
		name = "";
		for (int j = 0; j < 10; j++) {
			name += alphabet[(rand() % 26) + 0];
		}
		users1.name[i] = name + std::to_string(i);
		charValue = charValue + users1.name[i].length();
		value = hashasX.Readingas(users1.name[i]);
		NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(users1.name[i]);
		NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(users1.name[i]);
		maxValue = maxValue + value;
		UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
		Hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
		users1.publicKey[i] = Hash;
		users1.sum[i] = (rand() % 1000) + 10;
	}
	return users1;
}
std::string ProofOfWork(blockChain BlockChain[], int count, block Block[], int ccount) {
	int skaitliukas = 100000;
	hashas hashasX;
	int skaitliukasSPACE = 1; // number of spaces in document + 1
	int maxValue = 1; // ASCII sum of all the characters in document + 1
	int charValue = 1; // Number of characters in document + 1
	int NumberOfLetterA = 1; // Number of letter a in document + 1
	int NumberOfLetterE = 1; // Number of number 1 in document + 1
	int value;
	long long int UniqueHashSeed;
	Block[0].PBH = "";
	if (count == 0) {
		for (int i = 0; i < 64; i++) {
			Block[0].PBH = Block[0].PBH + "0";
		}
	}
	else Block[count].PBH = BlockChain[ccount - 1].Hash;
	Block[count].timestamp = std::time(nullptr);
	Block[count].version = std::to_string(count) + ".0";
	Block[count].diffTarget = "0";
	int sizer = Block[count].diffTarget.size();
	srand((unsigned)time(0));
	std::string hash;
	for (int i = 0; i < skaitliukas; i++) {
		Block[count].nonce = rand() % 1000000;
		std::string Hash = Block[count].diffTarget + Block[count].MRH[0] + std::to_string(Block[count].nonce) + Block[count].PBH + Block[count].timestamp + Block[count].version;
		std::string Hashed;
		charValue = charValue + Hash.length();
		value = hashasX.Readingas(Hash);
		NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(Hash);
		NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(Hash);
		maxValue = maxValue + value;
		UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
		hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
		if (hash.substr(1, sizer) == Block[count].diffTarget) return hash;
	}
	std::cout << "Code ran into a problem" << std::endl;
	ProofOfWork(BlockChain, count, Block, ccount);
}

void MT(block Block[], int count) {
	int skaitliukas = 50;
	int skaitliukasSPACE = 1; // number of spaces in document + 1
	int maxValue = 1; // ASCII sum of all the characters in document + 1
	int charValue = 1; // Number of characters in document + 1
	int NumberOfLetterA = 1; // Number of letter a in document + 1
	int NumberOfLetterE = 1; // Number of number 1 in document + 1
	int value;
	hashas hashasX;
	long long int UniqueHashSeed;
	std::string Hashed;
	std::string Hash;
	for (int i = 0; i < 100; i += 2) {
		Hash = Block[count].tAction[i] + Block[count].tAction[i + 1];
		charValue = charValue + Hashed.length();
		value = hashasX.Readingas(Hashed);
		NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(Hashed);
		NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(Hashed);
		maxValue = maxValue + value;
		UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
		Hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
		Block[count].MRH[i / 2] = Hash;
	}
	while (skaitliukas != 1) {
		for (int i = 0; i < skaitliukas; i++) {
			Hash = Block[count].MRH[i] + Block[count].MRH[i + 1];
			charValue = charValue + Hashed.length();
			value = hashasX.Readingas(Hashed);
			NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(Hashed);
			NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(Hashed);
			maxValue = maxValue + value;
			UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
			Hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
			Block[count].MRH[i] = Hash;
			for (int j = i + 1; j < skaitliukas - 1; j++) {
				Block[count].MRH[j] = Block[count].MRH[j + 1];
			}
			skaitliukas--;
		}
	}
}