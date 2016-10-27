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

	// Tell the renderer to draw the first frame of the scene
	this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene)
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
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		}
	}
}

void SceneManager::HandleMessage(enum MESSAGE_TYPE msg, void* data) {
	std::cout << "SceneManager: I received a message! It contains data: " << *(int*)data << "\n";
	switch (msg) {
		case MOVE_UP:
			GibVect3* distance = new GibVect3(0.0, 1.0, 0);
			this->scene->Move();
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case MOVE_DOWN:
			GibVect3* distance = new GibVect3(0.0, -1.0, 0);
			this->scene->Move();
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case MOVE_LEFT:
			GibVect3* distance = new GibVect3(-1.0, 0.0, 0);
			this->scene->Move();
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		case MOVE_RIGHT:
			GibVect3* distance = new GibVect3(1.0, 0.0, 0);
			this->scene->Move();
			this->msgBus->PostMessage(MESSAGE_TYPE::REBUFFER_DATA, SYSTEM_TYPE::RENDERER, this->scene);
			break;
		default:
			break;
	}

}
