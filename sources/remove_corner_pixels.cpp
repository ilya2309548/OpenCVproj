#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include "remove_corner_pixels.hpp"

using namespace cv;
using namespace std;

void remove_corner_pixels(Mat& img) {
    Mat marker = Mat::zeros(img.size(), CV_8UC1);

    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            uchar p1 = img.at<uchar>(i, j);
            uchar p2 = img.at<uchar>(i - 1, j);
            uchar p3 = img.at<uchar>(i - 1, j + 1);
            uchar p4 = img.at<uchar>(i, j + 1);
            uchar p5 = img.at<uchar>(i + 1, j + 1);
            uchar p6 = img.at<uchar>(i + 1, j);
            uchar p7 = img.at<uchar>(i + 1, j - 1);
            uchar p8 = img.at<uchar>(i, j - 1);
            uchar p9 = img.at<uchar>(i - 1, j - 1);

            // Условия для углового пикселя
            bool is_corner_pixel = false;

            // Проверка верхнего левого угла
            if (p1 == 1 && p2 == 0 && p4 == 0 && p3 == 1 && p8 == 1) {
                is_corner_pixel = true;
            }
            // Проверка верхнего правого угла
            else if (p1 == 1 && p2 == 0 && p4 == 1 && p3 == 1 && p5 == 0) {
                is_corner_pixel = true;
            }
            // Проверка нижнего правого угла
            else if (p1 == 1 && p6 == 0 && p4 == 1 && p5 == 1 && p7 == 0) {
                is_corner_pixel = true;
            }
            // Проверка нижнего левого угла
            else if (p1 == 1 && p6 == 0 && p8 == 1 && p7 == 1 && p9 == 0) {
                is_corner_pixel = true;
            }

            if (is_corner_pixel) {
                marker.at<uchar>(i, j) = 1;
            }
        }
    }
    img &= ~marker;
}