//Bernadetha Belva Arjanti 	2257051021
//Farid Shidiq s 			2257051028
//Muhammad Aziz Almuhadi 	2217051108


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ncurses\ncurses.h>

using namespace std;
void setcolor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

void header()
{
	cout << "====================================" << endl;
    cout << "|                                  |" << endl;
    cout << "|   Ayo Bermain Kuis Matematika    |" << endl;
    cout << "|                                  |" << endl;
    cout << "====================================" << endl;
   
}
void loading(){
	initscr();
	
	mvprintw(12, 55, "Loading");
	
	mvprintw(13, 48, "=====================");
	mvprintw(14, 48, "[]                 []");
	mvprintw(15, 48, "=====================");
			
	for(int r = 1; r < 10; r++){	 
		for(int j = 1; j < 5; j++){
			mvprintw(12, 61 + j, ".");
			refresh();
			Sleep(50);    //mendelay layar selama 0,05 detik				   
	    }	
			mvprintw(14, 48 +r + r, "o");
			refresh();
			Sleep(300);		//mendelay layar selama 0,3 detik		 	  
	}
	
	refresh();
	endwin();  
}



void kuis()
{
	header();
    bool done=false;
    while (!done)
       {
       srand(time(NULL)); // Untuk merandom
       int CorrectAnswers=0,AnswersDone=0; 
       while(1)
           {
           if (AnswersDone==10){break;}
           int Answer=0;
           int Num  = rand()%10;  // Menyimpan angka random pertama antara 0 dan 10
           int Num2 = rand()%10;  // Menyimpan angka random pertama antara 0 dan 10
           cout << "Solve the following equalation:\n" << Num << " + " << Num2 << " = ";
           cin >> Answer;
           if (Answer==(Num+Num2))
              {
                setcolor(2);
              cout << endl << "CORRECT! \"" << Num << " + " << Num2 << "\" is infact " << Answer << endl;
              CorrectAnswers++;
                setcolor(7);
              }
           else
              {
                setcolor(4);
              cout << endl << "WRONG ANSWER! The correct answer is \"" << Num << " + " << Num2 << " = " << Num+Num2 << endl;
                setcolor(7);
              }

           AnswersDone++;
           }
       if (CorrectAnswers==10){cout << endl << CorrectAnswers << " out of " << AnswersDone << " that's a perfect score!!" << endl;}
       if (CorrectAnswers>=6 && CorrectAnswers<10){cout << endl << CorrectAnswers << " out of " << AnswersDone << " that's pretty good!" << endl;}
       if (CorrectAnswers>=3 && CorrectAnswers<6){cout << endl << CorrectAnswers << " out of " << AnswersDone << " that's kinda bad!" << endl;}   
       if (CorrectAnswers>=0 && CorrectAnswers<3){cout << endl << CorrectAnswers << " out of " << AnswersDone << " that's sucks!" << endl;}
	   cout<<"Nilai : "<<  CorrectAnswers*10;   
       cout << endl << "Wanna try again? [0=Yes][1=No]" << endl;
       cin >> done;
       cout << endl;
       system("cls");
       }    
    cout << "Thanks for using this program, bye!" << endl;
    system("PAUSE");   // Menunggu input sebelum selesai
    }
    

void menu(){
	//judul();
	
	char siap;
	cout << "\n\t\t\t\t\t\t Apakah Anda Siap Bermain ?\n";
	cout << "\t\t\t\t\t\t          (y/t) ? ";
	cin >> siap;
	
	if( siap=='y'||siap=='Y') kuis();
	else {
		system("cls"); menu();
	} 

}
int main()
{
	loading();
	menu();
	getch();
	return 0;
	
}  

