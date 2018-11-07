#include<bits/stdc++.h>
#include<ctime>
/*
ID: arun.ga1
LANG: C++
TASK:
 */

using namespace std;

#define prime 1000000007
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;

/////////////////////////////////////////////////////////////////////

int board[3][3];

void setupBoard();
void printBoard();
bool checkValidMove(int move);
void updateBoard(int move, int turn);
bool isWinner();

void  updateBoard(int move, int turn)
{
	int row = (move-1)%3;
	int col = (move-1)/3;
	if(turn%2)
		board[row][col] = 0;
	else
		board[row][col] = 10;
}

void setupBoard()
{
	int i,j,cnt=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			board[i][j] = cnt++;
		}
	}
}


void printBoard()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j] <=9 && board[i][j] >=1)
				cout << "-" ;
			else if(board[i][j]==0)
				cout << "X";
			else if(board[i][j]==10)
				cout << "O";
			if(j!=2)
					cout << "|";
		}
		cout << endl;
	}
	cout << endl;
}


bool checkValidMove(int move)
{
	int row = (move-1)%3;
	int col = (move -1)/3;
	if(board[row][col] >=1 && board[row][col]<=9)
		return true;
	return false;
}

bool isWinner()
{
	if(board[0][0]==board[0][1] && board[0][1]==board[0][2])
		return true;
	if(board[1][0]==board[1][1] && board[1][1]==board[1][2])
		return true;
	if(board[2][0]==board[2][1] && board[2][1]==board[2][2])
		return true;
	if(board[0][0]==board[1][0] && board[1][0]==board[2][0])
		return true;
	if(board[0][1]==board[1][1] && board[1][1]==board[2][1])
		return true;
	if(board[0][2]==board[1][2] && board[1][2]==board[2][2])
		return true;
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
		return true;
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(unsigned(time(0)));
	int turn = 1,arr[9],i;

	for(i=0;i<9;i++)
		arr[i] = i+1;
	//random_shuffle(vec.begin(),vec.end());
	// random_shuffle(arr,arr+siz);

	setupBoard();
	printBoard();

	// DEBUG(board[0][2]);

	bool solvedFlag = false;
	int move;

	while(!solvedFlag)
	{
		printBoard();
		if(turn%2)//player move
		{

			// make modular
			cin >> move;
			if(checkValidMove(move))
			{
				updateBoard(move,turn);
				turn++;
				if(isWinner())
				{
					printBoard();
					cout << "Player 1 wins!" << endl;
					return 0;
				}
			}
			else
				cout << "Retry! Invalid Move" << endl;

		}
		else
		{
			random_shuffle(arr,arr+9);
			for(i=0;i<9;i++)
			{
				// make modular
				if(checkValidMove(arr[i]))
				{
					updateBoard(arr[i],turn);
					turn++;
					if(isWinner())
					{
						printBoard();
						cout << "Computer 1 wins!" << endl;
						return 0;
					}
					break;
				}
			}
		}
		if(turn==10)
		{
			cout << "Draw!" << endl;
			return 0;
		}
	}

	return 0;
}
