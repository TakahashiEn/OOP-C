//
// Created by Miguel Duarte on 5/12/2019.
//

#include "garden.h"

class void add_flower(garden this, flower f)
{
    this->f = f;
}

class void grow(garden this)
{
    if (!this->f)
        printf("No flower in garden!\n");
    else
        this->f->bloom();
}

garden new_garden()
{
    log_cons(garden);

    garden new_cl = create_obj(garden);
    new_cl->add_flower = add_flower;
    new_cl->grow = grow;

    return new_cl;
}

void del_garden(garden obj)
{
    log_deco(garden);
    del_obj(obj);
}