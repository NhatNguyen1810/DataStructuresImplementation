#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct ShipRecord
{
    int serialNum;
    int shipType;
    string name;
    int year;
    int cap;
    ShipRecord* link;
};

const int SIZE = 10;
class HashMgr {
    private:
        ShipRecord* hashTable[SIZE] = {nullptr};


    public:
        HashMgr() {
            string line;
            ifstream myfile;
             myfile.open("/Users/nguyennhat/Desktop/hwhash/shipRecords.txt");
             if(myfile.is_open())
             {
                while (!myfile.eof()) {
                    getline (myfile, line);
                    addInfo(line);
                }
                myfile.close();
             }
        }


     ~HashMgr(){


         for(int i = 0 ; i < SIZE ; i++){
            if(hashTable[i] != nullptr){
                ShipRecord* current = hashTable[i];
                ShipRecord* next;
                while(current != nullptr){
                    next = current->link;
                    delete current;

                    cout << "The ship with " << current->serialNum << " is deleted"<< endl;
                    current = next;
                }

                hashTable[i] = nullptr;


            }
         }

     }


    void addInfo(string str){

        string tmp = "";

        vector<string> res ;

        bool hasQuote = false;
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == ' ' && i == 0){
                continue;
            } //for leading blanks

            else if( str[i] == ' ' && (str[i+1] == '\"' || str[i-1] == '\"') && i < str.size() - 1){
                continue;
            } //leading blanks and taling blankls for takens, blanks between tokens
            else if(str[i] == ' ' && (str[i-1] == ' ') && i < str.size() - 1){
                continue;
            } //redundant blanks between words, only the first blank is needed.


            else if (str[i] == '\"' && tmp.compare("") == 0){
                hasQuote = true;// to make sure that will print some words on the same line

                continue;

            }// first double quote, starting a new token

            else if(str[i] == '\"' && tmp.compare("") != 0 && hasQuote == true){


                    res.push_back(tmp);
                    tmp = "";

                    hasQuote = false;//start new token
                    continue;
            }//ending quote, print then reset

            else if(str[i] == '\"' && tmp.compare("") != 0 && hasQuote == false){



                     res.push_back(tmp);
                    tmp = "";
                    hasQuote = true;//start new token
                    continue;
            }//start a quote token but there is a word without blank before it

            else if(str[i] == ' ' && tmp.compare("") != 0  && hasQuote == false){

                res.push_back(tmp);
                tmp = "";
                continue;
            }//not contained in any quote, then print when facing a space


            else{
                tmp += str[i];

            }// add to the return string







        }



        if(tmp.compare("") != 0){
            res.push_back(tmp);

            tmp = "";
        }


        string serialNum = res.at(0);
        int serial = atoi(serialNum.c_str());
        int bucket = serial%10;
        if (hashTable[bucket] == nullptr){
            hashTable[bucket]= new ShipRecord();
            hashTable[bucket]->serialNum = serial;
            hashTable[bucket]->shipType = atoi(res[1].c_str());
            hashTable[bucket]->name = res[2];
            hashTable[bucket]->year = atoi(res[3].c_str());
            hashTable[bucket]->cap = atoi(res[4].c_str());
            hashTable[bucket]->link = nullptr;


        }
        else{

            ShipRecord* head = hashTable[bucket];
            while(head->link != nullptr){
                head = head->link;
            }
            ShipRecord* newNode = new ShipRecord();
            newNode->serialNum = serial;
            newNode->shipType = atoi(res[1].c_str());
            newNode->name = res[2];
            newNode->year = atoi(res[3].c_str());
            newNode->cap = atoi(res[4].c_str());
            newNode->link = nullptr;
            head->link = newNode;
        }

    }
    void displayOne(int serial){
        if (hashTable[serial%10 ] == nullptr){
            cout << "Nothing to display" << endl;
        }
        else{
            bool flag = false;
            ShipRecord* head = hashTable[serial%10 ];
            while(head != nullptr){
                if (head->serialNum == serial){
                    flag = true;
                    cout << head-> serialNum << " " << head->shipType << " " << head->name << " " << head->year << " " << head->cap << endl;
                }

                head = head->link;
            }
            if(flag == false){
                cout << "Nothing to display";
            }
        }
    }
    void displayAll(){
        for(int i = 0 ; i < SIZE ; i++){
            if(hashTable[i] != nullptr){
                cout << "Bucket " << i << endl;
                ShipRecord* head = hashTable[i];
                while(head != nullptr){
                    cout << head-> serialNum << " " << head->shipType << " " << head->name << " " << head->year << " " << head->cap << endl;
                    head = head->link;
                }
                cout << endl;
            }


        }
    };
    void deleteOne(int serial){
        bool flag = false;
        int seri = serial%10;
        if(hashTable[seri] != nullptr){
            ShipRecord* head = hashTable[seri];
            ShipRecord* prev;

            if(head != nullptr && head->serialNum == serial){
                hashTable[seri] = head->link;
                delete head;
                head = nullptr;
                return;
            }

            while(head != nullptr && head->serialNum !=serial){
                prev = head;
                head = head->link;
            }


            if(head == nullptr){
                return;
            }

            prev->link = head->link;

            delete head;
            head = nullptr;

        }
        if(flag == false){
            cout << "Nothing to delete"<< endl;
        }

    };



};






int main() {



    HashMgr hm;
    hm.displayAll();
    cout << endl;

    hm.displayOne(1009);
    hm.displayOne(1010);
    hm.displayOne(1019);
    hm.displayOne(1029);
    hm.displayOne(1039);
    hm.displayOne(1014);
    hm.displayOne(1008); /// Prompt a message to that the record does not exist
    cout << endl;



    hm.deleteOne(1009);
    hm.deleteOne(1039);
    hm.deleteOne(1039);// promt a message that says no data to delete

    cout << endl;

    hm.displayAll();// all the deleted ships are not displayed again in this function
    hm.~HashMgr();

    cout << endl;
    cout << "Trying to display again" << endl;
    hm.displayAll();// nopthinf displayed, then my algorithm inside the destructor works
    cout << "program ends here" << endl;
    return 0;


}





