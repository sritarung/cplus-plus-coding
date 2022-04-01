#include <iostream>
#include<limits>//defines max number of characters limit
#include <map> 
#include <sstream> //istringstream
#include <algorithm> //transform
using namespace std;


void wordsCount(string str)
{
    int count = 1;
    
    map<string, int> mp;

    istringstream wstream(str);

    string word;

    while (wstream >> word)
    {
        pair<map<string, int>::iterator, bool> rValue;

        rValue = mp.insert(pair<string, int>(word, count));

        if (rValue.second == false){
            ++rValue.first->second;
        }
    } 

    map<string, int>::iterator iterator;

    for (iterator = mp.begin(); iterator != mp.end(); ++iterator)
    {
        cout << '\t' << iterator->first;
        cout << '\t' << iterator->second << '\n';
    }

}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW9P1.cpp" << " Date: 12/7/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );// cin ignores max number of characters until new line(\n)
    string s;
    getline(cin, s);
    for (int i = 0, len = s.size(); i < len; i++)
    {
        if (ispunct(s[i]))
        {
            s.erase(i--, 1);
            len = s.size();
        }
        if (isupper(s[i]))
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
    }
    
    wordsCount(s);
    return 0;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW9P1.cpp Date: 12/7/2021
Student Name: Sri
----------------------------------------------
four score and seven years ago our fathers brought forth upon this continent, 
a new nation, conceived in liberty, and dedicated to the proposition that all 
men are created equal. now we are engaged in a great civil war, testing whether 
that nation, or any nation so conceived and so dedicated, can long endure. we are 
met on a great battle-field of that war. we have come to dedicate a portion of that 
field, as a final resting place for those who here gave their lives that that nation 
might live. it is altogether fitting and proper that we should do this.
        a       5
        ago     1
        all     1
        altogether      1
        and     4
        any     1
        are     3
        as      1
        battlefield     1
        brought 1
        can     1
        civil   1
        come    1
        conceived       2
        continent       1
        created 1
        dedicate        1
        dedicated       2
        do      1
        endure  1
        engaged 1
        equal   1
        fathers 1
        field   1
        final   1
        fitting 1
        for     1
        forth   1
        four    1
        gave    1
        great   2
        have    1
        here    1
        in      2
        is      1
        it      1
        liberty 1
        live    1
        lives   1
        long    1
        men     1
        met     1
        might   1
        nation  4
        new     1
        now     1
        of      2
        on      1
        or      1
        our     1
        place   1
        portion 1
        proper  1
        proposition     1
        resting 1
        score   1
        seven   1
        should  1
        so      2
        testing 1
        that    7
        the     1
        their   1
        this    2
        those   1
        to      2
        upon    1
        war     2
        we      4
        whether 1
        who     1
        years   1
*/