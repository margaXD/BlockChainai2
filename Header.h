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