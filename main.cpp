#include <iostream>
#include "Camera.cpp"
#include "Sphere.cpp"
#include "Object.cpp"
#include <vector>
#include <fstream>

int main()
{
	std::cout << "\nRay Tracer Version1 ";
		
	int width = 500;
	int height = 500;

	Camera cam = Camera(width/2, height/2, -10); //create a camera origin at -1 in z-axis

	// Declare a memory block of size width*height
	int* imgArr = new int[width*height]; // just a grayscale image 0-255, 0 - being black to 255-being while

	// Scene creation
	std::vector<Object*> sceneObjects; // create an empty vector for storing object, this needs to be accelerated in the future with BVH
	Sphere* sphere1 = new Sphere(20 , width / 2, height / 2, +30); //create a sphere right in front of the camera 
	sceneObjects.push_back(sphere1);

	// make image with 500x500, starting from bottom left to top right when seen from front of camera
	for (int i = 0; i < height; i++) // horizontal - width
	{
		for (int j = 0; j < width; j++) // vertical - height
		{
			//create a new ray here
			// create a new Ray and shoot it in a particular direction
			// TODO: think if it is better if this ray is created in camera class

			// set rays expanding from the camera
			//Ray ray = Ray(cam.getCameraLocation().x, cam.getCameraLocation().y, cam.getCameraLocation().z); //ray starting position is camera origin
			// set rays parallel to image plane
			Ray ray = Ray(i, j, 0); // ray origin is image plane in -1 z-axis

			// send a ray from each pixel
			cam.shootRay(ray, i, j, 1); // we are creating a new ray at each pixel and in positive z-axis +1

			// for each object in the scene, check if the ray hits the object
			for (Object *obj : sceneObjects)
			{
				// TODO: add depth check to make sure you don't overwrite color based on order of objects
				if (obj->checkHit(ray)) // check if the object is hit by ray, and update the payload
				{
					// can do more things in future once I know this object is hit by ray
					std::cout << "\tPixel hit coordinate: " << i << ":" << j;
				}
			}

			// write the ray payLoad color into image array
			imgArr[i * width + j] = ray.getRayLoad();
		}
	}

	// write to image - convert from array to image using the PPM - Portable PixMap format
	std::ofstream myImage;
	myImage.open("rayTracerVersion1.ppm");
	myImage << "P3" << std::endl;
	myImage << width << " " << height << std::endl;
	myImage << "255" << std::endl;

	int pixel = 0;
	for (int i = height-1; i >= 0; i--) // horizontal - width
	{
		for (int j = 0; j <width; j++) // vertical - height
		{
			// a grayscale in rgb is just the same value to all three channels
			myImage << imgArr[i * width + j] << " " << imgArr[i * width + j] << " " << imgArr[i * width + j] << std::endl;
		}
	}

	myImage.close();

	return 0; // zero is exit-code for true or running normally
}