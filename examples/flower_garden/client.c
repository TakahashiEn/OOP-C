//
// Created by miguel on 5/14/19.
//

#include "client.h"

class void see()
{
    flower f1 = new(red_rose);
    flower f2 = new(yellow_rose);
    flower f3 = new(daisy);
    garden g = new(garden);

    g->add_flower(g, f1);
    g->grow(g);
    g->add_flower(g, f2);
    g->grow(g);
    g->add_flower(g, f3);
    g->grow(g);

    del(garden, g);
    del(yellow_rose, f2);
    del(red_rose, f1);
    del(daisy, f3);
}

client new_client()
{
    log_cons(client);

    client new_cl = create_obj(client);
    new_cl->see = see;

    return new_cl;
}

void del_client(client obj)
{
    log_deco(client);
    del_obj(obj);
}