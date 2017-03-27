/**
*
* @daniel
*
*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

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
	
	Mat leftUpSide(src, Rect(0, 0, width / 2, height / 2));
	Mat rightUpSide(src, Rect(width / 2, 0, width / 2, height / 2));
	Mat leftDownSide(src, Rect(0, height / 2, width / 2, height / 2));
	Mat rightDownSide(src, Rect(width / 2, height / 2, width / 2, height / 2));
	Mat imageParts[] = { leftUpSide, rightUpSide, leftDownSide, rightDownSide};

	Mat saida = Mat::zeros(src.size(), src.type());
	
	
	imageParts[0].copyTo(saida(Rect(width / 2, width / 2, height/ 2, height/ 2)));
	imageParts[1].copyTo(saida(Rect(0, height / 2, width / 2, height / 2)));
	imageParts[2].copyTo(saida(Rect(height / 2, 0, width / 2, height / 2)));
	imageParts[3].copyTo(saida(Rect(0, 0, width / 2, height / 2)));

	namedWindow("Questão 2", WINDOW_AUTOSIZE);
	imshow("Questão 2", saida);
	waitKey();
	return 0;
}