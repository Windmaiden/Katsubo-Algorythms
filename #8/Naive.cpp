#include <iostream>
#include <string>
using namespace std;

bool native(string base, string fin)
{
	bool ans = false;
	for (int i = 0; i < (int)base.size() - (int)fin.size() + 1; ++i)
	{
		for (int j = 0; j < fin.size(); ++j)
		{
			if (base[i + j] != fin[j]) break;
			if (j == fin.size() - 1) return true;
		}

	}
	return false;
}

int main()
{
	string base, fin;
	cin >> base >> fin;
	cout << native(base, fin) << endl;
	system("pause");
}