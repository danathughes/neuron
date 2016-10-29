#pragma once

#include <Subsystem.h>
#include <LLNode.h>
#include <Triangle.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class SceneManager : public Subsystem
{
public:
	SceneManager();
	~SceneManager();
	void StartUp(MessageBus* mb);
	void ShutDown();
	void AddObject(LLNode<Triangle>* object);
	void RemoveObject(LLNode<Triangle>* object);
	void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data);
	void CheckObjects();

	LLNode<Triangle>* scene;
};
