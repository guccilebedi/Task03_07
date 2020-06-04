#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int counter = 0;
    int temp;
    ifstream in("input.txt");
    ofstream out("output.txt");
    if (!in.is_open())
    {
        cout << "Ошибка чтения файла.";
        return 1;
    }
    else
    {
        while (!in.eof()) 
        {
            in >> temp;
            counter++;
        }
        in.clear();
        in.seekg(0);
        int* arr = new int[counter];
        for (int i = 0; i < counter; i++)
        {
            in >> arr[i];
        }
        for (int i = 0; i < counter; i++) {
            for (int j = 0; j < counter; j++) {
                if (arr[i] < arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for (int i = 0; i < counter; i++) {
            out << arr[i] << " ";
        }
    }
}