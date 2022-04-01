//
// Created by vito on 30/03/2022.
//

#ifndef GAME_ARRAYDRAW_H
#define GAME_ARRAYDRAW_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Sorters/Sorter.h"
#include <cstdlib>

class ArrayDraw {
private:
    std::vector<int> array;
    float height, length, startingPoint;
    sf::RenderWindow *window;
    Sorter *sorter;

public:
    ArrayDraw(sf::RenderWindow &w, float l, float h, float sp, int arrlen, Sorter *s);
    void draw(std::vector<int> &array);
    void drawSort();

};


#endif //GAME_ARRAYDRAW_H
