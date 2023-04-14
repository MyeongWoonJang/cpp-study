#include "UI.h"


void UI::init()
{
	cv::Mat whiteImage(height, width, CV_8UC4, cv::Scalar(255, 255, 255));
	Background = whiteImage;

	cv::namedWindow(winname);

	cv::setMouseCallback(winname, MouseCallback);
}

void UI::draw()
{

}

void UI::progress()
{
	cv::imshow(winname, Background);

	while (!cv::waitKey())
	{
		
	}

}

void UI::addButton(int x, int y, int width, int height, std::string label, std::string filename)
{
	cv::Vec2i pos(x, y);
	cv::Vec2i size(width, height);
	Button btn(pos, size, filename);
	button.push_back(btn);

	cv::Mat Button;
	cv::Rect button_rect(x, y, width, height);

	Button = cv::imread(filename, cv::IMREAD_UNCHANGED);

	cv::resize(Button, Button, button_rect.size());

	Button.copyTo(Background(button_rect));
}

void UI::MouseCallback(int event, int x, int y, int flags, void* userdata)
{
	// std::cout << "x: " << x << "y: " << y << std::endl;

	if (event & cv::EVENT_LBUTTONDOWN) {
		std::cout << "Left mouse button is pressed" << std::endl;
		std::cout << "x: " << x << "y: " << y << std::endl;
	}
}

