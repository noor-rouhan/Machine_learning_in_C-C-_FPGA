#include <iostream>
// #include <stdlib>
#include <Math.h>
using namespace std;


float sigmoid(float x)
{
	return 1/(1+exp(-x));
}

int main()

{
	int row_x = 4;
	int col_x = 1;

	int row_w = 1;
	int col_w = 4;

	float b = -.0028125;

	float x[3] = {0,19,19000};
	float w[3] = {-.000625,.006453125, -121.25};

	float temp = 0;

	for( int i = 0; i < col_w; i++)
	{    
        temp = temp + w[i]*x[i];
	}


	float z = temp + b;
	float a = sigmoid(z);
	cout << a << endl;
}