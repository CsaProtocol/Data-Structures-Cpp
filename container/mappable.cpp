#pragma once
#include "mappable.hpp"
#include <stdexcept>

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

//PostOrderMappableContainer
template<typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PostOrderMap(fun);
}

template<typename Data>
void PostOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    PostOrderFold(fun, punt);
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
