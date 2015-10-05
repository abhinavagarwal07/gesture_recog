#pragma  once
#include "lib.ih"
Mat fgMaskMOG2;
Mat frame;
#define MORPH_ELLIPSE_SIZE_THRES 2
void background_subtractor(const string& videoFilename)
{

	Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2();
	VideoCapture capture(videoFilename);
	if(!capture.isOpened()){
		cerr << "Unable to open video file: " << videoFilename << endl;
		exit(-1);
	}
	
        //get the frame number and write it on the current frame
        while(1){
		if(!capture.read(frame)) {
		    cerr << "Unable to read next frame." << endl;
		    cerr << "Exiting..." << endl;
		    exit(-1);
		}
		cvtColor(frame, frame, CV_BGR2GRAY);
		erode(frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES,MORPH_ELLIPSE_SIZE_THRES)) );
		erode(frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES, MORPH_ELLIPSE_SIZE_THRES)) );
		dilate( frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES, MORPH_ELLIPSE_SIZE_THRES)) ); 
		dilate( frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES, MORPH_ELLIPSE_SIZE_THRES)) ); 
		erode(frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES,MORPH_ELLIPSE_SIZE_THRES)) );
		erode(frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES, MORPH_ELLIPSE_SIZE_THRES)) );
		dilate( frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES, MORPH_ELLIPSE_SIZE_THRES)) ); 
		dilate( frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(MORPH_ELLIPSE_SIZE_THRES, MORPH_ELLIPSE_SIZE_THRES)) ); 

	       	pMOG2->apply(frame, fgMaskMOG2);

		stringstream ss;
		rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
		          cv::Scalar(255,255,255), -1);
		ss << capture.get(CAP_PROP_POS_FRAMES);
		string frameNumberString = ss.str();
		putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
		        FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));
		//show the current frame and the fg masks
		imshow("Frame", frame);
	        imshow("FG Mask MOG 2", fgMaskMOG2);
	        if(waitKey(50) >= 27) break;
	}
	
	capture.release();
}
