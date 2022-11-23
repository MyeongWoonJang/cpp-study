#include "my_unique_ptr_app.h"

void my_unique_ptr_app::run()
{
    Test::set_output_file_path("Test Result.txt");
    Test::set_output_locale("");
    
    Test::add_case(tcreation_nullptr, "널포인터로부터 생성");
    Test::add_case(tcreation_default, "기본 생성");
    Test::add_case(tcreation_new, "리소스 획득 생성");
    Test::add_case(tcreation_move_new, "이동 생성");
    Test::add_case(tmove_allocation, "이동 할당");
    Test::add_case(tget, "get() 동작");
    Test::add_case(toperator_pointer, "operator->() 동작");
    Test::add_case(toperator_dereference, "operator*() 동작");
    Test::add_case(treset_default, "reset() 인자 없이 동작 - 자원을 소유하고 있지 않았을 때");
    Test::add_case(treset_default_already_had_resource, "reset() 인자 없이 동작 - 자원을 소유하고 있었을 때");
    Test::add_case(treset_nullptr, "reset() 널 포인터를 인자로 동작 - 자원을 소유하고 있지 않았을 때");
    Test::add_case(treset_nullptr_already_had_resource, "reset() 널 포인터를 인자로 동작 - 자원을 소유하고 있었을 때");
    Test::add_case(treset_other, "reset() 다른 포인터를 인자로 동작 - 자원을 소유하고 있지 않았을 때");
    Test::add_case(treset_other_already_had_resource, "reset() 다른 포인터를 인자로 동작 - 자원을 소유하고 있었을 때");
    
    Test::run();
}

Test::result my_unique_ptr_app::tcreation_nullptr()
{
    my_unique_ptr<Dog> t{nullptr};
    
    return Test::result::PASS;
}

Test::result my_unique_ptr_app::tcreation_default()
{
    my_unique_ptr<Dog> t{};
    
    return Test::result::PASS;
}

Test::result my_unique_ptr_app::tcreation_new()
{
    my_unique_ptr<Dog> t{new Dog};
    
    return Test::result::PASS;
}

Test::result my_unique_ptr_app::tcreation_move_new()
{
    my_unique_ptr<Dog> t1{new Dog};
    my_unique_ptr<Dog> t2{std::move(t1)};
        
    return Test::result::PASS;
}

Test::result my_unique_ptr_app::tmove_allocation()
{
    my_unique_ptr<Dog> t1;
    my_unique_ptr<Dog> t2{new Dog};
    t1 = std::move(t2);
    
    return Test::result::PASS;
}

Test::result my_unique_ptr_app::tget()
{
    auto t1 = new Dog;
    my_unique_ptr<Dog> t2{t1};
    
    if (t1 == t2.get()) return Test::result::PASS;
    else return Test::result::FAIL;
}

Test::result my_unique_ptr_app::toperator_pointer()
{
    auto t1 = new Dog;
    my_unique_ptr<Dog> t2{t1};
    
    if (t1 == t2.operator->()) return Test::result::PASS;
    else return Test::result::FAIL;
}

Test::result my_unique_ptr_app::toperator_dereference()
{
    auto t1 = new Dog;
    my_unique_ptr<Dog> t2{t1};
    
    if (*t1 == *t2) return Test::result::PASS;
    else return Test::result::FAIL;
}

Test::result my_unique_ptr_app::treset_default()
{
    my_unique_ptr<Dog> t1;
    t1.reset();
    
    if (t1.get() == nullptr) return Test::result::PASS;
    else Test::result::FAIL;
}

Test::result my_unique_ptr_app::treset_default_already_had_resource()
{
    my_unique_ptr<Dog> t1{new Dog};
    t1.reset();
    
    if (t1.get() == nullptr) return Test::result::PASS;
    else Test::result::FAIL;
}

Test::result my_unique_ptr_app::treset_nullptr()
{
    my_unique_ptr<Dog> t1;
    t1.reset(nullptr);
    
    if (t1.get() == nullptr) return Test::result::PASS;
    else Test::result::FAIL;
}

Test::result my_unique_ptr_app::treset_nullptr_already_had_resource()
{
    my_unique_ptr<Dog> t1{new Dog};
    t1.reset(nullptr);
    
    if (t1.get() == nullptr) return Test::result::PASS;
    else Test::result::FAIL;
}

Test::result my_unique_ptr_app::treset_other()
{
    my_unique_ptr<Dog> t1;
    auto t2 = new Dog;
    t1.reset(t2);
    
    if (t1.get() == t2) return Test::result::PASS;
    else Test::result::FAIL;
}

Test::result my_unique_ptr_app::treset_other_already_had_resource()
{
    my_unique_ptr<Dog> t1{new Dog};
    auto t2 = new Dog;
    t1.reset(t2);
    
    if (t1.get() == t2) return Test::result::PASS;
    else Test::result::FAIL;
}