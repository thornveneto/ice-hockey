#pragma once
#include "Vector2D.h"
class Region {
public:
	int id;
	Vector2D centroid;
	double width;
	double height;
	virtual bool inside(const Vector2D& check_point) = 0;
	virtual ~Region() {}
};