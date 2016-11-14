#include "ball.h"

Ball::Ball(float radius)
    : m_shape()
    , m_color(255, 255, 255)
    , m_radius(radius)
{
    randomInit(&m_position, &m_velocity);
    m_shape.setPosition(m_position.x, m_position.y);
    m_shape.setRadius(m_radius);
    m_shape.setFillColor(m_color);
}

void Ball::advance() {
    if (m_position.y >= FRAME_SIZE_Y || m_position.y <= 0)
        m_velocity.y *= -1;
    
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
    
}

const sf::CircleShape& Ball::getShape() {
    m_shape.setPosition(m_position.x, m_position.y);
    return m_shape;
}

void Ball::reset() {
    randomInit(&m_position, &m_velocity);
}

void Ball::randomInit(sf::Vector2f* pos, sf::Vector2f* vel) {
    time_t t;
    srand((unsigned) time(&t));
    vel->x = max((rand() % 10), 4);
    vel->x *= rand() % 2 ? -1 : 1;
    vel->y = 10 - vel->x;
    vel->y *= rand() % 2 ? -1 : 1;

    pos->x = (rand() % 1200);
    pos->x = pos->x > 800 ? 800 : pos->x;
    pos->x = pos->x < 400 ? 400 : pos->x;
    pos->y = (rand() % 800);
    pos->y = pos->y > 500 ? 500 : pos->y;
    pos->y = pos->y < 300 ? 300 : pos->y;


}