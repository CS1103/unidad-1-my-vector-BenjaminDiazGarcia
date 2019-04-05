//
// Created by rudri on 3/29/2019.
//

#include "Vector.h"

namespace UTEC {
    int array[1];
    void vector::push_back(const int &value) {
        _size += 1;
        /* *_arr2 = nullptr;
         int array2[_size];*/
        _arr = array;
        
        if (_size == 1){
            array[0] = {value};
        }
        
        else {
            int* _arr2 = new int [_size];
            for (int i = 0; i < _size-1; i++){
                *(_arr2 + i) = *(_arr + i);
            }
            int array[_size];
            
            for (int i = 0; i < _size; i++){
                *(_arr + i) = *(_arr2 + i);
            }
            *(_arr + _size-1) = value;
            delete[] _arr2;
        }
    }

    void vector::pop_back() {
        _size -= 1;
        if (_size != 0){
            auto *_arr2 = new int [_size];
            for (int i = 0; i < _size-1; i++){
                *(_arr2 + i) = *(_arr + i);
            }
            int array[_size];
            
            for (int i = 0; i < _size; i++){
                *(_arr + i) = *(_arr2 + i);
            }
            delete[] _arr2;
        }
    }
    void vector::insert(int pos, const int &value){
        _size++;
        auto* _arr2 = new int [_size];
        for (int i = 0; i < pos; i++){
            *(_arr2 + i) = *(_arr + i);
        }
        *(_arr2 + pos) = value;
        for (int i = pos; i < _size; i++){
            *(_arr2 + i + 1) = *(_arr + i);
        }
        int array[_size];
        for (int i = 0; i < _size; i++){
            *(_arr + i) = *(_arr2 + i);
        }
        delete[] _arr2;
    }
    vector::vector() : _arr{nullptr}, _size(0) {}
    vector::~vector() {
        //Creo que va esto
        delete[] vector::_arr;
    }

    int vector::size() {return _size;}

    int vector::get_item(int i) {return _arr[i];}
}
