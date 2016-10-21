#pragma once

#include <LinkedList.h>

class Scene
{
public:
	LinkedList* objects;
	Scene();
	~Scene();
	LinkedList* AddObject();
	void RemoveObject();
};
