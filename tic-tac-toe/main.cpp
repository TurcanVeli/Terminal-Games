#include <iostream>
using namespace std;

#define BOARD_N 3
#define NEW_LINE "\n"
#define TAB "\t"

const int X = 1, O =-1, EMPTY = 0;
int board[BOARD_N][BOARD_N];
int First_player = 1;
int second_player = -1;

void prepare_boardFor_game(){
    for(int i = 0; i<BOARD_N; i++){
        for (int j = 0; j < BOARD_N; j++){
            board[i][j] == EMPTY;
        }
    }
}

void showUi(){
    cout << TAB << "1" << TAB << "2" << TAB << "3" << NEW_LINE;
    for (int i = 0; i < BOARD_N; i++){
        cout << i+1 << TAB;
        cout<< (board[i][0]==1?"X":board[i][0]==-1?"O":"_")  << TAB << (board[i][1]==1?"X":board[i][1]==-1?"O":"_") << TAB << (board[i][2]==1?"X":board[i][2]==-1?"O":"_") << NEW_LINE;
    }
    cout<< NEW_LINE << NEW_LINE;

}

bool check_game(int player){
    return (((board[0][0] + board[0][1] + board[0][2]) == player*3)
     || ((board[0][0] + board[1][1] + board[2][2])== player*3)
      || ((board[0][0] + board[1][0] + board[2][0])== player*3)
       || ((board[0][1] + board[1][1] + board[2][2])== player*3)
        || ((board[0][2] + board[1][2] + board[2][2])== player*3)
         || ((board[0][2] + board[1][1] + board[0][3])== player*3)
          || ((board[1][0] + board[1][1] + board[1][2])== player*3)
           || ((board[2][0] + board[2][1] + board[2][2])== player*3));

}


void play(int player){
    int x,y; 
    while (true){
        cout<< "işaretini hangi kordinatlara koymak istersiniz" << NEW_LINE;
        cin>>x>>y;
        int item  = board[x-1][y-1];
        if ( item != EMPTY ){
            cout<<"Bu kordinatlar dolu..." << NEW_LINE;
        }else{
            board[x-1][y-1] = player;
            break;
        }  
    }
}

int main()
{
    int x;
    cout << "Tikitaka oyununa hoşgeldin!!" << NEW_LINE;
    cout << "devam etmek için 1 tuşuna basiniz? Cikis yapmak icin 0" << NEW_LINE;
    cin >> x;
    if (x == 0)
    {
        cout << "Cikiliyor...";
        return 0;
    }
    prepare_boardFor_game();
    while (1){    
        showUi();
        play(1);
        showUi();
        if (check_game(1))
        {
            cout << "1. player oyunu kazandi";
            break; 
        }
        play(-1);
        showUi();   
         if (check_game(-1))
        {
            cout << "2. player oyunu kazandi";
            break;
        
        }
        
    }
  
    return 0;
}