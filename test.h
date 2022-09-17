/******************************************************************************

단위 테스트용 클래스 Test

함수 Test::add_case - 단위 테스트 등록
@첫 번째 인자: Test::result 타입을 반환하는 인자 없는 함수(함수 포인터)
@두 번째 인자: 단위 테스트를 식별하는 이름

함수 Test::run - 등록된 모든 단위 테스트 실행

열거형 Test::result - Test::result::PASS, Test::result::FAIL 두 가지가 존재


test.h 파일(현재 파일)의 네임스페이스 environment - 프로그램을 컴파일 하기 전에 변경할 실행 환경


*******************************************************************************/

#ifndef _test
#define _test

#include <string>
#include <string_view>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>

class Test
{
public:
    enum class result { FAIL, PASS };

	static void add_case(result(*c)(), std::string&& identification);
	static void add_case(result(*c)(), const std::string& identification);
	static void run();
	
	static void set_output_file_path(std::string&& ofile_path);
	static void set_output_locale(std::string&& olocale);
	static void set_output_file_path(const std::string& ofile_path);
	static void set_output_locale(const std::string& olocale);
	static const std::string& get_output_file_path();
	static const std::string& get_output_locale();
	
private:
    static void put_time(std::ostream& out);
    
    static std::string goutput_file_path;
    static std::string goutput_locale;
	static std::vector<std::pair<result(*)(), const std::string>> gcases;
};

#endif