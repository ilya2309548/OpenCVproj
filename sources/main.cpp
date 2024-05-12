#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

int main() {

	string path = "../data/oboi.png";
	Mat image = imread(path);
	if (image.empty()) {
        std::cerr << "Failed to read image!" << std::endl;
        return 1;	
    }
	else{	
	imshow("Image", image);
	waitKey(0);
	return 0;}

}
