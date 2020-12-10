#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <chrono>
#include <ctime>
#include <streambuf>
#include <stdlib.h>
#include <cstdlib>
#include <bitcoin/bitcoin.hpp>
std::string Hash(std::string line);
char GetChar(int r1, char r11);
struct users {
	std::string name;
	std::string publicKey;
	double sum;
};
struct block
{
	std::string PBH;
	int timestamp;
	std::string version;
	std::string MRH[50];
	int nonce;
	std::string DiffTarget;
	std::string tAction[100];
};
struct transaction
{
	std::string tActionID[1000];
	std::string deliverer[1000];
	std::string receiver[1000];
	double sum[1000];
};
struct blockchain
{
	std::string Hash;
	std::string Transactions[100];
};
void MT(block tActions[], int blocks);
void BeUser(users A[]);
transaction tActionFunc(users A[]);
std::string ProofOfWork(block tActions[], blockchain bChain[], int blocks, int c, int& skaitliukas);
bc::hash_digest create_merkle(bc::hash_list& merkle);