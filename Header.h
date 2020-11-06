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
struct blockchainas {
	std::string prevHash;
	int timestamp;
	std::string version;
	std::string MRH;
	int Nonce;
	int DifTarget;
	struct transaction {
		std::string transactionID;
		std::string receiver;
		std::string deliverer;
		int sum;
	};
};