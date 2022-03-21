/*Camera class for keep track of camera features like camera size, focal length for depth of field*/

#include <iostream>
#include "Ray.cpp"
#include <glm/glm.hpp>

class Camera
{
public:
	Camera(int x, int y, int z)
	{
		cameraLocation = glm::vec3(x, y, z); //creating a camera in given location
		std::cout << "\nCamera created at location:<"<<x<<":"<<y<<":"<<z<<">";
	}

	glm::vec3 getCameraLocation()
	{
		return cameraLocation;
	}

	void shootRay(Ray& inputRay, int x, int y, int z)
	{
		inputRay.setRayDirection(x, y, z); //create a ray in the particular direction
	}

private:
	glm::vec3 cameraLocation;
};