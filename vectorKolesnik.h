//
// Created by Daniil Kolesnik on 27/05/2021.
//all rights and lefts reserved

#ifndef HW2_VECTORKOLESNIK_H
#define HW2_VECTORKOLESNIK_H


#include <iostream>
#include <stdexcept>




//-----------------------------------------------------------------------
//using std::rel_ops::operator !=;
//using std::rel_ops::operator>;
//using std::rel_ops::operator<=;
//using std::rel_ops::operator>=;
template<typename T>//шаблон
class vectorKolesnik {
    int _size;
    int _capacity;
    T *_arr;
public:
    typedef size_t size_type;
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef const T *reverse_iterator;
    typedef const T *const_reverse_iterator;

    explicit vectorKolesnik();//конструктор
    vectorKolesnik(const vectorKolesnik<T> &);//конструктор копирования
    ~vectorKolesnik();
    size_type size() const;

    size_type capacity() const;

    void resize(size_type, T = T());

    void reserve(size_type);

    void push_back(const T &);

    void pop_back();

    iterator erase(iterator);

    iterator erase(iterator, iterator);

    iterator insert(iterator, const T &);

    void clear();

    void swap(vectorKolesnik<T> &);

    T *data();

    T &front();

    T &back();

    T &at(size_type);

    [[nodiscard]] bool empty() const;

    const vectorKolesnik &operator=(const vectorKolesnik &);

    const T &operator[](size_type) const;

    T &operator[](size_type);

    iterator begin();

    const_iterator cbegin() const;

    reverse_iterator rbegin();

    const_reverse_iterator crbegin() const;

    iterator end();

    const_iterator cend() const;

    reverse_iterator rend();

    const_reverse_iterator crend() const;
};

// Констр

template<typename T>
vectorKolesnik<T>::vectorKolesnik() :
        _size(0), _capacity(2 * _size), _arr(nullptr) {
}



// Констр копир

template<typename T>
vectorKolesnik<T>::vectorKolesnik(const vectorKolesnik<T> &c) :
        _size(c._size), _capacity(c._capacity), _arr(new T[_capacity]) {
    for (size_type i = 0; i != _size; ++i)
        _arr[i] = c._arr[i];
}



// destr

template<typename T>
vectorKolesnik<T>::~vectorKolesnik() {
    delete[] _arr;
}



// size


template<typename T>
typename vectorKolesnik<T>::size_type vectorKolesnik<T>::size() const {
    return _size;
}


// capacity

// Возвращает число элементов, которое вектор может содержать без выделения дополнительного пространства.

template<typename T>
typename vectorKolesnik<T>::size_type vectorKolesnik<T>::capacity() const {
    return _capacity;
}


// resize

// Определяет новый размер вектора.

template<typename T>
void vectorKolesnik<T>::resize(size_type _new_size, T c) {
    _capacity = 2 * _new_size;
    T *_new_arr = new T[_capacity];
    for (size_type i = 0; i != (_size <= _new_size ? _size : _new_size); ++i)
        _new_arr[i] = _arr[i];
    for (size_type i = (_size <= _new_size ? _size : _new_size); i != _new_size; ++i)
        _new_arr[i] = c;

    delete[] _arr;
    _size = _new_size;
    _arr = _new_arr;
}


// data


// Возвращает указатель на первый элемент в векторе

template<typename T>
T *vectorKolesnik<T>::data() {
    return _arr;
}



// push_back


template<typename T>
void vectorKolesnik<T>::push_back(const T &val) {
    if (_size == _capacity) {
        resize(_size + 1);
        --_size;
    }

    _arr[_size++] = val;
}



// pop_back


template<typename T>
void vectorKolesnik<T>::pop_back() {
    if (_size > 0)
        --_size;
}



// erase(по итератору)


template<typename T>
typename vectorKolesnik<T>::iterator vectorKolesnik<T>::erase(iterator position) {
    for (iterator i = position; i != end(); ++i)
        *i = *(i + 1);
    --_size;
    return position;
}



// erase(диапозон по итераторам)


template<typename T>
typename vectorKolesnik<T>::iterator vectorKolesnik<T>::erase(iterator first, iterator last) {
    size_type beg = first - begin();
    size_type end = last - begin();
    size_type _new_size = _size - end + beg;
    size_type _new_capacity = 2 * _new_size;

    T *_new_arr = new T[_new_capacity];

    for (size_type i = 0; i != beg; ++i)
        _new_arr[i] = _arr[i];

    for (size_type i = beg, j = end; j != _size; ++i, ++j)
        _new_arr[i] = _arr[j];

    delete[] _arr;

    _size = _new_size;
    _capacity = _new_capacity;
    _arr = _new_arr;
    return begin() + beg;
}



// insert


// Вставка одного элемента

template<typename T>
typename vectorKolesnik<T>::iterator vectorKolesnik<T>::insert(iterator position, const T &x) {
    size_type tmp = position - begin();
    if (_size + 1 > _capacity)
        resize(_size + 1);
    else
        ++_size;
    position = begin() + tmp;
    for (iterator i = end() - 1; i != position; --i)
        *i = *(i - 1);
    *position = x;
    return position;
}



// clear


// Очищает элементы вектора.
template<typename T>
void vectorKolesnik<T>::clear() {
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
    _capacity = 0;
}


// swap


// Меняет местами элементы двух векторов.

template<typename T>
void vectorKolesnik<T>::swap(vectorKolesnik<T> &c) {


    std::swap(_size, c._size);
    std::swap(_capacity, c._capacity);
    std::swap(_arr, c._arr);

}



// at
// Возвращает ссылку на элемент в заданном положении в векторе.

template<typename T>
T &vectorKolesnik<T>::at(size_type index) {
    if (index >= _size)
        throw std::out_of_range("Expression: vector subscript out of range.");
    return _arr[index];
}



// front

// Возвращает ссылку на первый элемент в векторе.

template<typename T>
T &vectorKolesnik<T>::front() {
    return at(0);
}


// back


// Возвращает ссылку на последний элемент вектора.

template<typename T>
T &vectorKolesnik<T>::back() {
    return at(_size - 1);
}



// empty


// Проверяет, пуст ли контейнер вектора.

template<typename T>
bool vectorKolesnik<T>::empty() const {
    return _size == 0;
}


// operator=


// Оператор присваивания копированием

template<typename T>
const vectorKolesnik<T> &vectorKolesnik<T>::operator=(const vectorKolesnik<T> &c) {

    _size = c._size;
    _capacity = c._capacity;
    delete[] _arr;
    _arr = new T[_capacity];
    for (size_type i = 0; i != c._size; ++i)
        _arr[i] = c._arr[i];


    return *this;
}


// const operator[]

template<typename T>
const T &vectorKolesnik<T>::operator[](size_type n) const {
    return _arr[n];
}



// operator[]

template<typename T>
T &vectorKolesnik<T>::operator[](size_type n) {
    return _arr[n];
}



// begin
// Возвращает итератор произвольного доступа, указывающий на первый элемент в векторе.

template<typename T>
typename vectorKolesnik<T>::iterator vectorKolesnik<T>::begin() {
    return _arr;
}


// cbegin


// Возвращает постоянный итератор произвольного доступа, указывающий на первый элемент в векторе.

template<typename T>
typename vectorKolesnik<T>::const_iterator vectorKolesnik<T>::cbegin() const {
    return _arr;
}



// rbegin


// Возвращает итератор, указывающий на первый элемент в обратном векторе.

template<typename T>
typename vectorKolesnik<T>::reverse_iterator vectorKolesnik<T>::rbegin() {
    return _arr + _size - 1;
}



// crbegin
// Возвращает константный итератор, который указывает на первый элемент в обратном векторе.

template<typename T>
typename vectorKolesnik<T>::const_reverse_iterator vectorKolesnik<T>::crbegin() const {
    return _arr + _size - 1;
}


// end


// Возвращает итератор произвольного доступа, который указывает на конец вектора.

template<typename T>
typename vectorKolesnik<T>::iterator vectorKolesnik<T>::end() {
    return _arr + _size;
}


// cend


// Возвращает константный итератор произвольного доступа, указывающий на позицию, следующую за концом вектора.

template<typename T>
typename vectorKolesnik<T>::const_iterator vectorKolesnik<T>::cend() const {
    return _arr + _size;
}


// rend
// Возвращает итератор, который указывает на последний элемент в обратном векторе.

template<typename T>
typename vectorKolesnik<T>::reverse_iterator vectorKolesnik<T>::rend() {
    return _arr - 1;
}



// crend


// Возвращает константный итератор, который указывает на последний элемент в обратном векторе.

template<typename T>
typename vectorKolesnik<T>::const_reverse_iterator vectorKolesnik<T>::crend() const {
    return _arr - 1;
}



// reserve

// Резервирует минимальную длину хранилища для объекта вектора.

template<typename T>
void vectorKolesnik<T>::reserve(size_type newCap) {
    if (_capacity < newCap) {
        T *temp = static_cast<T *>(::operator new(newCap * sizeof(T)));
        if (_capacity) {
            for (size_t i = 0; i < _size; ++i) {
                temp[i] = _arr[i];
                _arr[i].~T();
            }
            ::operator delete(_arr, _capacity * sizeof(T));
        }
        _arr = temp;
        _capacity = newCap;
    }
}
#endif //HW2_VECTORKOLESNIK_H
