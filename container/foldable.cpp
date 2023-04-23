
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//FoldableContainer

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& dat) const noexcept {
    Data cmp = dat;
    bool ris = false;
    Fold({
        [this,&cmp](const Data & dt, void * ext) {
            if(dt==cmp){*((bool*)ext)=true;}
        }
    },&ris);
    return ris;
}

// PreOrderFoldableContainer
template<typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    PreOrderFold(fun, punt);
}

template<typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    PostOrderFold(fun, punt);
}
template<typename Data>
void InOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    InOrderFold(fun, punt);
}
/*template<typename Data>
void BreadthFoldableContainer<Data>::Fold(FoldFunctor fun, void* punt) const {
    BreadthFold(fun, punt);
}*/
/* ************************************************************************** */

}
