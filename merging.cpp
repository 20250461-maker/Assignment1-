#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

Image mergeImages(Image image1, Image image2)
{
	int w = 0, h = 0;

	if (image1.width == image2.width && image1.height == image2.height)
	{
		w = image1.width;
		h = image1.height;
	}
	else
	{
		cout << "The 2 images are not the same size. If you want to resize the 2 images to the max choose option: 1, and if you want merge common area choose option: 2. " << endl;
		int option;
		cin >> option;

		if (option == 1)
		{
			w = max(image1.width, image2.width);
			h = max(image1.height, image2.height);


			if (image1.width != w || image1.height != h)
			{
				Image emptyImage1(w, h);
				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						int oldi = i * image1.height / h;
						int oldj = j * image1.width / w;

						emptyImage1(j, i, 0) = image1(oldj, oldi, 0);
						emptyImage1(j, i, 1) = image1(oldj, oldi, 1);
						emptyImage1(j, i, 2) = image1(oldj, oldi, 2);
					}
				}
				image1 = emptyImage1;
			}


			if (image2.width != w || image2.height != h)
			{
				Image emptyImage2(w, h);
				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						int oldi = i * image2.height / h;
						int oldj = j * image2.width / w;

						emptyImage2(j, i, 0) = image2(oldj, oldi, 0);
						emptyImage2(j, i, 1) = image2(oldj, oldi, 1);
						emptyImage2(j, i, 2) = image2(oldj, oldi, 2);
					}
				}
				image2 = emptyImage2;
			}
		}
		else if (option == 2)
		{
			w = min(image1.width, image2.width);
			h = min(image1.height, image2.height);
		}
	}


	Image mergedImage(w, h);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			for (int c = 0; c < 3; ++c) {
				mergedImage(j, i, c) = (image1(j, i, c) + image2(j, i, c)) / 2;
			}
		}
	}

	return mergedImage;
}

int main() {
	string inFile1, inFile2;
	cout << " Enter your first image name: " << endl;
	cin >> inFile1;

	cout << " Enter your sec image name: " << endl;
	cin >> inFile2;

	Image image1(inFile1);
	Image image2(inFile2);
	Image mergedImage = mergeImages(image1, image2);

	string outFile;
	cout << "Enter your merged image name: " << endl;
	cin >> outFile;
	mergedImage.saveImage(outFile);

	return 0;
}