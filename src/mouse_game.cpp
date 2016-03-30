#include "mouse_game.h"

Player::Player(int type){
	this->player_type = type;
	this->points = 0;
	this->turns = 0;
}

/*
int Player::roll_die(void){
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

	auto random_integer = uni(rng);
}*/

void Player::AddPoints(int pts){
	this->points += pts;
}

int Player::GetPoints(void){
	return this->points;
}

void Player::IncrementTurns(void){
	this->turns++;
}

int Player::GetTurns(void){
	return this->turns;
}

bool Player::strategy(int cur_points){
	
	if(this->player_type == 0){
		return false;
	}else if(this->player_type == 1){
		if(cur_points > 9){
			return true;
		}else{
			return false;
		}
	}else{
		return true; // Banks all the time. Have to implement the random banker.
	}
}

void Player::stats(void){
	std::cout<<"Player type: "<<this->player_type<<std::endl;
	std::cout<<"Player points: "<<this->points<<std::endl;
	std::cout<<"Player turns: "<<this->turns<<std::endl;
}

void Player::reset(void){
	this->points = 0;
	this->turns = 0;
}

Game::Game(int pts, int d_min, int d_max){
	this->Max_points = pts;
	this->die_min = d_min;
	this->die_max = d_max;
	//std::uniform_int_distribution<int> uni_tmp(d_min,d_max);
	//mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	//this->uni = uni_tmp;
	this->game_on = true;
}

void Game::play(Player* player){
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	while(this->game_on){
		int turn_points = 0;
		player->IncrementTurns();
		while(true){
			std::uniform_int_distribution<int> uni(this->die_min,this->die_max);
			auto die_outcome = uni(rng); // Roll the die
			//std::cout<<"die outcome: "<<die_outcome<<std::endl;
			if(die_outcome > 1){
				turn_points += die_outcome;
				if(player->GetPoints() + turn_points >= this->Max_points){
					player->AddPoints(turn_points);
					this->game_on = false;
					//std::cout<<"Player won in "<<player->GetTurns()<<" turns with "<<player->GetPoints()<<" points"<<std::endl;
					break;
				}else if(player->strategy(turn_points)){
					player->AddPoints(turn_points);
					//std::cout<<"Player banked. Eearned "<<turn_points<<" total points"<<std::endl;
					break;
				}else{
					//std::cout<<"Player did not bank. Carried "<<turn_points<<" total points"<<std::endl;
					continue;
				}
			}else{
				//std::cout<<"Turn ended. Player lost all "<<turn_points<<std::endl;
				turn_points = 0;
				break;
			}
		}
	}
}

void Game::reset(void){
	this->game_on = true;
}
