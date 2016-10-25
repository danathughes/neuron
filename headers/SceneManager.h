#pragma once

#include <Subsystem.h>
#include <LLNode.h>
#include <Triangle.h>

class SceneManager : public Subsystem
{
public:
	SceneManager();
	~SceneManager();
	void StartUp();
	void ShutDown();
	void AddObject(LLNode<Triangle>* object);
	void RemoveObject(LLNode<Triangle>* object);
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
private:
	LLNode<Triangle>* scene;
};
