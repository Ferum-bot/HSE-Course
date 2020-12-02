#pragma once

#include "typelist.h"

template<typename TList, typename NewType>
struct Append;

template<typename Head, typename Tail, typename NewType>
struct Append<TypeList<Head, Tail>, NewType> {
private:

    typedef Append<Tail, NewType>::NewTypeList backOfList;

public:

    typedef TypeList<Head, backOfList> NewTypeList;

};


template<typename NewType>
struct Append<NullType, NewType> {

    typedef TypeList<NewType, NullType> NewTypeList;

};

template<>
struct Append<NullType, NullType> {

    typedef NullType NewTypeList;

};
