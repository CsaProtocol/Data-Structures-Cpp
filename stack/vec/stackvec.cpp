
namespace lasd {

/* ************************************************************************** */
//Default Constructor
template<typename Data>
StackVec<Data>::StackVec(): Vector<Data>::Vector(1){}

//Specific Constructor
template<typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& con): Vector<Data>::Vector(con) {
    size=con.Size();
    top=size;
}
template<typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&& con): Vector<Data>::Vector(con) {
    size=con.Size();
    top=size;
}

//Copy Constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stackvec): Vector<Data>::Vector(stackvec) {
    top = stackvec.top;
}
//Copy Assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackvec) {
    Vector<Data>::operator=(stackvec);
    top=stackvec.top;
    return *this;
}
//Move Constructor
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackvec): Vector<Data>::Vector(stackvec) {
    top = stackvec.top;
}
//Move Assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackvec) noexcept {
    Vector<Data>::operator=(std::move(stackvec));
    std::swap(top, stackvec.top);
    return *this;
}

//Comparison operator (==)
template<typename Data>
bool StackVec<Data>::operator==(const StackVec& s) const noexcept {
        if (top != s.top) {
            return false;
        }
        for (unsigned long i = 0; i < top; i++) {
            if (Vector<Data>::operator[](i) != s.Vector<Data>::operator[](i)) {
                return false;
            }
        }
        return true;
}
    /*if(this == &s)
        return true;
    if(top != s.top)
        return false;
    unsigned long index = 0;
    while(index < top && Vector<Data>::operator[](index) == s.Vector<Data>::operator[](index))
        index++;
    return index == top;*/

//Comparison operator !=
template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& s) const noexcept {
    return !(*this == s);
}

//Top Function (const)
template <typename Data>
const Data& StackVec<Data>::Top() const {
    if(Empty())
        throw std::length_error("Couldn't remove from StackQueue. Actual size = 0");
    return Vector<Data>::operator[](top-1);
}
//Top Function
template <typename Data>
Data& StackVec<Data>::Top() {
    if(Empty())
        throw std::length_error("Couldn't remove from StackQueue. Actual size = 0");
    return Vector<Data>::operator[](top-1);
}

//Pop Function
template<typename Data>
void StackVec<Data>::Pop() {
    if(Empty())
        throw std::length_error("Couldn't remove from StackQueue. Actual size = 0");
    Data to_delete = std::move(Vector<Data>::operator[](--top));
    (void) to_delete;

    if(top < size/4)
        Reduce();
}

//TopNPop
template<typename Data>
Data StackVec<Data>::TopNPop() {
    Data result = Top();
    Pop();
    return result;
}
//Push Copia
template<typename Data>
void StackVec<Data>::Push(const Data& d) {
    if(top == size)
        Expand();
    Vector<Data>::operator[](top++) = d;
}
//Push move
template<typename Data>
void StackVec<Data>::Push(Data&& d) {
    if(top == size)
        Expand();
    Vector<Data>::operator[](top++) = std::move(d);
}

template<typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return top == 0;
}

template<typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
    return top;
}

template<typename Data>
void StackVec<Data>::Clear() noexcept {
    Vector<Data>::Resize(1);
    top = 0;
}
//expand
template<typename Data>
void StackVec<Data>::Expand() {
    Vector<Data>::Resize(size*2);
}
//reduce
template<typename Data>
void StackVec<Data>::Reduce() {
    Vector<Data>::Resize(size/2);
}

/* ************************************************************************** */

}
