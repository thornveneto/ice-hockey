#pragma once
struct Telegram {
	int sender;
	int receiver;

	int msg_id; //TODO: redo with union

	Telegram() : sender(-1), receiver(-1), msg_id(-1) {} //TODO: do we need this?

	Telegram(int sender, int receiver, int msg_id) 
		: sender(sender), receiver(receiver), msg_id(msg_id) {

	}
};