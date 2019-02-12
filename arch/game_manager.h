#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H


#include <vector>
class Game;

class Game_Manager{
	public:
		Game_Manager();
		void set_game(Game* game);
		void toDo();

	private:
		std::vector<Game*> m_current_game;
};

#endif //GAME_MANAGER_H
