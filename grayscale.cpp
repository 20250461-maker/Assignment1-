#include <iostream>
#include "Image_Class.h"
using namespace std;

void grayScale(Image& image)
{
	for (int i = 0; i < image.width; i++) {
		for (int j = 0; j < image.height; j++) {

			int R = image(i, j, 0);
			int G = image(i, j, 1);
			int B = image(i, j, 2);
			int gray = (R + G + B) / 3;

			image(i, j, 0) = gray;
			image(i, j, 1) = gray;
			image(i, j, 2) = gray;

		}
	}
}
int main() {
	string inFile;
	cout << "Enter your Image name: " << endl;
	cin >> inFile;

	Image image(inFile);
	grayScale(image);


	string outFile;
	cout << "Enter your new image name: " << endl;
	cin >> outFile;
	image.saveImage(outFile);
	return 0;
}