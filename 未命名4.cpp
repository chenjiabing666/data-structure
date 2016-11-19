#include "iostream"
using namespace std;

class Link
{
public:

   Link *next;

   int element;
   Link(Link *rnext)
   {
       next=rnext;
   }

   Link(int b,Link *rnext)
   {
        element=b;
        next=rnext;
   }
};

class LLink
{
private:
    Link *head;
public:
    LLink()
    {
       head=new Link(NULL);

    }

    /*void input()
    {
        int i=0;
        while(i<4)
        {
            int node;
            cout<<"input node:";
            cin>>node;
            Link *p=new Link(node,NULL);
            Link *htemp=head;
             if(htemp==NULL)
             {
                htemp->next=p;
             }
             else
             {
                  while(1)
                  {
                      if(htemp->next==NULL)
                      {
                          htemp->next=p;
                          break;
                      }
                      htemp=htemp->next;

                  }
             }
           i++;

        }
    }*/

    void input()
    {
        int i=0;
        while(i<4)
        {
            int node;
            cout<<"node:";
            cin>>node;
       Link *p=new Link(node,NULL);
        Link *htemp=head;
        while(1)
        {
           if(htemp->next==NULL)
           {
                htemp->next=p;
                break;
           }
           else
           htemp=htemp->next;
        }
        i++;
        }

    }

    void display()
    {
        Link *p=head->next;
        while(p)
        {
            cout<<p->element<<"  ";
            p=p->next;
        }
        cout<<endl;
    }


    void sort_element()
    {
        Link **bottom,**top;
        bottom=top=new Link * [100];
        for(int b=0;b<100;b++)
        {
            bottom[b]=NULL;

        }



        Link *firstNode=head;



        for(;firstNode!=NULL;firstNode=firstNode->next)
        {

             int theBin=firstNode->element;
             if(bottom[theBin]==NULL)
             {
                 //cout<<"kong"<<endl;

             bottom[theBin]=top[theBin]=firstNode;
             }
             else
             {
                 cout<<"µÚ¶þ¸ö44"<<endl;
                 cout<<bottom[theBin]->element<<endl;

                 top[theBin]->next=firstNode;

                 top[theBin]=top[theBin]->next;
                 top[theBin]->element=99;
                  cout<<bottom[theBin]->element<<endl;
             }
        }



           Link *y=NULL;
          for(int theBin=0;theBin<100;theBin++)
        {

            if(bottom[theBin]!=NULL)
            {


            if(y==NULL)

              firstNode=bottom[theBin];


              else

                y->next=bottom[theBin];
                  y=top[theBin];

              }
        }


        if(y!=NULL)
            y->next=NULL;


             /*for(;firstNode!=NULL;firstNode=firstNode->next)
        {
            cout<<firstNode->element<<" ";
        }*/

        cout<<endl;



        delete [] bottom;
         delete [] top;



    }


    /*void input_e()
    {
         Link *p=new Link(99,NULL);
         Link *htemp=new Link(199,NULL);
         p->next=htemp;
         tail->next=p;
         tail=htemp;
    }*/



};


int main()
{
  LLink app;
  app.input();
  app.display();
  cout<<endl;
  app.sort_element();

 app.display();




return 0;
}
