﻿#include <iostream>
#include<chrono>

using namespace std;

const int N = 16;

void showMatrix(int n, int C[][N]) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << C[i][j] << " ";
		cout << endl;
	}
}

//algorythm of matrix multipclication
void СlassicMultiply(int A[][N], int B[][N], int C[][N]) 
{  
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			C[i][j] = 0;
			for (int t = 0; t < 2; t++) {
				C[i][j] = C[i][j] + A[i][t] * B[t][j];
			}
		}
	}
}


void AddMatrix(int n, int X[][N], int Y[][N], int Z[][N]) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Z[i][j] = X[i][j] + Y[i][j];
		}
	}
}

void SubMatrix(int n, int X[][N], int Y[][N], int Z[][N]) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Z[i][j] = X[i][j] - Y[i][j];
		}
	}
}

/**
"n" indicates the order of A,B,C
*/
void Strassen(int n, int A[][N], int B[][N], int C[][N])
{
	int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
	int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
	int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
	int M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
	int AA[N][N], BB[N][N];

	if (n == 2) 
	{ 
		СlassicMultiply(A, B, C);
	}
	else 
	{
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + n / 2];
				A21[i][j] = A[i + n / 2][j];
				A22[i][j] = A[i + n / 2][j + n / 2];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + n / 2];
				B21[i][j] = B[i + n / 2][j];
				B22[i][j] = B[i + n / 2][j + n / 2];
			}
		}

		// M1 = (A11 + A22) × (B11 + B22)
		AddMatrix(n / 2, A11, A22, AA);
		AddMatrix(n / 2, B11, B22, BB);
		Strassen(n / 2, AA, BB, M1);

		// M2 = (A21 + A22) × B11
		AddMatrix(n / 2, A21, A22, AA);
		Strassen(n / 2, AA, B11, M2);

		// M3 = A11 × (B12 - B22)
		SubMatrix(n / 2, B12, B22, BB);
		Strassen(n / 2, A11, BB, M3);

		// M4 = A22 × (B21 - B11)
		SubMatrix(n / 2, B21, B11, BB);
		Strassen(n / 2, A22, BB, M4);

		// M5 = (A11 + A12) × B22
		AddMatrix(n / 2, A11, A12, AA);
		Strassen(n / 2, AA, B22, M5);

		// M6 = (A21 - A11) × (B11 + B12)
		SubMatrix(n / 2, A21, A11, AA);
		AddMatrix(n / 2, B11, B12, BB);
		Strassen(n / 2, AA, BB, M6);

		// M7 = (A12 - A22) × (B21 + B22)
		SubMatrix(n / 2, A12, A22, AA);
		AddMatrix(n / 2, B21, B22, BB);
		Strassen(n / 2, AA, BB, M7);

		// C11 = M1 + M4 - M5 + M7
		AddMatrix(n / 2, M1, M4, AA);
		SubMatrix(n / 2, M7, M5, BB);
		AddMatrix(n / 2, AA, BB, C11);

		// C12 = M3 + M5
		AddMatrix(n / 2, M3, M5, C12);

		// C21 = M2 + M4
		AddMatrix(n / 2, M2, M4, C21);

		// C22 = M1 - M2 + M3 + M6
		SubMatrix(n / 2, M1, M2, AA);
		AddMatrix(n / 2, M3, M6, BB);
		AddMatrix(n / 2, AA, BB, C22);

		//merge C[][N]
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				C[i][j] = C11[i][j];
				C[i][j + n / 2] = C12[i][j];
				C[i + n / 2][j] = C21[i][j];
				C[i + n / 2][j + n / 2] = C22[i][j];
			}
		}
	}
}

void Alg2(int A[][N], int B[][N], int C[][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
}






int main() {

	//int A[N][N] = {
	//	{5, 6, 2, 8},
	//	{6, 1, 9, 5},
	//	{4, 5, 6, 5},
	//	{7, 8, 9, 7}
	//};
	//
	//int B[N][N] = {
	//	{4, 5, 6, 5},
	//	{7, 8, 9, 7},
	//	{7, 3, 8, 2},
	//	{1, 2, 9, 1}
	//};

	srand(time(0));

	int A[N][N];
	int B[N][N];
	cout << "A = " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = rand()%10;
		}
	}
	showMatrix(N, A);
	cout << endl;
	cout << "B = " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			 B[i][j] = rand() % 10;
		}
	}

	showMatrix(N, B);

	cout << endl;

	int C1[N][N];

	auto start = chrono::high_resolution_clock::now();

	Strassen(N, A, B, C1);

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	cout << "C1 = " << endl;

	showMatrix(N, C1);
	cout << endl;

	cout << "Duration Strassen =  " << duration.count() << endl;

	int C2[N][N];

	auto st = chrono::high_resolution_clock::now();

	Alg2(A, B, C2);

	auto e = chrono::high_resolution_clock::now();
	chrono::duration<float> dur = e - st;

	cout << "C2 = " << endl;

	showMatrix(N, C2);
	cout << endl;

	cout << "Duration Alg2 =  " << dur.count() << endl;



	system("pause");
	return 0;
}
