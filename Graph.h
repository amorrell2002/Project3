#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>
#include "County.h"

using namespace std;
using namespace  sf;

class Graph {
    //window
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

public:
    Graph();
    void draw(vector<County*> &counties, string demographicSelection, string foodAccessSelection);
    void run(vector<County*>& counties, string demographicSelection, string foodAccessSelection);
    void close();
};


