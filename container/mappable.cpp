#pragma once
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//PreOrderMappableContainer
template<typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun);
}

template<typename Data>
void PreOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    PreOrderFold(fun, punt);
}

template<typename Data>
void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor fun, void* punt) const {
    PreOrderMap([fun, punt](const Data& x){fun(x, punt);});
}

//PostOrderMappableContainer
template<typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PostOrderMap(fun);
}

template<typename Data>
void PostOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    PostOrderFold(fun, punt);
}

template<typename Data>
void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor fun, void* punt) const {
    PostOrderMap([fun, punt](const Data& x){fun(x, punt);});
}

//InOrderMappableContainer
template<typename Data>
void InOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    InOrderMap(fun);
}

template<typename Data>
void InOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    InOrderFold(fun, punt);
}

template<typename Data>
void InOrderMappableContainer<Data>::InOrderFold(FoldFunctor fun, void* punt) const {
    InOrderMap([fun, punt](const Data& x){fun(x, punt);});
}

//BreadthMappableContainer
template<typename Data>
void BreadthMappableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    BreadthFold(fun, punt);
}

template<typename Data>
void BreadthMappableContainer<Data>::BreadthFold(FoldFunctor fun, void * punt) const {
    BreadthMap([fun, punt](const Data& x){fun(x, punt);});
}

//MutablePreOrderMappableContainer
template<typename Data>
void MutablePreOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

//MutablePostOrderMappableContainer
template<typename Data>
void MutablePostOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    PostOrderMap(fun);
}

//MutableInOrderMappableContainer
template<typename Data>
void MutableInOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    InOrderMap(fun);
}

//MutableBreadth
template<typename Data>
void MutableBreadthMappableContainer<Data>::Map(MutableMapFunctor fun) {
    BreadthMap(fun);
}


/* ************************************************************************** */

//ExistsFunctions
//PreOrderNonMutable
template<typename Data>
bool PreOrderMappableContainer<Data>::Exists(const Data& dat) const noexcept {
    Data cmp = dat;
    bool ris = false;
    Fold({
        [this,&cmp](const Data & dt, void * ext) {
            if(dt==cmp){*((bool*)ext)=true;}
        }
    },&ris);
    return ris;
}


}
