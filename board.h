#ifndef BOARD_H
#define BOARD_H

#include "ball.h"
#include "paddle.h"


class Board {
public:
    Board(sf::Font font);
    
    void draw(sf::RenderWindow* window);
    
    void acceleratePlayer(unsigned playerId, bool direction);
    
    void deceleratePlayer(unsigned playerId);
    
    bool advance();
    
    void reset();
        
    sf::Text getScoreText();
    
    Ball m_ball;
    Paddle m_p1;
    Paddle m_p2;

private:
    bool m_scoreHasChanged;
    sf::Vector2i m_score;
    sf::Font m_font;
};

#endif