#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"
#include "bmplib.cpp"


void EnterFileNameImage();
void savefile();
void Filter_1();
void Filter_2();



using namespace std;
unsigned char image[256][256];



int main() {
    int choice;
	cout << "Which filter do you want?" << endl;
	cout << "1-Filter-1: convert image into white/black image." << endl << "2-Filter-2: convert image to its reverse" << endl;
	cin >> choice;
	if (choice == 1){
        EnterFileNameImage();
        Filter_1();
        savefile();
	}
	else if (choice == 2){
        EnterFileNameImage();
        Filter_2();
        savefile();
	}



	return 0;
}

void EnterFileNameImage() {
	char imagefilename[100];

	cout << "Enter the file name: ";
	cin >> imagefilename;

	strcat(imagefilename, ".bmp");

	int source = readGSBMP(imagefilename, image);
}

void savefile() {
	char imagefilename[100];

	cout << "Enter the new name of file: ";
	cin >> imagefilename;

	strcat(imagefilename, ".bmp");

	int source = writeGSBMP(imagefilename, image);
}

void Filter_1() {
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			if (image[i][j] < 127) {
				image[i][j] = 0;
			}
			else {
				image[i][j] = 255;
			}
		}
	}
}

void Filter_2(){
    for (int i = 0; i < 256; i++){
        for (int j = 0; j < 256; j++){
            if (image[i][j] == 255){
                image[i][j] = 0;
            }
            else if(image[i][j] == 0){
                image[i][j] = 255;
            }
            else{
                image[i][j] = 255 - image[i][j];
            }
        }
    }
}



