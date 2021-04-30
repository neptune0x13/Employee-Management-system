#include <iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
#include<map>
using namespace std;
float flag=0;
template<typename credentials>                                                          //template function
credentials checker (credentials username[10],credentials password[10]){
    if((strcmp(username,"admin") && strcmp(password,"admin"))==0)
        return flag =1;
    else
        return flag=0;
}
class Employee {
private:
    double salary;
public:
    string name;
    double pc;
    double duration;
    double performance;
    Employee() {
        cout << "\n Enter name: ";
        cin >> this->name;
        cout << "\n Enter duration: ";
        cin >> this->duration;
        cout << "\n Enter no.of projects completed: ";
        cin >> this->pc;
        cout<<"\n Enter current salary: ";
        cin>>this->salary;
        this->performance = this->pc + (this->duration / 365) * 10;
        cout << "\n Performance: " << this->performance;
    }
    ~Employee(){
    }
    friend class Employee1;
    friend void appraisal(Employee);                                              //friend function
};
Employee & changeName(Employee & te){                                             //return by reference
    cout<<"\n Enter new name:";
    cin>>te.name;
    cout<<"\n (Print the array to view the made changes)";
    return te;
}
Employee & changePerformance(Employee & te){                                      //return by reference
    cout<<"\n (Note: salary will be updated with respect to the performance entered)";
    cout<<"\n Enter new Performance:";
    cin>>te.performance;
    cout<<"\n (Print the array to view the made changes)";
    return te;
}
void appraisal(Employee e){
    try {                                                                        //exception handling
        if (e.pc == 0) {
            throw string("No.of projects cant be zero");
        }
        else {
            e.salary= e.salary+e.performance*1000;
            cout<<e.salary;
        }
    }
    catch(string s){
        cout<<"\n error "<<s;
    }
}
void showstack(stack <string> s,stack <double> s1)
{
    int i=0;
    cout<<"\n\tThe Stack";
    cout<<"\n|INDEX|EMPLOYEE\t|PERFORMANCE|";
    while (!s.empty())
    {
        cout <<"\n"<<i<<"\t"<<s.top()<<"\t"<<s1.top();
        i++;
        s.pop();
        s1.pop();
    }
    cout << '\n';
}
class Employee1 {
public:
    double salary;
    string name;
    Employee1() {}
    Employee1(string emcode) {                                                    //Polymorphism
        cout << "\n Enter name";
        cin >> this->name;
        cout << "\n Enter current salary: ";
        cin >> this->salary;
    }
    Employee1 operator > (Employee1 tempC){                                      //operator overloading
        Employee1 returnValue;
        if(returnValue.salary>tempC.salary){
            cout<<"\n The employee with more salary:"<<returnValue.name;
        }
        else
            cout<<"\n The employee with more salary:"<<tempC.name;
        return tempC;
    }
};
class Department {                                                             //abstract class
public:
    Department(){}
    virtual void display()=0;                                                  //pure virtual function
};
class Manager :public virtual Department{
private:
protected:
public:
    int empduration;
    double appraisalscore;
    double skillrate;
    int DPID;
    string name;
    Manager(int empduration,double skillrate,int DPID,string name):Department(){
        this->empduration=empduration;
        this->DPID=DPID;
        this->name=name;
        this->skillrate=skillrate;
    }
    void display(){
        cout<<"\n Department id:"<<DPID;
        cout<<"\n Apraisal score:"<<appraisalscore;
        cout<<"\n Salary Addition:"<<appraisalscore*100;
    }
};
class HRDepartment:public virtual Department{                               //Inheritance
private:
protected:
    string empe;
    double DPID;
    int noofmembers;
    double appraisalscore,skillrate,empduration;
public:
    HRDepartment(double  DPID):Department(){
        cout << "\n Enter employee name:";
        cin >>this->empe;
        cout << "\n Enter no of members:";
        cin >> this->noofmembers;
        cout<<"\n Enter duration:";
        cin>>this->empduration;
        cout<<"\n Skill rate out of 10:";
        cin>>this->skillrate;
    }
    HRDepartment():Department(){}
    void assessemployee(Manager &m) {
        m.appraisalscore=m.skillrate+((m.empduration*100)/365);
    }
    void display(){
        appraisalscore=skillrate+(empduration*100)/365;
        cout<<"\n Name:"<<this->empe;
        cout<<"\n Apraisal score:"<<this->appraisalscore;
        cout<<"\n Salary Addition:"<<this->appraisalscore*100;
    }
};
class GeneralManager : public Manager {
public:
    int noofprojects;
    GeneralManager():Manager(empduration,skillrate,DPID,name){
        cout << "\n Enter employee name:";
        cin >> this->name;
        cout << "\n Enter noof days since employement:";
        cin >> this->empduration;
        cout << "\n Department id:";
        cin >> this->DPID;
        cout << "\n Enter skill rate on a scale of 1 to 10:";
        cin >> this->skillrate;
        cout << "\n No of projects Completed:";
        cin >> this->noofprojects;
    }
    void display(){
        cout<<"\n Department id:"<<this->DPID;
        cout<<"\n Apraisal score"<<this->appraisalscore;
        cout<<"\n Salary Addition:"<<this->appraisalscore*100;
    }
    inline void appraisal(){                                                 //inline function
        appraisalscore=skillrate+(empduration*100)/365;
    }
};
class Skillgrade{
public:
    char skillgrade;
    double skillrate;
    string name;
    Skillgrade(){
        cout<<"\nEnter name of employee:";
        cin>>name;
        cout<<"\nEnter the employees skill rate on a scale of 1 to 10:";
        cin>>skillrate;
        skillgrade = 'N';
    }
    void show() {
        cout<<"\nEmployee name:"<<name<<"\nSkillgrade:"<<skillgrade;
         }
};
class Assessment {
public:
    void assesemp(vector<Skillgrade> & vec){
        auto it = vec.begin();
        for ( ; it !=  vec.end(); it++) {
            if((*it).skillrate<=5)
                (*it).skillgrade = 'C';
            else if((*it).skillrate<=8)
                (*it).skillgrade = 'B';
            else if((*it).skillrate>8)
                (*it).skillgrade = 'A';
        }
    }
};
int main(){
    char username[10],password[10];
    cout<<"\n Enter user name :";
    gets(username);
    cout<<"\n Enter password :";
    gets(password);
    checker(username,password);
    if (flag == 1) {
        int a, b;
        char ch = 'y';
        while (ch == 'y') {
            cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
            cout << "\n Welcome to RedLab";
            cout << "\n1.Employee Appraisal \n2.Department Appraisal \n3.New Emlpoyee Array \n4.Write and Print skilgrade \n5.New Employee Stack \n6.New Employee Map \n7.Exit";
            cout << "\n Choose anyone of the options above \n";
            cin >> b;
            if (b == 2) {
                cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                cout << "\n Enter department \n1.HRdeparment \n2.Manger \n3.GeneralManger \n4.Main Menu\n";
                cin >> a;
                switch (a) {
                    case 1: {
                        double DPID;
                        cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                        cout << "\n Department id:\t";
                        cin >> DPID;
                        HRDepartment h = HRDepartment(DPID);
                        h.display();                                                   //Runtime polymorphism
                        cout << "\n" << system("PAUSE");
                        cout << "\n ............../Redirecting to Main Menu";
                        break;
                    }
                    case 2: {
                        string empname;
                        double days, skrt;
                        int id;
                        cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                        cout << "\n Enter employee name:";
                        cin >> empname;
                        cout << "\n Enter noof days since employement:";
                        cin >> days;
                        cout << "\n Department id:";
                        cin >> id;
                        cout << "\n Enter skill rate on a scale of 1 to 10:";
                        cin >> skrt;
                        HRDepartment h;
                        Manager m = Manager(days, skrt, id, empname);
                        h.assessemployee(m);
                        m.display();                                                    //Runtime polymorphism
                        cout << "\n" << system("PAUSE");
                        cout << "\n ............../Redirecting to Main Menu";
                        break;
                    }
                    case 3: {
                        cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                        GeneralManager g = GeneralManager();
                        g.appraisal();
                        g.display();                                                    //Runtime polymorphism
                        cout << "\n" << system("PAUSE");
                        cout << "\n ............../Redirecting to Main Menu";
                        break;
                    }
                    case 4: {
                        break;
                    }
                }
            }
            else if (b == 4){                                                                  //object Vector
                    int D;
                    cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                    cout<<"\n Enter number of Employees to be graded:";
                    cin>>D;
                    vector<Skillgrade>stdVector;
                    for ( int i = 0; i < D; i++ ) {
                        Skillgrade s = Skillgrade();
                        stdVector.push_back(s);
                    }
                    auto iter = stdVector.begin();
                    Assessment p;
                    p.assesemp(stdVector);
                    for ( iter = stdVector.begin(); iter !=  stdVector.end(); iter++)
                        (*iter).show();
                    cout << "\n" << system("PAUSE");
                    cout << "\n ............../Redirecting to Main Menu";
                }
            else if (b == 5){
                    cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                    int g;
                    stack <string> s;                                                            //Stack
                    stack <double> s1;
                    cout<<"\n Enter the number of records you want to enter:";
                    cin>>g;
                    for(int i=0;i<g;i++) {
                        Employee e;
                        s.push(e.name);
                        s1.push(e.performance);
                    }
                    cout<<"\n To printing and deleting the stack";
                    cout << "\n" << system("PAUSE");
                    showstack(s,s1);
            }
            else if (b == 6){
                cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                int g;
                map<string,double>empdata;                                              //Map
                cout<<"\n Enter the number of records you want to enter:";
                cin>>g;
                for(int i=0;i<g;i++) {
                    Employee e;
                    empdata.insert(pair<string, double>(e.name, e.performance));
                }
                cout<<"\n To printing the Map";
                cout << "\n" << system("PAUSE");
                int i=0;
                map<string,double>::iterator it;
                cout<<"\n\tThe Map";
                cout<<"\n|INDEX|EMPLOYEE\t|PERFORMANCE|";
                for (it = empdata.begin(); it != empdata.end(); ++it) {
                    cout <<"\n"<<i<<"\t"<<it->first<<"\t"<<it->second;
                    i++;
                }

            }
            else if (b == 7) {
                exit(0);
            } else if (b == 1) {
                int k;
                cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                cout << "\n1.Comaparison \n2.Appraisal\n3.Main Menu\n";
                cin >> k;
                switch (k) {
                    case 1: {
                        string emname1, emname2;
                        cout << "\n Enter details for the first employee:";
                        cout << "\n Enter employee code:";
                        cin >> emname1;
                        Employee1 e1 = Employee1(emname1);
                        cout << "\n Enter details for the second employee:";
                        cout << "\n Enter employee code:";
                        cin >> emname2;
                        Employee1 e2 = Employee1(emname2);
                        Employee1 e3;
                        e3 = e1 > e2;
                        cout << "\n" << system("PAUSE");
                        cout << "\n ............../Redirecting to Main Menu";
                        break;
                    }
                    case 2: {
                        Employee e = Employee();
                        cout << "\n New salary :";
                        appraisal(e);
                        cout << "\n" << system("PAUSE");
                        cout << "\n ............../Redirecting to Main Menu";
                        break;
                    }
                    case 3: {
                        break;
                    }
                }
            } else if (b == 3) {
                int N;
                cout << "\n Enter no.of employees you would like to accomodate";
                cin >> N;
                Employee *myemparray = new Employee[N];                             //Dynamic object array
                int b;
                char ch = 'y';
                while (ch == 'y') {
                    cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                    cout<< "\n1.Compare performances \n2.Print \n3.Modify Array \n4.Delete Array \n5.Main menu \n(Note:Comparisons are done within the array)\n";
                    cin >> b;
                    switch (b) {
                        case 1: {
                            double l;
                            int indexe;
                            l = myemparray[2].performance;
                            for (int i = 0; i < N; i++) {
                                if (myemparray[i].performance > l) {
                                    l = myemparray[i].performance;
                                    indexe = i;
                                }
                            }
                            cout << "\n Employee with the highest performance :" << myemparray[indexe].name;
                            break;
                        }
                        case 2: {
                            if (N == 0) {
                                cout << "\n Array deleted ";
                            } else {
                                cout << "\n --------------------------------------------------------";
                                cout << "\n|Index|\t|Employee Name|\tPerformance|\tNew Salary|";
                                for (int i = 0; i < N; i++) {
                                    cout << "\n --------------------------------------------------------";
                                    cout << "\n" << i << "\t" << myemparray[i].name << "\t\t"
                                         << myemparray[i].performance
                                         << "\t\t";
                                    appraisal(myemparray[i]);
                                }
                                cout << "\n --------------------------------------------------------";
                            }
                            break;
                        }
                        case 3: {
                            int index;
                            cout << "\n Enter the index of the employee record you want to modify :";
                            cin >> index;
                            int d;
                            char ch = 'y';
                            while (ch == 'y') {
                                cout << "\n1.Modify name\n2.Modify Performance\n3.Back to Array Menu\n";
                                cin >> d;
                                switch (d) {
                                    case 1: {
                                        changeName(myemparray[index]);
                                        break;
                                    }
                                    case 2: {
                                        changePerformance(myemparray[index]);
                                        break;
                                    }
                                    case 3: {
                                        break;
                                    }
                                }
                                cout << "\n To Continue Modification press y:";
                                cin >> ch;
                            }
                            break;
                        }
                        case 4: {
                            delete[]myemparray;
                            N = 0;
                            break;
                        }
                        case 5: {
                            cout<<"\n Deleting created array........";
                            delete[]myemparray;
                            N = 0;
                            break;
                        }
                    }
                    if (b != 5) {
                        cout << "\n To Continue with array prees y :";
                        cin >> ch;
                    } else
                        break;
                }
            }
        }
    }
    else{
        cout<<"\n invalid credentials";
    }
    return 0;
}