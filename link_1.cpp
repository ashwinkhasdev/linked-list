#include <iostream>
using namespace std ;
struct node 
{ int data ;
  struct node * next ;
}*first = NULL;
      void createlink(int A[],int n)
      {
        struct node *t , *last ;
        first = new node ;
        first-> data = A[0];
        first->next= NULL ;
        last = first ;
        for(int i=1;i<n;i++)
        { t = new node ;
          t-> data = A[i] ;
          t-> next = NULL;
          last-> next = t ;
          last =t ;
        }
      }
      void displayfunc(struct node * p){
        while(p!=0){
          cout<<p->data <<endl;
          p= p->next ;
        }
      }
      int getinfo(struct node * a ){ // indicates total num of node 
        int sum= 0 ;
        while(a!=0)
        {
         sum=sum+a->data ;
         a=a->next ;
        }
        return sum ;
      }
      node * setvalue(node * p , int key ){ // swaping node from first 
        node * q ; 
        
        while(p != 0 ){
          if (key == p-> data ){
          q-> next = p-> next ;
          p-> next = first ;
          first = p ;
          }
          q = p ;
          p= p-> next;
        }
      }
      
        
    node * at_Index(node * p , int key , int n ){ // inserting a node 
        node * q , * var ;
        q=p ;
        for (int i=1 ; i<key - 1 ; i++){
          q = q->next ;
        }
        int x = 100 ;
        var = new node ;
        var -> data = x ;
        var -> next = q -> next ;
        q-> next = var ;
        while(p!=0){
        if( p-> data == n -1 ){
           p->next= NULL ;
        }
        p=p-> next ;
        }
      }
      
      int main (){
        cout<< "Enter arry size  : "  ;
        int n =0 ;
        cin >>n;
        int A[n] ;
        for(int i=0;i<n;i++)
        {
          cin>>A[i] ;
        }
        struct node call ;
        createlink(A , n) ;
        displayfunc(first) ;
        cout<<"Total of nodes data  :"<<getinfo(first) <<endl;
        //cout <<" enter key who have to set on first : " ;
        cout<<"Enter key to set on position : " ;
        int key ;
        cin>> key ;
      
        // cin>> key ;
        //  setvalue(first , key ) ;
        at_Index(first,key ,n ) ;
        displayfunc(first) ;



        return 0 ;
      }