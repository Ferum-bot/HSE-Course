#pragma once

#include "erase.h"
#include "typelist.h"

template<typename TList>
struct NoDuplicates;

template<>
struct NoDuplicates<NullType> {

    typedef NullType NewTypeList;

};

template<typename Head>
struct NoDuplicates<TypeList<Head, NullType>> {

    typedef TypeList<Head, NullType> NewTypeList;

};

template<typename Head, typename Tail>
struct NoDuplicates<TypeList<Head, TypeList<Head, Tail>>> {
private:

    typedef NoDuplicates<TypeList<Head, Tail>>::NewTypeList backOfList;

public:

    typedef backOfList NewTypeList;

};

template<typename HeadFirst, typename HeadSecond, typename Tail>
struct NoDuplicates<TypeList<HeadFirst, TypeList<HeadSecond, Tail>>> {
private:

    typedef NoDuplicates<TypeList<HeadSecond, Tail>>::NewTypeList backOfList;

public:

    typedef TypeList<HeadFirst, backOfList> NewTypeList;

};