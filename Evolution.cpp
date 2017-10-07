#include "Evolution.h"



Evolution::Evolution(int pokemon, string event) : Pokemon_(pokemon), Event_(event)
{
}


Evolution::~Evolution()
{
}

int Evolution::getPokemonId() const {
	return Pokemon_;
}

string Evolution::getEvolvingEvent() const {
	return Event_;
}

void Evolution::setPokemonId(int pokemon) {
	Pokemon_ = pokemon;
}

void Evolution::setEvent(string event) {
	Event_ = event;
}
