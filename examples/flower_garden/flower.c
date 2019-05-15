//
// Created by Miguel Duarte on 5/12/2019.
//

#include "flower.h"

class int num_all;

class void show_name(flower this)
{
    printf("My name is %s.\n", this->name);
}

class void set_name(flower this, char* name)
{
    strcpy(this->name = malloc(strlen(name) + 1), name);
}

class void bloom()
{
    printf("A flower bloom.\n");
}

class int get_num_all()
{
    return num_all;
}

flower new_flower()
{
    log_cons(flower);

    flower new_cl = create_obj(flower);
    new_cl->bloom = bloom;
    new_cl->set_name = set_name;
    new_cl->show_name = show_name;
    static_init(new_cl->num_all, num_all);
    new_cl->get_num_all = get_num_all;
    num_all++;

    return new_cl;
}

void del_flower(flower obj)
{
    log_deco(flower);
    num_all--;
    if (obj->name)
        free(obj->name);
    del_obj(obj);
}