#include <iostream>
using namespace std;
/*
Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени,
изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения.
Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных
студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.
*/


class Person {
private:
    static int count; 
protected:
    string m_name;
    int m_age;
    string m_gender;
    int m_wight;
public:
    static int GetCount() { return count; } 

    Person(const string& name, const int& age, const string& gender, const int& wight)
        : m_name(name), m_age(age), m_wight(wight), m_gender(gender)
    {
        count++; 
    }

    string GetName() { return m_name; } 
    int GetAge() { return m_age; }
    int GetWighr() { return m_wight; }
    virtual void Print()   
    {
        cout << m_name << ' ' << m_age << ' ' << m_gender << ' ' << m_wight << endl;
    }
};

class Student : public Person {
private:
    int m_year;
public:
    Student(int year, const string& name, const int age, const string& gender, const int wight)
        :Person(name, age, gender, wight), m_year(year) {}

    int GetYear() { return m_year; } 
    void AddYear(int addValue) 
    {
        m_year += addValue;
    }
    void AddYear()
    {
        m_year++; 
    }
    void Print() 
    {
        cout << m_year << ' ';
        Person::Print();
    }
};


/*HOMEWORK2
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет).
Добавить новый класс GrannySmith, который наследует класс Apple.
*/
class Fruit
{
public:
    string name;
    string color;

    Fruit(string name, string color) : name(name), color(color) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};

class Banana : public Fruit
{
public:
    Banana(string name = "Banana", string color = "Yellow") : Fruit(name, color) 
    {}

};

class Apple : public Fruit
{
public:
    Apple(string name = "Apple", string color = "Red") : Fruit(name, color) 
    {}

};

class GrannyEgor : public Apple
{
public:
    GrannyEgor(string name = "Granny Egor", string color = "Green") : Apple(name, color) 
    {}
};


/*HOMEWORK3
Изучить правила игры в Blackjack.
Подумать, как написать данную игру на С++,
используя объектно-ориентированное программирование.
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
Продумать реализацию игры с помощью классов и записать результаты.
*/
void Blackjack()
{
    cout << "\nСоздаем классы: Dealer, Player, Hands(Руки), Deck(Колода), Deckpile(Раздача карт).";
    cout << "\nDealer, Player классы базовые, остальные производные.";
}




int Person::count = 0;
int main()
{
    setlocale(LC_ALL, "Rus");
    {
        //HOMEWORK1
        auto student1 = new Student(6, "Денис", 19, "male", 140);
        auto student2 = new Student(4, "Данил", 21, "female", 42);
        auto student3 = new Student(4, "Днмитий", 31, "male", 35);
        auto student4 = new Student(1, "Олег", 4, "female", 250);
        auto student5 = new Student(2, "Егор", 20, "male", 59.500);
        student1->Print();
        student2->Print();
        student3->Print();
        student4->Print();
        student5->Print();
        delete student1;
        delete student2;
        delete student3;
        delete student4;
        delete student5;
    }

    {
        //HOMEWORK2
        Apple a("red");
        Banana b;
        GrannyEgor c;

        cout << "\nMy " << a.getName() << " is " << a.getColor() << ".\n";
        cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    }

    {
        //HOMEWORK3
        Blackjack();
    }

    return 0;
};