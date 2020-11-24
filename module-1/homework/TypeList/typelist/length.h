#pragma once

#include "typelist.h"

template<typename TList> 
struct Length;

template<>
struct Length<NullType> {
    static const size_t length = 0;
};

template<typename Head, typename Tail>
struct Length<TypeList<Head, Tail>> {
    static const size_t length = Length<Tail>::length + 1;
};