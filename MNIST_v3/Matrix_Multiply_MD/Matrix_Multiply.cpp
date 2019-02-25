/*****************************\
> Matrix Multiply in C++
> Version: 1.0
> Author: Saif Ahmed Quarishi
> Data: 11.JAN.2019
\*****************************/

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned char U8;
typedef unsigned short int U16;

const U16 Len_A_x = 4;
const U16 Len_A_y = 6;

const U16 Len_B_x = 6;
const U16 Len_B_y = 5;

U16 mat_A[Len_A_x][Len_A_y];
U16 mat_B[Len_B_x][Len_B_y];
U16 mat_C[Len_A_x][Len_B_y];

// Multiply function
enum{A, B, C, AxB, BxA};

void Multiply_Mx(U8 num){
	switch(num){
		case AxB:
			
		break;

		default:break;
	}
}

// void Print_Mx(U8 num){
// for (U16 x = 0; x < Len_x; ++x)
// 	{
// 		cout << endl;
// 		for (U16 y = 0; y < Len_y; ++y)
// 			{
// 			switch(num){
// 			case A: cout << mat_A[x][y]; break;
// 			case B: cout << mat_B[x][y]; break;
// 			case C: cout << mat_C[x][y]; break;
// 			default:break;
// 			}
// 			cout << ", ";
// 		}
// 	}
// }

int main() {

	// Check for mismatch
	if(Len_A_y != Len_B_x){
		cout << "Bad Matirx"<< endl;
		return 0;
	}

	// Set Random Value to Matrix A
	for (int x = 0; x < Len_A_x; ++x)
	{
		for (int y = 0; y < Len_A_y; ++y)
		{
			mat_A[x][y] = (U16)(rand()%1000);
		}
	}

	// Set Random Value to Matrix B
	for (int x = 0; x < Len_B_x; ++x)
	{
		for (int y = 0; y < Len_B_y; ++y)
		{
			mat_B[x][y] = (U16)(rand()%1000);
		}
	}

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	// Multiply
	for (U16 x = 0; x < Len_A_x; ++x)
	{
		for (U16 y = 0; y < Len_B_y; ++y)
		{
			mat_C[x][y] = 0;
			for (U16 i = 0; i < Len_A_y; ++i)
			{
				mat_C[x][y] += mat_A[x][i] * mat_B[i][y];
			}
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	long double duration = duration_cast<nanoseconds>(t2-t1).count();

	// Print Matrix A
	cout << "Matrix A: ";
	for (int x = 0; x < Len_A_x; ++x)
	{
		cout << endl;
		for (int y = 0; y < Len_A_y; ++y)
		{
			cout << mat_A[x][y] << ", ";
		}
	}
	cout << endl << endl;

	// Print Matrix B
	cout << "Matrix B: ";
	for (int x = 0; x < Len_B_x; ++x)
	{
		cout << endl;
		for (int y = 0; y < Len_B_y; ++y)
		{
			cout << mat_B[x][y] << ", ";
		}
	}
	cout << endl << endl;

	// Print Matrix C
	cout << "Matrix C: ";
	for (int x = 0; x < Len_A_x; ++x)
	{
		cout << endl;
		for (int y = 0; y < Len_B_y; ++y)
		{
			cout << mat_C[x][y] << ", ";
		}
	}

	cout << endl << endl;

	cout << "Duration: " << duration << "ns";

	cout << endl << endl;
	return 0;
}