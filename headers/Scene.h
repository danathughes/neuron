#pragma once

#include <LLNode.h>

class Scene
{
public:
	LLNode* objects;
	Scene();
	~Scene();
	LLNode* AddObject();
	void RemoveObject();
};
