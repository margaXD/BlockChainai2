#include "Header.h"
int main()
{
	int  x = 1000, j = 0, l, h;
	int c = 0, blocks = 0;
	users A[1000];
	BeUser(A);
	blockchain bChain[100];
	std::ofstream fd("output.txt");
	std::string line, newhash;
	std::string start;
	transaction tActionFuncThing;
	tActionFuncThing = tActionFunc(A);
	block tActions[5];
	while (x > 100)
	{
		for (int b = 0; b < 5; b++)
		{
			l = 0;
			srand((unsigned)time(0));
			for (int i = 0; i < 100; i++)
			{
				h = rand() % (x - 1);
				for (j = 0; j < 1000; j++) {
					if (tActionFuncThing.deliverer[h] == A[i].publicKey)break;
				}
				if (tActionFuncThing.sum[h] >= A[j].sum && tActionFuncThing.tActionID[h] == Hash(tActionFuncThing.deliverer[h] + tActionFuncThing.receiver[h] + std::to_string(tActionFuncThing.sum[h]))){
					tActions[l].tAction[blocks] = tActionFuncThing.tActionID[h];
				}
				else {
					for (j = h; j < (x - 2); j++){
						tActionFuncThing.tActionID[j] = tActionFuncThing.tActionID[j + 1];
						tActionFuncThing.receiver[j] = tActionFuncThing.receiver[j + 1];
						tActionFuncThing.deliverer[j] = tActionFuncThing.deliverer[j + 1];
						tActionFuncThing.sum[j] = tActionFuncThing.sum[j + 1];
					}
					i--;
					x--;

				}
			}
			MT(tActions, blocks);
		}
		int deliver = 0, recieve = 0;
		int skaitliukas = 10000;
		start = "0";
		while (start == "0"){
			for (int i = 0; i < 5; i++){
				start = ProofOfWork(tActions, bChain, blocks, c, skaitliukas);
			}
			skaitliukas *= 2;
			std::cout << "Naujo rasto bloko hashas :" << start << "   " << std::endl;
		}
		bChain[c].Hash = start;
		for (int i = 0; i < 100; i++){
			for (int j = 0; j < x; j++)
				if (tActionFuncThing.tActionID[j] == tActions[blocks].tAction[i])
					break;
			for (int k = 0; k < 1000; k++){
				if (A[k].publicKey == (tActionFuncThing.deliverer[j]))deliver = k;
				else if (A[k].publicKey == tActionFuncThing.receiver[j])recieve = k;
				if (deliver != 0 && recieve != 0)break;
			}
			A[deliver].sum -= tActionFuncThing.sum[j];
			A[recieve].sum += tActionFuncThing.sum[j];
			for (int m = j; m < (x - 1); m++)
			{
				tActionFuncThing.tActionID[m] = tActionFuncThing.tActionID[m + 1];
				tActionFuncThing.deliverer[m] = tActionFuncThing.deliverer[m + 1];
				tActionFuncThing.receiver[m] = tActionFuncThing.receiver[m + 1];
				tActionFuncThing.sum[m] = tActionFuncThing.sum[m + 1];
			}
			x--;
		}
		for (int i = 0; i < 100; i++)
			bChain[i].Transactions[c] = tActions[blocks].tAction[i];

		fd <<"Naujo rasto bloko hashas :"<< bChain[c].Hash << std::endl;
		c++;
	}
	return 0;
}