#pragma once

#include "typelist.h"

template<typename TList, typename OldType, typename NewType> 
struct Replace;

template<typename OldType, typename NewType>
struct Replace<NullType, OldType, NewType> {

    typedef NullType NewTypeList;

};

template<typename Head, typename OldType, typename NewType>
struct Replace<TypeList<Head, NullType>, OldType, NewType> {

    typedef TypeList<Head, NullType> NewTypeList;

};

template<typename OldType, typename NewType>
struct Replace<TypeList<OldType, NullType>, OldType, NewType> {

    typedef TypeList<NewType, NullType> NewTypeList;

};

template<typename OldType, typename NewType>
struct Replace<TypeList<NewType, NullType>, OldType, NewType> {

    typedef TypeList<NewType, NullType> NewTypeList;

};

template<typename Tail, typename OldType, typename NewType>
struct Replace<TypeList<OldType, Tail>, OldType, NewType> {
private:

    typedef Replace<Tail, OldType, NewType>::NewTypeList backOfList;

public:

    typedef TypeList<NewType, backOfList> NewTypeList;

};

template<typename Tail, typename OldType, typename NewType>
struct Replace<TypeList<NewType, Tail>, OldType, NewType> {
private:

    typedef Replace<Tail, OldType, NewType>::NewTypeList backOfList;

public:

    typedef TypeList<NewType, backOfList> NewTypeList;

};

template<typename Head, typename Tail, typename OldType, typename NewType>
struct Replace<TypeList<Head, Tail>, OldType, NewType> {
private:

    typedef Replace<Tail, OldType, NewType>::NewTypeList backOfList;

public:

    typedef TypeList<Head, backOfList> NewTypeList;

};
