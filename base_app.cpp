#include "base_app.h"

void base_app::run()
{
    Test::set_output_file_path("Test Result.txt");
    Test::set_output_locale("");

    Test::add_case(tgrowl, "으르렁거리기 테스트");
    Test::add_case(tbark, "짖기 테스트");
    Test::run();
}

Test::result base_app::tgrowl() noexcept
{
    Dog dog;
    dog.growl();

    return Test::result::PASS;
}

Test::result base_app::tbark() noexcept
{
    Dog dog;
    dog.bark();

    return Test::result::PASS;
}