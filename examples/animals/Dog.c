//
// Created by miguel on 5/15/19.
//

#include "Dog.h"

void bark()
{
    printf("Bark.\n");
}

void say_hello()
{
    printf("Bark bark.\n");
}

Dog new_Dog()
{
    Dog new_cl = create_inher(Animal, Dog);
    new_cl->bark = bark;
    new_cl->say_hello = say_hello;

    return new_cl;
}

void del_Dog(Dog obj)
{
    del(Animal, obj);
}