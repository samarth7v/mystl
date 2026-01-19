#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>
#include "iterator.h"

template<typename T>
class vector{
    public:

    //constructors for vector
        vector(size_t size, T _value):capacity_(size),size_(size),data_(std::make_unique<T[]>(capacity_))
        {
            for(int i=0;i<size_;i++){
                data_[i] = _value;
            }
        }
        vector():capacity_(2), size_(0), data_(std::make_unique<T[]>(2)) {}
        vector(std::initializer_list<T> _list)
        {
            int size = std::distance(_list.begin(),_list.end());
            capacity_ = size;
            size_ = size;
            data_  = std::make_unique<T[]>(capacity_);
            for(int i=0;i<size_;i++){
                data_[i] = *(_list.begin()+i);
            }
        }
        class iota:public Iterator<T>{
            using Iterator<T>::Iterator;
        };
        iota begin(){
            iota I(&data_[0]);
            return I;
        }
        iota end(){
            iota I(&data_[size_]);
            return I;
        }
    
    //push back
        void push_back(const T& value)
        {
            if(size_+1>capacity_){
                nsize(2);
            }
            data_[size_] = value;
            size_ ++;
        }
        T back()
        {
            return data_[size_-1];
        }
        void pop_back()
        {
            size_--;
            data_[size_]=none;
        }
        size_t size(){
            return size_;
        }
        T& operator[](size_t index){
            if(index>=size_){
                std::cout<<"Index exceeded size of vector\n";
                return none;
            }
            return data_[index];
        }
    private:
        size_t capacity_;
        size_t size_;
        std::unique_ptr<T[]> data_;

        void nsize(int n){
            auto newdata = std::make_unique<T[]>(n*capacity_);
            for(int i=0; i<size_ ; i++){
                newdata[i] = std::move(data_[i]);
            }
            data_ = std::move(newdata);
            capacity_ = n*capacity_;
        }
        T none;
};