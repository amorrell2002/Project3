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
    pointSprite.setScale(sf::Vector2f(0.03f, 0.03f));

    //Make a sprite for the extreme points
    sf::Texture extremePointTexture;
    extremePointTexture.loadFromFile("bluePlotPoint.png");
    sf::Sprite extremePointSprite;
    extremePointSprite.setTexture(extremePointTexture);
    //scale
    extremePointSprite.setScale(sf::Vector2f(0.01f, 0.01f));

    window.clear(Color::Black);
    window.draw(blankGraphSprite);
    //Print dots for counties
    for (int i = 10; i < counties.size() - 1; i++)
    {
        //cout << "demographic value: " << Shell::GetStatistic(counties[i], demographicSelection) << endl;
        //cout << "food access value: " << Shell::GetStatistic(counties[i], foodAccessSelection) << endl;

        float x = 126 + 900 * Shell::GetStatistic(counties[i], demographicSelection) / 100;
        float y = 1040 - (900 * Shell::GetStatistic(counties[i], foodAccessSelection)) / 100;
        
        //cout << "x coordinate: " << x << endl;
       // cout << "y coordinate: " << y << endl;
        if (i >= (counties.size() - 10))
        {
            extremePointSprite.setPosition(sf::Vector2f(x, y));
            window.draw(extremePointSprite);
        }
        else
        {
            pointSprite.setPosition(sf::Vector2f(x, y));
            window.draw(pointSprite);
        }       
    }
    for(int i = 0; i <= 9; i ++)
    {
        float x = 126 + 937 * Shell::GetStatistic(counties[i], demographicSelection) / 100;
        float y = 1040 - (937 * Shell::GetStatistic(counties[i], foodAccessSelection)) / 100;

        extremePointSprite.setPosition(sf::Vector2f(x, y));
        window.draw(extremePointSprite);
    }
    window.display();
}

void Graph::close()
{
    window.close();
}

