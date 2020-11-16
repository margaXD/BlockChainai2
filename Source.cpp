#include "Header.h"

int main()
{
	/* 
	
	
	
	GENERATION PHASE
	
	
	
	*/
	const int MAX = 26;
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
					  'h', 'i', 'j', 'k', 'l', 'm', 'n',
					  'o', 'p', 'q', 'r', 's', 't', 'u',
					  'v', 'w', 'x', 'y', 'z' };
	// hashing seed factors
	int skaitliukasSPACE = 1; // number of spaces in document + 1
	int maxValue = 1; // ASCII sum of all the characters in document + 1
	int charValue = 1; // Number of characters in document + 1
	int NumberOfLetterA = 1; // Number of letter a in document + 1
	int NumberOfLetterE = 1; // Number of number 1 in document + 1
	int value;
	blockchainas blockChain[10];
	hashas hashasX;
	std::string publicKeyArray[1000];
	std::string transactionHashArray[10000];
	std::string transactionLines[10000];
	long long int UniqueHashSeed;
	std::ofstream GenUser("users.txt");
	std::ofstream GentAction("transactions.txt");
	for (int i = 0; i < 1000; i++) {
			std::string res = "";
			for (int j = 0; j < 10; j++){
				res = res + alphabet[rand() % MAX];
			}
			GenUser << res << " ";
			charValue = charValue + res.length();
			value = hashasX.Readingas(res);
			NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(res);
			NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(res);
			maxValue = maxValue + value;
			UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
			std::string hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
			GenUser << hash << " ";
			publicKeyArray[i] = hash;
			int suma = rand() % 1000000 + 100;
			GenUser << suma << std::endl;
			skaitliukasSPACE = 1; // number of spaces in document + 1
			maxValue = 1; // ASCII sum of all the characters in document + 1
			charValue = 1; // Number of characters in document + 1
			NumberOfLetterA = 1; // Number of letter a in document + 1
			NumberOfLetterE = 1; // Number of number 1 in document + 1
			int value = 0;
	}
	for (int i = 0; i < 10000; i++) {
		int seed1 = rand() % 999 + 1;
		int seed2 = rand() % 999 + 1;
		if (seed1 == seed2) seed2 = rand() % 999 + 1;
		int weight = rand() % 1000000 + 100;
		std::string res1 = publicKeyArray[seed1] + " " + publicKeyArray[seed2] + " " + std::to_string(weight);
		std::cout << res1 << std::endl;
		charValue = charValue + res1.length();
		value = hashasX.Readingas(res1);
		NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(res1);
		NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(res1);
		maxValue = maxValue + value;
		UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
		std::string hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
		transactionHashArray[i] = hash;
		GentAction << hash << " ";
		GentAction << publicKeyArray[seed1] << " ";
		GentAction << publicKeyArray[seed2] << " ";
		GentAction << weight << std::endl;
	}
	/*
	
	
	
	END GENERATION PHASE



	*/
	/*
	
	
	
	BLOCK CHAIN GENERATION PHASE
	
	
	
	*/
	/*TRANSAKCIJU PASIRINKIMAS*/
	int transactionSeeds[100];
	for (int i = 0; i < 100; i++)
	{
		transactionSeeds[i] = rand() % 9999;
	}
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i < 100; i++)
		{
			for (int j = i; j < 100; j++)
			{
				if (transactionSeeds[i] == transactionSeeds[j]) transactionSeeds[j] = rand() % 9999;
			}
		}
	}
	/*TRANSAKCIJU PASIRINKIMAS*/
	/*TRANSAKCIJU IDEJIMAS I BLOKA*/
	std::ifstream user("users.txt");
	std::ifstream tAction("transactions.txt");
	std::string reciever, deliverer;
	int weight1;
	int skaitliukas = 0;
	for (int i = 0; i < 10000; i++) {
		tAction >> reciever;
		tAction >> deliverer;
		tAction >> weight1;
		if (i == transactionSeeds[i]) {
			blockChain[0].T[skaitliukas].deliverer = deliverer;
			blockChain[0].T[skaitliukas].receiver = reciever;
			blockChain[0].T[skaitliukas].sum = weight1;
		}
	}
	for (int i = 0; i < 100; i++) {
		blockChain[0].T[i].transactionID = transactionHashArray[transactionSeeds[i]];
	}
	std::string finalHash = "";
	for (int i = 0; i < 100; i++) {
		finalHash = finalHash + blockChain[0].T[i].transactionID;
	}
	charValue = charValue + finalHash.length();
	value = hashasX.Readingas(finalHash);
	NumberOfLetterA = NumberOfLetterA + hashasX.Readingas2(finalHash);
	NumberOfLetterE = NumberOfLetterE + hashasX.Readingas3(finalHash);
	maxValue = maxValue + value;
	UniqueHashSeed = skaitliukasSPACE + maxValue + charValue * NumberOfLetterA * NumberOfLetterE;
	std::string hash = hashasX.Hashavimas(UniqueHashSeed, skaitliukasSPACE, maxValue, charValue, NumberOfLetterA, NumberOfLetterE);
	/*TRANSAKCIJU IDEJIMAS I BLOKA*/
	/*GENESIS BLOCK KURIMAS*/
	blockChain[0].MRH = hash;
	blockChain[0].prevHash = "0000000000000000000000000000000000000000000000000000000000000000";
	for (int i = 0; i < 10; i++)
	{
		blockChain[i].version = std::to_string(i) + ".0";
		blockChain[i].timestamp = std::time(nullptr);
	}
}
