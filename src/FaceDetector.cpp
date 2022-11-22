#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;



void main() {
	string path = "Resources/mark.png";
	Mat img = imread(path);

	CascadeClassifier face_detector;
	face_detector.load("Resources/haarcascade_frontalface_default.xml");

	vector<Rect> faces;
	face_detector.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {

		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 0), 5);
	}

	imshow("Img", img);
	waitKey(0);
}
