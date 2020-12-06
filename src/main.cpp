#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main(int argv, char** argc) {
    int x, y, width, height;
    std::string user;
    std::cout << "Type User: \n";
    std::cin >> user;
    if(user == "Szymon") {
        x = -1280;
        y = 0;
        width = 3200;
        height = 1080;
    } else {
        std::cout << "Type Informations: \n";
        std::cin >> x;
        std::cin >> y;
        std::cin >> width;
        std::cin >> height;
    }

    sf::RenderWindow window(sf::VideoMode(width, height), "ColorX", sf::Style::None);
    window.setVisible(true);
    window.setPosition(sf::Vector2i(x, y));
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    float r = 0.0f, g = 0.0f, b = 0.0f;
    sf::Color backgroundColor = sf::Color(r, g, b, 0.0f);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) { window.close(); }
            if(event.key.code == sf::Keyboard::Escape) { window.close(); }
        }
        window.clear(backgroundColor);

        if(r < 255.0f) {
            r = r + 1.0f;
        } else if(g < 255.0f) {
            g = g + 1.0f;
        } else if(b < 255.0f) {
            b = b + 1.0f;
        } else {
            r = 0.0f;
            g = 0.0f;
            b = 0.0f;
        }
        backgroundColor = sf::Color(r, g, b, 0.0f);

        window.display();
    }

    return 0;
}