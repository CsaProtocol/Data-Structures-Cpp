
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data> & con) {
    bool all = true;
    con.Map(
            [this, & all](const Data & dat) {
                all &= Insert(dat);
            }
        );
    return all;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MutableMappableContainer<Data> && con) {
    bool all = true;
    con.Map(
            [this, & all](const Data & dat) {
                all &= Insert(dat);
            }
        );
    return all;
}

template<typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data> & con) {
    bool all = true;
    con.Map(
            [this, & all](const Data & dat) {
                all &= Remove(dat);
            }
        );
    return all;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data> & con) {
    bool some = false;
    con.Map(
            [this, & some](const Data & dat) {
                some |= Insert(dat);
            }
    );
    return some;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MutableMappableContainer<Data> && con) {
    bool some = true;
    con.Map(
            [this, & some](const Data & dat) {
                some |= Insert(dat);
            }
    );
    return some;
}

template<typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data> & con) {
    bool some = true;
    con.Map(
            [this, & some](const Data & dat) {
                some |= Remove(dat);
            }
    );
    return some;
}

/* ************************************************************************** */

}
