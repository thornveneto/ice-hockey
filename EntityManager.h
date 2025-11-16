#pragma once
#include <map>
#include "GameEntity.h"

class EntityManager {
private:
	int next_id{ 1 };
	std::map<int, GameEntity*> entity_register;
public:
	int allocate_id() { return next_id++; }

	void register_entity(GameEntity* game_entity) {
		entity_register.insert({ game_entity->id, game_entity });
	}

	GameEntity* get_entity(int id) {
		return entity_register[id];
	}
};