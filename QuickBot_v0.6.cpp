#include <iostream>  
#include <ctime>
#include <windows.h>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

class QuickBot{
/*---------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                     Public	
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/

    public:
    	
/*---------------------------------------------------------------------------------------------------------------------------------------------------------                                                                                                    
	                                                                Constructor
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
      //Comienza el constructor
      QuickBot(){

      //Sistema de color:
      system("color 08");
    
      //Funcion de pass
      password();
    
      //  >>Variables<<
      string nombre;
      char comando;
    
      //Guia de Quick:
    
      cout<<"Hello user! My name is QuickBot, I hope you have a nice day\n";
    
      cout<<"I am here to help you, please enter [i]\n"<<endl;
    
      cin>>comando;
     //condicional para iniciar el codigo:
    
     if (comando == 'i') {
      while(true){
        
        cout<<"\tChoose any option:\n"<<endl;
        //Lista de comandos:
        
        char ListaDeComandos[] = {
    
        " <1> Show current time\n"
        "<2> Solution a basic math operation\n"
        " <3> Password generator\n"
        "<4> Get character's ascii value\n"
        " <5> Math game\n"
        "<6> Exit\n"
         };
         
         cout<<ListaDeComandos<<endl;
         int num;
         cin>>num;
         //switch de comandos:
         
         switch(num){
         case 1:
        //Hora actual:
            opcion_1();
        break;
          case 2:
              //Operaciones matematicas    
            math();
          break;
          case 3:
              //Password generator
           opcion_3();    
           break;
           case 4:
               //Character converter
            opcion_4();
               break;
            case 5:
               //Juego
            game(5, 20);
            	break;
            case 6:
            	//Exit
            exit(1);
            	break;
          default:
          cout<<"Please enter a valid option.\n\n"<<ListaDeComandos<<endl;
          break;             
 }
        
        cout<<endl<<endl;
  }
    
   }
      }

 /*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                            User verification
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/  
  void password(){
	string pass;
	cout<<"Please type your p4ssw0rd..."<<endl;
	do{
		cin>>pass;
		cout<<"\n"<<endl;
		if(!(pass=="p4ssw0rd")){
			MessageBox(NULL,"Wrong password!\n Please try again","Acces denied",MB_OK);
		}            
	}
	while(!(pass=="p4ssw0rd"));
	
} 
            
 /*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                               Basic calculator
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
      

void math(){
    cout<<"Enter your operation: ";
    char op; float n1; float n2; float result;
    cin>>n1;
    cin>>op;
    cin>>n2;
    switch(op)
    {
        case '+':
    result = n1 + n2;
    break;
    
    case '-':
        result = n1 - n2;
        break;
        
        case '*':
        case 'x':
            result = n1 * n2;
        break;
        case '/':
        	result = n1 / n2;
        case '^':
        result = pow(n1, n2);
    break;        
	};
	cout<<"Your result is: "<<result;
}
      
 /*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                  	 Ascii value converter
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
      
void opcion_4(){     //Caracters ascii value
    char ch;
    cout<<"Enter the ascii character to get value: ";
    cin>>ch;
    cout<<"The ascii value of: ["<< ch <<"] is: "<< int(ch);
    
}
      
/*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                         Password generator
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
      
void opcion_3(){   //Password generator
                      
	srand(time(0));
	
	string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "0123456789" "@&$?#%!~";
	
	int u, cha, c;
	cha = chars.length();
	cout<<"Enter the number of characters: ";
	cin>>u;
	cout<<"\n Your password is:\n";
	while(c < u){
	    
	    cout<<chars[rand() % cha];
	    c++;
	}
}
     
/*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                            Current time
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
     
void opcion_1(){
    
    cout<<"The current time is:\n"<<endl;
  time_t current_time;
    struct tm * time_info;
   char timeString[9];
    time(&current_time);
   time_info = localtime(&current_time);
    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
   puts(timeString);
   
}
    
 /*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                                Game
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
int game(unsigned int attempts = 0, unsigned int range = 0){
	unsigned int score = 0;
	cout<<"Welcome to math games!\n";
	time_t start = time(NULL);
	int result;
	int ans;
	int c = 0;
	while(c<attempts){
		
		srand(time(0));
		string lst = "+-*/";
		int chars = lst.length();
		char rdchar = lst[rand() % chars];
		int rdnum1 = rand() % range;
		int rdnum2 = rand() % range;
		cout<<rdnum1<<rdchar<<rdnum2<<": ";
		switch(rdchar){
		case '+':
		 result = rdnum1 + rdnum2;
		break;
		case '-':
		 result = rdnum1 - rdnum2;
		break;
		case '*':
		
		 result = rdnum1 * rdnum2;
		break;
		case '/':
		
		 result = rdnum1 / rdnum2;
		};
		cin>>ans;
		if(sizeof(ans) != 4){
			system("cls");
			return 0;
		}
		if(ans == result){
		    cout<<"\nCorrect!, score +1\n\n";
		    score++;
		}
		else{
		    cout<<"\nIncorrect!\n\n";
		}
		    c++;
	}
	time_t end = time(NULL);
	int seconds = end - start;
	cout << "\nYour score is " << score << " of " << attempts << endl;
	cout << "Your time is >_ " << seconds << endl;
	}

};

/*---------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                                  Funcion main
  ----------------------------------------------------------------------------------------------------------------------------------------------------------                                            
*/
int main() {
	QuickBot Mybot;
	
	return 0;
}
