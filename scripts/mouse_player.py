# Defining a player class which consits of points and two functions
# for rolling a die and a strategy for the next move.

import random

class Player:
	
	def __init__(self, kind):
		self.points = 0
		self.turns = 0
		self.kind = kind

	def roll_die(self):
		return random.randint(1,4)

	def strategy(self, cur_points):
		
		if(self.kind == 0): # This is the player that never banks.
			bank = False 
		elif(self.kind == 1):
			if(cur_points > 9): # Banks as soon as points in the current turn are greater than some number.
				bank = True 
			else:
				bank = False
		elif(self.kind == 2):
			if(cur_points > 9): # Banks at random as soon as points in the current turn are greater than some number.
				bank = bool(random.randint(0,1)) 
			else:
				bank = False
		else:
			bank = bool(random.randint(0,1)) # This is the player that banks on random
		
		return bank
	
	def reset(self):
		self.points = 0
		self.turns = 0

class Game:
	
	def __init__(self, points):
		self.Max_points = points
		self.game_on = True
	
	def play(self, player):
		#print("Game Started!")
	
		while(self.game_on):

			turn_points = 0
			player.turns += 1
			while(True):
				die_outcome = player.roll_die()
		
				if(die_outcome > 1):
					turn_points += die_outcome
					if(player.points + turn_points >= self.Max_points):
						player.points += turn_points
						self.game_on = False
						#print("Player won in turn %d with %d points!" % (player.turns, turn_points))
						break
					elif(player.strategy(turn_points)):
						player.points += turn_points
						#print("Banked. Kept %d total points!" % turn_points)
						break
					#else:
						#print("Did not bank. Kept %d total points!" % turn_points)
				else:
					#print("Turn ended. Lost all %d points!" % turn_points)
					turn_points = 0
					break

		#print("Gamer over!")
		#print("Player earned %d points in %d turns!" % (player.points, player.turns))

	def reset(self):
		self.game_on = True
