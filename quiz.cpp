#include <iostream>
#include <string>
using namespace std;
int calculate_quiz;
int sum_quiz;
class Quiz{
private:
    string ques;
    string ans1,ans2,ans3;
    int Right_ans;
    int marks;
public:
    void VALUES(string, string, string, string, int, int);
    void ASK();
};
void Quiz::VALUES(string q, string a1, string a2, string a3, int ca, int pa){
    ques=q;
    ans1=a1;
    ans2=a2;
    ans3=a3;
    Right_ans=ca;
    marks=pa;
}
void Quiz::ASK(){
    cout<<endl;
    cout<<ques<<endl;
    cout<<"1. "<<ans1<<endl;
    cout<<"2. "<<ans2<<endl;
    cout<<"3. "<<ans3<<endl;
    cout<<endl;
    cout<<"what is your answer?(in number)"<<endl;
    cin>>calculate_quiz;

    if (calculate_quiz==Right_ans){
        cout<<endl;
        cout<<"correct !"<<endl;
        sum_quiz+=marks;
    }
    else{
        cout<<endl;
        cout<<"wrong!"<<endl;
        cout<<"score=0 out of 10"<<endl;
        cout<<"correct answer is "<<Right_ans<<endl;
    }

}
int Quiz_Game(){

   cout<<"\n\t\t\tQUIZ ZONE"<<endl;

   string name;

   cout<<"enter your name "<<endl;
   cin>>name;
   cout<<endl;

   string respond;
   cout<<"Ready for the quiz"<<name<<"?! yes/no"<<endl;
   cin>>respond;
   if(respond=="yes"){
    cout<<endl;
    cout<<"best of luck"<<endl;
   }
   else{
    cout<<"thank you"<<endl;
    return 0;
   }
   Quiz A,B,C,D,E,F,G,H,I,J;

   A.VALUES("question: What is the longest word in the English language? ","Antidisestablishmentarianism","Hippopotomonstrosesquippedaliophobia","Floccinaucinihilipilification",1,10);
   B.VALUES("question: What is the collective name for a group of unicorns?","A sparkle","A spell","A blessing",3,10);
   C.VALUES("question: what is the meaning of 'Hakuna Matata'?","No worries","Goodnight","Thank you ",1,10);
   D.VALUES("question: Who is credited with inventing the World Wide Web?","Steve Jobs","Tim Berners-Lee","Bill Gates",2,10);
   E.VALUES("question: 'Magnum opus' is a Latin phrase for what in literature?","An author’s best work","A love story","A tragedy ",1,10);
   F.VALUES("question: What was the first fruit to be eaten on the Moon?","Grapes","Apple","peach",3,10);
   G.VALUES("question: In which country was the game of chess invented?","China","Greece","India",3,10);
   H.VALUES("question: How many bones do sharks have in their body?","Zero","52","32",1,10);
   I.VALUES("question: How many humans have walked on the Moon?","13","12","15",2,10);
   J.VALUES("question: A green owl is the mascot for which app?","Duolingo","Spotify","Instagram",1,10);


   A.ASK();
   B.ASK();
   C.ASK();
   D.ASK();
   E.ASK();
   F.ASK();
   G.ASK();
   H.ASK();
   I.ASK();
   J.ASK();

   cout<<"total score="<<sum_quiz<<" out of 100"<<endl;
   return 0; 
}


