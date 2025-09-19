#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;

int main()
{   
    Mat photo = imread("/home/kmj/Desktop/hw1.png", IMREAD_COLOR);
    Mat hsv_photo;
    Mat photo_green;
    Mat photo_red;
    Mat photo_blue;
    Mat red_1;
    Mat red_2;

    cvtColor(photo, hsv_photo, COLOR_BGR2HSV);
    Scalar range_green_1(35, 50, 50);
    Scalar range_green_2(85, 255, 255);
    Scalar range_red_1(0, 100, 100); // 밝은 빨간색 범위
    Scalar range_red_2(10, 255, 255);
    Scalar range_red_3(170, 100, 100); // 어두운 빨간색 범위
    Scalar range_red_4(180, 255, 255);
    Scalar range_blue_1(100, 100, 100);
    Scalar range_blue_2(130, 255, 255);

    
    inRange(hsv_photo, range_green_1, range_green_2, photo_green);
    inRange(hsv_photo, range_red_1, range_red_2, red_1);
    inRange(hsv_photo, range_red_3, range_red_4, red_2);
    inRange(hsv_photo, range_blue_1, range_blue_2, photo_blue);
    photo_red = red_1 + red_2;

    Mat red_blur;
    Mat blue_blur;
    Mat green_blur;
    GaussianBlur(photo_red, red_blur, Size(31, 31), 0);
    GaussianBlur(photo_blue, blue_blur, Size(31, 31), 0);
    GaussianBlur(photo_green, green_blur, Size(31, 31), 0);
    imshow("red_blur", red_blur);
    imshow("blue_blur", blue_blur);
    imshow("green_blur", green_blur);

    imshow("photo_green",photo_green);
    imshow("photo_red",photo_red);
    imshow("photo_blue",photo_blue);

    waitKey(0);
    return 0;
}