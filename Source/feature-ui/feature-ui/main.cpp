#include <iostream>
#include "opencv2/opencv.hpp"

int main()
{
	std::cout << "OpenCV version : " << CV_VERSION << std::endl;

	cv::Mat MenuButton;
	cv::Rect button_rect(0, 0, 250, 250);

	MenuButton = cv::imread("image/solution.png", cv::IMREAD_UNCHANGED); // 이미지 읽기	

	cv::resize(MenuButton, MenuButton, button_rect.size());
	
	// 이미지가 없을 경우 예외 처리
	if (MenuButton.empty())
	{
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	int height = 1080;
	int width = 1920;

	cv::Mat whiteImage(height, width, CV_8UC4, cv::Scalar(255, 255, 255));

	MenuButton.copyTo(whiteImage(button_rect));

	cv::namedWindow("ASCII Converter"); // 메인 윈도우

	cv::imshow("ASCII Converter", whiteImage);


	cv::waitKey(); // 종료 키 대기

	return 0;
}