#ifndef _base_app
#define _base_app

#include <iostream>

#include "test.h"
#include "dog.h"

class base_app
{
public:
    void run();
    
private:
    static Test::result tgrowl() noexcept;
    static Test::result tbark() noexcept;
};

#endif