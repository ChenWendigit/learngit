#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;

int main(int argc,char*argv)
{
    VideoCapture capture(0);
    Mat frame;
    if (!capture.isOpened())
    {
        return -1;
    }

    while(1)
    {
        char key = cv::waitKey(50);
        capture.read(frame);
        if(frame.empty())
        {
            cout<<"FALL!(No captured frame)"<<endl;
            break;
        }
        imshow("video",frame);

        if(key == 27) break;
        if(key == 115)
        {
            imwrite("./cap.jpg",frame);
            imshow("image",frame);
        }
    }
    return 0;
}
