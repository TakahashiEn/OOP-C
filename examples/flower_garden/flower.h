//
// Created by Miguel Duarte on 5/12/2019.
//

#ifndef OOP_C_FLOWER_H
#define OOP_C_FLOWER_H

#include <stdio.h>
#include <string.h>
#include "oo_lan.h"

#define __flower_content__ \
void func(bloom)(); \
void func(show_name)(flower this); \
void func(set_name)(flower this, char* name); \
char* name; \
int static_member num_all; \
int func(get_num_all)();

class_declaration(flower);

#endif //OOP_C_FLOWER_H
