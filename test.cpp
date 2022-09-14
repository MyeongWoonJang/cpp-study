#include "test.h"

void Test::add_case(result(*c)(), std::string&& identification)
{
	gcases.push_back(std::make_pair(c, identification));
}

void Test::add_case(result(*c)(), const std::string& identification)
{
	gcases.push_back(std::make_pair(c, identification));
}

void Test::run()
{
	std::ofstream out{goutput_file_path};
	
	put_time(out);
	
	for ( const auto& [run_case, identification] : gcases )
	{
	    try
	    {
		    out << identification << " : ";
		    if ( run_case() == result::PASS )
		    {
		        out << "pass\n";
		        continue;
		    }
	    }
	    catch(std::exception& e) { out << "- std::exception: " << e.what() << '\n'; }
	    catch(...) { out << "- undefined error\n"; }
	    
	    out << "fail\n";
	}
	
	out << "\nTest Done.\n";
}

void Test::set_output_file_path(std::string&& ofile_path) { goutput_file_path = ofile_path; }
void Test::set_output_locale(std::string&& olocale) { goutput_locale = olocale; }
void Test::set_output_file_path(const std::string& ofile_path) { goutput_file_path = ofile_path; }
void Test::set_output_locale(const std::string& olocale) { goutput_locale = olocale; }
const std::string& Test::get_output_file_path() { return goutput_file_path; }
const std::string& Test::get_output_locale() { return goutput_locale; }

void Test::put_time(std::ostream& out)
{
    auto clock_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	
	auto local_time = localtime(&clock_time);
	
	out.imbue(std::locale{goutput_locale});
	out << std::put_time(local_time, "%c - (%A)") << '\n';
}


std::string Test::goutput_file_path{"Test Result.txt"};
std::string Test::goutput_locale{""};
std::vector<std::pair<Test::result(*)(), const std::string>> Test::gcases{};