#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	
	int WHITE = 255;
	int BLACK = 0;
	int BACKGROUND = 20;
	int BUBBLE = 60;
	int CIRCLE = 190;

	CvPoint p(0,0);
	Mat src = imread("bubble.png", CV_LOAD_IMAGE_GRAYSCALE);

	imshow("Labeling original", src);
	int width = src.size().width;
	int height = src.size().height;

	//Add white spaces in the edges
	for (int i = 0; i < width; i++) {
		src.at<uchar>(i, height - 1) = WHITE;
		src.at<uchar>(i, 0) = WHITE;
	}

	for (int i = 0; i < height; i++) {
		src.at<uchar>(0, i) = WHITE;
		src.at<uchar>(width - 1, i) = WHITE;
	}
	//Floodfill the images to all become black and the bubbles in the edge desapear
	floodFill(src, p, BLACK);
	//Mark what is background
	floodFill(src, p, BACKGROUND);


	//Search for the circles, with and without bubbles
	int qtdTotal = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (src.at<uchar>(i, j) == WHITE) {
				p.x = j;
				p.y = i;
				floodFill(src, p, CIRCLE);
				qtdTotal++;
			}
		}
	}

	//Search for the bubbles
	int comBolha = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (src.at<uchar>(i, j) == BLACK) {
				p.x = j;
				p.y = i;
				floodFill(src, p, CIRCLE);
				floodFill(src, p, BUBBLE);
				comBolha++;
			}
		}
	}

	imshow("Labeling", src);
	imwrite("labeling.png", src);
	printf("Quantidade de elementos sem bolhas: %d, com bolhas: %d\n", qtdTotal - comBolha, comBolha);
	waitKey();
	return 0;
}