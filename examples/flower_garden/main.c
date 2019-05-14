#include <stdio.h>
#include <memory.h>
#include <assert.h>

#include "daisy.h"
#include "red_rose.h"
#include "yellow_rose.h"
#include "client.h"


int main()
{
    flower af;
    af = new(yellow_rose);
    af->bloom();
    del(yellow_rose, af);

    af = new(red_rose);
    af->bloom();
    del(red_rose, af);

    af = new(daisy);
    af->bloom();


    yellow_rose bf = new(yellow_rose);
    bf->stab();
    bf->set_name((flower)bf, "Bob");
    bf->show_name((flower)bf);


    assert(af->get_num_all() == static_get(bf->num_all));
    printf("Now has %d flowers.\n", static_get(bf->num_all));

    del(daisy, af);
    del(yellow_rose, bf);

    client nc = new(client);
    nc->see();
    del(client, nc);

    return 0;
}