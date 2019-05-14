//
// Created by Miguel Duarte on 5/12/2019.
//

#include "rose.h"

class void bloom()
{
    printf("A rose bloom.\n");
}

class void stab()
{
    printf("Rose is stabbing.\n");
}

rose new_rose()
{
    log_cons(rose);

    rose new_cl = create_inher(flower, rose);
    new_cl->bloom = bloom;
    new_cl->stab = stab;

    return new_cl;
}

void del_rose(rose obj)
{
    log_deco(rose);
    del(flower, obj);
}