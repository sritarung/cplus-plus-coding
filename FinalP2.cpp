#include<iostream>
#include<map>
#include<fstream>
using namespace std;

void copyMap(map<string, int>& mp)
{
    ifstream text;
    text.open("Hemingway.txt");

    if(!text.is_open()){
        cout<<"Error in opening text file"<<endl;
        return;
    }
    string word= "";
    cout<<endl;

    while(!text.eof()){
        text>>word;

        string str = "";
        int i=0;
        while(i< word.size()){
            if(isalpha(word[i]))
                str.push_back(tolower(word[i]));

            if(word[i]=='\''  || word[i]=='-')
                str.push_back(word[i]);
                i++;
        }
        if(str=="i") str[0] = toupper(str[0]);
        mp[str]++;
    }
    text.close();
}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: FinalP2.cpp" << " Date: 12/19/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    map<string, int>::iterator iter;
    map<string, int> txtMap;

    copyMap(txtMap);

    cout <<"Unique Word List " << endl;
    cout << "Count: " << txtMap.size() << endl;
    for(iter = txtMap.begin(); iter != txtMap.end(); iter++) {

        cout << "Word: "<< iter->first<<"\t\t"
             << "Count: " << iter->second << endl;

    }
    cout << endl;
    cout << endl;

    string magicWords[] = {"love", "death", "money", "blood", "lips", 
    "he", "she", "hero", "coward", "eyes","mouth", "years", "best", "bed", "table", 
    "ice", "fish", "animal", "sky", "glass","wine", "liquor", "old", "young", "man", 
    "big", "small", "home", "road", "chair","table", "boy", "boat", "food", "door", 
    "window", "days", "weeks", "wind", "sea","ice", "water", "wind", "they", "the", 
    "and", "week", "I", "of"
    }; 

    cout<<endl;

    map<string, int> magMap;
    for(int i = 0; i < sizeof(magicWords)/sizeof(string); i++) {
        for(iter = txtMap.begin(); iter != txtMap.end(); iter++) { 
            if(iter->first == magicWords[i]) {
                pair<string, int> str(iter->first, iter->second);
                magMap.insert(str);
                break;
            }

        }
    }

    cout << "Magic Word List "<< endl;
    cout << "Count: " << magMap.size()<< endl;
    for(iter = magMap.begin(); iter != magMap.end(); iter++) {

        cout << "Word: " << "" << iter->first<<"\t\t"
             << "Count: " << iter->second << endl;

    }
    cout<< endl;


    return 0;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: FinalP2.cpp Date: 12/19/2021
Student Name: Sri
----------------------------------------------


Unique Word List 
Count: 249
Word:           Count: 2
Word: I         Count: 1
Word: a         Count: 8
Word: about             Count: 2
Word: across            Count: 2
Word: after             Count: 1
Word: again             Count: 1
Word: alone             Count: 1
Word: already           Count: 1
Word: always            Count: 1
Word: an                Count: 1
Word: and               Count: 29
Word: angry             Count: 1
Word: another           Count: 1
Word: around            Count: 1
Word: as                Count: 4
Word: at                Count: 4
Word: back              Count: 1
Word: backed            Count: 1
Word: bank              Count: 1
Word: because           Count: 1
Word: been              Count: 1
Word: benevolent                Count: 1
Word: big               Count: 1
Word: block             Count: 1
Word: blotches          Count: 2
Word: boat              Count: 2
Word: boy               Count: 6
Word: boys              Count: 1
Word: brings            Count: 1
Word: brown             Count: 1
Word: but               Count: 5
Word: butchered         Count: 1
Word: came              Count: 1
Word: cancer            Count: 1
Word: carried           Count: 1
Word: carry             Count: 2
Word: caught            Count: 3
Word: cheeks            Count: 1
Word: cheerful          Count: 1
Word: cl                Count: 1
Word: coiled            Count: 1
Word: color             Count: 1
Word: come              Count: 1
Word: cords             Count: 1
Word: could             Count: 1
Word: cove              Count: 1
Word: current           Count: 1
Word: cut               Count: 2
Word: day               Count: 3
Word: days              Count: 4
Word: deep              Count: 1
Word: deep-creased              Count: 1
Word: defeat            Count: 1
Word: definitely                Count: 1
Word: depths            Count: 1
Word: desert            Count: 1
Word: did               Count: 1
Word: down              Count: 2
Word: drifted           Count: 1
Word: dropped           Count: 1
Word: each              Count: 2
Word: east              Count: 1
Word: edge              Count: 1
Word: eighty-four               Count: 1
Word: eighty-seven              Count: 1
Word: either            Count: 1
Word: empty             Count: 1
Word: end               Count: 1
Word: erosions          Count: 1
Word: every             Count: 1
Word: everything                Count: 1
Word: except            Count: 1
Word: eyes              Count: 1
Word: face              Count: 1
Word: factory           Count: 2
Word: faint             Count: 1
Word: finally           Count: 1
Word: fins              Count: 1
Word: first             Count: 2
Word: fish              Count: 7
Word: fished            Count: 1
Word: fishermen         Count: 3
Word: fishless          Count: 1
Word: flag              Count: 1
Word: flesh             Count: 1
Word: flour             Count: 1
Word: for               Count: 3
Word: form              Count: 1
Word: forty             Count: 2
Word: fresh             Count: 1
Word: from              Count: 4
Word: full              Count: 1
Word: fun               Count: 1
Word: furled            Count: 2
Word: gaff              Count: 1
Word: gaunt             Count: 1
Word: go                Count: 1
Word: gone              Count: 2
Word: good              Count: 2
Word: gulf              Count: 1
Word: had               Count: 12
Word: handling          Count: 1
Word: hands             Count: 1
Word: harbour           Count: 1
Word: harpoon           Count: 1
Word: hauled            Count: 1
Word: havana            Count: 1
Word: he                Count: 4
Word: heavy             Count: 1
Word: help              Count: 1
Word: hides             Count: 1
Word: him               Count: 7
Word: his               Count: 6
Word: hoisted           Count: 1
Word: house             Count: 1
Word: how               Count: 1
Word: ice               Count: 1
Word: imbed             Count: 1
Word: in                Count: 10
Word: into              Count: 2
Word: is                Count: 1
Word: it                Count: 4
Word: its               Count: 1
Word: laid              Count: 1
Word: length            Count: 1
Word: like              Count: 1
Word: lines             Count: 2
Word: livers            Count: 1
Word: looked            Count: 2
Word: loved             Count: 1
Word: lucky             Count: 1
Word: made              Count: 3
Word: man               Count: 7
Word: many              Count: 1
Word: market            Count: 1
Word: marlin            Count: 1
Word: mast              Count: 1
Word: men               Count: 1
Word: money             Count: 1
Word: neck              Count: 1
Word: no                Count: 1
Word: none              Count: 1
Word: north             Count: 1
Word: not               Count: 2
Word: now               Count: 2
Word: odour             Count: 1
Word: of                Count: 14
Word: off               Count: 2
Word: old               Count: 9
Word: older             Count: 1
Word: on                Count: 7
Word: ones              Count: 1
Word: only              Count: 1
Word: or                Count: 1
Word: orders            Count: 1
Word: other             Count: 1
Word: others            Count: 1
Word: out               Count: 2
Word: parents           Count: 1
Word: patched           Count: 1
Word: permanent         Count: 1
Word: plank             Count: 1
Word: planks            Count: 1
Word: pleasant          Count: 1
Word: politely          Count: 1
Word: ran               Count: 1
Word: reflection                Count: 1
Word: remember          Count: 1
Word: removed           Count: 1
Word: sacks             Count: 1
Word: sad               Count: 2
Word: said              Count: 2
Word: sail              Count: 2
Word: salao             Count: 1
Word: salting           Count: 1
Word: same              Count: 1
Word: santiago          Count: 1
Word: sat               Count: 1
Word: scars             Count: 2
Word: sea               Count: 2
Word: see               Count: 1
Word: seen              Count: 1
Word: shark             Count: 2
Word: sharks            Count: 1
Word: show              Count: 1
Word: side              Count: 1
Word: sides             Count: 1
Word: skiff             Count: 3
Word: skin              Count: 1
Word: skinned           Count: 1
Word: smell             Count: 1
Word: some              Count: 1
Word: spoke             Count: 1
Word: staggering                Count: 1
Word: stay              Count: 1
Word: steady            Count: 1
Word: stream            Count: 1
Word: strips            Count: 1
Word: successful                Count: 1
Word: sun               Count: 1
Word: sunny             Count: 1
Word: tackle            Count: 1
Word: taken             Count: 1
Word: taking            Count: 1
Word: taught            Count: 1
Word: terrace           Count: 2
Word: that              Count: 3
Word: the               Count: 58
Word: their             Count: 7
Word: them              Count: 4
Word: then              Count: 2
Word: there             Count: 1
Word: these             Count: 1
Word: they              Count: 10
Word: thin              Count: 1
Word: those             Count: 1
Word: three             Count: 2
Word: to                Count: 8
Word: today             Count: 1
Word: told              Count: 1
Word: tropic            Count: 1
Word: truck             Count: 1
Word: two               Count: 2
Word: undefeated                Count: 1
Word: unlucky           Count: 1
Word: up                Count: 1
Word: waited            Count: 1
Word: was               Count: 11
Word: we                Count: 1
Word: weather           Count: 1
Word: week              Count: 1
Word: weeks             Count: 1
Word: well              Count: 1
Word: went              Count: 2
Word: were              Count: 8
Word: weve              Count: 1
Word: what              Count: 1
Word: when              Count: 1
Word: where             Count: 3
Word: which             Count: 2
Word: who               Count: 2
Word: wind              Count: 2
Word: with              Count: 8
Word: without           Count: 3
Word: worst             Count: 1
Word: wrinkles          Count: 1
Word: you               Count: 2
Word: youre             Count: 1



Magic Word List
Count: 20
Word: I         Count: 1
Word: and               Count: 29
Word: big               Count: 1
Word: boat              Count: 2
Word: boy               Count: 6
Word: days              Count: 4
Word: eyes              Count: 1
Word: fish              Count: 7
Word: he                Count: 4
Word: ice               Count: 1
Word: man               Count: 7
Word: money             Count: 1
Word: of                Count: 14
Word: old               Count: 9
Word: sea               Count: 2
Word: the               Count: 58
Word: they              Count: 10
Word: week              Count: 1
Word: weeks             Count: 1
Word: wind              Count: 2
*/