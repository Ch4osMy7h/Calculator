//
// Created by chaosmyth on 12/12/2017.
//

#ifndef CALCULATOR_VECTOR_H
#define CALCULATOR_VECTOR_H

#define DEFAULT_CAPACITY 100
typedef int Rank;
template <typename T> class Vector
{
protected:
    Rank _size; int _capacity; T* _elem;
    void copyFrom (T const* A, Rank lo, Rank hi);
    void expand();
    void shrink();
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
    {
        _elem = new T[_capacity = c];
        for(_size = 0; _size < s; _elem[_size++] = v);
    }
    Rank size() { return _size; }
    Vector(T const* A, Rank n) { copyFrom(A, 0, n); }
    T& operator[] (Rank r) const;
    ~Vector(){ delete [] _elem; }
    Rank insert(Rank r, T const& e);
    void push_back(T const& e);
    int remove(Rank lo, Rank hi);
    T& remove(Rank r);
    //void sort(Rank lo = 0, Rank hi = _size);
    void traverse(void (*) (T&));
    template <typename VST> void traverse(VST&);
};



template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while(lo < hi)
        _elem[_size++] = A[lo++];
}

template <typename T>
T& Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

template <typename T>
void Vector<T>::expand()
{
    if(_size < _capacity) return;
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* old = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i = 0; i < _size; ++i)
        _elem[i] = old[i];
    delete [] old;
}

template <typename T>
void Vector<T>::shrink()
{
    if(_capacity < DEFAULT_CAPACITY << 1) return;
    if(_size << 2 >_capacity) return;
    T* old = _elem;
    _elem = new T[_capacity >>= 1];
    for(int i = 0; i < _size; ++i)
        _elem[i] = old[i];
    delete [] old;
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e)
{
    expand();
    for(int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T>
void Vector<T>::push_back(T const &e)
{
    insert(size(), e);
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if(lo == hi) return 0;
    while(hi < _size) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}

template <typename T>
T& Vector<T>::remove(Rank r)
{
    T old = _elem[r];
    remove(r, r + 1);
    return old;
}

template <typename T>
void Vector<T>::traverse(void (*visit) (T&))
{
    for(int i = 0; i < _size; i++)
        visit(_elem[i]);
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit)
{
    for(int i = 0; i < _size; i++)
        visit(_elem[i]);
}



#endif //CALCULATOR_VECTOR_H
