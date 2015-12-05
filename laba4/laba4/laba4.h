#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

//������ "���������� �������" ���10

//������
typedef enum AMPLUA_E {
	GOALKEEPER = 0,
	DEFENDER = 1,
	FORWARD = 2
} amplua_e;

//����� ����� �����
class CPlayer
{
public:
	int create_player();
	void print_player_info();
	virtual void print_player_goal_info() {}
	string get_name() { return name; } //���
	time_t get_play_time() { return play_time; }
	time_t get_penalty_time() { return penalty_time; }
	virtual amplua_e get_amplua() = 0;
protected:
	string name; //���
	time_t play_time; //����� � ����
	time_t penalty_time; //��������
};

//�������
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

//��������
class CDefender : public CPlayer
{
public:
	amplua_e get_amplua() { return DEFENDER; }
private:
	
};

//����������
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


//����
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
	string competitor; // ������������ ���������
	vector <CPlayer> g_players; // ������ ����� ������� � ������ ����
	struct tm time;	// ���� ����
};


//�������
class CTeam
{
public:
	int add_player();
	string get_team_name() { return team_name; }
	string get_coach_name() { return coach_name; }
	void print_games(); // ����� ����������� ������� ���
	int del_game(struct tm time); // �������� ���� �� ����
	CGame* find_game(struct tm time); // ����� ���� �� ���� (NULL - �� �����)
	void add_game(CGame* game); // ���������� ����
	
private:
	string team_name; //�������� �������
	string coach_name; //��� �������

	vector <CPlayer> players; // ������ ������� � �������
	vector <CGame> games; // ������ ���
};

//������ ������ ���������
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
