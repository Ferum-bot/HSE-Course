#pragma once

#include "typelist.h"

template<typename TList, typename TargetType>
struct IndexOf;

template<typename TargetType>
struct IndexOf<NullType, TargetType> {
    static const int32_t pos = -1;
};

template<typename Tail, typename TargetType>
struct IndexOf<TypeList<TargetType, Tail>, TargetType> {
    static const int32_t pos = 0;
};

template<typename Head, typename Tail, typename TargetType>
struct IndexOf<TypeList<Head, Tail>, TargetType> {
private:

    static const int32_t actual = IndexOf<Tail, TargetType>::pos;

public:

    static const int32_t pos = actual == -1 ? -1 : actual + 1;

};