/*****************************\
> MNIST Test Program
> Version: 1.0
> Author: Saif Ahmed Quarishi
> Data: 06.MAR.2018
\*****************************/

#include <iostream>
#include "mnist.hpp"
#include<math.h>

using namespace std;

typedef unsigned char U8;
typedef unsigned short int U16;

const U16 Len_A_x = 4;
const U16 Len_A_y = 6;

float learning_rate = .1;


const U16 flatten_length_of_image = 784;


float mat_weights[784];
float b;
float z;


  float sigmoid(float z){

 // return 1/(1+exp(-z));
    return (1/(1+exp(-z)))-0.0001;

}



int main()
{

  //initialized weights ///////////////////////////

  for(U16 i = 0; i < 784; i++){
    mat_weights[i] = (float)(rand()%100)/100;
  }

  b = 0;



  //############################


  mnist_read("train-images.idx3-ubyte", "train-labels.idx1-ubyte");

	// cout << "Number of Images: " << mnist.getImageNum() << endl;
	// cout << "Rows: " << mnist.getRows() << endl;
	// cout << "Columns: " << mnist.getColumns() << endl;

  cout << n_len << endl;

  u_int imgn = 457;
  vector<unsigned char> pixl;
  u_int n_rows = mnist_getRows();
  u_int n_cols = mnist_getColumns();
  u_int pix;


  pixl = mnist_getPixels(imgn);


  for (int i = 0; i < (n_len-1); ++i){
    pix = pixl[i+1];
    z = z+ mat_weights[i]*pix;
   // cout << pix << endl;

  }

z = z+ b;

float A = sigmoid(z);



cout << z << endl;


cout <<A << endl;

//cout << sigmoid(1000) << endl;

float y = 1;

float cost = -(y*log(A) + (1-y)*log(1-A));

cout << cost<<endl;

float dw;
float db = A - y;

for (int i = 0; i < (n_len-1); ++i){
    pix = pixl[i+1];

    dw = dw + pix*db;

   // z = z+ mat_weights[i]*pix;
   // cout << pix << endl;

  }

  cout << dw << endl;
  cout << db << endl;


  ///optimization
//#############################################33

  for (int i = 0; i < (n_len-1); ++i){
    pix = pixl[i+1];
      mat_weights[i] = mat_weights[i] - learning_rate * dw;
    cout << mat_weights[i] << endl;

  }

   /* for(U16 i = 0; i < 784; i++){
    mat_weights[i] = (float)(rand()%100)/100;
  }*/


  b = b - learning_rate * db;

  cout << b << endl;


  /*for (int r = 0; r < n_rows; ++r)
  { 
    cout << endl;
    for (int c = 0; c < n_cols; ++c)
      { 
        pix = pixl[(n_rows*r)+c+1];

        pix = (pix>128)? 1:0;

       cout << pix;
      }
  }*/

  // cout << "Label: " << mnist.getLabel(imgn) << endl;

  cout << endl;
	
	return 0;
}
