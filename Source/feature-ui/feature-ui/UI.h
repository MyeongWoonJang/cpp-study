#ifndef __UI
#define __UI

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
#include "Button.h"

class UI
{
public:
	UI(int _width, int _height, std::string _winname) : width(_width), height(_height), winname(_winname) 	{	}

	void init();
	void draw();
	void progress();
	void addButton(int x, int y, int width, int height, std::string label, std::string filename);
	static void MouseCallback(int event, int x, int y, int flags, void* userdata);

private:
	int width;
	int height;	
	std::string winname;
	cv::Mat Background;
	std::vector<Button> button;
};

#endif