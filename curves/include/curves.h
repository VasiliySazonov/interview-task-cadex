#pragma once

class Vector3D
{
private:
	double mX, mY, mZ;

public:
	Vector3D();
	Vector3D(double value);
	Vector3D(double x, double y, double z);

	Vector3D(const Vector3D &other);
	
	Vector3D &operator=(const Vector3D &other);

	inline double getX() const { return mX; }
	inline double getY() const { return mY; }
	inline double getZ() const { return mZ; }

	inline void setX(double x) { mX = x; }
	inline void setY(double y) { mY = y; }
	inline void setZ(double z) { mZ = z; }
};

class ParametricCurve
{
public:
	virtual Vector3D pointFromAngle(double angle) const { return Vector3D(0); }
};

class Circle : public ParametricCurve
{
private:
	double mRadius;

public:
	Circle(double radius);

	Vector3D pointFromAngle(double angle) const override;

	inline double getRadius() const { return mRadius; }
};

class Ellipse : public ParametricCurve
{
private:
	double mRadiusX;
	double mRadiusY;

public:
	Ellipse(double radiusX, double radiusY);

	Vector3D pointFromAngle(double angle) const override;

	inline double getRadiusX() const { return mRadiusX; }
	inline double getRadiusY() const { return mRadiusY; }
};

class Helix : public ParametricCurve
{
private:
	double mRadius;
	double mStep;

public:
	Helix(double radius, double step);

	Vector3D pointFromAngle(double angle) const override;

	inline double getRadius() const { return mRadius; }
	inline double getStep() const { return mStep; }
};
