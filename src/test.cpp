#include "mouse_game.h"
#include <time.h>

using namespace std;

int main(void){

	int target = 50;
	int num_play = pow(10,8);
	//random_device rd;     // only used once to initialise (seed) engine
	//mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	int sum_n = 0;
	
	Player* player1 = new Player(1);
	Game game1 = Game(target,1,4);

	const clock_t begin_time = clock();
	for(int i=0; i<num_play; i++){
		
		game1.play(player1);
		sum_n += player1->GetTurns();

		if(i%10000 == 0){
			printf ("Loop: %d, time(s): %4.3f \n", i, float( clock () - begin_time ) /  CLOCKS_PER_SEC);
			printf ("Running average: %4.5f \n", (float) sum_n/(i+1));
		}
		game1.reset();
		player1->reset();
	}
	
	float end_time = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	printf ("It took %4.3f seconds... \n", end_time);
	printf ("Expected number of turns: %4.5f \n", (float) sum_n/num_play);	

	delete player1;

	return 0;
}
