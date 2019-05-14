//
// Created by Miguel Duarte on 5/12/2019.
//

#include "red_rose.h"

class void bloom()
{
    printf("A red rose bloom.\n");
}

red_rose new_red_rose()
{
    log_cons(red_rose);

    red_rose new_cl = create_inher(rose, red_rose);
    new_cl->bloom = bloom;

    return new_cl;
}

void del_red_rose(red_rose obj)
{
    log_deco(red_rose);
    del(rose, obj);
}