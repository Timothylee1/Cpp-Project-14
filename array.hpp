/*******************************************************************************
\File array.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Half-Open Ranges with Function Templates; Cloning std::Array<T,N>
\Par Programming Lab #8
\Date 10-03-2022

  \Brief
   The purpose of this laboratory implement a class template that abstracts a 
   static array - that is, a simpler clone of std::array<T, N>. Elements will 
   be stored in the static array, and a compile time constant representing the 
   static array's size. A class template, and use template type parameter T 
   [for the array element type] and nontype parameter N 
   [for the array dimension], respectively. There will be member function 
   implementations such as begin(), front(), end(), back(), swap(), size(),
   and so on so forth as described below.

- begin
   Returns an iterator pointing to the first element in the container.

- end
   Returns an iterator pointing to the past-the-end element in the container.

- begin
   Returns an iterator pointing to the first element in the container. Note 
   that this is a overload const where the element cannot be modified.
    
- end
   Returns an iterator pointing to the past-the-end element in the container. 
   Note that this is a overload const where the element cannot be modified.

- cbegin
   Returns a const_iterator pointing to the first element in the container.
    
- cend
   Returns a const_iterator pointing to the past-the-end element in the 
   container.
       
- front
   Returns a reference to the first element in the container.
          
- back
   Returns a reference to the last element in the container.
          
- front
   Returns a const_reference pointing to the first element in the container.
          
- back
   Returns a const_reference pointing to the past-the-end element in the 
   container if the container is not empty, else, returns the reference to the 
   past-the-end element
   
- prev
   Returns a reference pointing to the last element in the container.

- operator[]
   Subscript operator that returns a reference to the element in the x param.
    
- operator[]
   Subscript operator that returns a const_reference to the element in the x 
   param.
   
- size
   Returns the number of elements in the container.

- fill
   No return value but assigns x to all the elements in the range.
    
- swap
   Swaps two objects. There is no return value but the two objects are
   swapped in place
        
- empty
   Returns boolean expression, true or false, for is the container empty 
   (i.e. whether its size is 0).

*******************************************************************************/

//-------------------------------------------------------------------------
#ifndef ARRAY_HPP
#define ARRAY_HPP
//-------------------------------------------------------------------------
#include <cstddef> // for size_t

namespace hlp2 {

// define class template Array<T,N> and document each member function

// this file will contain the definition of ALL member functions
// declared in class template Array<T,N>
    template <typename T, size_t N>
    class Array {
    
        public:
        using size_type = size_t;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;
        using const_iterator = const value_type*;
        using const_reference = const value_type&;
        value_type arr[N];

        pointer begin();
        pointer end();
        pointer begin() const;
        pointer end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        reference front();
        reference back();
        const_reference front() const;
        const_reference back() const;

        //additional for simplicity
        reference prev();

        reference operator[](size_type x);
        const_reference operator[](size_type x) const;

        size_type size() const;
        void fill(T const& x);
        void swap(Array<T, N> &rhs);
        bool empty() const;
    };



#include "array.tpp"
} // end namespace hlp2

#endif
