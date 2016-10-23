#pragma once

#include <LLNode.h>
#include <Triangle.h>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void StartUp();
	void ShutDown();
	void AddObject(LLNode<Triangle>* object);
	void RemoveObject(LLNode<Triangle>* object);
private:
	LLNode<Triangle>* scene;
};
