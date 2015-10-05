#pragma once

#include "lib.ih"
#include <string>
void record(const string& name,const int frames,const int fps=25)
{
	VideoCapture cap(0);
	if(!cap.isOpened())
	{
		cout << "Error opening webcam\n";exit(0);
	}
	int frame_width=   cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height=  cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	
	VideoWriter video("records/"+name+"avi",CV_FOURCC('P','I','M','1'),fps, Size(frame_width,frame_height),true);
	if ( !video.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
   	{
	        cout << "ERROR: Failed to write the video" << endl;
       		exit(0);
   	}
	Mat M;
	namedWindow("webcam",CV_WINDOW_AUTOSIZE);
	for(int i=0;i<frames;++i)
	{
		cap >> M;
		video.write(M);
		imshow("webcam",M);
		if(waitKey(1000/fps) == 27) break; //interupt 
	}
	cout << "successfully recorded video: " << name+".avi\n";
	return;
}
