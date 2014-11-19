//
//  Array3D.h
//  arr3d
//
//  Created by Bob Polis on 07/10/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#ifndef __arr3d__Array3D__
#define __arr3d__Array3D__

#include <iostream>

template<typename T>
class Array3D {
public:
	Array3D(); // default constructor
	Array3D(size_t x_size, size_t y_size, size_t z_size); // preferred constructor
	Array3D(const Array3D& other); // copy constructor
	Array3D(Array3D&& other); // move constructor

	~Array3D(); // destructor (not virtual because this class is not meant to be subclassed)

	Array3D<T>& operator=(const Array3D& other); // copy assignment
	Array3D<T>& operator=(Array3D&& other); // move assignment

	// storing & retrieving values
	void put(const T& val, size_t x, size_t y, size_t z) { p[index(x, y, z)] = val; }
	T get(size_t x, size_t y, size_t z) const { return p[index(x, y, z)]; }

	// number of elements
	size_t size() const { return x_size * y_size * z_size; }

	// accessors
	size_t get_x_size() const { return x_size; }
	size_t get_y_size() const { return y_size; }
	size_t get_z_size() const { return z_size; }

	Array3D& operator==(Array3D);

private:
	size_t x_size, y_size, z_size;
	T* p;

	// translation from (x, y, z) to flat index
	size_t index(size_t x, size_t y, size_t z) const { return y_size * x_size * z + x_size * y + x; }

	// copy initializer, used by copy constructor and copy assignment
	void init_storage(const Array3D& other);

	// cleanup, used by destructor and copy assignment
	void cleanup_storage();
};

#include "Array3D.hpp"

#endif /* defined(__arr3d__Array3D__) */