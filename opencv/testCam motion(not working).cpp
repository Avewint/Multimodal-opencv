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

///

///functions 1 
int dig_key = 0;
int region_coordinates[10][4];
void myMouseCallback(int event, int x, int y, int flags, void* param)
{

	IplImage* img = (IplImage*)param;

	switch (event) {
	case CV_EVENT_MOUSEMOVE:
		//printf("%d x %d\n", x, y);
		break;

	case CV_EVENT_LBUTTONDOWN:
		//printf("%d x %d\n", region_coordinates[dig_key][0], region_coordinates[dig_key][1]);  
		if (region_coordinates[dig_key][0] != 0 && region_coordinates[dig_key][1] != 0 && region_coordinates[dig_key][2] == 0 && region_coordinates[dig_key][3] == 0)
		{
			region_coordinates[dig_key][2] = x;
			region_coordinates[dig_key][3] = y;
		}
		if (region_coordinates[dig_key][0] == 0 && region_coordinates[dig_key][1] == 0)
		{
			region_coordinates[dig_key][0] = x;
			region_coordinates[dig_key][1] = y;
		}
		break;

	case CV_EVENT_RBUTTONDOWN:
		break;
	case CV_EVENT_LBUTTONUP:
		break;
	}
}
///end functions 1



int main()
{
	VideoCapture cap(0); // 1st device, DSHOW
	while (cap.isOpened())
	{
		Mat frame;
		cap >> frame;
		imshow("ocv", frame);

		///variables
		IplImage* image = 0;
		CvCapture* capture = 0;
		int fps = 0;
		int fps_sec = 0;
		int now_sec = 0;
		char fps_text[2];
		CvFont font;
		cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, 1.0, 1, 1, 8);
		/// end variables

		//// zdes nachinaem
		cvSetMouseCallback("Motion", myMouseCallback, (void*)image);
		if (region_coordinates[dig_key][0] != 0 && region_coordinates[dig_key][1] != 0 && region_coordinates[dig_key][2] == 0 && region_coordinates[dig_key][3] == 0)
			cvRectangle(image, cvPoint(region_coordinates[dig_key][0], region_coordinates[dig_key][1]), cvPoint(region_coordinates[dig_key][0] + 1, region_coordinates[dig_key][1] + 1), CV_RGB(0, 0, 255), 2, CV_AA, 0);

		if (region_coordinates[dig_key][0] != 0 && region_coordinates[dig_key][1] != 0 && region_coordinates[dig_key][2] != 0 && region_coordinates[dig_key][3] != 0)
			cvRectangle(image, cvPoint(region_coordinates[dig_key][0], region_coordinates[dig_key][1]), cvPoint(region_coordinates[dig_key][2], region_coordinates[dig_key][3]), CV_RGB(0, 0, 255), 2, CV_AA, 0);
		cvPutText(image, fps_text, cvPoint(5, 20), &font, CV_RGB(255, 255, 255));
		cvShowImage("Motion", image);
		//// zdes konchaem
		int k = waitKey(10);
		if (k == 27) break;
	}


	return 0;
}