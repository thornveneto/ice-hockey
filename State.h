#pragma once
class GamePlayer;

class State {
public:
	virtual ~State() = default;

	virtual void enter(GamePlayer*) = 0;
	virtual void execute(GamePlayer*) = 0;
	virtual void exit(GamePlayer*) = 0;
};