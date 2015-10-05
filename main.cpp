#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <utility>
using namespace cv;
using namespace std;
#include "lib/background_subtraction.hpp"
//#include "lib/record.hpp"
const int fps = 50;
int main()
{
	namedWindow("Frame");
	namedWindow("FG Mask MOG 2");

	background_subtractor("records/3.webm");
//	record("1",100);
/*	VideoCapture cap("records/1.webm"); // open the default camera
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
*/
}
