#include "UI.h"

void UI::progress()
{
	cv::namedWindow(winname);

	// ��� ui���� �׸���(?)
	// copyToBackGround();

	// ��� ��� �̹���
	cv::imshow(winname, Background);

	cv::waitKey(); // ���� Ű ���
}

