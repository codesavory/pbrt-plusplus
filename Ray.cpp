/* Created by Suriya Dakshina on 20th March, 2022
Ray file keep track of a ray load and adds ray properties to file
*/
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
		rayLoad = inputRayLoad;
	}

private:
	int rayLoad = 0; // initially the load of the ray is empty, but this gets update eventually once it hits objects
	glm::vec3 rayOrigin;
	glm::vec3 rayDirection;
};