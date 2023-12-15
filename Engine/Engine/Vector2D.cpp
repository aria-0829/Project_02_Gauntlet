#include "EngineCore.h"

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(float _x, float _y)
{
	this->x = _x;
	this->y = _y;
}

void Vector2D::Normalize() 
{
    float magnitude = sqrt(x * x + y * y);

    if (magnitude != 0.0f) 
	{
        x /= magnitude;
        y /= magnitude;
    }
}

Vector2D& operator+(const Vector2D& v1, const Vector2D& v2)
{
	Vector2D result(v1.x + v2.x, v1.y + v2.y);

	return result;
}

Vector2D& operator-(const Vector2D& v1, const Vector2D& v2)
{
	Vector2D result(v1.x - v2.x, v1.y - v2.y);

	return result;
}

Vector2D& operator*(const Vector2D& v1, const Vector2D& v2)
{
	Vector2D result(v1.x * v2.x, v1.y * v2.y);

	return result;
}

Vector2D& operator/(const Vector2D& v1, const Vector2D& v2)
{
	Vector2D result(v1.x / v2.x, v1.y / v2.y);

	return result;
}

Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;

	return v1;
}

Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;

	return v1;
}

Vector2D& operator*=(Vector2D& v1, const Vector2D& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;

	return v1;
}

Vector2D& operator/=(Vector2D& v1, const Vector2D& v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;

	return v1;
}

Vector2D& Vector2D::operator*(const float& i)
{
	this->x *= i;
	this->y *= i;

	return *this;
}
