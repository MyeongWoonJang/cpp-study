/******************************************************************************

C++ 복습/심화학습 용 소스 자료
Made By Artlife

1 메인 함수에서 애플리케이션을 실행함.
2 애플리케이션이 단위 테스트 API를 이용, 단위 테스트들을 등록
3 애플리케이션이 단위 테스트 API를 이용, 단위 테스트들을 실행 후 결과 저장

애플리케이션 예시 - base_app.h, base_app.cpp
단위 테스트 API - test.h, test.cpp
테스트용 클래스 - dog.h


*******************************************************************************/
#define _CRT_SEQURE_NO_WARNINGS

#include "base_app.h"

using application = base_app;

int main(int argc, char* argv[]) {
	application app;
	app.run();
	
	std::cout << "hi" << std::endl;
	std::cout << "hi2" << std::endl;	
	
	return 0;
}