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

static inline void* __create_obj(size_t size)
{
    void* new_obj = malloc(size);
    memset(new_obj, 0, size);
    return new_obj;
}

static inline void* __create_inher(void* ori, size_t size, size_t p_size)
{
    void* new_obj = realloc(ori, size);
    memset(new_obj+p_size, 0, size-p_size);
    return new_obj;
}

#define create_obj(class) \
    __create_obj(sizeof(_##class))


#define create_inher(parent_class, class) \
    __create_inher(new(parent_class), sizeof(_##class), sizeof(_##parent_class))


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
