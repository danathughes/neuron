#include <iostream>

#include <Subsystem.h>
#include <SceneManager.h>
#include <LLNode.h>
#include <Triangle.h>
#include <Messages.h>
#include <MessageBus.h>


SceneManager::SceneManager() {

}

SceneManager::~SceneManager() {

}

void SceneManager::StartUp(MessageBus* mb) {
	this->msgBus = mb;

	// TODO: Refactor this to use WAD files; this will require writing the FileManager system, and will unblock writing a Shader class
	GibVect3* vert1 = new GibVect3(-0.1f, -0.1f, 0.0f); // Bottom Left
	GibVect3* vert2 = new GibVect3(-0.1f, 0.1f, 0.0f);  // Top Left
	GibVect3* vert3 = new GibVect3(0.1f, 0.1f, 0.0f);	// Top Right
	Triangle* sceneObj = new Triangle(vert1, vert2, vert3);
	this->scene = new LLNode<Triangle>(sceneObj, nullptr);
	//delete(vert1);
	//delete(vert2);
	//delete(vert3);
	//delete(sceneObj);

	// Tell the renderer to draw the first frame of the scene
	// FIXME: Can't do this before the MB starts up!
	//this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
}

void SceneManager::ShutDown() {

}

void SceneManager::AddObject(LLNode<Triangle>* object) {

}

void SceneManager::RemoveObject(LLNode<Triangle>* object) {

}

void SceneManager::CheckObjects() {
	LLNode<Triangle>* object = this->scene;
	while (object != nullptr){
		if (object->data->dirty == true){
			this->msgBus->PostMessage(MESSAGE_TYPE::READY, SYSTEM_TYPE::RENDERER, nullptr);
			break;
		}
	}
}

void SceneManager::HandleMessage(const enum MESSAGE_TYPE msg, const void* const data) {
	if (data != nullptr) {
		std::cout << "SceneManager: I received a " << msg << " message! It contains data: " << *(int*)data << "\n";
	}
	else {
		std::cout << "SceneManager: I received a message! The data was a null pointer. \n";
	}
	GibVect3* distance; // TODO: Refactor - distance should only apply to Move() related messages
	switch (msg) {
		case MOVE_UP:
			distance = new GibVect3(0.0, 0.1, 0);
			this->scene->data->Move(distance);
			delete(distance);
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case MOVE_DOWN:
			distance = new GibVect3(0.0, -0.1, 0);
			this->scene->data->Move(distance);
			delete(distance);
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case MOVE_LEFT:
			distance = new GibVect3(-0.1, 0.0, 0);
			this->scene->data->Move(distance);
			delete(distance);
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case MOVE_RIGHT:
			distance = new GibVect3(0.1, 0.0, 0);
			this->scene->data->Move(distance);
			delete(distance);
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case READY:
			// Now initialize the scene
			this->msgBus->PostMessage(MESSAGE_TYPE::INITIALIZE_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		default:
			break;
	}

}
