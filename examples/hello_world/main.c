#include <stdio.h>

#include "Animal.h"

int main()
{
    Animal a = new(Animal);
    a->say_hello();
    return 0;
}