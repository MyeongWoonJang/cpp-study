#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>

void opencv_sample()
{
    cv::namedWindow("sample");

    cv::String text = "Funny text inside the box";
    int fontHeight = 60;
    int thickness = -1;
    int linestyle = cv::LINE_8;
    cv::Mat img(600, 800, CV_8UC3, cv::Scalar::all(0));
    int baseline=0;
    cv::Ptr<cv::freetype::FreeType2> ft2;
    ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData( "../../resources/GOUDOS.TTF", 0 );
    cv::Size textSize = ft2->getTextSize(text,
                                    fontHeight,
                                    thickness,
                                    &baseline);
    if(thickness > 0){
        baseline += thickness;
    }
    // center the text
    cv::Point textOrg((img.cols - textSize.width) / 2,
                (img.rows + textSize.height) / 2);
    // draw the box
    cv::rectangle(img, textOrg + cv::Point(0, baseline),
            textOrg + cv::Point(textSize.width, -textSize.height),
            cv::Scalar(0,255,0),1,8);
    // ... and the baseline first
    cv::line(img, textOrg + cv::Point(0, thickness),
        textOrg + cv::Point(textSize.width, thickness),
        cv::Scalar(0, 0, 255),1,8);
    // then put the text itself
    ft2->putText(img, text, textOrg, fontHeight,
                cv::Scalar::all(255), thickness, linestyle, true );

    cv::imshow("sample", img);
    cv::waitKey(25);
}

int main()
{
    char ch;
    std::cout << "Hello, World!\n";

    opencv_sample();

    std::cout << "press any key to exit.\n";
    std::cin >> ch;
}