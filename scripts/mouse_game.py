# A game of mouse script

from mouse_player import Player, Game
import random
import time

target = 20
num_play = 10**12

turns = [0]*num_play
#turns_n = []
#turns_count = []
player1 = Player(1)
game1 = Game(target)
random.seed()
startT = time.time()
for i in range(num_play):
	
	game1.play(player1)
	turns[i] = player1.turns
	"""
	if(player1.turns in turns_n):
		turns_count[turns_n.index(player1.turns)] += 1
	else:
		turns_n.append(player1.turns)
		turns_count.append(1)
	"""

	if(i%10000 == 0):
		endT = time.time()
		print("Loop %d, time: %f seconds" % (i,endT-startT))
		print("Player earned %d points in %d turns!" % (player1.points, player1.turns))
	player1.reset()
	game1.reset()

endT = time.time()
print("It took %f seconds" % (endT-startT))
print("Expected number of turns is %f" % float(sum(turns)/num_play))
"""
expN = 0
for i in range(len(turns_n)):
	expN += turns_count[i]*turns_n[i]
expN = expN/num_play

print("Expected number of turns is %f" % expN)
"""
