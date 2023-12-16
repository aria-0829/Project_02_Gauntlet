#pragma once
#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_

#include "EngineCore.h"

class Vector2D
{
public:
	float x = 0;
	float y = 0;

	Vector2D();
	Vector2D(float x, float y);
	Vector2D& Add(const Vector2D& vec)
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	Vector2D& Multiply(const Vector2D& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;

		return *this;
	}
	void Normalize();

	friend Vector2D& operator+(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(const Vector2D& v1, const Vector2D& v2);

	friend Vector2D& operator+=(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-=(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*=(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/=(const Vector2D& v1, const Vector2D& v2);

	Vector2D& operator*(const float& i);
};

#endif // !_VECTOR_2D_H_

