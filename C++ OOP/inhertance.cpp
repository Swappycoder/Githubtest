#include <iostream>
using namespace std;
//...............................................................................
class Employee
{
protected:
    string ename;
    int eid;

public:
    Employee()
    {
        ename = "Mohit";
        eid = 10;
    }
    Employee(string name, int id)
    {
        ename = name;
        eid = id;
    }

    void display();
   // virtual  void earning();
};
//...............................................................................

class salemp : public Employee
{
    double weeklysal;

public:
    salemp()
    {
        weeklysal = 180;
    }

    salemp(string n, int id, double ws) : Employee(n, id)
    {
        ename = n;
        eid = id;
        weeklysal = ws;
    }

    void earning()
    {
        cout << "\n weeklysal is- " << weeklysal << endl;
    }
};
//...............................................................................

class houremp : public Employee
{
    double wage;
    double hours;
    double hourlysalary;

public:
    houremp()
    {
        wage = 240;
        hours = 12;
    }
    houremp(string n, int id, double w, double h) : Employee(n, id)
    {
        wage = w;
        hours = h;
        ename = n;
        eid = id;
    }
    void earning()
    {
        if (hours < 40)
        {
            hourlysalary = hours * wage;
        }
        else
        {
            hourlysalary = 40 * wage + ((hours - 40) * wage) * 1.5;
        }
        cout << "\n wages are-" << wage << endl;
        cout << "\n hours are-" << hours << endl;
        cout << "\n hourlysalary is-" << hourlysalary << endl;
    }
};
//...............................................................................

class commissionemp : public Employee
{
    double grosssale;
    double commissionrate;
    double commissionsalary;

public:
    commissionemp()
    {
        grosssale = 24;
        commissionrate = 120;
    }
    commissionemp(string n, int id, double g, double cr) : Employee(n, id)
    {
        grosssale = g;
        commissionrate = cr;
        ename = n;
        eid = id;
    }
    void earning()
    {
        commissionsalary = grosssale * commissionrate;

        cout << "\n grosssale is-   " << grosssale << endl;
        cout << "\n commissionrate is -     " << commissionrate << endl;
        cout << "\n commissionsalary is-    " << commissionsalary << endl;
    }
};
//...............................................................................

void Employee::display()
{
    cout << "\n employee name is-   " << ename << endl;
    cout << "\n employee id id -    " << eid << endl;
}
//...............................................................................

int main()
{

    Employee e1;
    Employee e2("mohit", 10);
    salemp se1;
    salemp se2("sid", 10, 1000);
    houremp he1;
    houremp he2("aarul", 10, 300, 12);
    commissionemp c1;
    commissionemp c2("trupti", 10, 50, 120);

    cout << "\n____________________________________________________________________" << endl;
    
    se1.display();
    se1.earning();
    cout << "\n____________________________________________________________________" << endl;

    se2.display();
    se2.earning();
    cout << "\n____________________________________________________________________" << endl;

    he1.display();
    he1.earning();
    cout << "\n____________________________________________________________________" << endl;

    he2.display();
    he2.earning();
    cout << "\n____________________________________________________________________" << endl;

    c1.display();
    c1.earning();
    cout << "\n____________________________________________________________________" << endl;

    c2.display();
    c2.earning();
    cout << "\n____________________________________________________________________" << endl;
    return 0;

}