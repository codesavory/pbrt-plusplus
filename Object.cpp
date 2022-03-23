/*created by Suriya Dakshina on 21st-March-2022
The object class is any hittable object in the scene - sphere, box, pyramid, etc*/
// header guard at start of header file
#ifndef OBJECT_CPP
#define OBJECT_CPP
#include "Ray.cpp"

class Object
{
public:
	int getColor()
	{
		return color;
	}
	void setColor(int inputColor)
	{
		color = inputColor;
	}
	virtual bool checkHit(Ray&) = 0; // check if a Ray intersects an Object in each child class
private:
	int color = 255; // default color of object is white(1), unless changed in child class
};
//End guard at bottom of header file
#endif 