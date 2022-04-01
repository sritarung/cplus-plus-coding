#include <iostream>
#include<limits>//defines max number of characters limit
#include <map>
#include <iterator>
 
using namespace std;
 
int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW9P2.cpp" << " Date: 12/7/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );// cin ignores max number of characters until new line(\n)
    multimap <string, int> fruits; 
    string fruitName, heavyName, lightName;
    int fruitWeight, heavyWeight=-1, lightWeight=10000000;

    for(int i=0;i<20;i++){
        cout<<"Enter fruit name: ";
        getline(cin, fruitName);

        cout<<"Enter fruit weight(in kg): ";
        cin>>fruitWeight;

        cin.ignore();

        //find max weight and fruit name
        if(heavyWeight<fruitWeight){
            heavyWeight = fruitWeight;
            heavyName = fruitName; 
        }

        if(lightWeight>fruitWeight){
            lightWeight = fruitWeight; 
            lightName = fruitName; 
        }

        fruits.insert(pair<string, int> (fruitName, fruitWeight));
    }


    multimap <string, int> :: iterator itrMap;

    //print fruit and weight
    for (itrMap = fruits.begin(); itrMap != fruits.end(); ++itrMap){
        cout << "Fruit: " << itrMap->first<< "\nWeight: " << itrMap->second << '\n';
    }

    //print heavy weight name and weight
    cout<<"Heavy weight fruit name: "<<heavyName<<" and weight: "<<heavyWeight<<" kg"<<endl;

    //print light weight name and weight
    cout<<"Light weight fruit name: "<<lightName<<" and weight: "<<lightWeight<<" kg"<<endl;

    return 0;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW9P2.cpp Date: 12/7/2021
Student Name: Sri
----------------------------------------------
Enter fruit name: Apple
Enter fruit weight(in kg): 1
Enter fruit name: Avocado
Enter fruit weight(in kg): 2
Enter fruit name: Banana
Enter fruit weight(in kg): 2
Enter fruit name: Blueberries
Enter fruit weight(in kg): 3
Enter fruit name: Cucumber
Enter fruit weight(in kg): 2
Enter fruit name: Dragonfruit
Enter fruit weight(in kg): 4
Enter fruit name: Grapes
Enter fruit weight(in kg): 3
Enter fruit name: Guava
Enter fruit weight(in kg): 4
Enter fruit name: Jackfruit
Enter fruit weight(in kg): 11
Enter fruit name: Kiwi
Enter fruit weight(in kg): 2
Enter fruit name: Lemon
Enter fruit weight(in kg): 2
Enter fruit name: Mango
Enter fruit weight(in kg): 4
Enter fruit name: Oranges
Enter fruit weight(in kg): 3
Enter fruit name: Olive
Enter fruit weight(in kg): 2
Enter fruit name: Papaya
Enter fruit weight(in kg): 7
Enter fruit name: Pineapple
Enter fruit weight(in kg): 9
Enter fruit name: Pear
Enter fruit weight(in kg): 2
Enter fruit name: Peach
Enter fruit weight(in kg): 3
Enter fruit name: Strawberries
Enter fruit weight(in kg): 3
Enter fruit name: Watermelon
Enter fruit weight(in kg): 10
Fruit: Apple
Weight: 1
Fruit: Avocado
Weight: 2
Fruit: Banana
Weight: 2
Fruit: Blueberries
Weight: 3
Fruit: Cucumber
Weight: 2
Fruit: Dragonfruit
Weight: 4
Fruit: Grapes
Weight: 3
Fruit: Guava
Weight: 4
Fruit: Jackfruit
Weight: 11
Fruit: Kiwi
Weight: 2
Fruit: Lemon
Weight: 2
Fruit: Mango
Weight: 4
Fruit: Olive
Weight: 2
Fruit: Oranges
Weight: 3
Fruit: Papaya
Weight: 7
Fruit: Peach
Weight: 3
Fruit: Pear
Weight: 2
Fruit: Pineapple
Weight: 9
Fruit: Strawberries
Weight: 3
Fruit: Watermelon
Weight: 10
Heavy weight fruit name: Jackfruit and weight: 11 kg
Light weight fruit name: Apple and weight: 1 kg
*/