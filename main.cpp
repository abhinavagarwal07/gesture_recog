#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <utility>
using namespace cv;
using namespace std;
const int fps = 25;
int main()
{
	VideoCapture cap(0); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	namedWindow("original",1);

	for(;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("original",frame);
		
		if(waitKey(1000/fps) >= 0) break;
	}

}
