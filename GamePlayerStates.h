#pragma once
#include "State.h"
class GamePlayer;

class ChasePuck : public State {

public:

	ChasePuck() = default;

	static ChasePuck* instance();

	virtual void enter(GamePlayer*); ///TODO: should there be word virtual void?
	virtual void execute(GamePlayer*);
	virtual void exit(GamePlayer*);
};

class Idle : public State {

public:

	Idle() = default;

	static Idle* instance();

	virtual void enter(GamePlayer*);
	virtual void execute(GamePlayer*);
	virtual void exit(GamePlayer*);
};

class DrivePuckUpfield : public State {

public:

	DrivePuckUpfield() = default;

	static DrivePuckUpfield* instance();

	virtual void enter(GamePlayer*);
	virtual void execute(GamePlayer*);
	virtual void exit(GamePlayer*);
};