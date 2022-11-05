#include "instruction.h"

Instruction::Instruction(sf::RenderWindow *window_, std::string textInstruction, std::string link_):mouse(window_)
{
    nextGame = 0;

    window = window_;
    link = link_;

    if(link_ == "")
    {
        text.emplace_back(createText(textInstruction, *fonts[Fonts::Id::arial], 28, sf::Color::White, 400, 200));

        buttons.emplace_back(170, 350, 460, 100, L"Rozpocznij grę", fonts[Fonts::Id::arial], 35,
                &Instruction::goNext, window);
    }
    else
    {
        text.emplace_back(createText("Gratulacje!!!", *fonts[Fonts::Id::arial], 32, sf::Color::White, 400, 160));
        text.emplace_back(createText(textInstruction, *fonts[Fonts::Id::arial], 28, sf::Color::White, 400, 200));

        buttons.emplace_back(170, 350, 220, 70, L"Następna gra", fonts[Fonts::Id::arial], 18,
                &Instruction::goNext, window);
        buttons.emplace_back(410, 350, 220, 70, L"Dowiedz się więcej", fonts[Fonts::Id::arial], 18,
                &Instruction::readMore, window);
    }

    gameLoop();
}

Instruction::~Instruction()
{
    ;
}

int Instruction::gameLoop()
{
    window->setFramerateLimit(100);

    sf::Clock clock;
    while (window->isOpen())
    {
        eventsMouseAndWindow();

        drawing();

        if(nextGame)
        {
            return 1;
        }

    }
    return 0;
}

sf::Text Instruction::createText(std::string text, const sf::Font &font, unsigned int characterSize, sf::Color color, int x, int y)
{
    sf::Text text_(text, font, characterSize);
    text_.setPosition(x, y);
    text_.setFillColor(color);
    text_.setOrigin(text_.getLocalBounds().width/2, text_.getLocalBounds().height/2);

    return text_;
}

void Instruction::eventsMouseAndWindow()
{
    mouse.thisFrameType = MouseAndCursor::Arrow;
    mouse.clicked_left = 0;
    mouse.clicked_right = 0;
    sf::Vector2i mousePosition = mouse.getPosition(*window);

    sf::Event event;
    while (window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window->close();
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                mouse.clicked_left = 1;

            }
            if(event.mouseButton.button == sf::Mouse::Right)
            {
                mouse.clicked_right = 1;
            }
        }
    }

    for(unsigned int i=0; i<buttons.size(); i++)
    {
        if(buttons[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            mouse.thisFrameType = MouseAndCursor::Hand;
            if(mouse.clicked_left)
            {
                if(buttons[i].getFunction() != nullptr)
                {
                    (this->*buttons[i].getFunction())();
                }
            }

        }
    }
    mouse.setCursor();
}

void Instruction::drawing()
{
    window->clear(sf::Color::Black);

    for(const auto &object: gameObjects)
    {
        object->drawing();
    }

    for(unsigned int i = 0; i<buttons.size(); i++)
    {
        buttons[i].drawing();
    }

    for(const auto &object: text)
    {
        window->draw(object);
    }

    window->display();
}

void Instruction::goNext()
{
    nextGame = 1;
}

void Instruction::readMore()
{
    system(("start " + link).c_str());
}
