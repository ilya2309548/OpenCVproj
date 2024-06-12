#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
//#include <opencv2/ximgproc.hpp>
#include <iostream>
#include <vector>
#include "my_function.hpp"
#include "skeletonization.hpp"
#include "zhang_suen.hpp"
#include "remove_corner_pixels.hpp"

using namespace cv;
using namespace std;


bool isPointClose(const Point& pt1, const Point& pt2, float tolerance) {
    return norm(pt1 - pt2) <= tolerance;
}

int countNonMatchingPoints(const vector<Point>& points1, const vector<Point>& points2, float tolerance) {
    int nonMatchingCount = 0;

    for (const auto& pt1 : points1) {
        bool matchFound = false;
        for (const auto& pt2 : points2) {
            if (isPointClose(pt1, pt2, tolerance)) {
                matchFound = true;
                break;
            }
        }
        if (!matchFound) {
            nonMatchingCount++;
        }
    }

    return nonMatchingCount;
}


float calculateMatchProbability(const vector<Point>& points1, const vector<Point>& points2, float tolerance) {
    int nonMatchingCount1 = countNonMatchingPoints(points1, points2, tolerance);
    int nonMatchingCount2 = countNonMatchingPoints(points2, points1, tolerance);

    int totalPoints = max(points1.size(), points2.size());
    int totalNonMatching = nonMatchingCount1 + nonMatchingCount2;

    float matchProbability = (1.0 - (float)totalNonMatching / (2.0 * totalPoints)) * 100.0;
    return matchProbability;
}



int sum_of_points(Mat& img, int& x, int& y) {
    if (img.at<uchar>(x, y) == 1) {
        int sum = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                sum += img.at<uchar>(x + i, y + j);
            }
        }
        return sum;
    }
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


int main() {
    Mat img = imread("../data/finger1.png", IMREAD_GRAYSCALE);
    imshow("img_show", img);
    waitKey(0);

    if (img.empty()) {
        cout << "Image is empty!" << endl;
        return -1;
    }


    threshold(img, img, 127, 255, THRESH_BINARY);


    bitwise_not(img, img);

    skeletonization(img);
    //ximgproc::thinning(img, img);


    imshow("img_show", img);
    waitKey(0);

    Mat img_with_point;

    cvtColor(img, img_with_point, COLOR_GRAY2BGR);
    //circle(img_with_point, Point(img_with_point.cols / 2, img_with_point.rows / 2), 50, Scalar(0, 0, 255), -1);
    //imshow("img_with_point", img_with_point);
    //waitKey(0);
 

    imwrite("skeletonized_fingerprint.png", img);

    ////imshow("Skeletonized Fingerprint", img);

    //waitKey(0);
    



    //paint key_point on image
    img /= 255;

    vector<Point> FINGER1_pt_2;
    vector<Point> FINGER1_pt_4;

    Scalar color_1(0, 0, 255);
    Scalar color_3(0, 255, 0);
    int radius = 2;
    int thickness = 1;

    for (int x = 1; x < img.rows - 1; ++x) {
        int one = 300;
        for (int y = 1; y < img.cols - 1; ++y) {
            if (sum_of_points(img, x, y) == 2) {
                circle(img_with_point, cv::Point(y, x), radius, color_1, thickness);
                FINGER1_pt_2.push_back(Point(x, y));
            }
            else if (sum_of_points(img, x, y) == 4) {
                circle(img_with_point, cv::Point(y, x), radius, color_3, thickness);
                FINGER1_pt_4.push_back(Point(x, y));
            }
        }
    }


    imwrite("img_with_point.png", img_with_point);
    img *= 255;
    imshow("img_with_point", img_with_point);
    waitKey(0);







    //FINGER2





    Mat img2 = imread("../data/finger3.png", IMREAD_GRAYSCALE);
    imshow("img2_show", img2);
    waitKey(0);

    if (img2.empty()) {
        cout << "Image is empty!" << endl;
        return -1;
    }


    threshold(img2, img2, 127, 255, THRESH_BINARY);


    bitwise_not(img2, img2);

    skeletonization(img2);
    //ximg2proc::thinning(img2, img2);


    imshow("img2_show", img2);
    waitKey(0);

    Mat img2_with_point;

    cvtColor(img2, img2_with_point, COLOR_GRAY2BGR);
    //circle(img2_with_point, Point(img2_with_point.cols / 2, img2_with_point.rows / 2), 50, Scalar(0, 0, 255), -1);
    //imshow("img2_with_point", img2_with_point);
    //waitKey(0);


    imwrite("skeletonized_fingerprint.png", img2);

    ////imshow("Skeletonized Fingerprint", img2);

    //waitKey(0);




    //paint key_point on image
    img2 /= 255;

    vector<Point> FINGER2_pt_2;
    vector<Point> FINGER2_pt_4;


    for (int x = 1; x < img2.rows - 1; ++x) {
        int one = 300;
        for (int y = 1; y < img2.cols - 1; ++y) {
            if (sum_of_points(img2, x, y) == 2) {
                circle(img2_with_point, cv::Point(y, x), radius, color_1, thickness);
                FINGER2_pt_2.push_back(Point(x, y));
            }
            else if (sum_of_points(img2, x, y) == 4) {
                circle(img2_with_point, cv::Point(y, x), radius, color_3, thickness);
                FINGER2_pt_4.push_back(Point(x, y));
            }
        }
    }


    imwrite("img2_with_point.png", img2_with_point);
    img2 *= 255;
    imshow("img2_with_point", img2_with_point);
    waitKey(0);









    ////VIEW VECTOR OF 2 KEY-POINTS
    //for (int i = 0; i < pt_2.size(); ++i) {
    //    cout << pt_2[i] << endl;
    //}





 
    float tolerance = 15.0;

    float matchProbability = calculateMatchProbability(FINGER1_pt_2, FINGER2_pt_2, tolerance);

    cout << "Match probability: " << matchProbability << "%" << endl;


    return 0;
}   