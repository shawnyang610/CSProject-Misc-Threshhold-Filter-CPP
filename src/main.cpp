//  CS780-37 Project 1.3 Calculating ThreshHold Value
//  Shawn Yang

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string infileName;
    string outfileName;
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    std::ifstream infile;
    std::ofstream outfile;
    int threshValue;
    int pixelValue;
    string threshValueStr;
    
    if (argc !=2){
        cout<<"Please supply input file."<<endl;
        return 1;
    }
    //step0
    infileName = argv[1];
    try {
        infile.open(infileName.c_str());
    } catch (exception* e ){
        cout<<"error opening inputfile"<<endl;
        return 1;
    }
    //step1, read header from infile
    infile>> numRows >> numCols >> minVal >> maxVal;
    //step2, get ThreshValue from user
    cout<<"Please enter a thresh hold value: ";
    cin>>threshValue;
    threshValueStr=to_string(threshValue);
    //step3 generate outfile name
    outfileName=infileName.substr(0,infileName.find_first_of("."));
    outfileName=outfileName+"_thr_"+threshValueStr+".txt";
    //step4 create/open outfile
    outfile.open(outfileName.c_str());
    //step5 write numRows, numCols, 0, 1 to outfile
    outfile<<numRows<<" "<<numCols<<" "<<"0 "<<"1"<<endl;
    //step6 process input
    for (int r=0; r<numRows; r++){
        for (int c=0; c<numCols; c++){
            infile>>pixelValue;
            if (pixelValue>=threshValue)
                outfile<<1<<" ";
            else
                outfile <<0<<" ";
        }
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
