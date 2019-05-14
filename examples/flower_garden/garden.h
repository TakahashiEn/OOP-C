//
// Created by Miguel Duarte on 5/12/2019.
//

#ifndef OOP_C_GARDEN_H
#define OOP_C_GARDEN_H

#include "oo_lan.h"
#include "flower.h"

#define __garden_content__ \
void func(grow)(garden this); \
void func(add_flower)(garden this, flower); \
flower f;

class_declaration(garden);

#endif //OOP_C_GARDEN_H
