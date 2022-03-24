/*created by Suriya Dakshina on 21st-March-2022
Sphere class has the properties of a sphere creation and all the collision properties and material properties
*/
#ifndef SPHERE_CPP
#define SPHERE_CPP
#include "Object.cpp"
#include <glm/glm.hpp>
#include "Ray.cpp"

class Sphere : public Object
{
public:
	Sphere(int inputRadius, int x, int y, int z)
	{
		radius = inputRadius;
		sphereCenter = glm::vec3(x, y, z);
	}

	bool checkHit(Ray& inputRay)
	{
		// here you have ray details and object details, so update the Ray payload values
		// math logic inspired from RTOW - Ray Tracing in one weekend
		/* simple logic - t^2b⋅b + 2tb⋅(A−C)+(A−C)⋅(A−C)−r^2=0, solve for t
		where P(t)=A+tb -> Ray Equation
		and (P−C)⋅(P−C)=r2 -> Sphere Equation*/
		/*glm::vec3 oc = inputRay.getRayOrigin() - sphereCenter;
		auto a = glm::dot(inputRay.getRayDirection(), inputRay.getRayDirection());
		auto b = 2.0 * glm::dot(oc, inputRay.getRayDirection());
		auto c = glm::dot(oc, oc) - radius * radius;
		auto discriminant = b * b - 4.0 * a * c;

		if (discriminant > 0) // ray will hit object at some time
		{
			inputRay.setRayLoad(getColor()); // gets the color of the object and sets the rayLoad color
			return true;
		}
		return false;*/

		// geometric solution
		glm::vec3 L = sphereCenter - inputRay.getRayOrigin();
		float tca = glm::dot(L, inputRay.getRayDirection());
		float d2 = glm::dot(L, L) - tca * tca;
		if (d2 > radius)
			return false;
		inputRay.setRayLoad(getColor());
		return true;
	}
private:
	int radius;
	glm::vec3 sphereCenter;
};
//End guard at bottom of header file
#endif 