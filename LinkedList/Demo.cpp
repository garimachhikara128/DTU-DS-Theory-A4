#include<iostream>

using namespace std ;

class Student
{
    char name ;
    int age ;

    public :

    Student()
    {
        cout << "In Default Constructor" << endl ;
    }

    Student(char name, int age)
    {
        cout << "In Parametrized Constructor" << endl ;
    }
} ;

int main()
{

    Student s1 ;
    Student s2('A' , 10) ;

    Student *s3 = new Student() ;
    Student *s4 ;



}