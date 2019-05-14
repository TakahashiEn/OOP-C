//
// Created by Miguel Duarte on 5/12/2019.
//

#include "yellow_rose.h"

class void bloom()
{
    printf("A yellow rose bloom.\n");
}

yellow_rose new_yellow_rose()
{
    log_cons(yellow_rose);

    yellow_rose new_cl = create_inher(rose, yellow_rose);
    new_cl->bloom = bloom;

    return new_cl;
}

void del_yellow_rose(yellow_rose obj)
{
    log_deco(yellow_rose);
    del(rose, obj);
}