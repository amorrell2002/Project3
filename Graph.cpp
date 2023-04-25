#include "Graph.h"
#include "Shell.h"

const sf::Time Graph::TimePerFrame = seconds(1.f / 60.f);

Graph::Graph()
{
    resolution = Vector2f(1181, 1168);
    window.create(VideoMode(resolution.x, resolution.y), "Food Access Graph", Style::Default);
    window.setFramerateLimit(FPS);
}

void Graph::run(vector<County*>& counties, string demographicSelection, string foodAccessSelection)
{
    while (window.isOpen())
    {
        draw(counties, demographicSelection, foodAccessSelection);
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void Graph::draw(vector<County*>& counties, string demographicSelection, string foodAccessSelection)
{
    //Make a sprite for the graph
    sf::Texture blankGraphTexture;
    blankGraphTexture.loadFromFile("blankGraph.png");
    sf::Sprite blankGraphSprite;
    blankGraphSprite.setTexture(blankGraphTexture);

    //Make a sprite for the points
    sf::Texture pointTexture;
    pointTexture.loadFromFile("plotPoint.png");
    sf::Sprite pointSprite;
    pointSprite.setTexture(pointTexture);
    //scale
    pointSprite.setScale(sf::Vector2f(0.05f, 0.05f));

    window.clear(Color::Black);
    window.draw(blankGraphSprite);
    //Print dots for counties
    for (int i = 0; i < counties.size() - 1; i++)
    {
        float x = 1181 - 1181 * Shell::GetStatistic(counties[i], demographicSelection) / 100;
        float y = 1168 - 1168 * Shell::GetStatistic(counties[i], foodAccessSelection) / counties[i]->population2010;
        pointSprite.setPosition(sf::Vector2f(x, y));
        window.draw(pointSprite);
    }
    window.display();
}

void Graph::close()
{
    window.close();
}

