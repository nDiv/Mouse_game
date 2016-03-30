#include <iostream>
#include <stdio.h>
#include <math.h>
#include <random>

class Player{
		int points; // Accumulative points per game
		int turns;  // Accumulative turns per game
		int player_type;   // Type of player: 0 - never banks, 
								// 1 - banks after half the objetive, 
								// 2 - banks at random after half the objetive, and
								// else - banks at random.
	public:
		Player(int);
		//int roll_die(void);
		void AddPoints(int);
		int GetPoints(void);
		void IncrementTurns(void);
		int GetTurns(void);
		bool strategy(int); //Return True to bank and False otherwise.
		void reset(void);
		void stats(void);
};

class Game{
		int Max_points; //Points to play for
		bool game_on;   
		int die_min;
		int die_max;
		//std::uniform_int_distribution<int> uni;
		//std::mt19937 rng;

	public:
		Game(int,int,int);
		//void play(std::mt19937, Player*);
		void play(Player*);
		void reset(void);
};
