#pragma once

#include "typelist.h"

template<typename TList, typename TargetType>
struct EraseAll;

template<typename TargetType>
struct EraseAll<NullType, TargetType> {

    typedef NullType NewTypeList; 

};

template<typename Tail, typename TargetType> 
struct EraseAll<TypeList<TargetType, Tail>, TargetType>{
private:

    typedef EraseAll<Tail, TargetType>::NewTypeList backOfList;

public:

    typedef backOfList NewTypeList;

};

template<typename Head, typename Tail, typename TargetType>
struct EraseAll<TypeList<Head, Tail>, TargetType> {
private:

    typedef EraseAll<Tail, TargetType>::NewTypeList backOfList;

public:

    typedef TypeList<Head, backOfList> NewTypeList;

};