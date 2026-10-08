#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

void sunlight(Image& image) {
	for (int i = 0; i < image.width; i++) {
		for (int j = 0; j < image.height; j++) {
			int R = image(i, j, 0) + 50;
			image(i, j, 0) = min(255, R);

			int G = image(i, j, 1) + 40;
			image(i, j, 1) = min(255, G);

			int B = image(i, j, 2) - 15;
			image(i, j, 2) = max(0, B);
		}
	}
}
int main() {
	string inFile;
	cout << "Enter your Image name: " << endl;
	cin >> inFile;

	Image image(inFile);
	sunlight(image);


	string outFile;
	cout << "Enter your new image name: " << endl;
	cin >> outFile;
	image.saveImage(outFile);
	return 0;
}