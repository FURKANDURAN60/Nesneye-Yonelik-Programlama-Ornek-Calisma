#include <iostream>
#include <string>
using namespace std;


class Person{
    
    protected:
        string name;
        int age;
    public:

        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }


        Person(){
            cout << "Person Created" << endl;
        }
        
        Person(string name, int age) : Person() {
            this->name = name;
            this->age = age;
            cout << "Person Created with parameters" << endl;
        }

        virtual string ToString(){
            return "Name : " + this->name + " , Age : " + std::to_string(this->age);
        }

};

class Teacher : public Person{
    protected:
        string subject;
    public:

        string getSubject(){
            return subject;
        }

        void setSubject(string subject){
            this->subject = subject;
        }

        Teacher(string name, int age, string subject) : Person(name, age) {
            this->subject = subject;
            cout << "Teacher Created with parameters and Teacher subject : "<< this->subject<< endl;
        }

        string ToString() override{
            return "Name : " + this->name + " , Age : " + std::to_string(this->age) + " , Subject : " + this->subject;
        }


};

class Student :  public Person{
    protected:
        string studentNumber;
    public:

        string getStudentNumber(){
            return studentNumber ; 
        }

        void setStudentNumber(string studentNumber){
            this->studentNumber = studentNumber;
        }

        Student(string name, int age, string studentNumber) :Person(name, age){
            this->studentNumber = studentNumber;
            cout << "Student Created with parameters and Student number : "<< this->studentNumber << endl;
        }

        string ToString() override{
            return "Name : " + this->name + " , Age : " + std::to_string(this->age) + " , Student Number : " + this->studentNumber;
        }

        
};


int main(){

    Teacher teacher1 = Teacher("Halit Oztekin", 48, "Computer Architecture");
    cout << teacher1.ToString() << endl;
    Student student1 = Student("Furkan", 25, "B210109048");
    cout << student1.ToString() << endl;


};