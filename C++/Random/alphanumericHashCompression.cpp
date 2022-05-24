#include <iostream>
#include <string>
using namespace std;

    string intToAlphaNum(long int input)
    {
        //convert inputNum to alphaNum
        return "aaaaa";
    }

    long int alphaNumToInt(string alphaNum)
    {
        //convert alphaNum to long int
        return 0000;
    }

int main()
{   
/*    long int inputNum = 234567;
    string alphaNum8k = "4k2a";

    cout << inputNum << " converted to alphaNum: " << intToAlphaNum(inputNum) << endl;
    cout << alphaNum8k << " converted to int: " << alphaNumToInt(alphaNum8k) << endl;
*/

    //todo: convert long int to RGBXYT
    string nums[62] = {"0","1","2","3","4","5","6","7","8","9",
                    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
                    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int numLength = sizeof(nums)/sizeof(nums[0]);
    cout << numLength << endl;
    for (int i = 0; i < numLength; i++)
    {
        //cout << nums[i] << endl;
    }
    /*char aChar = '0';
    for (int c = 17; c < 43; c++)
    {
        aChar = '0'+c;
        cout << c << ": " << aChar << endl;
    }
    for (int d = 49; d < 75; d++)
    {
        aChar = '0'+d;
        cout << d << ": " << aChar << endl;
    }*/
    

    for (int i = 0; i < numLength; i++)
    {
        for (int j = 0; j < numLength; j++)
        {
            cout << nums[i] << "_" << nums[j] << " ";
        }
        cout << endl << endl;
    }
    return 0;
}