#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

//работа "спортивная команда" вар10

//амплуа
typedef enum AMPLUA_E {
	GOALKEEPER = 0,
	DEFENDER = 1,
	FORWARD = 2
} amplua_e;

//абстр класс игрок
class CPlayer
{
public:
	int create_player();
	void print_player_info();
	virtual void print_player_goal_info() {}
	string get_name() { return name; } //ФИО
	time_t get_play_time() { return play_time; }
	time_t get_penalty_time() { return penalty_time; }
	virtual amplua_e get_amplua() = 0;
protected:
	string name; //ФИО
	time_t play_time; //время в игре
	time_t penalty_time; //штрафное
};

//вратарь
class CGoalkeeper: public CPlayer
{
public:
	unsigned int get_attempts() { return attempts; }
	unsigned int get_goals() { return goals; }
	amplua_e get_amplua() { return GOALKEEPER; }
	void print_player_goal_info();
private:
	unsigned int goals;
	unsigned int attempts;
};

//защитник
class CDefender : public CPlayer
{
public:
	amplua_e get_amplua() { return DEFENDER; }
private:
	
};

//нападающий
class CForward : public CPlayer
{
public:
	amplua_e get_amplua() { return FORWARD; }
	unsigned int get_attempts() { return attempts; }
	unsigned int get_goals() { return goals; }
	void print_player_goal_info();
private:
	unsigned int goals;
	unsigned int attempts;
};


//игра
class CGame
{
public:

	void add_player(CPlayer* player);
	int del_player(CPlayer* player);
	string get_competitor() { return competitor; }
	//CPlayer* get_players() { return players; }
	struct tm get_time() { return time; }
	void print_game_info();
private:
	string competitor; // наименование соперника
	vector <CPlayer> g_players; // список наших игроков в данной игре
	struct tm time;	// дата игры
};


//команда
class CTeam
{
public:
	int add_player();
	string get_team_name() { return team_name; }
	string get_coach_name() { return coach_name; }
	void print_games(); // показ содержимого таблицы игр
	int del_game(struct tm time); // удаление игры по дате
	CGame* find_game(struct tm time); // поиск игры по дате (NULL - не нашли)
	void add_game(CGame* game); // добавление игры
	
private:
	string team_name; //название команды
	string coach_name; //имя тренера

	vector <CPlayer> players; // список игроков в команде
	vector <CGame> games; // список игр
};

//шаблон класса итератора
template<class T>
class Iterator_my {

private:
	T* current;
public:
	Iterator_my(T* curr) :current(curr)
	{
	}
	Iterator_my& operator =(const Iterator_my& other)
	{
		if (this != &other)
		{
			current = other.current;
		}
		return *this;
	}
	Iterator_my& operator ++()
	{
		++current;
		return *this;
	}
	T operator *()
	{
		return *current;
	}
	T* operator ->()
	{
		return current;
	}
};

typedef Iterator_my <CGame> CGameVector;
typedef Iterator_my <CPlayer> CPlayerVector;
