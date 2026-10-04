#include <iostream>
#include "Image_Class.h"
using namespace std;

void flipImage(Image& image)
{
	cout << "Enter 1 if Horizontal and 0 if Vertical: " << endl;
	bool isHorizontal;
	cin >> isHorizontal;

	if (isHorizontal) {
		for (int y = 0; y < image.height; y++) {
			for (int x = 0; x < image.width / 2; x++) {
				for (int z = 0; z < image.channels; z++) {


					pixel temp = image(x, y, z);
					image(x, y, z) = image(image.width - 1 - x, y, z);
					image(image.width - 1 - x, y, z) = temp;
				}
			}
		}
	}
	else {
		for (int x = 0; x < image.width; x++) {
			for (int y = 0; y < image.height / 2; y++) {
				for (int z = 0; z < image.channels; z++) {


					pixel temp = image(x, y, z);
					image(x, y, z) = image(x, image.height - 1 - y, z);
					image(x, image.height - 1 - y, z) = temp;
				}
			}
		}
	}
}

 int main() {
	string inFile;
	cout << " Enter your image name: " << endl;
	cin >> inFile;
	Image image(inFile);
	flipImage(image);

	
	string outFile;
	cout << "Enter your flipped image name: " << endl;
	cin >> outFile;
	image.saveImage(outFile);
	return 0;
 }
		
