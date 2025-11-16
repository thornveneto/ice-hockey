#pragma once
#include "Region.h"
class RectangleRegion : public Region {
public:
	RectangleRegion(int id, double center_x, double center_y, double width, double height) {
		this->id = id;
		centroid = Vector2D{ center_x, center_y };
		this->width = width;
		this->height = height;
	}

	

	bool inside(const Vector2D& check_point) {

		bool inside_by_x = centroid.x - width / 2 <= check_point.x && check_point.x <= centroid.x + width / 2;
		bool inside_by_y = centroid.y - height / 2 <= check_point.y && check_point.y <= centroid.y + height / 2;

		return inside_by_x && inside_by_y;
	}
};