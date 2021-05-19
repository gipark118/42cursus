/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:42:43 by gipark            #+#    #+#             */
/*   Updated: 2021/05/19 17:03:10 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T> class Array
{
private:
    unsigned int    len;
    T               *array;
public:
	Array()
    {
        this->len = 0;
        this->array = 0;
    }
	Array(unsigned int n)
    {
        this->len = n;
        this->array = new T[this->len];
        for (unsigned int i = 0; i < this->len; i++)
            this->array[i] = 0;
    }
	virtual ~Array()
    {
        delete this->array;
    }
	Array(const Array &other)
    {
        *this = other;
    }

	Array &operator=(const Array &other)
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

    unsigned int size(void) const
    {
        return len;
    }
    T &operator[](unsigned int index)
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

#endif
