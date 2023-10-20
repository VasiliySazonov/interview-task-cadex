#include <curves.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <math.h>
#include <random>
#include <ctime>

#define RANDOM_DOUBLE(min, max) min + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (max - min))

std::unique_ptr<ParametricCurve> randomCurve()
{
	switch (std::rand() % 3)
	{
		case 0:
		{
			double radius = RANDOM_DOUBLE(1, 10);
			return std::make_unique<Circle>(radius);
		}
		case 1:
		{
			double radiusX = RANDOM_DOUBLE(1, 10);
			double radiusY = RANDOM_DOUBLE(1, 10);
			return std::make_unique<Ellipse>(radiusX, radiusY);
		}
		case 2:
		{
			double radius = RANDOM_DOUBLE(1, 10);
			double step = RANDOM_DOUBLE(1, 10);
			return std::make_unique<Helix>(radius, step);
		}
	}

	// just to stop seeing the warning
	return std::make_unique<ParametricCurve>();
}

int main(int argc, char const *argv[])
{
	std::srand(std::time(0));

	// The first container
	std::vector<std::shared_ptr<ParametricCurve>> parametricCurves;

	// Filling the first container with random data
	for (int i = 0; i < 32; i++)
		parametricCurves.push_back(randomCurve());

	// Displaying data from the first container
	for (int i = 0; i < parametricCurves.size(); i++)
	{
		// I was also supposed to print a derivative but
		// The f do you even mean "derivative"? tanget???

		Vector3D point = parametricCurves[i]->pointFromAngle(M_PI_4);
		
		std::cout << "C(PI/4) for curve at " << &(*parametricCurves[i])
				  << " is " << point.getX() << " " << point.getY() << " " << point.getZ() << std::endl;
	}

	// The second container
	std::vector<std::shared_ptr<Circle>> circles;

	// Find all the circles and store them in the second container
	for (int i = 0; i < parametricCurves.size(); i++)
	{
		if (typeid(*parametricCurves[i]) == typeid(Circle))
			circles.push_back(std::dynamic_pointer_cast<Circle>(parametricCurves[i]));
	}

	// sorting the second container
	std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle> &a, const std::shared_ptr<Circle> &b){
		return a->getRadius() < b->getRadius();
	});

	// Computing the sum of circles' radii and printing data
	double circlesRadiiSum = 0;

	std::cout << "Radii in the ascending order:" << std::endl;

	for (int i = 0; i < circles.size(); i++)
	{
		circlesRadiiSum += circles[i]->getRadius();
		std::cout << "Radius of the circle at " << &(*circles[i]) << " is " << circles[i]->getRadius() << std::endl;
	}

	std::cout << "Total sum of the circles' radii: " << circlesRadiiSum << std::endl;

	return 0;
}
