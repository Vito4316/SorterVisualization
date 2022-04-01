//
// Created by vito on 30/03/2022.
//

#include <iostream>
#include "ArrayDraw.h"
#include <ctime>

ArrayDraw::ArrayDraw(sf::RenderWindow &w, float l, float h, float sp, int arrlen, Sorter *s) {
    height = h;
    length = l;
    startingPoint = sp;
    window = &w;
    array = std::vector<int>(arrlen);
    sorter = s;
    srand(time(nullptr));
    std::map<int, int> hash;
    for(int i = 0; i < array.size(); i++) {
        int random = rand() % array.size()-1;
        std::_Rb_tree_iterator<std::pair<const int, int>> x = hash.find(random);
        while(x != hash.end()) {
            random = rand() % array.size()-1;
            x = hash.find(random);
        }
        hash.insert(std::pair<int,int>(random,i));
        array[i] = random;
    }

}

void ArrayDraw::draw(std::vector<int> &array) {
    float space = length/(float)array.size();
    if(space <= 0) return; //error: space is not even a line
    //its lenght is space and height is to be resized later, momentarily set to height
    sf::Vector2f size(space, height);
    sf::RectangleShape rect(size);
    rect.setFillColor(sf::Color::White);
    //comparison vector
    std::vector<int> comp(sorter->status.lastCompared());
    //position is startingPoint and max window height minus our drawing space height
    for(float i = 0; i < array.size(); i+=1) {
        //resizing rectangle height, proportionate to how big it is in confront to 100
        size.y = ( height * (((float)array[(int)i]/(float)array.size())));
        rect.setSize(size);
        //recalculate position
        rect.setPosition(startingPoint + space*i, (float) window->getSize().y - size.y);
        //check if has been compared
        for(int c : comp) {
            if((int) i == c)
                rect.setFillColor(sf::Color::Green);
        }
        window->draw(rect);
        rect.setFillColor(sf::Color::White);
    }
}

void ArrayDraw::drawSort() {
    std::vector<int> x(array);
    sorter->sort(x);
    draw(x);
    if(!sorter->status.getMotion()) {
        array = std::vector<int>(x);
    }
}
