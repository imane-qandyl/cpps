/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:22 by imqandyl          #+#    #+#             */
/*   Updated: 2025/08/27 00:35:29 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array {
    private:
        T* _data;
        unsigned int _size;
    public:
        // Default constructor: empty array
        Array() : _data(NULL), _size(0) {}

        // Constructor with size
        Array(unsigned int n) : _data(NULL), _size(n) {
            if (n > 0)
                _data = new T[n]();
        }

        // Copy constructor
        Array(const Array& other) : _data(NULL), _size(other._size) {
            if (_size > 0) {
                _data = new T[_size]();
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
        }

        // Assignment operator
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] _data;
                _size = other._size;
                _data = (_size > 0) ? new T[_size]() : NULL;
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
            return *this;
        }

        ~Array() {
            delete[] _data;
        }

        // Subscript operator (non-const)
        T& operator[](unsigned int idx) {
            if (idx >= _size)
                throw std::out_of_range("Array index out of bounds");
            return _data[idx];
        }

        // size() member function
        unsigned int size() const {
            return _size;
        }
};
