#pragma once
#include "vector.hpp"
namespace lasd {

/* ************************************************************************** */
template<typename Data>
Vector<Data>::Vector(const unsigned long length) {
    element = new Data[length] {};
    size = length;
}
//Constructor for vector - MappableContainer
template<typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& con) {
    size = con.Size();
    element = new Data[size];
    unsigned long index = 0;
    con.Map(
        [this, & index](const Data & dat){
            element[index++] = dat;
        }
    );
}
//Constructor for vector - MutableMappableContainer
template<typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& con) {
    size = con.Size();
    element = new Data[size];
    unsigned long index = 0;
    con.Map(
        [this, & index](Data & dat){
            element[index++] = std::move(dat);
        }
    );
}

//Copy Constructor
template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vec) {
    size = vec.size;
    element = new Data[size];
    std::copy(vec.element, vec.element+size, element);
}

//Mv constructor
template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vec) noexcept {
    std::swap(element, vec.element);
    std::swap(size, vec.size);
}

//Destructor
template<typename Data>
Vector<Data>::~Vector() {
    delete[] element;
}


//Copy Assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec) {
    element = new Data[vec.size];
    std::copy(vec.element, vec.element + vec.size, element);
    size = vec.size;
    return *this;
    /*Vector<Data>* newvec = new Vector<Data>(vec);
    std::swap(*newvec, *this);
    delete newvec;
    return *this*/
}

//Mv assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept {
    std::swap(element, vec.element);
    std::swap(size, vec.size);
    return *this;
}

//Comparison operators
template<typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept {
    if(size == vec.size) {
        for(unsigned long i = 0; i<size;++i) {
            if(element[i] != vec.element[i]) {
                return false;
            }
        } return true;
    } else {
        return false;
    }
}
template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept {
    return !(*this == vec);
}

template<typename Data>
void Vector<Data>::Clear() {
    delete[] element;
    element = nullptr;
    size = 0;
}

//Specific member functions

template<typename Data>
void Vector<Data>::Resize(const unsigned long newsize) {
    if (newsize == 0) {
        Clear();
    } else if (size != newsize) {
        Data* TmpElements = new Data[newsize] {};
        unsigned long minsize = (size < newsize) ? size : newsize;
        for (unsigned long index = 0; index < minsize; ++index) {
            std::swap(element[index], TmpElements[index]);
        }
        std::swap(element, TmpElements);
        size = newsize;
        delete[] TmpElements;
    }
}
//Operator []
template<typename Data>
const Data& Vector<Data>::operator[](const unsigned long j) const {
    if(j<size) {
        return element[j];
    } else {
        throw std::out_of_range("Index not valid.");
    }
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long j) {
    if(j<size) {
        return element[j];
    } else {
        throw std::out_of_range("Index not valid.");
    }
}
//Front
template<typename Data>
const Data& Vector<Data>::Front() const {
    if(size != 0){
        return element[0];
    } else {
        throw std::length_error("The array is empty!");
    }
}

template<typename Data>
Data& Vector<Data>::Front() {
    if(size != 0){
        return element[0];
    } else {
        throw std::length_error("The array is empty!");
    }
}

template<typename Data>
const Data& Vector<Data>::Back() const {
    if(size != 0) {
        return element[size-1];
    } else {
        throw std::length_error("The array is empty!");
    }
}
template<typename Data>
Data& Vector<Data>::Back() {
    if(size != 0) {
        return element[size-1];
    } else {
        throw std::length_error("The array is empty!");
    }
}

template<typename Data>
void Vector<Data>::Sort() noexcept {
    for (unsigned long i = 1; i < size; ++i) {
        Data key = element[i];
        unsigned long j = i;
        while (j > 0 && element[j-1] > key) {
            element[j] = element[j-1];
            --j;
        }
        element[j] = key;
    }
}

template <typename Data>
void Vector<Data>::QuickSort(unsigned long left, unsigned long right) noexcept {
    if (left < right) {
        unsigned long pivot = Partition(left, right);
        QuickSort(left, pivot-1);
        QuickSort(pivot+1, right);
    }
}

template <typename Data>
unsigned long Vector<Data>::Partition(unsigned long left, unsigned long right) noexcept {
    // Choose the rightmost element as pivot
    Data pivot = element[right];
    unsigned long i = left - 1;
    for (unsigned long j = left; j < right; ++j) {
        if (element[j] < pivot) {
            ++i;
            std::swap(element[i], element[j]);
        }
    }
    std::swap(element[i+1], element[right]);
    return i+1;
}

//*************************************************************************** */

}
