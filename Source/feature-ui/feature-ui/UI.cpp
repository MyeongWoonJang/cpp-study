#include "UI.h"

void UI::init()
{
	cv::Mat whiteImage(height, width, CV_8UC4, cv::Scalar(255, 255, 255));
	Background = whiteImage;

	cv::namedWindow(winname);
}

void UI::progress()
{
	// ��� ui���� �׸���(?)
	// copyToBackGround();

	// ��� ��� �̹���
	cv::imshow(winname, Background);

	cv::waitKey(); // ���� Ű ���
}

void UI::addButton(int x, int y, int width, int height, std::string label, std::string filename)
{
	cv::Mat Button;
	cv::Rect button_rect(x, y, width, height);

	Button = cv::imread(filename, cv::IMREAD_UNCHANGED);

	cv::resize(Button, Button, button_rect.size());

	Button.copyTo(Background(button_rect));
}

