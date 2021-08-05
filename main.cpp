#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void csvSort(double min, double max, string fileName, node &root);

struct node
{
    int id;
    int size;
    node* next;
};

int main()
{
    // USER Settings -- define the min and max acreages that you want to search for
    double acreMin = 15.0;
    double acreMax = 45.0;
    // End user settings

    string fileName;
    node* root = new node;

    cout << "Please enter csv file name: ";
    getline(cin, fileName);
    
    csvSort(acreMin, acreMax, fileName, root);

    return 0;
}

void csvSort(double min, double max, string fileName, node* root)
{
    ifstream file;
    file.open(fileName);
    
    if (file.fail())
    {
        cout << "Invalid file name! " << endl;
    }
}