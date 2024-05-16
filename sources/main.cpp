#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;


vector<vector<int>> ImgToBin(Mat& ImgMat) {
    vector<vector<int>> BinMat(ImgMat.rows, std::vector<int>(ImgMat.cols));
    for (int i = 0; i < ImgMat.rows; ++i) {
        for (int j = 0; j < ImgMat.cols; ++j) {
            /*BinMat[i][j] = ImgMat.at<uchar>(i, j);*/
            if (ImgMat.at<uchar>(i, j) < 128) {
                BinMat[i][j] = 0;
            }
            else {
                BinMat[i][j] = 1;
            }
        }
    }
    return BinMat;
}


/////////////////  Images  //////////////////////

<<<<<<< HEAD
 int main() {

 	string path = "../../data/hare150.jpg";
 	Mat image = imread(path);
 	if (image.empty()) {
         std::cerr << "Failed to read image!" << std::endl;
         return 1;	
    }
 	else{	
 	imshow("Image", image);
 	waitKey(0);
    }

    vector<vector<int>> newbin(ImgToBin(image));
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            cout << newbin[i][j];
        }
        cout << endl;
    }
    return 0;s

 }
=======
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

>>>>>>> 716e39068b847bea684c75847f346ed7e1cbed4e

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


<<<<<<< HEAD
//int main() {
//    // Создание однотонного изображения размером 300x200 с белым цветом (255)
//    cv::Mat image(200, 300, CV_8UC3, cv::Scalar(255, 255, 255));
//
//    // Отображение изображения
//    cv::imshow("White Image", image);
//    cv::waitKey(0);
//    cv::destroyAllWindows();
//
//    return 0;
//}
=======
// int main() {
//     // Создание однотонного изображения размером 300x200 с белым цветом (255)
//     cv::Mat image(200, 300, CV_8UC3, cv::Scalar(255, 255, 255));

//     // Отображение изображения
//     cv::imshow("White Image", image);
//     cv::waitKey(0);
//     cv::destroyAllWindows();

//     return 0;
// }
>>>>>>> 716e39068b847bea684c75847f346ed7e1cbed4e
