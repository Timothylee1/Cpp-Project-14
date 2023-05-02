/*******************************************************************************
\File array.tpp
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

#include "array.hpp"

  
/******************************************************************************/
/*!
 \brief
   Returns an iterator pointing to the first element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::pointer Array<T, N>::begin(){
    return arr;
}

  
/******************************************************************************/
/*!
 \brief
   Returns an iterator pointing to the past-the-end element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::pointer Array<T, N>::end() {
    return (arr+N);
}

  
/******************************************************************************/
/*!
 \brief
   Returns an iterator pointing to the first element in the container. Note 
   that this is a overload const where the element cannot be modified.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::pointer Array<T, N>::begin() const{
    return arr;
}

  
/******************************************************************************/
/*!
 \brief
   Returns an iterator pointing to the past-the-end element in the container. 
   Note that this is a overload const where the element cannot be modified.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::pointer Array<T, N>::end() const{
    return (arr+N);
}

  
/******************************************************************************/
/*!
 \brief
   Returns a const_iterator pointing to the first element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cbegin() const{
    return arr;
}

  
/******************************************************************************/
/*!
 \brief
   Returns a const_iterator pointing to the past-the-end element in the 
   container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cend() const{
    return (arr+N);
}

  
/******************************************************************************/
/*!
 \brief
   Returns a reference to the first element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::reference Array<T, N>::front(){
    return *(begin());
}

  
/******************************************************************************/
/*!
 \brief
   Returns a reference to the last element in the container if the container 
   is not empty, else, returns the reference to the past-the-end element
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::reference Array<T, N>::back(){
    return empty() ? *(end()) : prev();
}

  
/******************************************************************************/
/*!
 \brief
   Returns a const_reference pointing to the first element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::const_reference Array<T, N>::front() const{
    return front();
}

  
/******************************************************************************/
/*!
 \brief
   Returns a const_reference pointing to the past-the-end element in the 
   container if the container is not empty, else, returns the reference to the 
   past-the-end element
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::const_reference Array<T, N>::back() const{
    return back();
}

  
/******************************************************************************/
/*!
 \brief
   Returns a reference pointing to the last element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::reference Array<T, N>::prev() {
    return *(arr+N-1);
}

  
/******************************************************************************/
/*!
 \brief
   Subscript operator that returns a reference to the element in the x param.
   
  \param x
   Represents the index of the element.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::reference Array<T, N>::operator[](size_type x) { 
    return arr[x];
}


/******************************************************************************/
/*!
 \brief
   Subscript operator that returns a const_reference to the element in the x 
   param.
   
  \param x
   Represents the index of the element.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::const_reference 
Array<T, N>::operator[](size_type x) const { 
    return arr[x];
}


/******************************************************************************/
/*!
 \brief
   Returns the number of elements in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
typename Array<T, N>::size_type Array<T, N>::size() const {
    return N;
}


/******************************************************************************/
/*!
 \brief
   No return value but assigns x to all the elements in the range.
   
  \param x
   The value to be assigned to each element in the container.
*/
/******************************************************************************/  
template <typename T, size_t N>
void Array<T, N>::fill(T const& x) {
    for (size_type i{}; i!=N; ++i) {
        arr[i] = x;       
    }
}


/******************************************************************************/
/*!
 \brief
   Swaps two objects. There is no return value but the two objects are
   swapped in place

  \param rhs
   The object to be swapped with arr.
*/
/******************************************************************************/  
template <typename T, size_t N>
void Array<T, N>::swap(Array<T, N> &rhs) {
/*     for (size_type i{}; i < N; ++i) { 
        T tmp = *(arr+i);
        *(arr+i) = rhs[i];
        rhs[i] = tmp;
    }   */
    for (size_type i{}; i < N; ++i) { 
        std::swap(arr[i], rhs[i]);
    }  
}


/******************************************************************************/
/*!
 \brief
   Returns boolean expression, true or false, for is the container empty 
   (i.e. whether its size is 0).
*/
/******************************************************************************/  
template <typename T, size_t N>
bool Array<T, N>::empty() const {
    return (N==0);
}
