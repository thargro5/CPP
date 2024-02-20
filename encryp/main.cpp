

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool verbose = false;
bool encrypt = false;
bool decrypt = false;
//if(verbose) will remove the debugging outputs 
string cypher(string textnum, int x, bool d){
            
            if(d) x = -x;
                for(int i = 0; i < textnum.length(); i++){
                    int deg = int(textnum[i]);
                    if(verbose)cout << "here"<<endl;
                    
                    if(deg >= int('a') && deg <= int('z')){
                        deg = deg + x;
                      
                    }
                    if(verbose)cout<<"here"<<endl;
                    
                    if(deg >= int('A') && deg <= int('Z')){
                        deg = deg + x;
                        
                        
                    }
                
                textnum[i] = char(deg);
                }
            return textnum;
        }
        
        
int main(int argc, char* argv[]){ //char** argv is a null character, an array of character pointers, he took away one of the stars
//first pointer is an array of pointers
//argc is haow many parameters are passed 
    string in = "";
    string out = "";
    char dash = '-';
    int num = 0;
    int key = 0;
    
    if(argc < 8){
        cout << "not enough arguments"<<endl;
        if(verbose)cout<<"here"<<endl;
        return 0;
        }else{
            for(int i = 0; i < argc; i++){
                if(strcmp(argv[i],"-i")== 0){
                    
                    if(argv[i + 1][0]!= dash){
                        in = argv[i + 1];
                        cout<<"In file: "<<in<<endl;
                    }
                }
                if(strcmp(argv[i],"-o")== 0){
                    
                    if(argv[i + 1][0]!= dash){
                        out = argv[i + 1];
                        cout<<"Out file: "<<out<<endl;
                    }
                }
                
                if(strcmp(argv[i],"-e")==0){
                    encrypt = true;
                    
                }
                
                if(strcmp(argv[i],"-d")==0){
                    decrypt = true;
                    
                }
                
                if(strcmp(argv[i],"-k")==0){
                    key = atoi(argv[i + 1]);
                    
                }
                
                
                
            }
            
        }
        
        
        
        
        ifstream filein;
        filein.open(in);
        
        string temp;
        string text;
        
        while(!filein.eof()){
            getline(filein, temp);
            text = text + temp;
            text = text + '\n';
            
        }
        
        text = cypher(text, key, decrypt);
        
        ofstream fileout;
        fileout.open(out);
        
        fileout << text;
        

filein.close();
fileout.close();
return 0;
}

