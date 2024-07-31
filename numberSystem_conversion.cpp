#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <vector>
using namespace std;

vector<int> hexadecimal_digits(string n);
void printing_hexadecimal(int array[], int size);
int decimal_to_binary(int n);
void decimal_to_hexa(int n);
int decimal_to_octal(int n);
int binary_to_decimal(string n);
void binary_to_hexa(string n);
int binary_to_octal(string n);
int octal_to_decimal(int n);
int octal_to_binary(int n);
void octal_to_hexa(int n);
int hexa_to_decimal(string n);
int hexa_to_octal(string n);
int hexa_to_binary(string n);

int main()
{
    cout << endl << "***********************************************************************" << endl;
    cout << "~~~~~~~~~~~~~~~ A number system conversion program ~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    int choice, choice2, choice3, choice4, choice5;
    int decimal, octal;
    string hexadecimal, binary;

    do
    { 
        cout << "Enter the number system you want to convert:" << endl;
        cout << "1.Decimal" << endl;
        cout << "2.Octal" << endl;
        cout << "3.Binary" << endl;
        cout << "4.hexadecimal" << endl;
        cout << "Choice: ";
        cin >> choice;

        cout << endl;

        switch(choice)
        {
            case 1: //decimal            
                cout << "Enter your decimal number: ";
                cin >> decimal;

                cout << endl;

                cout << "To which you want to convert: " << endl;
                cout << "1.Octal" << endl;
                cout << "2.Binary" << endl;
                cout << "3.Hexadecimal" << endl;
                cout << "Choice: ";
                cin >> choice2;

                cout << endl;

                switch(choice2)
                {
                    case 1:
                        cout << decimal << " in octal is " << decimal_to_octal(decimal);
                        break;
                    case 2:
                        cout << decimal << " in binary is " << decimal_to_binary(decimal) << endl;
                        break;
                    case 3:
                        decimal_to_hexa(decimal);
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break; 
                }           
                break;
            case 2: //octal
                cout << "Enter your octal number: ";
                cin >> octal;

                cout << endl;

                cout << "To which you want to convert: " << endl;
                cout << "1.Decimal" << endl;
                cout << "2.Binary" << endl;
                cout << "3.hexadecimal" << endl;
                cout << "Choice: ";
                cin >> choice3;

                cout << endl;

                switch(choice3)
                {
                    case 1:
                        cout << octal << " in decimal is " << octal_to_decimal(octal) << endl;
                        break;
                    case 2:
                        cout << octal << " in binary is " << octal_to_binary(octal);
                        break;
                    case 3:
                        octal_to_hexa(octal);
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break;
                } 
                break;
            case 3://binary
                cout << "Enter your binary number: ";
                cin >> binary;

                cout << endl;

                cout << "To which you want to convert: " << endl;
                cout << "1.Decimal" << endl;
                cout << "2.Octal" << endl;
                cout << "3.hexadecimal" << endl;
                cout << "Choice: ";
                cin >> choice4;

                cout << endl;

                switch(choice4)
                {
                    case 1:
                        cout << binary << " in decimal is " << binary_to_decimal(binary);
                        break;
                    case 2:
                        cout << binary << " in octal is " << binary_to_octal(binary);
                        break;
                    case 3:
                        binary_to_hexa(binary);
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break; 
                }
                break;
            case 4: //hexadecimal
                cout << "Enter your hexadecimal number: ";
                cin >> hexadecimal;

                cout << endl;
                
                cout << "To which you want to convert: " << endl;
                cout << "1.Decimal" << endl;
                cout << "2.Octal" << endl;
                cout << "3.Binary" << endl;
                cout << "Choice: ";
                cin >> choice5;

                cout << endl;

                switch(choice5)
                {
                    case 1:
                        cout << hexadecimal << " in decimal is " << hexa_to_decimal(hexadecimal) << endl;
                        break;
                    case 2:
                        cout << hexadecimal << " in octal is " << hexa_to_octal(hexadecimal);
                        break;
                    case 3:
                        cout << hexadecimal << " in binary is " << hexa_to_binary(hexadecimal);
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break; 
                }
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
        cout << endl << "***********************************************************************" << endl;
    }while(true);
    return 0;
}
vector<int> hexadecimal_digits(string n)
{
    int size = n.length();//finding the string length to know the size of the vector i should declare
    vector<int> num(size);
    for(int i = 0; i < size; i++) //converting the string to numbers
    {
        if(n[i] == 'A' || n[i] == 'a')
            num[i] = 10;
        else if(n[i] == 'B' || n[i] == 'b')
            num[i] = 11;
        else if(n[i] == 'C'|| n[i] == 'c')
            num[i] = 12;
        else if(n[i] == 'D' || n[i] == 'd')
            num[i] = 13;
        else if(n[i] == 'E'|| n[i] == 'e')
            num[i] = 14;
        else if(n[i] == 'F'|| n[i] == 'f')
            num[i] = 15;
        else 
        {
            stringstream(n.substr(i,1)) >> num[i]; //or u can do the same(like we did for the alphabets) for the numbers to
        }
    }

    return num;
}
void printing_hexadecimal(int array[], int size)
{
    for(int j = size - 1; j >= 0; j--)
    {
        if(array[j] == 10)
            cout << 'A';
        else if(array[j] == 11)
            cout << 'B';
        else if(array[j] == 12)
            cout << 'C';
        else if(array[j] == 13)
            cout << 'D';
        else if(array[j] == 14)
            cout << 'E';
        else if(array[j] == 15)
            cout << 'F';
        else     
            cout << array[j];
    }
    cout << endl;
}
int decimal_to_binary(int n)
{
    int temp = n;
    int num = 0;
    vector<int> binary; //declaring a vector to store each binary numbers
    
    //storing the binary digits inside the vector
    do
    {
        binary.push_back(temp % 2);
        temp /= 2;

    } while (temp > 0);
    
    int size = binary.size();

    for(int j = size - 1; j >= 0; j--)
    {
        num += binary[j]*pow(10,j);
    }
    return num;
}
void decimal_to_hexa(int n)
{
    int temp = n;
    int array[20]; //declaring an array to store each hexadecimal numbers
    int size = 0; //counter to know how many hexadecimal digits are there
    
    //storing the hexadecimal digits inside the array
    do
    {
        array[size] = temp % 16;
        temp /= 16;
        size++;

    } while (temp > 0);
    
    //printing the array in reverse order
    cout << n << " in hexadecimal is ";
    printing_hexadecimal(array, size);
}
int decimal_to_octal(int n)
{
    int temp = n;
    int array[30]; //declaring an array to store each octal numbers
    int i = 0; //counter to know how many octal digits are there
    
    //storing the octal digits inside the array
    do
    {
        array[i] = temp % 8;
        temp /= 8;
        i++;

    } while (temp > 0);

    int octal = 0;
    
    for(int j = i - 1; j >= 0; j--)
    {
        octal += array[j]*pow(10,j);
    }
    return octal;    
}
int binary_to_decimal(string n)
{
    int size = n.length();
    int array[size];
    for(int i = 0; i < size; i++)
    {
        stringstream(n.substr(i,1)) >> array[i];
    }

    //int temp = n;
    int digit, decimal = 0;
    int i = 0; //a counter to know its position value

    for(int i = size - 1; i >= 0; i--)
    {
        decimal += array[i]*pow(2,size - 1 - i);
    }
      
    return decimal;
}
void binary_to_hexa(string n)
{
    int decimal = binary_to_decimal(n);

    int array[20]; //declaring an array to store each hexadecimal numbers
    int size = 0; //counter to know how many hexadecimal digits are there
    
    //storing the hexadecimal digits inside the array
    do
    {
        array[size] = decimal % 16;
        decimal /= 16;
        size++;

    } while (decimal > 0);
    
    //printing the array in reverse order
    cout << n << " in hexadecimal is ";
    printing_hexadecimal(array, size);

}
int binary_to_octal(string n)
{   
    int decimal = binary_to_decimal(n);
    int octal = decimal_to_octal(decimal);

    return octal;
}
int octal_to_decimal(int n)
{
    int temp = n;
    int digit, i = 0, sum = 0;
    do
    {
        digit = temp % 10;
        temp /= 10;
        sum += digit * pow(8,i);
        i++;
    } while (temp > 0);
    
    return sum;
}
int octal_to_binary(int n)
{
    int decimal = octal_to_decimal(n);
    int binary = decimal_to_binary(decimal);

    return binary;
}
void octal_to_hexa(int n)
{
    int decimal = octal_to_decimal(n);
    decimal_to_hexa(decimal);
}
int hexa_to_decimal(string n)
{
    string originalNumber = n;

    vector<int> num = hexadecimal_digits(n);
    int size = num.size();

    int j = 0;
    int decimal = 0;

    for(int i = size - 1; i >= 0 ; i--) //reversing the array and calculating the hexadecimal value
    {
        num[i] *= pow(16, j);
        j++;
        decimal += num[i];
    }
    return decimal;   
}
int hexa_to_octal(string n)
{
    int decimal = hexa_to_decimal(n);
    int octal = decimal_to_octal(decimal);

    return octal;  
}
int hexa_to_binary(string n)
{
    int decimal = hexa_to_decimal(n);
    int binary = decimal_to_binary(decimal);   

    return binary;
}