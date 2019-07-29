#include<iostream>
#include<stdlib.h>
using namespace std;
char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player ='X';
 int n=0;
void draw(){
    cout<<"\t\tTic-Tac-Toe\n"<<endl;
for(int i=0;i<3;i++){

    for(int j=0;j<3;j++){
        if(j!=2){
            cout<<"\t"<<matrix[i][j]<<"\t|";
        }
        else {
            cout<<"\t"<<matrix[i][j];
        }
    }
    if(i!=2)
    cout<<"\n\t___________________________________\n";
}
}

void togglePlayer(){
if(player=='X'){
    player='O';
}
else
    player='X';
}


void change(){
    char value;
    int invalid = 0;
cout<<"\nPlayer "<<player<<" turn :";
cin>>value;
for(int i=0;i<3;i++){

    for(int j=0;j<3;j++){
        if(matrix[i][j]==value){
                matrix[i][j]=player;
                invalid++;
        }
    }
}

if(invalid==0){
    cout<<"invalid input";
    change();
}
}

char Win()
{
    //first player
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';

    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';

    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';

    //second player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';

    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';

    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';

    return '/';
}
void reset(){
    char a='1';
for(int i =0;i<3;i++){
    for(int j=0;j<3;j++){
        matrix[i][j]=a;
        a++;
    }
}
player = 'O';
n=0;
}
int main(){
    int restart;
    while(1){
            n++;
        system("CLS");
        draw();
        change();

        if (Win() == 'X')
        {
            cout << "X wins!......."<< endl;
            cout<<"You want to play again?? (1/2):";
            cin>>restart;
            if(restart==1){
               reset();
            }
            else{
                break;
            }
        }
        else if (Win() == 'O')
        {
            cout << "O wins!" << endl;
           cout<<"You want to play again?? (1/2):";
            cin>>restart;
            if(restart==1){
              reset();
            }
            else{
                break;
            }
        }
        else if (Win() == '/' && n == 9)
        {
            cout << "It's a draw!" << endl;
            cout<<"You want to play again?? (1/2):";
            cin>>restart;
            if(restart==1){
                reset();
            }
            else{
                break;
            }
        }
        togglePlayer();
    }

return 0;
}
