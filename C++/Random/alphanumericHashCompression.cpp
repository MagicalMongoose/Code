#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, char> nums =   {
                        {0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'},

                        {10,'a'},{11,'b'},{12,'c'},{13,'d'},{14,'e'},{15,'f'},{16,'g'},{17,'h'},{18,'i'},
                        {19,'j'},{20,'k'},{21,'l'},{22,'m'},{23,'n'},{24,'o'},{25,'p'},{26,'q'},{27,'r'},
                        {28,'s'},{29,'t'},{30,'u'},{31,'v'},{32,'w'},{33,'x'},{35,'y'},{36,'z'},

                        {37,'A'},{38,'B'},{39,'C'},{40,'D'},{41,'E'},{42,'F'},{43,'G'},{44,'H'},{45,'I'},
                        {46,'J'},{47,'K'},{48,'L'},{49,'M'},{50,'N'},{51,'O'},{52,'P'},{53,'Q'},{54,'R'},
                        {55,'S'},{56,'T'},{57,'U',},{58,'V'},{59,'W'},{60,'X'},{61,'Y'},{62,'Z'}
                        };

int bigNum = 3968;
int smallNum = 63;

string intToAlphaNum(long int n)
{
    //convert inputNum to alphaNum
    char output[64];
    int i = 0;
    while (n != 0)
    {
        int rem = 0;
        rem = n % bigNum;
        n = n / bigNum;
        cout << n << " Remainder: " << rem << endl;

        while (rem != 0)
        {
            int temp = rem / smallNum;
            rem = rem % smallNum;
            cout << temp << " Rem: " << rem << endl;
            rem = temp % smallNum;
        }
        
        cout << nums[rem]; //this needs to print the 63base remainder equivalent
        
        output[i] = nums[rem];

        i++;
    }
    for (int j = i-1; j>=0; j--)
    {
        cout << output[j];
    }

    return "aaa";
}

long int alphaNumToInt(string alphaNum)
{
    //convert alphaNum to long int
    for (int i = 0; i < smallNum; i++)
    {
        //take the letter and multiply by 63^{pos}
    }
    return 0000;
}

int main()
{   
    int counter = 0;
    for (int i = 0; i < smallNum; i++)
    {
        for (int j = 0; j < smallNum; j++)
        {
            cout << "(" << counter << ": "  << nums[i] << nums[j] << ") ";
            counter++;
        }
        cout << endl;
    }



    long int inputNum = 9513215;
    string alphaNum8k = "B2Sq";

    cout << inputNum << " converted to alphaNum: ";
    cout << endl;
    intToAlphaNum(inputNum);
    cout << endl;
    cout << alphaNum8k << " converted to int: " << alphaNumToInt(alphaNum8k) << endl;


    //todo: convert long int to RGBXYT

    
    
    return 0;
}