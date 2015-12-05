#include "laba4.h"
#include <iomanip>

using namespace std;

void CPlayer::print_player_info()
{
	std::cout << "Name: " << get_name() << endl;
	std::cout << "total play time: " << get_play_time() << endl;
	std::cout << "total penalty time: " << get_penalty_time() << endl;
	std::cout << "amplua: " << get_amplua() << endl;
	print_player_goal_info();
}

//добавление игрока в вектор игроков
int CTeam::add_player()
{
	int res = 0;
	cout << " GOALKEEPER = 0" << endl;
	cout << "DEFENDER = 1" << endl;
	cout << "GOALKEEPER = 2" << endl;
	cout << "Write number amplua:" << endl;

	int n_ampl = NULL;
	cin >> n_ampl;
	if (!cin.good())
	{
		cin.clear();
		cout << "error" << endl;
		return -1;
	}
	
	CDefender defender;
	CForward forward;
	if ((amplua_e)n_ampl == GOALKEEPER)
	{
		CGoalkeeper goalkeeper;
		goalkeeper.create_player();
		players.push_back(goalkeeper);
	}
	else if ((amplua_e)n_ampl == DEFENDER)
	{
		CGoalkeeper defender;
		defender.create_player();
		players.push_back(defender);
	}
	else if ((amplua_e)n_ampl == FORWARD)
	{
		CGoalkeeper forward;
		forward.create_player();
		players.push_back(forward);
	}
	else
	{
		cout << "error amplua" << endl;
		return -1;
	}

	return res;
}


// return: < 0 - ошибка, >= 0 - размер введенных данных 
int CPlayer::create_player()
{
	int res = 0;
	string p_name = NULL;
	cout << "Write name: ";
	cin >> p_name;

	if (!cin.good())
	{
		cin.clear();
		cout << "error" << endl;
		return -1;
	}

	return res;
}

void CGoalkeeper::print_player_goal_info()
{
	std::cout << "total goals: " << goals << endl;
	std::cout << "total saves: " << attempts << endl;
}

void CForward::print_player_goal_info()
{
	std::cout << "total goals: " << goals << endl;
	std::cout << "total attempts: " << attempts << endl;
}

void CGame:: print_game_info() 
{
	std::cout << "game time: " << std::put_time(&time, "%c %Z") << endl;
	std::cout << "competitor: " << competitor << endl;
	CPlayer* cur_player = players;
	for (CPlayer* cur_player = players; cur_player != NULL ; cur_player = cur_player->next)
	{
		std::cout << cur_player->get_name() << endl;
	}
}

void CGame::add_player(CPlayer* player) 
{
	g_players.push_back(*player);
}

void CGame::add_player(CPlayer* player)
{
	g_players.push_back(*player);
}

int CGame::del_player(CPlayer* player)
{
	g_players.erase(*player); ///
}

int main{



}