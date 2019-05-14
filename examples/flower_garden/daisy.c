//
// Created by Miguel Duarte on 5/12/2019.
//

#include "daisy.h"

class void bloom()
{
    printf("A daisy bloom.\n");
}

daisy new_daisy()
{
    log_cons(daisy);

    daisy new_cl = create_inher(flower, daisy);
    new_cl->bloom = bloom;

    return new_cl;
}

void del_daisy(daisy obj)
{
    log_deco(daisy);
    del(flower, obj);
}