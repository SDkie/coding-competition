/*
Mancala is a family of board games played around the world, which are also called “count-and-capture” games. In this challenge you will code a bot to play Mancala against other bots in the hackathon.

An illustration of the mancala board is given below.

Game Rules

The goal is to collect more marbles (in your mancala) than your opponent does.

The Mancala ‘board’ is made up of 2 rows of 6 holes each.
4 marbles are placed in each of the 12 holes. The color of the marble is irrelevant.
Each player has an empty ‘mancala’ to the right side of the Mancala board.
The game begins with one player picking up all of the marbles in any one of the non-empty holes on his side.
Moving counter-clockwise, the player deposits one of the marbles in each hole he runs into until the marbles run out.
If you run into your own mancala, deposit one marble in it. If you run into your opponent’s mancala, skip it.
If the last marble you drop is in your own mancala, you get a free turn. If the last marble you drop is in an empty hole on your side, you empty all marbles on the hole directly opposite to your hole and put it in your hole.
The game ends when all the 6 holes on one side of the Mancala board are empty.
The Player who still has marbles on his side of the board when the game ends captures all of those marbles and places it in his mancala.
Count all the marbles in each mancala. The winner is the Player with the most marbles.


As shown in illustration 2, Player B has moved the one marble from his hole B2 into the empty hole B3. He will now take that marble and the marbles in A4 and place all those marbles in B3. His turn will then end and the next player goes.

Input Format

The 1st line contains the Player id 1 or 2 indicating Player A and Player B respectively. 
The 2nd line contains the Mancala count for Player1. 
The 3rd line contains 6 single spaced integers each indicating the number of marbles in the 1st Player’s hole from left to right w.r.t player1.
The 4th line contains the Mancala count for player2. 
The 5th line contains 6 single spaced integers each indicating the number of marbles in the 2nd player’s hole from left to right w.r.t Player2.

Output Format

Each turn, output the number (1-6) of the hole you wish to empty.

Sample Input/Output:

Input for Player1:

1
0
4 4 4 4 4 4
0
4 4 4 4 4 4
Player1 output:

5
Input for Player2:

2
1
4 4 4 4 0 5
0
5 5 4 4 4 4
Explanation:

Player1 emptied the 5th hole, which put marbles on his side and mancala and Player2’s side. Player2 then recieves the current game state and makes a move:

Player2 output:

6
This would then be the input for Player1’s next move:

1
1
5 5 5 4 0 5
1
5 5 4 4 4 0
Task

Complete the function printNextMove which takes in 5 parameters as input

An integer player_id 1 or 2: player
An integer mancala of Player1: player1Mancala
A vector array of integers of marbles in holes of Player1: player1Marbles
An integer mancala of Player2: player2Mancala
A vector array of integers of marbles in holes of Player2: player2Marbles
and prints an integer of the hole you wish to empty.

Scoring

This is a competitive 2 player game. Please refer scoring on how bots are scored and how opponents are picked.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef struct state 
{
	int value;
	int mymancala;
	int mymarbles[6];
	int omancala;
	int omarbles[6];
	struct state* move[6];
}state;
int bestmove(state* root,int depth);
/* Head ends here */
//player1Marbles and player2Marbles are of size 6.

void printNextMove(int player, int player1Mancala, int* player1Marbles, int player2Mancala, int* player2Marbles) {
state root;
int depth=9;
if(player==1)
{
	root.mymancala=player1Mancala;
	memcpy(root.mymarbles,player1Marbles,sizeof(root.mymarbles));
	root.omancala=player2Mancala;
	memcpy(root.omarbles,player2Marbles,sizeof(root.omarbles));
}
else
{
	root.mymancala=player2Mancala;
	memcpy(root.mymarbles,player2Marbles,sizeof(root.mymarbles));
	root.omancala=player1Mancala;
	memcpy(root.omarbles,player1Marbles,sizeof(root.omarbles));
}
 root.value=(root.mymancala-root.omancala);
 printf("%d",bestmove(&root,depth)+1);
}

int bestmove(state* root,int depth)
{
	int i,bestchild=0;
	int ptr;
	if(depth==0)
	{
		root->value=root->mymancala - root->omancala;
		return root->value;
	}	

	for(i=0;i<6;i++)//copied state
	{
		root->move[i]=(state*)malloc(sizeof(state));
		root->move[i]->mymancala=root->mymancala;
		root->move[i]->omancala=root->omancala;
		memcpy(root->move[i]->mymarbles,root->mymarbles,sizeof(root->mymarbles));	
		memcpy(root->move[i]->omarbles,root->omarbles,sizeof(root->mymarbles));
	}
	if(depth%2==0)//my turn
	{
		for(i=0;i<6;i++)
		{
				ptr=i;
			while(root->move[i]->mymarbles[i])
			{
				root->move[i]->mymarbles[i]--;	
				ptr++;
				if(ptr==6)
					root->move[i]->mymancala++;
				else if(ptr<6)
					root->move[i]->mymarbles[ptr]++;
				else
					root->move[i]->omarbles[ptr%6]++;
			}
			root->move[i]->value=root->move[i]->mymancala - root->move[i]->omancala;
		}
		for(i=0;i<6;i++)
		{
			if(root->mymarbles[i]!=0)
			{
				bestchild=i;
				break;
			}
		}
		for(i=0;i<6;i++)
		{
			bestmove(root->move[i],depth-1);
			if(root->move[bestchild]->value  < root->move[i]->value && root->mymarbles[i]!=0)
				bestchild=i;
		}

	}
	else // other terns
	{
		for(i=0;i<6;i++)
		{
				ptr=i;
			while(root->move[i]->omarbles[i])
			{
				root->move[i]->omarbles[i]--;	
				ptr++;
				if(ptr==6)
					root->move[i]->omancala++;
				else if(ptr<6)
					root->move[i]->omarbles[ptr]++;
				else
					root->move[i]->mymarbles[ptr%6]++;
			}
			root->move[i]->value=root->move[i]->mymancala - root->move[i]->omancala;
		}
		for(i=0;i<6;i++)
		{
			if(root->mymarbles[i]!=0)
			{
				bestchild=i;
				break;
			}
		}

		for(i=0;i<6;i++)
		{
			bestmove(root->move[i],depth-1);
			if(root->move[bestchild]->value > root->move[i]->value && root->mymarbles[i]!=0)
				bestchild=i;
		}
	}

	for(i=0;i<6;i++)//copied state
	{
		free(root->move[i]);
	}
	root->value+=root->move[bestchild]->value;
	return(bestchild);
}



/* Tail starts here */
int main() {
    int _player;
    scanf("%d", &_player);
    
    int _player1Mancala;
    scanf("%d", &_player1Mancala);
    
    int _player1Marbles_size=6, _player1Marbles_i;
    int _player1Marbles[_player1Marbles_size];
    for(_player1Marbles_i = 0; _player1Marbles_i < _player1Marbles_size; _player1Marbles_i++) { 
        int _player1Marbles_item;
        scanf("%d", &_player1Marbles_item);
        _player1Marbles[_player1Marbles_i] = _player1Marbles_item;
    }
    
    int _player2Mancala;
    scanf("%d", &_player2Mancala);
    
    int _player2Marbles_size=6, _player2Marbles_i;
    int _player2Marbles[_player2Marbles_size];
    for(_player2Marbles_i = 0; _player2Marbles_i < _player2Marbles_size; _player2Marbles_i++) { 
        int _player2Marbles_item;
        scanf("%d", &_player2Marbles_item);
        _player2Marbles[_player2Marbles_i] = _player2Marbles_item;
    }
    
    printNextMove(_player, _player1Mancala, _player1Marbles, _player2Mancala, _player2Marbles);
    
    return 0;
}
