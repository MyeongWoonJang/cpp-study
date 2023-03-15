#include "UI.h"

void UI::init()
{
	cv::Mat whiteImage(height, width, CV_8UC4, cv::Scalar(255, 255, 255));
	Background = whiteImage;

	cv::namedWindow(winname);
}

void UI::progress()
{
	// 모든 ui들을 그리기(?)
	// copyToBackGround();

	// 흰색 배경 이미지
	cv::imshow(winname, Background);

	cv::waitKey(); // 종료 키 대기
}

void UI::addButton(int x, int y, int width, int height, std::string label, std::string filename)
{
	cv::Mat Button;
	cv::Rect button_rect(x, y, width, height);

	Button = cv::imread(filename, cv::IMREAD_UNCHANGED);

	cv::resize(Button, Button, button_rect.size());

	Button.copyTo(Background(button_rect));
}

