# include <iostream>
using namespace std;
# define size 10
class book
{
    private:
    struct queue
    {
        int queue[size];
        int front,rear;
        /* data */
    }Q;
    public:
    book();
        int books;
        int Qfull();
        int Qempty();
        int insert(int);
        int delet();
        void display();
        void fogg();
        void student();
        char name[20];
        int pass = 12345,passe;
        double id;
        char cls[5];
        void std();
        void fe();
        char feed[200];  
};
void book::student()
{
  cout<<" \n Enter the name ";
  cin>>name;
  cout<<" \n Enter  password ";
  cin>>passe;
  if(passe==pass)
  {
    cout<<" \n password is match to server!!";

  }
  else{
    cout<<" \n Sorry you are not in server";

  }
  cout<<" \n Enter your class  ";
  cin>>cls;
  cout<<" \n Enter your id number  ";
  cin>>id;
}
void book::std()
{
    cout<<" \n Name of student is "<<name<<endl;
    cout<<"\n Library password  "<<passe<<endl;
    cout<<"\n Student class "<<cls;
    cout<<"\n Id number is "<<id<<endl;
}
book::book()
{
    Q.front=-1;
    Q.rear=-1;

}
int book::Qfull()
{
  if(Q.rear>=size-1)
  return 1;
  else
  return 0;  
}
int book::insert(int books)
{
    if(Q.front==-1)
    Q.front++;
    Q.queue[++Q.rear]=books;
    return Q.rear;
}
int book::Qempty()
{
    if((Q.front==-1)||(Q.front>Q.rear))
    return 1;
    else
    return 0;

}
int book::delet()
{
    int books,n,m;
    books=Q.queue[Q.front];
    cout<<" \n how many books you have";
    cin>>n;
    m = Q.queue[Q.rear] - n;
    cout<<"\n reamining book "<<m;
    return Q.front;
}
void book::display()
{
    int i;
    for(i=Q.front;i<=Q.rear;i++)
    cout<<" "<<Q.queue[i];
}
void book::fogg()
{
    int r;
    int t;
    cout<<" \n which books you have";
    cin>>r;
    switch(r)
    {
        case 1:
        int z,c;
        cout<<" \n you choose chemistry type books";
        cout<<" \n how many books in chemistry";
        cin>>c;
         z = Q.queue[Q.rear]- c;
        cout<<"remaining books"<<z;
        break;
        case 2:
        cout<<"\n you choose physics type book";
        cout<<"\n how many books in phy";
        cin>>c;
        z = Q.queue[Q.rear] - c;
        cout<<"remaining books"<<z;
        case 3:
        cout<<" \n you choose other refferance book";
        cout<<"\n Enter number of books";
        cin>>c;
        z = Q.queue[Q.rear] - c;
        cout<<"reamining books"<<z;
    }
}
void book::fe()
{
    cout<<" \n Enter your feedback for our library \n Enter any query to devoolope our library \n ";
    cin>>feed;
}
int main(void)
{
    cout<<"\n ********************Global library************************** ";
        cout<<"\n ----------------------------------------------------------";
    int choice, books;
    char ans;
    book obj;
    do{
        cout<<"\n . Menu books";
        cout<<"\n 1. Student login";
        cout<<"\n 2. View student info";
        cout<<"\n 3.Add books ";
         cout<<"\n 4.Number of books ";
         cout<<"\n 5. list ";
         cout<<"\n 6.choose book";
         cout<<"\n7.feedback";
          cout<<"\n Enter your chioce";
          cin>>choice;
        if(choice==8)
          {
            cout<<"Thank you visit again!!!";
            break;
          }
          switch (choice)
          {
            case 1:
            obj.student();
            break;
            case 2:
            obj.std();
            break;
          case /* constant-expression */3:
          if (obj.Qfull())
          

           cout<<"\n Library books capacity is full";

           else
           {
             cout<<"\n Enter the number of books";
             cin>>books;
             

             obj.insert(books);

           }
            /* code */
            break;
            case 4:
            if(obj.Qempty())
             cout<<"\n NO any book in library";
             else 
             obj.delet();
             break;
             case 5:
             if(obj.Qempty())
              cout<<"\n all books are buyed";
              else 
              obj.display();
             
              break;
              case 6:
             obj.fogg();
             break;
         
            case 7:
            obj.fe();
            break;
             default:
             cout<<"please try again";
            break;

          }
           cout<<"\n do you want to continue";
           cin>>ans;
          
    }
    while(ans=='Y'||ans=='y');
    return 0;

}