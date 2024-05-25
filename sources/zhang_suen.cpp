#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// ������� ��� ���������� ������������ �� ������ Zhang-Suen
void thinningIteration(Mat& img, int iter) {
    Mat marker = Mat::zeros(img.size(), CV_8UC1);

    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            uchar p2 = img.at<uchar>(i - 1, j);
            uchar p3 = img.at<uchar>(i - 1, j + 1);
            uchar p4 = img.at<uchar>(i, j + 1);
            uchar p5 = img.at<uchar>(i + 1, j + 1);
            uchar p6 = img.at<uchar>(i + 1, j);
            uchar p7 = img.at<uchar>(i + 1, j - 1);
            uchar p8 = img.at<uchar>(i, j - 1);
            uchar p9 = img.at<uchar>(i - 1, j - 1);

            int A = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
                (p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
                (p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
                (p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
            int B = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
            int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
            int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);

            if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0) {
                marker.at<uchar>(i, j) = 1;
            }
        }
    }
    img &= ~marker;
}

// ������� ��� ���������� ������������ ����� �����������
void thinning(Mat& img) {
    img /= 255;

    Mat prev = Mat::zeros(img.size(), CV_8UC1);
    Mat diff;

    do {
        thinningIteration(img, 0);
        thinningIteration(img, 1);
        absdiff(img, prev, diff);
        img.copyTo(prev);
    } while (countNonZero(diff) > 0);



    img *= 255;
    imshow("img", img);
}

int main() {
    // ��������� ���� �������� ����������� ��������� ������
    Mat img = imread("../../data/finger1.png", IMREAD_GRAYSCALE);
   /* imshow("hare.png", img);*/

    if (img.empty()) {
        cout << "������ �������� �����������!" << endl;
        return -1;
    }

    // ��������� ��������� ��������� ��� ����������� �����������
    threshold(img, img, 127, 255, THRESH_BINARY);
    //imshow("bin.png", img);
    bitwise_not(img, img);


    // ��������� ������������
    thinning(img);

    // ��������� ���������
    imwrite("skeletonized_fingerprint.png", img);

    // ���������� ���������
    imshow("Skeletonized Fingerprint", img);
    waitKey(0);

    return 0;
}






//int main() {
//	string path = "../../data/finger1.png";
//	Mat img = imread(path, IMREAD_GRAYSCALE);
//	threshold(img, img, 127, 255, THRESH_BINARY);
//    imshow("bin.png", img);
//	Mat marker = Mat::zeros(img.size(), CV_8UC1);
//
//	uchar p1 =marker.at<uchar>(100,100) =255;
//	uchar p2 = marker.at<uchar>(101, 100) = 255;
//	uchar p3 = marker.at<uchar>(100, 101) = 255;
//	uchar p4 = marker.at<uchar>(101, 101) = 255;
//
//	imshow("img1", img);
//	img = img/255;
//	img = img*100;
//	imshow("img2", img);
//	waitKey(0);
//	return 0;
//}