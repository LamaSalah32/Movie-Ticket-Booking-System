#include <iostream> 
#include <string> 
using namespace std;
class ticket { 
      private :
            string Name; 
            string time;
            string day;
            float price; 
      public:
            void set_name (string n){ 
                  Name = n ;
            }

            string get_name(){ 
                  return Name;
            }

            void set_time (string t){ 
                  time = t;
            }

            string get_time(){ 
                  return time ;
            }

            void set_price (float p){ 
                  price = p;
            }

            float get_price (){ 
                  return price;
            }

            void set_day (string d){ 
                  day = d;
            }

            string get_day(){ 
                  return day ;
            }
};


int allOccupied (char arr[7][5]){
      int count=0;
      for(int i = 0; i < 7; i++){
            for(int j = 1; j < 5; j++)
                  if(arr[i][j] == 'X')
                        count++;
      }

      if(count==28)
            return 1;

      return 0;
}

void display(char arr[7][5]){
	
      for(int i = 0; i < 7; i++){
			cout << "			" << arr[i][0] << " - ";
            for(int j =1; j < 5; j++){
                  cout << " " << arr[i][j];
                  if(j != 4) cout << " |";
            }

            cout <<"\n";
      }
      cout << "\n";

      return;
}


string getData (){
      string p;
      cout << " Enter valid seat number to check like :1B, 2C OR N to end : ";
      cin >> p;   
      cout << "\n";

      return p;
}

void update(char arr[7][5],int row,int col){
      cout<<" congrats, your seat is valid. Reserved for you\n";
      cout<<" updated seat status...\n";
      arr[row][col]='X';
      
}

//checking whether user request for his sit no can be processed or not
int check(char arr[7][5], string s){ //if user input is not in the range 1A to 7D
      if( s[0] > '7'|| s[0] < '1' || s[1] > 'D' || s[1] < 'A'){
            cout << " invalid seat number\n"; 
            return 0;
      }

      //find the row number of the user sit
      int row = -1, col = -1; 
      for(int i = 0; i < 7; i++){
            if(arr[i][0] == s[0])  row = i;
      }

      //find the column number of user sit
      for(int j = 0; j < 5; j++){
            if(arr[row][j] == s[1])  col = j;
      }

      //check whether sit is already occupied or not.
      if(col == -1){
            cout << " Seat is already occupied\n";
            return 0;
      }
      else { //if it's a valid sit & not occupied, process the requested & update the sit as occupied
            system("clear");
			cout << "\n";
            update(arr,row,col);
      }

      return 1;
}


void airline(char arr[7][5]){ // user can stop process by pressing 'N'
      string s;
      while(true){
            s = getData(); 
            if(s[0] =='N')  break;

            if(check(arr,s))  display(arr);
            if(allOccupied(arr)){ 
                  cout<<" sorry, no more seats left! :(\n";
                  break; 
            }
      }

		system("clear");
		cout << "\n Thank you for dealing with us, have a nice time ;)\n";
}

int main(){ 
      ticket Fmovie; //initialize object from class "ticket"
      Fmovie.set_name ("Your name"); 
      Fmovie.set_time ("05:00"); 
      Fmovie.set_day("3/11/2020"); 
      Fmovie.set_price(20);

      ticket Smovie; 
      Smovie.set_name("Weathering with you"); //using the function set_name from the class
      Smovie.set_time ("08:30");
      Smovie.set_day("25/11/2020");
      Smovie.set_price(25); 

      cout << "\n Welcome to the world of makoto Shinkai. \n Which movie do you want to watch?\n\n";
      cout <<  " | 1 |  " << Fmovie.get_name() << ".\n | 2 |  " << Smovie.get_name() << ".\n | 3 |  End.  \n\n Enter your choice : "; 

      int x;   cin >> x; 

      for (int i = 1; ;i++){ 
      if (x == 1){ 
			system("clear");
            cout << "\n Great choice ;) \n This movie will be shown at \n\n ---------------------------------------------\n" ;
            
            cout << " |      date       |    time     |   price   |\n ---------------------------------------------\n";
            cout << " |    " << Fmovie.get_day() << "    |    " << Fmovie.get_time() <<"    |    " << Fmovie.get_price() << "$    |\n ---------------------------------------------\n\n" ;
            
            cout << " Is that okay with you ? (Y/N): " ;

            char z;  cin >> z;
            
            while(z != 'Y' && z != 'N'){
				cout << "\n Please enter the correct choice: " ;
				cin >> z;
			}

            if (z == 'Y'){
				system("clear");
                cout << "\n Great, these are the available seats\n Choose your seat:\n\n";
			}
			
            else{
				system("clear");
                cout << "\n Oh sorry, I hope to see you again.\n Good bye.";
                return 0;
            }
            

            char arr[7][5];
            for(int i = 0; i < 7; i++){ 
                  arr[i][0] = i+1+'0';
                  for(int j = 1; j < 5; j++) 
                        arr[i][j]='A'+j-1;
            }

            display(arr);
            airline(arr);
            break;
      }
      else if (x == 2){
			system("clear");
            cout << "\n Great choice ;) \n This movie will be shown at \n\n  --------------------------------------------\n" ;
            
            cout << " |      date        |    time     |   price   |\n  --------------------------------------------\n";
            cout << " |    " << Smovie.get_day() << "    |    " << Smovie.get_time() <<"    |    " << Smovie.get_price() << "$    |\n  --------------------------------------------\n\n" ;
            
            cout << " Is that okay with you ? (Y/N): " ;
            
            char z;  cin >> z;
            
			while(z != 'Y' && z != 'N'){
				cout << "\n Please enter the correct choice: " ;
				cin >> z;
			}

            if (z == 'Y'){
				system("clear");
                cout << "\n Great, these are the available seats\n Choose your seat:\n\n";
			}
			
            else{
				system("clear");
                cout << "\n Oh sorry, I hope to see you again.\n Good bye.";
                return 0;
            }

            char arr[7][5];
            for(int i=0 ;i<7 ; i++){ 
                  arr[i][0]=i+1+'0';
                  for(int j=1;j<5;j++) //to represent sit number A,B,C,D respectively
                        arr[i][j]='A'+j-1;
            }

            display(arr);
            airline(arr); 
            break;
		}

		else if (x == 3){
			system("clear");
			cout << "\n Good bye...";
            return 0;
		}
		else {
            cout << "\n Please enter the correct choice : ";
            cin >> x;
            }
      }


return 0; 
}
