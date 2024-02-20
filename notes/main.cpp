#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

bool verbose = false;
//if(verbose) will remove the debugging outputs 

int main(int argc, char* argv[]){ //char** argv is a null character, an array of character pointers, he took away one of the stars
//first pointer is an array of pointers
//argc is haow many parameters are passed 
    afstream filestream;
    
    filestream.open("JourneyToTheCenterofTheEarth.txt");
    
    


char c = 'z';
int k = 10;

if(c >= 'A' && c<= 'z'){
    cout<<(char)((((c + k)- 65)% 26)+ 65)<<endl;  //%creates a wrap around for the alphabet
}else{
    cout<<(char)((((c + k)- 97)% 26)+ 97)<<endl;
}


for(int i = 0; i<argc; i++){
    cout<<argv[i]<<endl;

    if(argv[i])[0] == '-'){
        if(argv[i])[1] == 'v'{//adding -v will show debugging 
        verbose = true;
        }//argv is an array of pointers
        
    }
    if(strcmp(argv[i],"--verbose")==0){
        verbose = true
    }

}//parcing is reading an array and pulling bits from it 

return 0;
}

