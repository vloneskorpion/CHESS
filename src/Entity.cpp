#include "Entity.hpp"

Entity::Entity()
{
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setFillColor(sf::Color::Magenta);
    movementSpeed = 100.0f;
}

Entity::~Entity()
{

}

//Functions

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
    shape.move(dir_x * movementSpeed * dt, dir_y * movementSpeed * dt);
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(shape);
}