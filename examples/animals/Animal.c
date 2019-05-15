//
// Created by miguel on 5/14/19.
//

#include "Animal.h"

class int num;

class void say_hello()
{
    printf("Hello World!\n");
}

class void grow(Animal this)
{
    this->age++;
}

class int get_age(Animal this)
{
    return this->age;
}

void set_name(Animal this, char* name)
{
    strcpy(this->name = malloc(strlen(name) + 1), name);
}

char* get_name(Animal this)
{
    return this->name;
}

Animal new_Animal()
{
    Animal new_cl = create_obj(Animal);
    new_cl->say_hello = say_hello;
    new_cl->get_age = get_age;
    new_cl->grow = grow;
    new_cl->get_name = get_name;
    new_cl->set_name = set_name;
    static_init(new_cl->num, num);

    num++;

    printf("Create.\n");

    return new_cl;
}

void del_Animal(Animal obj)
{
    if (obj->name)
        free(obj->name);
    num--;
    del_obj(obj);
}