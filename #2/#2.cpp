#include<iostream>
#include<vector>
using namespace std;

int separation(vector<int> &v, int left, int right, int pivot)
{
	int i = left;
	for (int j = left; j < right; j++){
		if (v[j] < pivot){
			swap(v[i], v[j]);
			i++;
		} else if (v[j] == pivot){
			swap(v[j], v[right]);
			j--;
		}
	}
	swap(v[i], v[right]);
	return i;
}


//Separates the bolts and nuts arrays
void match(vector<int> &bolts, vector<int> &nuts, int left, int right)
{
	if (left < right){
		int pivot = separation(nuts, left, right, bolts[right]);

		separation(bolts, left, right, nuts[pivot]);

		match(nuts, bolts, left, pivot - 1);
		match(nuts, bolts, pivot + 1, right);
	}
}

void CoutVector(vector<int> v, int n)
{
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


int main()
{
	int n = 10;
	vector<int> bolts = { 8, 3, 9, 2, 7, 1, 11, 4, 6, 5 };
	vector<int> nuts = { 9, 1, 3, 11, 5, 6, 2, 7, 8, 4 };

	cout << "Bolts: " << endl;
	CoutVector(bolts, n);
	cout << "Nuts: " << endl;
	CoutVector(nuts, n);
	match(bolts, nuts, 0, n - 1);
	cout << "Bolts and nuts after matching:" << endl;
	CoutVector(bolts, n);
	CoutVector(nuts, n);

	system("pause");
	return 0;
}
