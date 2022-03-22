#include <iostream>
#include "Camera.cpp"
#include "Sphere.cpp"
#include "Object.cpp"
#include <vector>

int main()
{
	std::cout << "\nRay Tracer Version1 ";
		
	int width = 50;
	int height = 50;

	Camera cam = Camera(width/2, height/2, -1); //create a camera origin at -1 in z-axis

	// Declare a memory block of size width*height
	int* imgArr = new int[width*height]; // just a grayscale image 0-255, 0 - being black to 255-being while

	// Scene creation
	std::vector<Object*> sceneObjects; // create an empty vector for storing object, this needs to be accelerated in the future with BVH
	Sphere* sphere1 = new Sphere(10, width / 2, height / 2, 10); //create a sphere right in front of the camera 
	sceneObjects.push_back(sphere1);

	// make image with 500x500, starting from bottom left to top right when seen from front of camera
	for (int i = 0; i < width; i++) // horizontal - width
	{
		for (int j = 0; j < height; j++) // vertical - height
		{
			//create a new ray here
			// create a new Ray and shoot it in a particular direction
			// TODO: think if it is better if this ray is created in camera class
			Ray ray = Ray(cam.getCameraLocation().x, cam.getCameraLocation().y, cam.getCameraLocation().z); //ray starting position is camera origin

			// send a ray from each pixel
			cam.shootRay(ray, i, j, 1); // we are creating a new ray at each pixel and in positive z-axis +1

			// for each object in the scene, check if the ray hits the object
			for (Object *obj : sceneObjects)
			{
				obj->checkHit(ray); // check if the object is hit by ray, and update the payload
			}
		}
	}

	// write to image - convert from array to image
	// using the PPM - Portable PixMap format

	return 0; // zero is exit-code for true or running normally
}