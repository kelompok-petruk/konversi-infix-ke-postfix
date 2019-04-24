// KELOMPOK        <<"""""DEAR""""">>

//                 1. Desta Feranita      1517051002
//                 2. Nia Nur Atika       1817051015
//                 3. Eka Intan Sari      1817051022
//                 4. Rena Okriyani       1817051029

// link github : https://github.com/kelompok-petruk/konversi-infix-ke-postfix/blob/master/Evaluate%20an%20Expression



#include<iostream>
#include<stdio.h>
#include<stdlib.h>               // untuk eluar ()
#include<ctype.h>               // untuk isdigit (char)
#include<string.h>
#define SIZE 100
// dinyatakan sebagai variabel global karena tumpukan [] digunakan lebih dari satu fungsi 
using namespace std;

char stack [SIZE];
int top = -1;
//tentukan operasi push
void push(char item) {
        if (top >= SIZE-1){
            cout<<"\nStack Overflow.";
        }
        else{
            top =top+1;
            stack[top] =item;
    }
}
//tentukan operasi pop
char pop(){
        char item;
        if (top <0){
                cout<<"stack under flow: ekspresi infiks tidak valid";
                getchar ();
                //under flow dapat terjadi untuk ekspresi tidak valid dimana (dan) tidak cocok
                exit(1);
        }
        else{
            item =stack[top];
            top = top-1;
            return(item);
        }
}
//define fungsi yang digunakan untuk menentukan apakah simbol adalah operator atau tidak (Yaitu simbol operan)
//Fungsi ini mengembalikan 1 jika simbol adalah operator yang lain mengembalikan 0
int is_operator (char symbol){
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'){
          return 1;
     }
     else{
     return 0;
   }
 }
// mendefinisikan fungsi yang digunakan untuk menetapkan prioritas kepada operator.
// Di sini ' menunjukkan operator eksponen.
// Dalam fungsi ini kita mengasumsikan nilai integer yang lebih tinggi Berarti prioritas lebih tinggi
int precedence(char symbol){
    if(symbol == '^'){ // operator eksponen, diutamkan tertinggi
            return(3);
    }
    else if(symbol == '*' || symbol == '/'){
            return(2);
    }
    else if(symbol == '+' || symbol == '-'){ // diutamakan terendah
            return(1);
    }
    else{
            return(0);
    }
}
void InfixToPostfix(char infix_exp[], char postfix_exp[]){
int i, j;
char item;
char x;

push ('(');                             // dorong '(' ke tumpukan
strcat (infix_exp,")");                  // tambahkan ')' ke infix ekspresi

i=0;
j=0;
item = infix_exp[i];                    // menginisialisasi sebelum loop

while(item != '\0'){                   // jalankan loop sampai akhir ekspresi infix
        if (item == '('){
                push (item);
               }
               else if (isdigit(item) || isalpha(item)){
                        postfix_exp[j] = item;                  //tambahkan simbol operan ke expr postfix
                        j++;
               }
               else if (is_operator(item) == 1 ){       // berarti simbol adalah operator
                        x = pop ();
                        while (is_operator(x) == 1 && precedence(x) >= precedence(item)){
                                postfix_exp[j] = x ;
                                j++;
                                x = pop();
                        }
                        push (x);
                        
                        push (item);            // dorong simbol operator saat ini ke tumpukan
                 }
                 else if (item == ')'){         // jika simbol sat ini adalah ')' maka pop dan terus muncul sampai '(' bertemu
                 x = pop() ;
                 	while(x != '('){               
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else{ // jika simbol saat ini bukan operan bukan '(' nor ')' dan juga tidak operator itu adalah simbol ilegal 
			cout<<"\nInvalid infix Expression.\n";        
			getchar();
			exit(1);
		}
		i++;
		item = infix_exp[i]; // pergi ke simbol berikutnya dari ekspresi infiks 
 				// sementara loop berakhir di sini
}
	if(top>0){
		cout<<"\nInvalid infix Expression.\n";        // itu adalah simbol ilegal 
		getchar();
		exit(1);
	}
	if(top>0){
		cout<<"\nInvalid infix Expression.\n";       // itu adalah simbol ilegal 
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0';// tambahkan sentinel else menempatkan () fungsi akan mencetak seluruh postfix [] array hingga SIZE
}
// fungsi utama dimulai 
int main(){
	char infix[SIZE], postfix[SIZE];       // mendeklarasikan string infiks dan string postfix 

	cout<<"\nMasukkan ekspresi Infix: ";
	gets(infix);
	InfixToPostfix(infix,postfix);               // panggilan untuk mengonversi 
	cout << "Ekspresi Postfix:";
	puts(postfix);                     // cetak ekspresi postfix 
	return 0;
}
                 
                        
                        
               
