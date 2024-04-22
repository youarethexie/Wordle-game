#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <map>
#include <list>
#include <random>
using namespace std;
string ans_list[12];//NEVER USE GLOBAL VARIABLES!!!
int ans_ct; //SEE ABOVE
//void readandwriteFile(string fn);

struct dictPair{
    string dictword;
    int wordInt;
};
bool operator<(const dictPair& a, const dictPair& b) {
    return a.dictword < b.dictword;
}
bool loaddict(const string & file, map<dictPair, string> & mydict){
    string word;
    //ifstream filed(file);
    ifstream filed{file};
    if (!filed.is_open()) {
        cout << "Error in file opening!" << endl;
        //ofstream file_writer(file);
        //exit(1);
        return false;
    }
    
    int num=0;
    dictPair d;
    if(filed.is_open()){
        while (getline(filed, word)){
            if((word.length() == 5) && !isupper(word[0])){
                d.wordInt = num;
                d.dictword = word;
                mydict[d] = d.wordInt;
                num++;
            }
        }
    }

    cout << num << endl;
    filed.close();
    return true;
}
void toLowerCase(string & input){
    for (int i=0; i<5; i++){
        if (input[i] < 97){
            input[i] = input[i]+32;
        }
    }
}

dictPair generateword(map<dictPair, string> & mapdict){
    dictPair d;
    int N = mapdict.size()-1;
    int num = 0;
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<int> dist(1,N);
    num = dist(e2);
    d.wordInt = num;
    for(std::map<dictPair, string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){
        dictPair k =  iter->first;
        if(k.wordInt == num){
            string word = k.dictword;
            d.dictword = word;
            cout << d.dictword << " " << d.wordInt << endl;
        }
        //ignore value
        //Value v = iter->second;
    }
    return d;
}

bool isValid(string input){
    if((input.length() > 5) || (input.length() < 5)){
        return false;
    }
    for (int i=0;i<5;i++){
        if ((input[i]<97) || (input[i]>122)){
            return false;
        }
    }
    return true;
}

bool testingdoWordsMatch(string s1, string s2){
    if (s1 == s2){
        return true;
    }
    return false;
};
void testingfindGs(string s1,string s2, vector<char> & charword, vector<bool> & found){
    for (int i=0; i<5; i++){
        if (s1[i] == s2[i]){
            charword[i] = 'G';
            found[i] = true;
        }
        else{
            charword[i] = ' ';
            found[i] = false;
        }
    }
};
void charprinting(vector<char> & charr){
    for (int i=0; i<5; i++){
        cout << charr[i] << " ";
    }
    cout << endl;
}

void boolprinting(vector<bool> & found){
    for (int i=0; i<5; i++){
        cout << found[i] << " ";
    }
    cout << endl;
}
void wordprinting( string line){
    for (int i=0; i<5; i++){
        cout << line[i] << " ";
    }
    cout << endl;
}
void testingfindYs(string s1,string s2, vector<char> & charr, vector<bool> & found){
    for(int i=0; i<5; i++){
        for(int a=0; a<5; a++){
            if((s1[i] == s2[a]) && (charr[i] != 'G')){
                charr[i] = 'Y';
                found[a] = true;
                for (int j=0; j<5; j++){
                    if((s2[a] == s2[j]) && (a > j)){
                        found[a] = false;
                    }
                }            
            }
        }
    }
}
void testingfindYys(string s1,string s2, vector<char> & charr, vector<bool> & found){
    for(int s=0; s<5; s++){
        for (int g=0; g<5; g++){
            if (((s1[s] == s1[g]) && (s!=g)) && ((charr[s] == 'Y') && (charr[g] == 'G'))){
                charr[s] = ' ';
                cout << "remove y because g" << endl;
            }
            else if (((s1[s] == s1[g]) && (g > s)) && ((charr[s] == 'Y') && (charr[g] == 'Y'))){
                charr[g] = ' ';
                cout << "remove y because y" << endl;
            }
        }
    }
};
int getSize(string fn){
return 0;
};
void readFile(string fn, string arr[], int num_words){

};
void playwordle(string word, string input, vector<vector<char>> & charr, vector<vector<bool>> & found, int currentTry){
    for(int i=0; i<5; i++){
        if(i == currentTry){
            vector<char> charrword;
            vector<bool> foundword;
            for (int s=0; s<5; s++){
                charrword.push_back('\0');
                foundword.push_back(0);
            }
            charr.push_back(charrword);
            found.push_back(foundword);

            testingfindGs(word, input, charrword, found[i]);
            testingfindYs(word, input, charrword, found[i]);
            testingfindYys(word, input, charrword, found[i]);
            wordprinting(word);
            wordprinting(input);
            charprinting(charrword);
            boolprinting(found[i]);
            
        }
    }
};
string getWord(int num, string arr[]){
return 0;
};
bool startGuessing(string curr_word){
return 0;
};
void printResults(vector<vector<char>> & charr, vector<string> tries){
    //cout << charr.size() << endl;
    cout << "*********************" << endl;
    for (int i=0; i<charr.size(); i++){
        for(int s=0; s<charr[i].size(); s++){
            cout << "|";
            char operation;
            switch(operation)
            {
                case 'G': system("Color 20"); break;
                case 'Y': system("Color 60"); break;
                case '\0': system("Color 80"); break;
            }
            cout << " " << tries[i][s] << " |";
            system("Color 70");
        }
        cout << endl;
    }
    cout << "*********************" << endl;
};
bool dictword(string curr_word, map<dictPair, string> & mapdict){
    std::map<dictPair,string>::iterator it;
    dictPair d;
    for(std::map<dictPair, string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){
        dictPair k =  iter->first;
        if(k.dictword == curr_word){
            d.wordInt = k.wordInt;
            d.dictword = curr_word;
            //cout << d.dictword << " " << d.wordInt << endl;
        }
        //ignore value
        //Value v = iter->second;
    }
    return mapdict.count(d);
};
bool doWordsMatch(string guess, string curr_word);
bool findGs(vector<char> & charword, vector<bool> & foundword){
    int numGs = 0;
    for(int i=0; i<5; i++){
        if((charword[i] == 'G') && (foundword[i] = 1)){
            numGs++;
        };
    }
    if(numGs == 5){return true;}
    return false;
};
void findYs(string guess, string curr_word,char ans[], bool found[]){
    int numys = 0;
    for(int i=0; i<5; i++){
        if(ans[i] == 'Y'){
            numys++;
            found[i] = true;
        };
    }
};
void reset_ans_list(){};


int main() {
    bool match;
    int len_of_words = 5;
    int num_of_tries = 6;
    int currentTry = 0;

    vector <vector<char>> charr;
    vector <vector<bool>> found;

    list <string> tries;
    string input1, input2, word;
    map<dictPair, string> mydict;
    string filepath = "/usr/share/dict/words";
    bool b = loaddict(filepath, mydict);
    if (b){
        dictPair word_int = generateword(mydict);
        word = word_int.dictword;
        toLowerCase(word);
        cout << "word " << word << endl;
        }
    else {
        cout << "cannot add " << endl;
    }

    while(input1 != "Q"){
        do{
            cout << "Would you like to start playing Wordle? Type Y to start or Q to quit: ";
            getline(cin, input1);
        }while(input1 != "Y" && input1 != "Q");
        if(input1 == "Q"){
            break;
        }
        if(input1 == "Y"){
            currentTry = 0;
            cout << "y" << endl;
            while(currentTry < num_of_tries){
                do{
                    cout << "Please enter your guess (word length must be 5) or type Q to quit: ";
                    getline(cin, input2);
                    if(input2 == "Q"){
                        break;
                    }
                    toLowerCase(input2);
                    while(!dictword(input2, mydict)){
                        cout << "Please enter a valid word found in the dictionary: " ;
                        getline(cin, input2);
                    };
                    tries.push_back(input2);
                    bool match = testingdoWordsMatch(word, input2);
                    cout << match << endl;
                    if(match){
                        break;
                    }
                    playwordle(word, input2, charr, found, currentTry);
                }while(!isValid(input2));
                if(input2 == "Q"){
                    break;
                }
                if(match == 1){
                    break;
                }
                currentTry++;
            }
            if(input2 == "Q"){
                    break;
            }
            if(match == 1){
                    break;
            }
        }
    };
    //printResults(charr);
    
    for (int i=0; i<tries.size(); i++){
        cout << tries.front() << ' ';
        tries.push_back(tries.front());
        tries.pop_front();
    }
    cout << endl;
    return 0;

}
