// ex01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int exam1()
{
    Mat img = imread("../../res/Lenna.png", IMREAD_COLOR);

    if (img.empty())
    {
        printf("image load error");
        return 1;
    }
    imshow("Display", img);
    waitKey(0);

    cout << "Hello World!\n";
    return 0;
}

int exam2_cam()
{
    Mat img_color;

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        printf("camera open error\n");
        return 1;
    }

    while (1)
    {
        cap.read(img_color);
        
        imshow("capture window", img_color);
        if (waitKey(25) >= 0) {
            break;
        }
    }

    imwrite("capture.png", img_color);

    return 0;

}



int main()
{
    
    return exam2_cam();
}
