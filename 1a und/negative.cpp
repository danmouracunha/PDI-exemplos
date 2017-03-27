/**
*
* @daniel
*
*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

/// Global variables
Mat src;
/**
* @function main
*/
int main(int, char** argv)
{
	/// Load an image
	src = imread("lena.jpg" , IMREAD_COLOR);
	
	int width = src.size().width;
	int height = src.size().height;
	
	int p1x = width/5;
	int p1y = width/5;
	int p2x = height;
	int p2y = height/2;

	namedWindow("Questão 1", WINDOW_AUTOSIZE);

	for (int i = p1x; i< p2x; i++) {
		for (int j = p1y; j< p2y; j++) {
			Vec3b valor = src.at<Vec3b>(i, j);
			valor[0] = 255 - valor[0];
			valor[1] = 255 - valor[1];
			valor[2] = 255 - valor[2];
			src.at<Vec3b>(i, j) = valor;
		}
	}
	imshow("Questão 1", src);
	waitKey();
	return 0;
}