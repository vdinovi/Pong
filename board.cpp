#include "board.h"

Board::Board(sf::Font font)
    : m_ball(8)
    , m_p1(2, 400, 12, 100)
    , m_p2(1188, 400, 12, 100)
    , m_scoreHasChanged(false)
    , m_score { 0, 0 }
    , m_font(font)
{
}

void Board::draw(sf::RenderWindow* window)
{
    window->draw(m_ball.getShape());
    window->draw(m_p1.getShape());
    window->draw(m_p2.getShape());
    window->draw(getScoreText());
}

void Board::acceleratePlayer(unsigned playerId, bool direction)
{
    if (playerId == 1) {
        m_p1.accelerate(direction);
    }
    else {
        m_p2.accelerate(direction);
    }
}

void Board::deceleratePlayer(unsigned playerId)
{
    if (playerId == 1) {
        m_p1.decelerate();
    }
    else {
        m_p2.decelerate();
    }

}


bool Board::advance()
{
    sf::Vector2f ballPos = m_ball.getPosition();
    if (m_ball.m_position.x < 10) {
        if (m_ball.m_position.y >= m_p1.m_position.y
            && m_ball.m_position.y <= m_p1.m_position.y + m_p1.m_size.y) {
            m_ball.m_velocity.x *= -1;
            m_ball.m_velocity.y += -0.3 * m_p1.m_velocity;
        }
        else {
            ++m_score.y;
            m_ball.reset();
        }
    }
    else if (m_ball.m_position.x > 1190) {
        if (m_ball.m_position.y >= m_p2.m_position.y
            && m_ball.m_position.y <= m_p2.m_position.y + m_p2.m_size.y) {
            m_ball.m_velocity.x *= -1;
            m_ball.m_velocity.y += -0.3 * m_p2.m_velocity;
        }
        else {
            ++m_score.x;
            m_ball.reset();
        }
    }
    m_p1.advance();
    m_p2.advance();
    m_ball.advance();
}

sf::Text Board::getScoreText()
{
    sf::Text scoreText(std::to_string(m_score.x) + " | " + std::to_string(m_score.y),
                       m_font, 50);
    scoreText.setPosition(550, 25);
    return scoreText;
}