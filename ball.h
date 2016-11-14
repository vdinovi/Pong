#ifndef BALL_H
#define BALL_H

#include "util.h"

class Ball {
public:
    Ball(float radius);
    
    static void randomInit(sf::Vector2f* pos, sf::Vector2f* vel);
        
    const sf::CircleShape& getShape();
    
    const sf::Vector2f& getPosition() { return m_position; }
    
    void advance();
    
    void reset();
    
    const sf::Color m_color;
    const float m_radius;
    
private:
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;

    sf::CircleShape m_shape;

    friend class Board;
};


#endif