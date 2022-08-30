#include "Entity.hpp"

Entity::Entity()
{

}

Entity::~Entity()
{

}

//Functions
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{

}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(sprite);
}