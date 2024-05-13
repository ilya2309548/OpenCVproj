#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

int main() {

	string path = "../../data/oboi.png";
	Mat image = imread(path);
	if (image.empty()) {
        std::cerr << "Failed to read image!" << std::endl;
        return 1;	
    }
	else{	
	imshow("Image", image);
	waitKey(0);
    }
    return 0;
}

// int main() {
//     // Создание матрицы размером 3x3 с элементами типа float
//     cv::Mat matrix(3, 3, CV_32F);

//     // Присвоение значений элементам матрицы
//     matrix.at<float>(0, 0) = 1.0;
//     matrix.at<float>(0, 1) = 2.0;
//     matrix.at<float>(0, 2) = 3.0;
//     matrix.at<float>(1, 0) = 4.0;
//     matrix.at<float>(1, 1) = 5.0;
//     matrix.at<float>(1, 2) = 6.0;
//     matrix.at<float>(2, 0) = 7.0;
//     matrix.at<float>(2, 1) = 8.0;
//     matrix.at<float>(2, 2) = 9.0;

//     // Вывод матрицы в консоль
//     std::cout << "Matrix:\n" << matrix << std::endl;

//     return 0;


// }


// int main() {
//     // Создание однотонного изображения размером 300x200 с белым цветом (255)
//     cv::Mat image(200, 300, CV_8UC3, cv::Scalar(255, 255, 255));

//     // Отображение изображения
//     cv::imshow("White Image", image);
//     cv::waitKey(0);
//     cv::destroyAllWindows();

//     return 0;
// }