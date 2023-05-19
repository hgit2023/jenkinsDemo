
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;
int main()
{
    int width = 800;
    int height = 600;

    Mat blackImg(600, 800, CV_8UC3, Scalar(0, 0, 0));

    int x, y, r;
    cout << "输入圆心x坐标:" << endl;
    cin >> y;
    cout << "输入圆心y坐标:" << endl;
    cin >> x;
    cout << "输入圆的半径r:" << endl;
    cin >> r;

    for (int i = x - r; i < x + r; i++) 
    {
        for (int j = y - r; j <= y + r; j++) 
        {
            if (i >= 0 && j >= 0 && i < 600 && j < 800) {
                if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
                    blackImg.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
            }
            
        }
    }
    imwrite("result.jpg", blackImg);
}

