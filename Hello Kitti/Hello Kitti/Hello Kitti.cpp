// Hello Kitti.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"


//! [includes]

#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma comment(lib, "opencv_core310.lib")
#pragma comment(lib, "opencv_imgcodecs310.lib")
#pragma comment(lib, "opencv_highgui310.lib")

using namespace cv;
//using namespace std;

int main(int argc, char** argv)
{
	//! [load]
	string repository("../data/ImageGroup1/"); // by default
	string imageNumber = stringPhotoNumber(1);
	string imageName = repository + imageNumber + ".png";

	//if (argc > 1)
	//{
	//	imageName = argv[1];
	//}

	//! [mat]
	Mat image;

	//! [imread]
	image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file

	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	//! [window]
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.

	//! [imshow]
	imshow("Display window", image);                // Show our image inside it.


	//! [wait]
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}



// s'il ne trouve pas la librairie : #pragma comment(lib, "talib.lib")