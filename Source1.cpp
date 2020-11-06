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
	HexStream << std::hex << UniqueHashSeed * 15480000;
	Hashavimas[1] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 5952000;
	Hashavimas[2] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 981004;
	Hashavimas[3] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 855002;
	Hashavimas[4] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 999009;
	Hashavimas[5] = HexStream.str();
	HexStream << std::hex << UniqueHashSeed * 10000002;
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