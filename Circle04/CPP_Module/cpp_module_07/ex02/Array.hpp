/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:42:43 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:42:43 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <exception>
#include <iostream>

template <class T> class Array
{
    private:
        unsigned int    len;
        T               *array;
    public:
		/* Default Constructor */
		Array()
        {
            this->len = 0;
            this->array = 0;
        }
		/* Constructor */
		Array(unsigned int n)
        {
            this->len = n;
            this->array = new T[this->len];
            for (unsigned int i = 0; i < this->len; i++)
                this->array[i] = 0;
        }
		/* Destructor */
		~Array()
        {
            delete this->array;
        }
		/* Copy Constructor */
		Array(const Array &other)
        {
            *this = other;
        }
        /* Operation overload = */
		Array &operator = (const Array &other)
        {
            if (this != &other)
            {
                if (this->array)
                    delete(this->array);
                this->len = other.len;
                this->array = new T[this->len];
                for (unsigned int i = 0; i < this->len; i++)
                    this->array[i] = other.array[i];
            }
            return (*this);
        }
		/* Other */
        unsigned int size(void) const
        {
            return len;
        }
        T & operator[](unsigned int index)
        {
            if (index >= this->len)
                throw std::exception();
            return (this->array[index]);
        }
        void print(void) const
        {
            for (unsigned int i = 0; i < this->len; i++)
                std::cout << this->array[i] << " ";
            std::cout << std::endl;
        }
};
