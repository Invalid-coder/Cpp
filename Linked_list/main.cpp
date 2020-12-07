#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    Person *p_next_person;
};

Person* addNew(Person *person);
Person* search_by_name(Person *p_root,string name);

int main()
{
    int amount;
    Person* p_root = NULL;

    cout << "Amount = ";
    cin >> amount;


    for(int i = 0; i < amount; i++)
    {
        p_root = addNew(p_root);
    }

    Person *needed_element = search_by_name(p_root,"Sasha");

    cout << "Found your element: " << needed_element->name;

    return 0;
}

Person* addNew(Person *p_root)
{
    Person* new_person = new Person;
    new_person->p_next_person = p_root;

    cout << "Name: ";
    cin >> new_person->name;

    return new_person;
}

Person* search_by_name(Person *p_root,string name)
{
    Person *current = p_root;

    while(current != NULL && current->name != name)
    {
        current = current->p_next_person;
    }

    return current;
}
