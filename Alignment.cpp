//// ALL OKAY. Everything is in okay

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
vector <string> text;
queue <string> temp;

void gettext()
{
    string words;
    while (true)
    {
        cin >> words;
       if (words == "end")
        {
            text.push_back(words);
           break;
        }
        else
        {
            text.push_back(words);
        }
    }
}

string line_align_left(int width)
{
    string str = "";
    int k = 0;
    for (int i = 0; i < text.size(); i++)
    {
        // cout<<text[i]<<' '<<text[i].length()<<endl;
        k += text[i].length();

        if (k > width)
        {
          //  cout<<k<<endl;
            str += "\n";
            k = 0;
            i = i - 1;
        }
        else if (k == width)
        {
            str += text[i] + "\n";
            k = 0;
        }
        else
        {
            cout<<k<<' '<<endl;
            str += text[i] + " ";
            k += 1;
            //
        }
    }
    return str;
}

string line_align_right(int width)
{
    string str = "";
    int k = 0;
    for (int i = 0; i < text.size(); i++)
    {
        k += text[i].length();
        if (k <= width)
        {
            temp.push(text[i]);
            k += 1;
        }
        else if ((k - 1) >= width)
        {
            for (int j = 0; j < (width - (k -1 - text[i].length())); j++)
            {
                str += " ";
            }
            while(!temp.empty())
            {
                str += temp.front() + " ";
                temp.pop();
            }
            str += "\n";
            k = 0;
            i = i - 1;
        }
    }
    for (int j = 0; j < width - k+1;j++)
    {
        str += " ";
    }
    while(!temp.empty())
    {
        str += temp.front() + " ";
        temp.pop();
    }
    str += "\n";
    return str;
}

int main()
{
    gettext();
    int width;
    cin >> width;
    string aligned;
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;
    aligned = line_align_left(width);
    cout << aligned << endl;
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;
    aligned = line_align_right(width);
    cout << aligned;
    for (int i = 0; i < width; i++)
        cout << "-";
    return 0;
}

/*
Sailor Moon Sailor Moon Sailor New Sailor Moon anime commemorating the 20th anniversary of Sailor Moon. Usagi Tsukino is a second-year middle school girl who is a little clumsy and a crybaby, but she is full of energy. One day, she meets Luna, a black cat with a crescent moon on her forehead, and she transforms into Sailor Moon, a Sailor Moon Sailor Moon Sailor sailor-uniformed pretty guardian of love and justice end
50
*/
