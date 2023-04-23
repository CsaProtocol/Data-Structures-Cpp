
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

// Specific member function (Inherited from FoldableContainer)
template<typename Data>
inline void LinearContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    PreOrderFold(fun, acc);
}

/* ************************************************************************** */

// Specific member function (Inherited from PreOrderFoldableContainer)
template<typename Data>
inline void LinearContainer<Data>::PreOrderFold(FoldFunctor fun, void* acc) const {
    for(unsigned long index = 0; index < size; ++index) {
        fun(operator[](index), acc);
    }
}

/* ************************************************************************** */

// Specific member function (Inherited from PostOrderFoldableContainer)
template<typename Data>
inline void LinearContainer<Data>::PostOrderFold(FoldFunctor fun, void* acc) const {
    unsigned long index = size;
    while (index > 0) {
        fun(operator[](--index), acc);
    }
}

/* ************************************************************************** */

// Specific member function (Inherited from MappableContainer)
template<typename Data>
inline void LinearContainer<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun);
}

/* ************************************************************************** */

// Specific member function (Inherited from PreOrderMappableContainer)
template<typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFunctor fun) const {
    for(unsigned long index = 0; index < size; ++index) {
        fun(operator[](index));
    }
}

/* ************************************************************************** */

// Specific member function (Inherited from PostOrderMappableContainer)
template<typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFunctor fun) const {
    unsigned long index = size;
    while (index > 0) {
        fun(operator[](--index));
    }
}

/* ************************************************************************** */

// Specific member function (Inherited from MutableMappableContainer)
template<typename Data>
inline void LinearContainer<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

/* ************************************************************************** */

// Specific member function (Inherited from MutablePreOrderMappableContainer)
template<typename Data>
inline void LinearContainer<Data>::PreOrderMap(MutableMapFunctor fun) {
    for(unsigned long index = 0; index < size; ++index) {
        fun(operator[](index));
    }
}

/* ************************************************************************** */

// Specific member function (Inherited from MutablePostOrderMappableContainer)
template<typename Data>
inline void LinearContainer<Data>::PostOrderMap(MutableMapFunctor fun) {
    unsigned long index = size;
    while (index > 0) {
        fun(operator[](--index));
    }
}

/* ************************************************************************** */
template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& con) const noexcept {
    if(size != con.size) return false;
    for(unsigned long i = 0; i<size; i++) {
        try{
            if((*this)[i] != con[i]) {
                return false;
            }
        } catch (const std::out_of_range&) {
            return false;
        }
    } return true;
}

template<typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& con) const noexcept {
    return !(*this == con);
}

}
