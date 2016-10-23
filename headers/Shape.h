#pragma once

class Shape
{
public:
	Shape();
	virtual ~Shape() = 0;
  virtual void Move() = 0;
};
