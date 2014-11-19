//
//  NDimArray.h
//  arr3d
//
//  Created by Bob Polis on 15/10/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#ifndef __arr3d__NDimArray__
#define __arr3d__NDimArray__

#include <iostream>
#include <vector>

template<typename T, size_t N>
class NDimArray {
public:
	// default constructor
	NDimArray()
		: p{ nullptr }
	{
		std::cerr << "default construction\n";
	}

	// preferred constructors
	NDimArray(const std::vector<size_t> dims)
		: p{ nullptr }
	{
		std::cerr << "preferred construction with vector\n";
		for (size_t i = 0; i < N; ++i) {
			dimensions[i] = dims.at(i);
		}
		p = new T[size()];
	}

	NDimArray(const size_t dims[])
		: p{ nullptr }
	{
		std::cerr << "preferred construction with array\n";
		for (int i{ 0 }; i < N; ++i) {
			dimensions[i] = dims[i];
		}
		p = new T[size()];
	}

	// copy constructor
	NDimArray(const NDimArray& other)
		: dimensions{ other.dimensions }, p{ nullptr }
	{
		std::cerr << "copy construction\n";
		init_storage(other);
	}

	// move constructor
	NDimArray(NDimArray&& other)
		: dimensions{ other.dimensions }, p{ other.p }
	{
		std::cerr << "move construction\n";
		other.p = nullptr;
	}

	// destructor (not virtual because this class is not meant to be subclassed)
	~NDimArray() { cleanup_storage(); }

	// copy assignment
	NDimArray<T, N>& operator=(const NDimArray& other)
	{
		std::cerr << "copy assignment\n";
		if (this != &other) {
			cleanup_storage();
			for (size_t i = 0; i < N; ++i) {
				dimensions[i] = other.dimensions[i];
			}
			init_storage(other);
		}
		return *this;
	}

	// move assignment
	NDimArray<T, N>& operator=(NDimArray&& other)
	{
		std::cerr << "move assignment\n";
		if (this != &other) {
			for (size_t i = 0; i < N; ++i) {
				dimensions[i] = other.dimensions[i];
			}
			p = other.p;
			other.p = nullptr;
		}
		return *this;
	}

	// storing & retrieving values
	void put(const T& val, const size_t coords[]) { p[index(coords)] = val; }
	T get(const size_t coords[]) const { return p[index(coords)]; }

	// number of dimensions
	size_t get_num_dimensions() const { return N; }

	// number of elements
	size_t size() const
	{
		size_t result{ 1 };
		for (size_t sz : dimensions) {
			result *= sz;
		}
		return result;
	}

	// accessor
	size_t get_size(size_t dimension) const { return dimensions[dimension]; }

private:
	size_t dimensions[N];
	T* p;

	// translation from (x, y, z) to flat index
	size_t index(const size_t coords[]) const
	{
		size_t result{ 0 };
		size_t prev_dim{ 1 };
		for (int i{ 0 }; i < N; ++i) {
			result += prev_dim * coords[i];
			prev_dim *= dimensions[i];
		}
		return result;
	}

	// copy initializer, used by copy constructor and copy assignment
	void init_storage(const NDimArray& other)
	{
		size_t sz{ size() };
		p = new T[sz];
		for (size_t i{ 0 }; i < sz; ++i) {
			p[i] = other.p[i];
		}
	}

	// cleanup, used by destructor and copy assignment
	void cleanup_storage() {
		delete[] p;
		p = nullptr;
	}
};

#endif /* defined(__arr3d__NDimArray__) */