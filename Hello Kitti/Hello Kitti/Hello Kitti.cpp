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
	string entry;
	int repositoryValue;
	bool validEntry = false;
	string repository; // by default
	int nbImages;
	
	//check valid entry and set photo folder used
	do {
		std::cout << "please enter the image repository number you want to use..." << endl;
		getline(cin, entry);
		repositoryValue = stoi(entry);
		switch (repositoryValue)
		{
		case 1:
			repository = "../data/ImageGroup1/";
			nbImages = 107;
			validEntry = true;
			std::cout << "valid entry" << endl;
			break;
		default:
			std::cout << "error ! try again, ";
			break;
		}

	} while (validEntry == false);

	int ActualImageValue = 1;
	namedWindow("DisplaySource", WINDOW_AUTOSIZE); // Create a window for display.
	std::cout << "starting images sample " << repositoryValue << " with " << nbImages << " images" << endl;

	do {

		//! [load]
		string imageNumber = stringPhotoNumber(ActualImageValue);
		string imageName = repository + imageNumber + ".png";

		//! [mat]
		Mat image;

		//! [imread]
		image = imread(imageName.c_str(), IMREAD_COLOR);	// Read the file
		if (image.empty())									// Check for invalid input
		{
			std::cout << "Could not open or find the image" << std::endl;
			return -1;
		}

		//! [imshow]
		imshow("DisplaySource", image);                // Show our image inside it.

		Sleep(1000);


		ActualImageValue++;
	} while (ActualImageValue < nbImages);

	std::cout << "images sample ending" << endl;


	//! [wait]
	
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}



// s'il ne trouve pas la librairie : #pragma comment(lib, "talib.lib")