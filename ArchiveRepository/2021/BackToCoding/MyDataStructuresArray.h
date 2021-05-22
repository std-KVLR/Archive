#ifndef MYDATASTRUCTURESARRAY_H
#define MYDATASTRUCTURESARRAY_H

#include <ctype.h>
#include <exception>
#include <iostream>
#include <cstdarg>
#include "SatterHelpers.h"



namespace myDataStructures
{

// RAW memory manage layer

template <typename T>
class ArrayBuf
{
    ArrayBuf(const ArrayBuf&) = delete;
    ArrayBuf& operator= (const ArrayBuf) = delete;

protected:
    T *arr_;
    size_t capacity_, size_;

    ArrayBuf(size_t sz = 0) :
        arr_( (sz == 0) ? NULL : static_cast<T*>(::operator new(sizeof(T) * sz))), // ::operator new(global) its malloc
        capacity_(sz), size_(0) {}
    ~ArrayBuf() {
        SatterHelpers::destroy(arr_, arr_ + size_);
        ::operator delete(arr_); // ::operator delete(global) its free
    }

    void swap(ArrayBuf &rhs) noexcept
    {
        std::swap(arr_, rhs.arr_);
        std::swap(capacity_, rhs.capacity_);
        std::swap(size_, rhs.size_);
    }
};


template<typename T, size_t N = 0> class Array final : private ArrayBuf<T>
{

private:
    Array(size_t sz):ArrayBuf<T>(sz){} // insert helping constructor

    //  filling funtion
    void fillin(const T* dataPointer, size_t num = 1)
    {
        for(size_t j = 0;j < num; ++j){
            SatterHelpers::copy_construct(arr_ + size_, dataPointer[j]);
            ++size_;
        }
    }

public:

    using ArrayBuf<T>::size_;
    using ArrayBuf<T>::capacity_;
    using ArrayBuf<T>::arr_;


    Array():ArrayBuf<T>(N * 2 + 1) {}
    explicit Array(const T& value, size_t filling = 1) : ArrayBuf<T>(filling * 2)
    {
        while(size_ < filling){
            fillin(&value);
        }
    }

    Array(T const (&cortage)[N]): ArrayBuf<T>(N * 2 + 1)
    {
        fillin((*&cortage), N);
    }

    Array(std::initializer_list<T> init) : ArrayBuf<T>(N > 0 ? N * 2 + 1 : init.size() * 2 + 1)
    {
        if(N > 0) fillin(init.begin(), N);
        fillin(init.begin(), init.size());
    }


    Array& operator=(const Array rhs)
    {
        if(&rhs == this) return *this;
        this->swap(rhs);
        return *this;
    }


    const T& operator[](size_t pos) const
    {
        if(pos > size_ - 1) throw std::out_of_range("Throw in MyDataStructures:Array operator[]");
        return arr_[pos];
    }

    T& operator[](size_t pos)
    {
        return const_cast<T&>(static_cast<const Array&>(*this)[pos]);
    }


    const T& top()
    {
        if(size_ < 1) throw  std::runtime_error("Array is empty");
        return arr_[size_ - 1];
    }

    void pop()
    {
        if(size_ < 1) throw  std::runtime_error("Array is empty");
        size_--;
        SatterHelpers::destroy(arr_ + size_);
    }

    void push(const T& t)
    {
        if(size_ == capacity_){
            Array tmp(capacity_ * 2 + 1);
            while(tmp.size() < size_) tmp.push(arr_[tmp.size()]);
            tmp.push(t);
            this->swap(tmp);
        }
        else {
            fillin(&t);
        }
    }
    const T& insert(const T& elem, size_t pos = 0)
    {
        size_t sz;
        if (size_ == capacity_) sz = capacity_ * 2 + 1;
        else sz = capacity_;
        Array tmp(sz);
        while(tmp.size() < pos) tmp.push(arr_[tmp.size()]);
        tmp.push(elem);
        while(tmp.size() <= size_) tmp.push(arr_[tmp.size() - 1]);
        this->swap(tmp);
    }

    size_t size() const { return size_;}
    size_t capacity() const { return capacity_;}
    const T* cbegin() const  { return arr_; }
    const T* cend() const  { return arr_ + size_; }
    T* begin() const  { return arr_; }
    T* end() const  { return arr_ + size_; }

    void debug()
    {
        for(size_t i = 0; i < size_; ++i) {
            std::cout << i << ':' <<  arr_[i] << '\n';
        }
    }

};


}


#endif // MYDATASTRUCTURESARRAY_H
