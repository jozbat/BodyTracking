#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <ctype.h>

int main (int argc, const char** argv)
{
    cv::VideoCapture cap;  
	cap.open(0);

    if (!cap.isOpened() )
    {
        std::cout << "***Could not initialize capturing...***\n";
        std::cout << "Current parameter's value: \n";
        return -1;
    }

    cv::namedWindow("Demo", 0);

    cv::Mat frame;
    bool paused = false;
    
    for (;;)
    {
        if (!paused)
        {
            cap >> frame;
            if (frame.empty())
                break;
        }
        imshow ("Demo", frame);

        char c = (char)cv::waitKey(1);
        if (c == 27)
            break;
    }

    return 0;
}
