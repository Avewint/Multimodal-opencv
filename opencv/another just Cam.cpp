#include "opencv2/opencv.hpp"
using namespace cv;

#include <iostream>
using namespace std;


///
#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
using namespace cv;
using namespace std;
int main()
{
	//create matrix for storage
	Mat image;
	Mat image2;
	Mat image3;
	Mat image4;

	//initialize capture
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		std::cerr << "Failed to open video capture" << std::endl;
		return -1;
	}

	namedWindow("window");

	while (true) {
		cap >> image;
		cap >> image2;

		if (image.empty() || image2.empty()) {
			std::cerr << "failed to capture images\n";
			return -1;
		}

		absdiff(image, image2, image3);
		threshold(image3, image4, 128, 255, THRESH_BINARY);

		imshow("window", image);
		int k = waitKey(30) & 0xff;
		if ('q' == k || 27 == k)
			break;

	}
}