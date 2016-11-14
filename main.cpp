#include <SFML/Audio.hpp>

#include <string>
#include "board.h"


int main(int, char const**)
{
    // Create the main window in video mode as 800x600
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Pong", sf::Style::Titlebar,
                            sf::ContextSettings::ContextSettings(0,0,0,2,0));
    window.setFramerateLimit(60);
    sf::Font font;
    if (!font.loadFromFile("/Library/Fonts/Arial.ttf")) {
        fprintf(stderr, "Error loading 'Arial.ttf'.");
        return -1;
    }
    
    //Board board(font);
    Board* board = new Board(font);
    bool isRunning = false;
    // Start the game loop
    while (window.isOpen())
    {
        board->m_p1.m_keyPressed = false;
        board->m_p2.m_keyPressed = false;
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            // Start/Stop
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::S) {
                    if (!isRunning) {
                        isRunning = true;
                    }
                    else {
                        isRunning = false;
                        delete board;
                        board = new Board(font);
                    }
                }
            }
            
            // Check for paddle movements & update
            if (isRunning) {
                if (event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::Up) {
                    board->acceleratePlayer(2, UP);
                    board->m_p2.m_keyPressed = true;
                }
                else if (event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::Down) {
                    board->acceleratePlayer(2, DOWN);
                    board->m_p2.m_keyPressed = true;
                }
                
                if (event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::A) {
                    board->acceleratePlayer(1, UP);
                    board->m_p1.m_keyPressed = true;
                }
                else if (event.type == sf::Event::KeyPressed
                         && event.key.code == sf::Keyboard::Z) {
                    board->acceleratePlayer(1, DOWN);
                    board->m_p1.m_keyPressed = true;
                }

            }
        }
        if (!board->m_p1.m_keyPressed) {
            board->deceleratePlayer(1);
        }
        if (!board->m_p2.m_keyPressed) {
            board->deceleratePlayer(2);
        }
        
        // Clear screen
        window.clear();
        
        // Render frame
        if (isRunning) {
            board->advance();
            board->draw(&window);
        }
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
