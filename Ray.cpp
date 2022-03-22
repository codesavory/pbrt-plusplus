/* Created by Suriya Dakshina on 20th March, 2022
Ray file keep track of a ray load and adds ray properties to file
*/
// header guard at start of header file
#ifndef RAY_CPP
#define RAY_CPP
#include <glm/glm.hpp>
#include <iostream>

class Ray
{
public:
	Ray(int x, int y, int z)
	{
		rayOrigin = glm::vec3(x, y, z);
		rayDirection = glm::vec3(x, y, 0); // TODO: default ray direction is to the center of image, maybe handle this better
		std::cout<<"\nRay Origin at location:<" << x << ":" << y << ":" << z << ">";
		std::cout<<"\nRay Direction at default location:<" << x << ":" << y << ":" << 0 << ">";
	}
	void setRayDirection(int x, int y, int z)
	{
		rayDirection = glm::vec3(x, y, z);
		std::cout << "\nRay direction at updated location:<" << x << ":" << y << ":" << z << ">";
	}
	int getRayLoad()
	{
		return rayLoad;
	}
	void setRayLoad(int inputRayLoad)
	{
		std::cout << "\nRay hit object";
		rayLoad = inputRayLoad;
	}
	glm::vec3 getRayOrigin()
	{
		return rayOrigin;
	}
	glm::vec3 getRayDirection()
	{
		return rayDirection;
	}

private:
	int rayLoad = 0; // initially the load of the ray is empty(0)-black, but this gets update eventually once it hits objects
	glm::vec3 rayOrigin;
	glm::vec3 rayDirection;
};
//End guard at bottom of header file
#endif 