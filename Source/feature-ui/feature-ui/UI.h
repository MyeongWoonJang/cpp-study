#ifndef __UI
#define __UI

#include <iostream>
#include "opencv2/opencv.hpp"

class UI
{
public:
	UI(int _width, int _height, std::string _winname) : width(_width), height(_height), winname(_winname) 
	{
		cv::Mat whiteImage(height, width, CV_8UC3, cv::Scalar(255, 255, 255));
		Background = whiteImage;
	}

	void progress();
	// void addButton(int x, int y, int width, int height, std::string label, std::string filename);

private:
	int width;
	int height;
	std::string winname;
	cv::Mat Background;
};

#endif