#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const ITrofimov::MenuItem ITrofimov::ALGEBRA_SUMM = {
    "1 - Хочу научиться складывать!", ITrofimov::study_summ, &ITrofimov::STUDY_ALGEBRA
};
const ITrofimov::MenuItem ITrofimov::ALGEBRA_SUBSTRACT = {
    "2 - Хочу научиться вычитать!", ITrofimov::study_substract, &ITrofimov::STUDY_ALGEBRA
};
const ITrofimov::MenuItem ITrofimov::ALGEBRA_MULTIPLY = {
    "3 - Хочу научиться умножать!", ITrofimov::study_multiply, &ITrofimov::STUDY_ALGEBRA
};
const ITrofimov::MenuItem ITrofimov::ALGEBRA_DIVIDE = {
    "4 - Хочу научиться делить!", ITrofimov::study_divide, &ITrofimov::STUDY_ALGEBRA
};
const ITrofimov::MenuItem ITrofimov::ALGEBRA_GO_BACK = {
        "0 - Выйти в главное меню", ITrofimov::go_back, &ITrofimov::STUDY_ALGEBRA
};

namespace {
    const ITrofimov::MenuItem* const algebra_children[] = {
        &ITrofimov::ALGEBRA_GO_BACK,
        &ITrofimov::ALGEBRA_SUMM,
        &ITrofimov::ALGEBRA_SUBSTRACT,
        &ITrofimov::ALGEBRA_MULTIPLY,
        &ITrofimov::ALGEBRA_DIVIDE
    };
    const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
}

const ITrofimov::MenuItem ITrofimov::STUDY_ALGEBRA = {
        "1 - Хочу учиться алгебре!", ITrofimov::show_menu, &ITrofimov::STUDY, algebra_children, algebra_size
};
const ITrofimov::MenuItem ITrofimov::STUDY_MATHEMATICAL_ANALYSIS = {
        "2 - Хочу учиться математическому анализу!", ITrofimov::show_menu, &ITrofimov::STUDY, nullptr, NULL
};
const ITrofimov::MenuItem ITrofimov::STUDY_GO_BACK = {
        "0 - Я передумал, пойду полежу", go_back, &ITrofimov::STUDY
};

namespace {
    const ITrofimov::MenuItem* const study_children[] = {
            &ITrofimov::STUDY_GO_BACK,
            &ITrofimov::STUDY_ALGEBRA,
            &ITrofimov::STUDY_MATHEMATICAL_ANALYSIS
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const ITrofimov::MenuItem ITrofimov::STUDY = {
    "1 - Хочу учиться математике!", ITrofimov::show_menu, &ITrofimov::MAIN, study_children, study_size
};
const ITrofimov::MenuItem ITrofimov::EXIT = {
    "0 - Я лучше пойду полежу...", ITrofimov::exit, &ITrofimov::MAIN
};

namespace {
    const ITrofimov::MenuItem* const main_children[] = {
        &ITrofimov::EXIT,
        &ITrofimov::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ITrofimov::MenuItem ITrofimov::MAIN = {
    nullptr, ITrofimov::show_menu, nullptr, main_children, main_size
};
