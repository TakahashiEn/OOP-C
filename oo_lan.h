//
// Created by Miguel Duarte on 5/12/2019.
//

#ifndef OOP_C_OO_LAN_H
#define OOP_C_OO_LAN_H

//#define debug

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

#define static_member *
#define static_init(obj_mem, real_mem) (obj_mem = &(real_mem))
#define static_get(static_p) (*(static_p))

#define declare_cons(class) \
class new_##class(); \
void del_##class(class)

#define class_declaration(class) \
typedef struct __##class _##class,*class; \
struct __##class \
{ \
    __##class##_content__ \
}; \
declare_cons(class);

#define new(class) ((void *)new_##class())
#define del(class, obj) (del_##class((class)obj))

#define func(func_name) (* func_name)

#define create_obj(class) malloc(sizeof(_##class))
#define create_inher(parent_class, class) \
    realloc(new(parent_class), sizeof(_##class))

#define class static

#define deconstruct_void(class) \
void del_##class(class obj) \
{ \
    free(obj);\
}

#define del_obj(obj) free(obj)



#ifdef debug

#define log_cons(class) printf("Exec constructor of class " #class ".\n")
#define log_deco(class) printf("Exec deconstructor of class " #class ".\n")

#else

#define log_cons(class)
#define log_deco(class)

#endif

#endif //OOP_C_OO_LAN_H
