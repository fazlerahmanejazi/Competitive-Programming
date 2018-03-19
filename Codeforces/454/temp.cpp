#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int v1,v2,v3,vm;
	cin >> v1 >> v2 >> v3 >> vm;
	for(int i = v1; i <= 2000; i++)
	{
		for(int j = v2; j < i; j++)
		{
			for(int k = v3; k < j; k++)
			{
				if(i >= v1 && i <= 2*v1 && j >= v2 && j <= 2*v2 && k >= v3 && 2*v3 >= k && vm <= k && 2*vm >= k)
				{
					cout << i <<" " << j <<" " << k;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}
