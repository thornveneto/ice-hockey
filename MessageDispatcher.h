#pragma once
#include "Telegram.h"
#include <deque>
#include "EntityManager.h"
class MessageDispatcher {
private:
	//std::deque<Telegram> message_queue; //TODO: for now, we send them immediately
	EntityManager* entity_manager;
public:
	MessageDispatcher(EntityManager* entity_manager) : entity_manager(entity_manager) {}

	void dispatch(Telegram message) {
		GameEntity* receiver = entity_manager->get_entity(message.receiver);

		if (receiver) {
			receiver->handle_message(message);
		}
	}
};