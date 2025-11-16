#pragma once
#include "State.h"
#include <typeinfo> //TODO: improve

class StateMachine {
private:
	GamePlayer* owner;
	State* current_state;
	State* previous_state;
	State* global_state;

public:
	StateMachine(GamePlayer* owner) : 
		owner(owner), 
		current_state(nullptr),
		previous_state(nullptr),
		global_state(nullptr)
	{}

	virtual ~StateMachine() {};

	void set_current_state(State* state) { current_state = state; }
	void set_global_state(State* state) { global_state = state; }
	void set_previous_state(State* state) { previous_state = state; }

	void update() {
		if(global_state) global_state->execute(owner);

		if (current_state) current_state->execute(owner);
	}

	void change_state(State* new_state) {
		// check not null
		previous_state = current_state;
		current_state->exit(owner);
		current_state = new_state;

		current_state->enter(owner);
	}

	void revert_state() {
		change_state(previous_state);
	}

	//bool is_in_state(const State& state) const {
	//	return typeid(*current_state) == typeid(state);
	//}
	template<typename T>
	bool is_in_state() const {
		return current_state && typeid(*current_state) == typeid(T);
	}

	State* get_current_state() const { return current_state;  }
	State* get_global_state() const { return global_state; }
	State* get_previous_state() const { return previous_state; }
};

