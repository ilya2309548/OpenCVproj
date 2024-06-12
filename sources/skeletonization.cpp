#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include "skeletonization.hpp"
#include "zhang_suen.hpp"
#include "remove_corner_pixels.hpp"
#include "guo_hall.hpp"


using namespace cv;
using namespace std;


void skeletonization(Mat& img) {
    img /= 255;

    Mat prev = Mat::zeros(img.size(), CV_8UC1);
    Mat diff;
    do {
        guo_hall(img, 0);
        guo_hall(img, 1);
        absdiff(img, prev, diff);
        img.copyTo(prev);
    } while (countNonZero(diff) > 0);

    img *= 255;
}