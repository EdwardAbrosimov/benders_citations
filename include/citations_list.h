#ifndef CITATIONS_LIST_H
#define CITATIONS_LIST_H

#include <map>            // Контейнер для создания словаря

//#define RUSSIAN
#ifdef RUSSIAN
std::map <std::string, int> citations_list = {
  {"Как и многие жизненные проблемы, эту можно решить сгибанием",0},
  {"Привет, начинки для гробов!",1},
  {"Я люблю вас, мешки с мясом!",2},
  {"Слава роботам! Убить всех человеков!",3},
  {"Все, я богат! Пока, неудачники! Я вас всегда ненавидел!",4},
  {"А ну, конечно, если все вокруг сгибается, то виноват робот, созданный для сгибания!",5},
  {"Не забывайте про правила хорошего тона. Вилки в левый карман, ложки — в правый!",6},
  {"Позеры! Я ненавидел Зойдберга еще до того, как это стало модным",7},
  {"Я не так знаменит, чтобы давить людей безнаказанно",8},
  {"Эпоха жестокостей предыдущего фараона миновала навсегда!.. Началась эпоха моих жестокостей!",9},
  {"Он съел пищу, которую я приготовил, и по случайному совпадению его желудок разорвало…",10},
};
#endif
#ifndef RUSSIAN
std::map <std::string, int> citations_list = {
  {"Like many life problems, this can be solved by bending",0},
  {"Hello, fillings for coffins!",1},
  {"I love you, bags of meat!",2},
  {"Glory to the robots! Kill all the people!",3},
  {"Everything, I'm rich! For now, losers! I've always hated you!",4},
  {"Well, of course, if everything around is bent, then the robot created for bending is to blame!",5},
  {"Do not forget the rules of good taste. Forks in the left pocket, spoons in the right!",6},
  {"Ruffians! I hated Zoidberg even before it became fashionable",7},
  {"I'm not so famous as to press people with impunity",8},
  {"The era of cruelties of the previous pharaoh passed forever! The era of my atrocities began!",9},
  {"He ate the food I had prepared, and by coincidence his stomach broke ...",10},
};
#endif
#endif // CITATIONS_LIST_H
