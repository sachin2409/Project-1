#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat rotate(Mat src, double angle)
{
	Mat rot;
	Point2f pt(src.cols/2., src.rows/2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);
	warpAffine(src, rot, r, Size(src.cols, src.rows));
	return rot;
}

int main()
{
	Mat image = imread("Chittorgarh.jpg");
	if (image.empty())
	{
		cout << "Error!" << endl;
		cin.get();
		return -1;
	}
	int ang;
	cin >> ang;
	Mat image1 = rotate(image, ang);
	imshow("Original", image);
	imshow("Rotated", image1);
	waitKey(0);
	destroyWindow("Original");
	destroyWindow("Rotated");
	return 0;
}