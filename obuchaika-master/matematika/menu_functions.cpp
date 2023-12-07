#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

static const char space = ' ';
static const char plus = '+';
static const char minus = '-';
static const char multi = '*';
static const char devide = '/';
static const int ESC = -1;

const ITrofimov::MenuItem* ITrofimov::show_menu(const MenuItem* current) {  //не трогать никогда
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const ITrofimov::MenuItem* ITrofimov::exit(const MenuItem* current) {
    std::exit(0);
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::study_summ(const MenuItem* current) {
    // TODO
    while (1) {
        const int a = rand() % 10, b = rand() % 10;
        const int real_ans = a + b;
        int get_ans;
        do {
            std::cout << "Для выхода тыкни -1" << std::endl;
            std::cout << "Реши этот пример: " << a << space << plus << space << b << " = ";
            std::cin >> get_ans;
            if (get_ans == ESC) return current->parent;
            if (get_ans != real_ans) std::cout << "Хммм попробуй еше раз\n";
        } while (get_ans != real_ans);
        std::cout << "Ты прав! " << std::endl;
        continue;
    }
}

const ITrofimov::MenuItem* ITrofimov::study_substract(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::study_multiply(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::study_divide(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

