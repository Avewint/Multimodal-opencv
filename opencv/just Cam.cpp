#include "opencv2/opencv.hpp"
using namespace cv;

#include <iostream>
using namespace std;

int main()
{
	VideoCapture cap(0); // 1st device, DSHOW
	while (cap.isOpened())
	{
		Mat frame;
		cap >> frame;
		imshow("ocv", frame);

		int k = waitKey(10);
		if (k == 27) break;
	}
	return 0;
}