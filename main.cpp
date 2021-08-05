#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    int id;
    double size;
    node* next;
};


void csvSort(double min, double max, string fileName, node* focusNode);
int split (string splittee, char separator, string array[], int size);
bool isValidNumber (string testString);

int main()
{
    // USER Settings -- define the min and max acreages that you want to search for
    double acreMin = 15.0;
    double acreMax = 45.0;
    // End user settings

    string fileName;
    node* root = new node;
    node* cursor = root;

    cout << "Please enter csv file name: ";
    getline(cin, fileName);
    
    csvSort(acreMin, acreMax, fileName, root);

    cout << "Parcels that fit the designated parameters:" << endl;
    while (cursor->next != nullptr)
    {
        cout << "ID: " << cursor->id << " " << "Acreage: " << cursor->size << endl;
        cursor = cursor->next;
    }

    return 0;
}

void csvSort(double min, double max, string fileName, node* focusNode)
{
    ifstream file;
    file.open(fileName);
    
    if (file.fail())
    {
        cout << "Invalid file name! " << endl;
        return;
    }

    string text = "";
    while (getline(file, text))
    {
        if (!(text[0] == '0' && text[1] == ',') && text[0] != 'p') // Accounts for blank parcels and initial declaration
        {
            string stringData[100];
            split(text, ',', stringData, 100);
            if (isValidNumber(stringData[5]))
            {
                double acreage = stod(stringData[5]);
                if (acreage >= min && acreage <= max)
                {
                    focusNode->id = stoi(stringData[0]);
                    focusNode->size = acreage;
                    focusNode->next = new node;
                    focusNode = focusNode->next;
                }
            }
        }
    }
}

int split (string splittee, char separator, string array[], int size)
{
    int arrayColumn = 0;
    string builder = "";
    
    for (int i = 0; i < splittee.length(); i++)
    {
        char seeker = splittee[i];
        if (seeker == separator)
        {
            array[arrayColumn] = builder;
            builder = "";
            arrayColumn += 1;
        }
        else
        {
            builder += seeker;
        }
    }
    array[arrayColumn] = builder;

    if (size < arrayColumn + 1)
    {
        return -1;
    }
    else if (splittee.length() > 0)
    {
        return arrayColumn+1;
    }
    else
    {
        return arrayColumn;
    }
}

bool isValidNumber (string testString)
{
    if (testString[0] >= '0' && testString[0] <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}