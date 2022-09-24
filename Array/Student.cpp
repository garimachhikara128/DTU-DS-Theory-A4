#include<iostream>

using namespace std ;

class Student
{
    char name ;
    int age ;

    public :

    Student(char n , int a)
    {   
        name = n ;
        age = a ;
    }

    void sayHi(Student s)
    {
        cout << name << " says hi to " << s.name ;
    }

} ;

int main()
{
    Student s1 ('A',10) ;
    Student s2 ('B', 20) ;

    s1.sayHi(s2) ;

}
