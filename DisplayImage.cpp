#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    Mat grey;
    Mat canny;
    image = imread( argv[1], 1 );
    cvtColor(image, grey, CV_BGR2GRAY);
    GaussianBlur( grey, grey, Size(9, 9), 2, 2 );
    Canny(grey, canny, 200.0, 200.0, 3);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    namedWindow("grey Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    imshow("grey Image",canny);
    waitKey(0);

    return 0;
}
