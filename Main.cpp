//
// Created by vito on 28/03/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ArrayDraw.h"
#include "Sorters/SorterBubbleSort.h"
#include "Sorters/SorterQuickSort.h"


/*
void testSorter() {
    std::vector<int> arr(20);

    for(int i = 0; i < arr.size(); i++) {
        arr[i] = (int) arr.size() - i;
    }

    for(int i : arr) {
        std::cout <<i<<"-";
    }

    std::cout<<"\n";

    Sorter *sorter = new SorterQuickSort();
    sorter->sort(arr);

    for(int i : arr) {
        std::cout <<i<<"-";
    }
}
void testStatusBst() {
    auto* head = new StatusBst(1, 10);
    head->addRight(new StatusBst(2, 9));
    head->addLeft(new StatusBst(3, 8));
    head->getLeft()->addRight(new StatusBst(4, 7));
    head->getLeft()->addLeft(new StatusBst(5, 6));
    head->getLeft()->getRight()->addRight(new StatusBst(6, 5));
    head->getLeft()->getRight()->addLeft(new StatusBst(7, 4));
    StatusBst* x = head->search(2, 9);
    if(x) std::cout<<x->getStart()<<"-"<<x->getEnd();
    else std::cout<<"not found";
}
*/
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorter",
                       sf::Style::Close);

    SorterQuickSort quickSort;
    SorterBubbleSort bubbleSort;
    Sorter *sort = &quickSort;
    ArrayDraw drawer(window, 800, 580, 0, 700, sort);
    sf::Font font;
    if(!font.loadFromFile(R"(C:\Windows\Fonts\arial.ttf)")) return -1;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    std::string stringComparisons("Comparisons: ");

    window.setFramerateLimit(0);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        text.setString(stringComparisons + std::to_string(sort->status.getComparisons()));
        window.draw(text);
        drawer.drawSort();

        window.display();
    }

    return 0;
}