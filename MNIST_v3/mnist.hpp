/*****************************\
> MNIST Access library
> Version: 1.0
> Author: Saif Ahmed Quarishi
> Data: 24.MAY.2018
\*****************************/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Member Variables
vector<vector<unsigned char> > ImgArray;
u_int number_of_images;
u_int n_rows;
u_int n_cols;
u_int n_len;

u_int minst_ReverseNum(u_int i){
  return (i&0xFF000000)>>24|(i&0x000000FF)<<24|(i&0x00FF0000)>>8|(i&0x0000FF00)<<8;
}

// Default Constructor
void mnist_mnist(){
	number_of_images = 0;
	n_rows = 0;
	n_cols = 0;
	n_len = 0;
}

// Distructor
void mnist_dist(){
	number_of_images = 0;
	n_rows = 0;
	n_cols = 0;
}

int mnist_read(const string &ImgFileName, const string &LabFileName){
	u_int magic_number;
	unsigned char tmp;
	ifstream file;

	file.open(ImgFileName, ios::binary);

	if(file.is_open())
	{
		file.read((char*)&magic_number,sizeof(magic_number));
		magic_number= minst_ReverseNum(magic_number);
		if (magic_number != 0x0803)
		{
			cout << "ERROR: Incorrect Image File." << endl;
			file.close();
			mnist_dist();
			return 1;
		}

		file.read((char*)&number_of_images,sizeof(number_of_images));
		number_of_images= minst_ReverseNum(number_of_images);
		ImgArray.resize(number_of_images);

		file.read((char*)&n_rows,sizeof(n_rows));
		n_rows= minst_ReverseNum(n_rows);
		file.read((char*)&n_cols,sizeof(n_cols));
		n_cols= minst_ReverseNum(n_cols);

		n_len = (n_rows * n_cols) + 1;

		for (u_int i = 0; i < number_of_images; ++i)
			ImgArray[i].resize(n_len);

		for (u_int i = 0; i < number_of_images; ++i) {
			for (u_int j = 1; j < n_len; ++j){
				tmp = 0;
				file.read((char*)&tmp,sizeof(tmp));
				ImgArray[i][j] = tmp;
			}
		}

		file.close();
	}
	else{
		cout << "ERROR: File \"" << ImgFileName << "\" dosen't exist." << endl;
		mnist_dist();
		return 2;
	}

	file.open(LabFileName, ios::binary);

	if(file.is_open())
	{
		file.read((char*)&magic_number,sizeof(magic_number));
		magic_number= minst_ReverseNum(magic_number);

		if (magic_number != 0x0801)
		{
			cout << "ERROR: Incorrect Label File." << endl;
			file.close();
			mnist_dist();
			return 3;
		}

		u_int temp;
		file.read((char*)&temp,sizeof(temp));
		temp= minst_ReverseNum(temp);

		if (temp != number_of_images)
		{
			cout << "ERROR: Number of Image miss match." << endl;
			file.close();
			mnist_dist();
			return 4;
		}

		for (u_int i = 0; i < number_of_images; ++i) {
		    tmp = 0;
		    file.read((char*)&tmp,sizeof(tmp));
		    ImgArray[i][0] = tmp;
		}

		file.close();
	}
	else{
		cout << "ERROR: File \"" << LabFileName << "\" dosen't exist." << endl;
		mnist_dist();
		return 2;
	}

	return 0;
}

// Accessor Functions
u_int mnist_getImageNum(){
	return number_of_images;
}
u_int mnist_getRows(){
	return n_rows;
}
u_int mnist_getColumns(){
	return n_cols;
}
u_int mnist_getImgLen(){
	return n_len;
}
u_int mnist_getLabel(u_int imgNum){
	return (u_int)ImgArray[imgNum][0];
}

void mnist_ImgOut(u_int imgNum, const string &PicName){
	ofstream img (PicName + ".ppm");
	img << "P3" << endl;
	img << n_rows << " " << n_cols << endl;
	img << "255" << endl;

	for (int r = 0; r < n_rows; ++r)
	{ 
		for (int c = 0; c < n_cols; ++c)
			{ 
				int pix = ImgArray[imgNum][(n_rows*r)+c+1];

				img << pix << " " << pix << " " << pix << " " << endl;
			}
	}
}

vector<unsigned char> mnist_getPixels(u_int imgNum){
	vector<unsigned char> vect;
	vect.resize(n_len-1);

	for (u_int j = 1; j < n_len; ++j){
		vect[j] = ImgArray[imgNum][j];
	}

	return vect;
}