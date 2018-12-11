#pragma once
#include "GameState.h"
#include <stack>

using namespace std;

class GameStateMachine {

private:
	stack<GameState*> pila;
public:
	GameState* currentState() {
		return pila.top();
	}

	void pushState(GameState* state) {
		pila.push(state);
	}

	void changeState() {

	}

	void popState() {
		pila.pop();
	}

};