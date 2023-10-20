#include <curves.h>
#include <math.h>

Vector3D::Vector3D() : mX(0), mY(0), mZ(0)
{}

Vector3D::Vector3D(double value) : mX(value), mY(value), mZ(value)
{}

Vector3D::Vector3D(double x, double y, double z) : mX(x), mY(y), mZ(z)
{}

Vector3D::Vector3D(const Vector3D &other) : mX(other.mX), mY(other.mY), mZ(other.mZ)
{}

Vector3D &Vector3D::operator=(const Vector3D &other)
{
	if (&other == this)
		return *this;

	mX = other.mX;
	mY = other.mY;
	mZ = other.mZ;

	return *this;
}

Circle::Circle(double radius) : mRadius(radius)
{}

Vector3D Circle::pointFromAngle(double angle) const
{
	Vector3D position;

	position.setX(sin(angle) * mRadius);
	position.setY(cos(angle) * mRadius);

	return position;
}

Ellipse::Ellipse(double radiusX, double radiusY) : mRadiusX(radiusX), mRadiusY(radiusY)
{}

Vector3D Ellipse::pointFromAngle(double angle) const
{
	Vector3D position;

	position.setX(sin(angle) * mRadiusX);
	position.setY(cos(angle) * mRadiusY);

	return position;
}

Helix::Helix(double radius, double step) : mRadius(radius), mStep(step)
{}

Vector3D Helix::pointFromAngle(double angle) const
{
	Vector3D position;

	position.setX(sin(angle) * mRadius);
	position.setY(cos(angle) * mRadius);
	position.setZ(angle / (2 * M_PI) * mStep);

	return position;
}
