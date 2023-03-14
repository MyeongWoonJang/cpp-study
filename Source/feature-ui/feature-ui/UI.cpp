#include "UI.h"

void UI::progress()
{
	cv::namedWindow(winname);

	// 모든 ui들을 그리기(?)
	// copyToBackGround();

	// 흰색 배경 이미지
	cv::imshow(winname, Background);

	cv::waitKey(); // 종료 키 대기
}

