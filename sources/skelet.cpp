#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//int main() {
// 
// 
    //// �������� �����������
    //Mat image = imread("../../data/butterfly.png", IMREAD_GRAYSCALE);
    //if (image.empty()) {
    //    cerr << "Error: Unable to load image!" << endl;
    //    return -1;
    //}
    //bool write_img = imwrite("img_output.png", image);

    //if (write_img) {
    //    std::cout << "Image saved successfully." << std::endl;
    //}
    //else {
    //    std::cerr << "Error saving image." << std::endl;
    //}




    //// ����������� ����������� (���� ����������� ��� �� ��������)
    //Mat binary_image;
    //threshold(image, binary_image, 250, 255, THRESH_BINARY);

    //bool bin_img = imwrite("binimg_output.png", image);
    //if (bin_img) {
    //    std::cout << "Image saved successfully." << std::endl;
    //}
    //else {
    //    std::cerr << "Error saving image." << std::endl;
    //}




    //// �������������� ����������� (���� ����������)
    //bitwise_not(binary_image, binary_image);

    //// �������� ������� ����������� ��� �������� ���������� ������������
    //Mat skeleton = Mat::zeros(binary_image.size(), CV_8UC1);

    //// ��������� ������������ ��������
    //Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));

    //// �������� ����
    //bool done;
    //do {
    //    // ��������������� ��������
    //    Mat eroded;
    //    erode(binary_image, eroded, element);
    //    Mat temp;
    //    dilate(eroded, temp, element);

    //    // ���������� ��������
    //    subtract(binary_image, temp, temp);
    //    bitwise_or(skeleton, temp, skeleton);

    //    binary_image = eroded.clone();

    //    // �������� ����������
    //    done = (countNonZero(binary_image) == 0);
    //} while (!done);

    //// �������������� ���������� (���� ����������)
    ////bitwise_not(skeleton, skeleton);

    //// ���������� ��� ����������� ����������
    //imwrite("skeletonized_image.png", skeleton);
    ////imshow("Skeleton", skeleton);
    //waitKey(0);

    //bool success = imwrite("output_skeleton.png", skeleton);
    //if (success) {
    //    std::cout << "Image saved successfully." << std::endl;
    //}
    //else {
    //    std::cerr << "Error saving image." << std::endl;
    //}
//
//    return 0;
//}
