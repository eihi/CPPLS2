//
//  Array3D.cpp
//  arr3d
//
//  Created by Bob Polis on 09/11/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//
//  NOTE: This file is included by Array3D.h, so any client only needs to include that one.
//

template<typename T>
Array3D<T>::Array3D()
: x_size{ 0 }, y_size{ 0 }, z_size{ 0 }, p{ nullptr }
{
	std::cerr << "default construction\n";
}

template<typename T>
Array3D<T>::Array3D(size_t x_size, size_t y_size, size_t z_size)
: x_size{ x_size }, y_size{ y_size }, z_size{ z_size }, p{ nullptr }
{
	std::cerr << "preferred construction\n";
	p = new T[size()];
}

template<typename T>
Array3D<T>::Array3D(const Array3D& other)
: x_size{ other.x_size }, y_size{ other.y_size }, z_size{ other.z_size }, p{ nullptr }
{
	std::cerr << "copy construction\n";
	init_storage(other);
}

template<typename T>
Array3D<T>::Array3D(Array3D&& other)
: x_size{ other.x_size }, y_size{ other.y_size }, z_size{ other.z_size }, p{ other.p }
{
	std::cerr << "move construction\n";
	other.p = nullptr;
}

template<typename T>
Array3D<T>::~Array3D()
{
	cleanup_storage();
}

template<typename T>
Array3D<T>& Array3D<T>::operator=(const Array3D& other)
{
	std::cerr << "copy assignment\n";
	if (this != &other) {
		cleanup_storage();
		x_size = other.x_size;
		y_size = other.y_size;
		z_size = other.z_size;
		init_storage(other);
	}
	return *this;
}

template<typename T>
Array3D<T>& Array3D<T>::operator=(Array3D&& other)
{
	std::cerr << "move assignment\n";
	if (this != &other) {
		x_size = other.x_size;
		y_size = other.y_size;
		z_size = other.z_size;
		p = other.p;
		other.p = nullptr;
	}
	return *this;
}

template<typename T>
void Array3D<T>::init_storage(const Array3D& other)
{
	size_t sz{ size() };
	p = new T[sz];
	for (size_t i{ 0 }; i < sz; ++i) {
		p[i] = other.p[i];
	}
}

template<typename T>
void Array3D<T>::cleanup_storage()
{
	delete[] p;
	p = nullptr;
}

template<typename T>
Array3D& operator==(const Array3D other)
{
	if (this == other) {
		//
	}
	return *this;
}
