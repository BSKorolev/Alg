//simple multiplier
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Ââåäèòå ÷èñëî:" << endl;
	int x;
	cin >> x;
	int  n3 = 1; //áåð¸ì ÷èñëà ðàâíûå 1 êàê K,L,M =0
	while (n3 <= x) 
	{
		int n5 = 1;
		while (n5 <= x) 
		{
			int n7 = 1;
			while (n7 <= x) 
			{
				int result = n3 * n5 * n7;
				if (result <= x) 
				{
					cout << result << endl;
				}
				n7 *= 7;
			}
			n5 *= 5;
		}
		n3 *= 3;
	}
};
