#pragma once
#include "GameObject.h"
#include "Game.h"
#include <list>
using namespace std;

class GameState {

private:
	list<GameObject*> stage;
	Game* game;

public:

	GameState() {}

	void update() {
		for (GameObject* o : stage)
			o->update();
	}
	void render() {
		for (GameObject* o : stage)
			o->render();
	}
	bool handleEvent(SDL_Event e) {
		auto it = stage.begin();
		bool handled = false;
		while (it != stage.end() && !handled) {
			if ((*it)->handleEvents(e))
				handled = true;
			else ++it;
		}
	}

	virtual ~GameState() {
		for (GameObject* o : stage)
			delete o;
	}
};
