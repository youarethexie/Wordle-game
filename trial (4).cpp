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

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */

#define B_BLACK   "\033[40m"    /* Black */
#define B_RED     "\033[41m"    /* Red */
#define B_GREEN   "\033[42m"    /* Green */
#define B_YELLOW  "\033[43m"    /* Yellow */
#define B_BLUE    "\033[44m"    /* Blue */
#define B_MAGENTA "\033[45m"    /* Magenta */
#define B_CYAN    "\033[46m"    /* Cyan */
#define B_WHITE   "\033[47m"    /* White */
#define B_GRAY "\033[47m"      /* Gray */

#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#define DIMBLACK "\033[2m\033[30m"    /* Dim Black */
#define DIMRED "\033[2m\033[31m"      /* Dim Red */
#define DIMGREEN "\033[2m\033[32m"    /* Dim Green */
#define DIMYELLOW "\033[2m\033[33m"   /* Dim Yellow */
#define DIMBLUE "\033[2m\033[34m"     /* Dim Blue */
#define DIMMAGENTA "\033[2m\033[35m"  /* Dim Magenta */
#define DIMCYAN "\033[2m\033[36m"     /* Dim Cyan */
#define DIMWHITE "\033[2m\033[37m"    /* Dim White */
#define MOVEUP "\033["                /* add integer, and add F */
#define ERASELINE "\033[2K"           /* erase current line */

struct dictPair{
    string dictword;
    int wordInt;
};
bool operator<(const dictPair& a, const dictPair& b) {
    return a.dictword < b.dictword;
}
bool loaddict(const string & file, map<dictPair, string> & mydict){
    string word;
    ifstream filed{file};
    if (!filed.is_open()) {
        cout << "Error in file opening!" << endl;
        exit(1);
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
        }
    }
};
int getSize(string fn){
return 0;
};
void readFile(string fn, string arr[], int num_words){

};
void playwordle(string word, string input, vector<vector<char>> & charr, vector<vector<bool>> & found, int currentTry, vector<string> & tries){
    for(int i=0; i<6; i++){
        if(i == currentTry){
            int bsize = charr.size(), asize = 0;
            vector<char> charrword;
            vector<bool> foundword;
            for (int s=0; s<5; s++){
                charrword.push_back('\0');
                foundword.push_back(0);
            }
            charr.push_back(charrword);
            found.push_back(foundword);
            asize = charr.size();
            tries.push_back(input);
            cout << "b " << bsize << " a " << asize << endl;
            testingfindGs(word, input, charr[i], found[i]);
            testingfindYs(word, input, charr[i], found[i]);
            testingfindYys(word, input, charr[i], found[i]);
            //wordprinting(word);
            //wordprinting(input);
            //charprinting(charr[i]);
            //boolprinting(found[i]);
        }
    }
};
string getWord(int num, string arr[]){
return 0;
};
bool startGuessing(string curr_word){
return 0;
};
void printResults(vector<vector<char>> & charr, vector<vector<bool>> & found, vector<string> & tries){
    //cout << charr.size() << endl;
    cout << "*************************" << endl;
    for (int i=0; i<charr.size(); i++){
        for(int s=0; s<charr[i].size(); s++){
            cout << "| ";
            
            if((charr[i][s] == 'G') && (found[i][s] == 1)){
                cout << BLACK << B_GREEN;
            }
            else if((charr[i][s] != 'G') && (found[i][s] == 1)){
                cout << BLACK << B_YELLOW;
            }
            else{
                cout << BLACK << B_GRAY;
            }
            cout << tries[i][s] << RESET << " |" ;
        }
        cout << endl << "*************************" << endl;
    }
    
};
bool dictword(string curr_word, map<dictPair, string> & mapdict){
    std::map<dictPair,string>::iterator it;
    dictPair d;
    for(std::map<dictPair, string>::iterator iter = mapdict.begin(); iter != mapdict.end(); ++iter){
        dictPair k =  iter->first;
        if(k.dictword == curr_word){
            d.wordInt = k.wordInt;
            d.dictword = curr_word;
        }
        //ignore value
        //Value v = iter->second;
    }
    return mapdict.count(d);
};
bool doWordsMatch(string guess, string curr_word);
bool findGs(vector<char> & charword, vector<bool> & foundword){
    int numGs = 0;
    for(int i=0; i<charword.size(); i++){
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
    int num_of_games = 0;

    vector <vector<char>> charr;
    vector <vector<bool>> found;

    vector <string> tries;
    string input1, input2, word;
    map<dictPair, string> mydict;
    string filepath = "/usr/share/dict/words";
    bool b = loaddict(filepath, mydict);

    while(input1 != "Q"){
        do{
            if(num_of_games > 0){
                input1 = "Y";
                continue;
            }
            cout << "Would you like to start playing Wordle? Type Y to start or Q to quit: ";
            getline(cin, input1);
        }while(input1 != "Y" && input1 != "Q");
        if(input1 == "Q"){
            break;
        }
        if(input1 == "Y"){
            dictPair word_int = generateword(mydict);
            word = word_int.dictword;
            toLowerCase(word);
            currentTry = 0;
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
                }while(!isValid(input2));
                if(input2 == "Q"){
                    break;
                }
                match = testingdoWordsMatch(word, input2);
                playwordle(word, input2, charr, found, currentTry, tries);
                printResults(charr, found, tries);
                currentTry++;
                if(match == 1){
                    if(currentTry == 1){    
                        cout << "You got the answer with only " << currentTry << "try !" << endl;
                    }
                    cout << "You got the answer in " << currentTry << "tries !" << endl;
                    switch(currentTry){
                        case 1: cout << "Genius!"; break;
                        case 2: cout << "Magnificent!"; break;
                        case 3: cout << "Impressive!"; break;
                        case 4: cout << "Splendid!"; break;
                        case 5: cout << "Great!"; break;
                        case 6: cout << "Phew!"; break;
                    }
                    cout << endl;
                    break;
                }
            }
            if(input2 == "Q"){
                break;
            }
            if(match == 1){
                string input3;
                do{
                    cout << "Would you like to play again? Enter Y for yes and Q for no: " << endl;
                    getline(cin, input3);
                }while(input1 != "Y" && input1 != "Q");
                if(input3 == "Y"){
                    currentTry = 0;
                    tries.clear();
                    found.clear();
                    charr.clear();
                    num_of_games += 1;
                    continue;
                }
                else if(input3 == "Q"){
                    break;
                }
            }
        }
    cout << "Bye!" << endl;
    };
    
    for (int i=0; i<tries.size(); i++){
        //cout << tries[i] << ' ';
    }
    //cout << endl;
    return 0;
}
