#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>

int main()
{
    char ch;
    std::cout << "Hello, World!\n";

    cv::freetype::createFreeType2();

    std::cout << "press any key to exit.\n";
    std::cin >> ch;
}