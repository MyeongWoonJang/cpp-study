#ifndef _my_unique_ptr_app
#define _my_unique_ptr_app

#include "../dog.h"
#include "../test.h"
#include "my_unique_ptr.h"

class my_unique_ptr_app
{
public:
    void run();
    
private:
    static Test::result tcreation_nullptr();
    static Test::result tcreation_default();
    static Test::result tcreation_new();
    static Test::result tcreation_move_new();
    static Test::result tmove_allocation();
    static Test::result tget();
    static Test::result toperator_pointer();
    static Test::result toperator_dereference();
    static Test::result treset_default();
    static Test::result treset_default_already_had_resource();
    static Test::result treset_nullptr();
    static Test::result treset_nullptr_already_had_resource();
    static Test::result treset_other();
    static Test::result treset_other_already_had_resource();
};

#endif