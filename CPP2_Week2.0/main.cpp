//
//  main.cpp
//  arr3d
//
//  Created by Bob Polis on 07/10/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include "Array3D.h"
#include "NDimArray.h"
#include <iostream>
using namespace std;

template<typename T>
Array3D<T> make_box(size_t x_size, size_t y_size, size_t z_size, T val)
{
	Array3D<T> a{ x_size, y_size, z_size };
	for (size_t z{ 0 }; z < a.get_z_size(); ++z) {
		for (size_t y{ 0 }; y < a.get_y_size(); ++y) {
			for (size_t x{ 0 }; x < a.get_x_size(); ++x) {
				a.put(val++, x, y, z);
			}
		}
	}
	return a;
}

template<typename T>
void print_box(const Array3D<T>& box)
{
	for (size_t z{ 0 }; z < box.get_z_size(); ++z) {
		for (size_t y{ 0 }; y < box.get_y_size(); ++y) {
			for (size_t x{ 0 }; x < box.get_x_size(); ++x) {
				cout << box.get(x, y, z) << ' ';
			}
		}
	}
	cout << '\n';
}

int main(int argc, const char * argv[])
{
	Array3D<int> box{ make_box<int>(2, 3, 4, 0) };
	print_box(box);

	Array3D<int> doos{ box };
	print_box(doos);

	Array3D<int> blikje;
	blikje = box;
	box.put(42, 0, 0, 0);
	print_box(blikje);

	NDimArray<int, 3> nbox{ { 2, 3, 4 } };
	int val{ 0 };
	for (size_t z{ 0 }; z < nbox.get_size(2); ++z) {
		for (size_t y{ 0 }; y < nbox.get_size(1); ++y) {
			for (size_t x{ 0 }; x < nbox.get_size(0); ++x) {
				size_t coords[] {x, y, z};
				nbox.put(val++, coords);
			}
		}
	}
	for (size_t z{ 0 }; z < nbox.get_size(2); ++z) {
		for (size_t y{ 0 }; y < nbox.get_size(1); ++y) {
			for (size_t x{ 0 }; x < nbox.get_size(0); ++x) {
				size_t coords[] {x, y, z};
				cout << nbox.get(coords) << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << '\n';

	NDimArray<int, 0> scalar{ { 0 } };
	scalar.put(42, { 0 });
	cout << scalar.get({ 0 }) << '\n';

	return 0;
}