#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include "skeletonization.hpp"
#include "zhang_suen.hpp"

using namespace cv;
using namespace std;

void skeletonization(Mat& img){
    img /= 255;

    Mat prev = Mat::zeros(img.size(), CV_8UC1);
    Mat diff;

    do {
        zhang_suen(img, 0);
        zhang_suen(img, 1);
        absdiff(img, prev, diff);
        img.copyTo(prev);
    } while (countNonZero(diff) > 0);



    img *= 255;
    imshow("img", img);
}