#include "paddle.h"

Paddle::Paddle(float x, float y, float width, float height)
    : m_shape()
    , m_color(255, 255, 255)
    , m_size(width, height)
    , m_position { x, y }
    , m_velocity(0)
    , m_acceleration(0)
{
    m_shape.setPosition(x, y);
    m_shape.setSize(m_size);
    m_shape.setFillColor(m_color);
}

const sf::RectangleShape& Paddle::getShape()
{
    return m_shape;
}


void Paddle::accelerate(bool direction) {
    // Don't exceed maximum acceleration
    if (direction == UP && m_acceleration < MAX_ACCEL) {
        m_acceleration = -MAX_ACCEL;
    }
    else if (m_acceleration > -MAX_ACCEL) {
        m_acceleration = MAX_ACCEL;
    }
}

void Paddle::decelerate() {
    m_acceleration /= 4;
    if (m_velocity > 0) {
        --m_velocity;
    }
    else if (m_velocity < 0) {
        ++m_velocity;
    }
}

void Paddle::advance() {
    // Don't exceed maximum velocity
    if (abs(m_velocity) < MAX_VELOCITY) {
        m_velocity += m_acceleration;
    }
    if (m_position.y + m_velocity + m_size.y <= FRAME_SIZE_Y
        && m_position.y + m_velocity >= 0) {
        m_position.y += m_velocity;
    }
    updatePosition();
}