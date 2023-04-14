#ifndef __Button
#define __Button

#include <string>
#include "opencv2/opencv.hpp"

class Button
{
public:
	Button(cv::Vec2i _position, cv::Vec2i _size, std::string _file_name) : position(_position), size(_size), file_name(_file_name) {};

	void draw();

	cv::Vec2i GetPos() { return position; }
	cv::Vec2i GetSize() { return size; }
	std::string GetFileName() { return file_name; }

private:
	cv::Vec2i position;
	cv::Vec2i size;
	std::string file_name;

	//Renderer render;
};

#endif // !1
