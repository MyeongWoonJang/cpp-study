#ifndef __UI
#define __UI

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

class UI
{
public:
	UI(int _width, int _height, std::string _winname) : width(_width), height(_height), winname(_winname) 	{	}

	void init();
	void progress();
	void addButton(int x, int y, int width, int height, std::string label, std::string filename);


private:
	int width;
	int height;
	std::string winname;
	cv::Mat Background;
};

#endif