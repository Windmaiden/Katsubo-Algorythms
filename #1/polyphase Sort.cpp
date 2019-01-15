#include <iostream>
#include <vector>
using namespace std;

//Initial sort. Complexity is O(n)
void firstSort(vector<int> &A)
{
	vector<int> B(A.size());
	int x = -1; 
	//counts the amount of "0" in array
	for (int i = 0; i < A.size(); ++i)
		if (A[i] == 0) x++;
	int y = A.size() - 1;
	for (int i = A.size() - 1; i >= 0; --i){
		if (A[i] == 0){
			B[x] = A[i];
			x--;
		}
		else{
			B[y] = A[i];
			y--;
		}
	}
	A = B;
}

//Second sort. O(n)
void secondSort(vector<int> &A)
{
	int c = 0;
	for (int i = 0; i < A.size(); ++i){
		if (A[i] == 0){
			swap(A[i], A[c]);
			c++;
		}
	}
}

//Third sort.
void thirdSort(vector<int> &A)
{
	int i = -1; //index of the last "0" in sorted array
	for (int j = 0; j < A.size(); ++j){
		if (A[j] == 0){
			for (int k = j; (k - i - 1) > 0; k--){
				swap(A[k], A[k - 1]);
			}
			i++;
		}
	}
}

void Show(vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> A = { 1,0,1,0,1,0,1 };
	vector<int> B = { 1,1,1,1,1,1,0,0,0,0,0,0,1,1};
	vector<int> C = { 0,0,0,0,1,1,0,0,1,0,1 };
	cout << "First Sort: ";
	firstSort(A);
	Show(A);
	cout << "Second Sort: ";
	secondSort(B);
	Show(B);
	cout << "Third Sort: ";
	thirdSort(C);
	Show(C);
	cin.get();
	return 0;
}
