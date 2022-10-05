#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<string.h>
#include<ctime> // to get time 
using namespace std;



void wishme();//function to wish user a time
void datetime();




void wishme(){
	
	time_t now = time(0);
	tm *time = localtime(&now);
	
	if (time->tm_hour <12){
		cout<<"Good Morning" << endl;
		
	}
	else if(time-> tm_hour > 12 && time->tm_hour <=16){
		cout<<"Good Afternoon" << endl;
	}
	else if(time->tm_hour > 16 && time->tm_hour < 24){
		cout<<"Good Evening"<<endl;
	}
	else{
		cout<<"Good Night"<<endl;
	}
}





void datetime(){
	time_t now = time(0);
	char *dt = ctime(&now);
	cout<<"The date and time is "<<endl << dt << endl;
	
}





int main(){
	
	system("cls");
	
	cout<<"\t\t---------------Welcome-----------------------"<<endl;
	cout<<"\t\t---------------I'M Jarvis!!!-----------------"<<endl;
	cout<<"\t\t---------------Your virtual Assitant!!-------"<<endl;
	char password[20]; // to take password
	char ch[100]; // to take command
	
	
	
	do{
		cout<<"***********************"<<endl;
		cout<< "|Enter your Password|"<<endl;
		cout<<"***********************"<<endl;
		
		
		string phrase = "enter your password";
    	string command = "espeak \"" + phrase + "\"";
    	const char *charCommand = command.c_str();
    	system(charCommand);
		
		
		gets(password);
		
		if (strcmp(password , "jarvis") == 0){
			cout<<"Correct password"<<endl;
			wishme();
			
			STARTUPINFO startInfo = {0};
			PROCESS_INFORMATION processInfo= {0}; 
			
			do{
			
			cout<<endl<<"***********************"<<endl;
			cout<<endl<<"How can I help you....???"<<endl<<endl;
			
			string phrase = "how can i help you";
    		string command = "espeak \"" + phrase + "\"";
    		const char *charCommand = command.c_str();
    		system(charCommand);
			
			
			cout<<"Enter your query===>";
			gets(ch);
			cout<<endl<<"Here are the results===>"<<endl;
			
			
			if(strcmp(ch , "hii") == 0 || strcmp(ch , "hey") == 0) {
				cout<<"Hello Boss!!!....";
			}
			else if(strcmp(ch , "quit" )== 0 || strcmp(ch , "exit") == 0 ){
				cout<<"Okay Boss GoodBye...."<<endl;
				exit(0);
			}
			else if(strcmp(ch , "open notepad" )== 0  ){
				cout<<"Opening Notepad.."<<endl;
				CreateProcess(TEXT("C:\\Program Files\\WindowsApps\\Microsoft.WindowsNotepad_11.2207.11.0_x64__8wekyb3d8bbwe\\Notepad\\Notepad.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&startInfo , &processInfo);
			}
			else if(strcmp(ch , "date" )== 0 || strcmp(ch , "time" )== 0 ){
				datetime();
			}
			else if(strcmp(ch , "open google" )== 0  ){
				system("start https://www.google.com");
				
			}
			else if(strcmp(ch , "open youtube" )== 0  ){
				system("start https://www.youtube.com");
				
			}
			else{
				cout<<endl<<"Results not Found...Try Another query...:("<<endl;
			}
		    }while(1);
		}
		
		
		
		else{
			cout<<"Incorrect password"<<endl;
		}
	}while(1);
	return 0;
}
