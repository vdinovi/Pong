#ifndef PADDLE_H
#define PADDLE_H

#include "util.h"

#define UP true
#define DOWN false

class Paddle {
public:
    Paddle(float x, float y, float width, float height);
    
    const sf::RectangleShape& getShape();
    
    void advance();
    
    void updatePosition() { m_shape.setPosition(m_position.x, m_position.y); }
    
    void accelerate(bool direction);
    
    void decelerate();
    
    int getAcceleration() { return m_acceleration; }

    int getVelocity() { return m_velocity; }

    const sf::Vector2f& getPosition() { return m_position; }

    bool m_keyPressed;
    
private:
    const sf::Color m_color;
    sf::Vector2f m_position;
    int m_velocity;
    int m_acceleration;
    sf::Vector2f m_size;
    
    sf::RectangleShape m_shape;
    
    friend class Board;
};

#endif