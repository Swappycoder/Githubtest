#include<iostream>
using namespace std;
class Area{
    int a;
    int b;
    int r;
    float area;
    public :
        void triangle()
        {
            cout<<"Enter base and height: "<<endl;
            cin>>a>>b;
            area = 0.5*a*b;
        }
        
        void circle()
        {
            cout<<"Enter radius of circle: "<<endl;
            cin>>r;
            area = 3.14*r*r;
        }
        
        void square()
        {
            cout<<"Enter side of square: "<<endl;
            cin>>a;
            area = a*a;
        }
        
        void rectangle()
        {
            cout<<"Enter the length and breadth of rectangle: "<<endl;
            cin>>a>>b;
            area = a*b;
        }
        
        
        float show()
        {
            return area;
        }
};



int main()
{
    float t,c,s,r;
    int ch,x;
    Area a1,a2,a3,a4;
    do
    {
        cout<<"Enter choice:\n1.tirangle\n2.circle\n3.square\n4.rectangle\n";
        cin>>ch;
        switch(ch)
        {
            case 1: 
            a1.triangle();
            t=a1.show();
            cout<<"The area of triangle is :"<<t<<endl;
            break;

            case 2:
            a2.circle();
            c=a2.show();
            cout<<"The area of is circle:"<<c<<endl;
            break;

            case 3:
            a3.square();
            s=a3.show();
            cout<<"The area of is square:"<<s<<endl;
            break;

            case 4:
            a4.rectangle();
            r=a4.show();
            cout<<"The area of is rectangle:"<<r<<endl;
            break;
        }
        cout<<"Do you want to continue press 1 or to exit press 0."<<endl;
        cin>>x;
    }while(x==1);
    


    
    
    
    
    return 0;
}