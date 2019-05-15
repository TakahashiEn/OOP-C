//
// Created by miguel on 5/14/19.
//

#ifndef OOP_EXAMPLE_ANIMAL_H
#define OOP_EXAMPLE_ANIMAL_H

#include "oo_lan.h"

#define __Animal_content__ \
void func(say_hello)(); \
void func(grow)(Animal this); \
int func(get_age)(Animal this); \
int age; \
void func(set_name)(Animal this, char* name); \
char* func(get_name)(Animal this); \
char* name; \
int static_member(num);

class_declaration(Animal);

#endif //OOP_EXAMPLE_ANIMAL_H
