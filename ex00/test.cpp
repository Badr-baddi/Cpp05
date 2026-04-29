#include <iostream>
#include <exception>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 5;
    try{
        if (index >= 5)
        {
            throw "index out of range";
        }
        std::cout<<arr[index]<< std::endl;
    }
        catch (const char* e){
            std::cout<< "Error:Index out of range"<< e << std::endl;
        }
    return 0;
}