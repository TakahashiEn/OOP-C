//
// Created by miguel on 5/14/19.
//

#include "Animal.h"

class void say_hello()
{
    printf("Hello World!\n");
}

Animal new_Animal()
{
    Animal new_cl = create_obj(Animal);
    new_cl->say_hello = say_hello;

    return new_cl;
}

deconstruct_void(Animal)