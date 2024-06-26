//                                  TIC-TAC-TOE GAME

#include<iostream>
using namespace std;

char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board();    //To show board
void get_x_choice();   //Take player 1 choice
void get_o_choice();   //Take player 1 choice
int count_board(char symbol); 
char check_winner();
void player1_vs_player2();

int main(){
    cout<<"====== GAME STARTED ======="<<endl;
    player1_vs_player2();
    return 0;
}

//-------------------------------------------------------------------------------
void player1_vs_player2(){
    string x_player_name,O_player_name;
    cout<<"enter X player name"<<endl;
    cin>>x_player_name;
    cout<<"enter O player name"<<endl;
    cin>>O_player_name;
    while (true){
        system("cls");
        show_board();
        if(count_board('X')==count_board('O')){
            cout<<x_player_name<<"'s Turn"<<endl;
            get_x_choice();
        }
        else{
            cout<<O_player_name<<"'s Turn"<<endl;
            get_o_choice();
        }
        char winner = check_winner();
        if(winner=='X'){
            system("cls");
            show_board();
            cout<<x_player_name<<" won the game"<<endl;
            break;
        }
        else if(winner =='O'){
            system("cls");
            show_board();
            cout<<O_player_name<<" won the game"<<endl;
            break;
        }
        else if(winner=='D'){
            system("cls");
            show_board();
            cout<<"The game is a draw"<<endl;
            break;
        }
    }
}

// -------------Get choice from player 1--------------------------------------
void get_x_choice(){
    while(true){
        cout<<"select position from 1 to 9"<<endl;
        int choice;
        cin>>choice;
        choice--;
        if(choice<0 || choice>8){
            cout<<"please select position from 1 to 9 "<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"please select an empty position"<<endl;
        }
        else{
            board[choice]='X';
            break;
        }
    }
}

//-------------------------get choice from player 2-------------------------
void get_o_choice(){
    while(true){
        cout<<"select position from 1 to 9"<<endl;
        int choice;
        cin>>choice;
        choice--;
        if(choice<0 || choice>8){
            cout<<"please select position from 1 to 9 "<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"please select an empty position"<<endl;
        }
        else{
            board[choice]='O';
            break;
        }
    }
}

//---------------------------------Give total occupied positions--------------------------
int count_board(char symbol){
    int total=0;
    for(int i=0; i<9; i++){
        if(board[i]==symbol){
            total += 1;
        }
    }
    return total;
}

//---------------------------------Check winnner-----------------------------------
char check_winner(){
    //checking winner horizontally
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' '){
        return board[0];
    }
    if(board[3]==board[4] && board[4]==board[5] && board[3]!=' '){
        return board[3];
    }
    if(board[6]==board[7] && board[7]==board[8] && board[6]!=' '){
        return board[6];
    }

    //checking vertically
    if(board[0]==board[3] && board[3]==board[6] && board[0]!=' '){
        return board[0];
    }
    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' '){
        return board[1];
    }
    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' '){
        return board[2];
    }

    //checking diagonally
    if(board[0]==board[4] && board[4]==board[8] && board[0]!=' '){
        return board[0];
    }
    if(board[2]==board[4] && board[4]==board[6] && board[2]!=' '){
        return board[2];
    }

    //check if board is full
    if(count_board('X') + count_board('O') < 9){
        return 'C';
    }
    else{
        return 'D';
    }
}

//----------------------To print Game board-----------------------------
void show_board(){
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"  "<<board[0]<<"   |   "<<board[1]<<"  |   "<<board[2]<<endl;
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"  "<<board[3]<<"   |   "<<board[4]<<"  |   "<<board[5]<<endl;
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"  "<<board[6]<<"   |   "<<board[7]<<"  |   "<<board[8]<<endl;
}
