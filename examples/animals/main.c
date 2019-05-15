#include <stdio.h>

#include "Animal.h"
#include "Dog.h"

int main()
{
    Animal a = new(Animal);
    Dog b = new(Dog);
    printf("Now have %d animal.\n", static_get(a->num));
    del(Animal, a);
    printf("Now have %d animal.\n", static_get(a->num));
    del(Dog, b);
    return 0;
}