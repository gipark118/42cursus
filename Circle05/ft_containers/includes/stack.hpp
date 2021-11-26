#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = vector<T> >
    class stack
    {
    public:
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

    private:
        container_type _container;

    public:
        // Member functions
        // (constructor)
        explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) {}

        // (destructor)
        virtual ~stack() {}

        // empty
        bool        empty() const
        {
            return this->_container.empty();
        }

        // size
        size_type   size() const
        {
            return this->_container.size();
        }

        // top
        value_type& top()
        {
            return this->_container.back();
        }
        const value_type& top() const
        {
            return this->_container.back();
        }

        // push
        void push (const value_type& val)
        {
            return this->_container.push_back(val);
        }

        // pop
        void pop()
        {
            return this->_container.pop_back();
        }

        // Non-member function overloads
        // relational operators
        // (1)
        friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._container == rhs._container);
        }
        // (2)
        friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._container != rhs._container);
        }
        // (3)
        friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._container < rhs._container);
        }
        // (4)
        friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._container <= rhs._container);
        }
        // (5)
        friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._container > rhs._container);
        }
        // (6)
        friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._container >= rhs._container);
        }

    };
}

#endif
