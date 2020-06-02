/*
File	: jr494_project3.cpp
Author	: Jose Luis Rojas Salazar
Date	: 23/12/2013
Brief	: Design a program that will accept three input files:
          - pam250matrix.csv (a file containing the PAM250 scoring matrix
          - sequenceA.txt (amino acid input sequence A.)
          - sequenceB.txt (amino acid input sequence B.)
          Must compute the similarity graph and the dissimilarity score to write them
          in the OUTPUT.TXT file with the sequenceA and sequenceB.          
Built	: g++ jr494_project3.cpp -o jr494_project3.run
Execution:  ./jr494_project3.run
*/


#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;


int main()
{
    ifstream file("pam250matrix.csv");
    string value;
    char tabla[80][80][80]={""};//Will be use to represent a modified table of the file pam250matrix.csv so we can use the info provided in the file.


//Reading the info of the file pam250matrix.csv line by line

    string line1, line2, line3, line4, line5, line6, line7,
           line8, line9, line10, line11, line12, line13, line14,
           line15, line16, line17, line18, line19, line20, line0;
    fstream inputStream;
    inputStream.open("pam250matrix.csv");
    inputStream>>line0;
    inputStream>>line1;
    inputStream>>line2;
    inputStream>>line3;
    inputStream>>line4;
    inputStream>>line5;
    inputStream>>line6;
    inputStream>>line7;
    inputStream>>line8;
    inputStream>>line9;
    inputStream>>line10;
    inputStream>>line11;
    inputStream>>line12;
    inputStream>>line13;
    inputStream>>line14;
    inputStream>>line15;
    inputStream>>line16;
    inputStream>>line17;
    inputStream>>line18;
    inputStream>>line19;
    inputStream>>line20;
      
//Start to filling the 3D table named tabla[file][column][excess] cell by cell

    int f; 
    int p=0;
    int t=0;

    string line;

  for(int h=0;h<21;h++)
   {
    if(h==0)
     {
      line=line0;
      f=0;
      p=0;
      t=0;
     }
    else if(h==1)
     {
      line=line1;
      f=1;
      p=0;
      t=0;
     }
    else if(h==2)
     {
      line=line2;
      f=2;
      p=0;
      t=0;
     }
    else if(h==3)
     {
      line=line3;
      f=3;
      p=0;
      t=0;
     }
    else if(h==4)
     {
      line=line4;
      f=4;
      p=0;
      t=0;
     }
    else if(h==5)
     {
      line=line5;
      f=5;
      p=0;
      t=0;
     }
    else if(h==6)
     {
      line=line6;
      f=6;
      p=0;
      t=0;
     }
    else if(h==7)
     {
      line=line7;
      f=7;
      p=0;
      t=0;
     }
    else if(h==8)
     {
      line=line8;
      f=8;
      p=0;
      t=0;
     }
    else if(h==9)
     {
      line=line9;
      f=9;
      p=0;
      t=0;
     }
    else if(h==10)
     {
      line=line10;
      f=10;
      p=0;
      t=0;
     }
    else if(h==11)
     {
      line=line11;
      f=11;
      p=0;
      t=0;
     }
    else if(h==12)
     {
      line=line12;
      f=12;
      p=0;
      t=0;
     }
    else if(h==13)
     {
      line=line13;
      f=13;
      p=0;
      t=0;
     }
    else if(h==14)
     {
      line=line14;
      f=14;
      p=0;
      t=0;
     }
    else if(h==15)
     {
      line=line15;
      f=15;
      p=0;
      t=0;
     }
    else if(h==16)
     {
      line=line16;
      f=16;
      p=0;
      t=0;
     }
    else if(h==17)
     {
      line=line17;
      f=17;
      p=0;
      t=0;
     }
    else if(h==18)
     {
      line=line18;
      f=18;
      p=0;
      t=0;
     }
    else if(h==19)
     {
      line=line19;
      f=19;
      p=0;
      t=0;
     }
    else if(h==20)
     {
      line=line20;
      f=20;
      p=0;
      t=0;
     }
    else
     {      
      cout<<" ";
     }

//At this part each line have symbols as ',' or '-' and numbers so I will select what I need in my table tabla, I will choose positive numbers, - that represent negative numbers (for this project we need to know only if is negative,0 or positive) and the letters that represent the aminoacids in the first line and first column.


    for(int i=0;i<58;i++)
     {
      if (line[i]=='-')
       {        
        line0[i]='Z';
        tabla[f][p][t]=line[i];
        i=i+1;        
       }

      else if(line[i]=='\n'||line[i]=='\0')
       {
        p=p-1;
        break;
       }
      

      else if (line[i]==',')
       {
        p=p-1;                
       }
       
      else
       {        
        if(line[i-1]=='Z')
         {
          i=i+1;
          p=p-1;
         }
        else
         {            
          tabla[f][p][t]=line[i];
          t=t+1;
           if(line[i+1]=='0'||line[i+1]=='2'||line[i+1]=='7')
            {
             i=i+1;
            }

         }        
       }

      t=0;
      p=p+1;
      
     }

   }       
   

/*This was used to test the table so we have now an useful table to start to compute the project tasks.

for(int tb=0;tb<21;tb++)
 {
  cout<<endl;
  for(int tc=0;tc<58;tc++)
   {
    cout<<tabla[tb][tc][0]<<" ";
   }
 }


cout<<tabla[0][0][0]<<" "<<tabla[0][1][0]<<" "<<tabla[0][2][0]<<" "<<tabla[0][3][0]<<endl;
cout<<tabla[1][0][0]<<" "<<tabla[1][1][0]<<" "<<tabla[1][2][0]<<" "<<tabla[1][3][0]<<endl;
cout<<tabla[2][0][0]<<" "<<tabla[2][1][0]<<" "<<tabla[2][2][0]<<" "<<tabla[2][3][0]<<endl;
cout<<tabla[3][0][0]<<" "<<tabla[3][1][0]<<" "<<tabla[3][2][0]<<" "<<tabla[3][3][0]<<endl;

*/


//The table must look like a table or matrix of [21][21] elements*******************


char tablaout[80][80][80]={""};//I left[80][80][80] to experiment with more bigger tables 

for(int outi=0;outi<21;outi++)
 {
  for(int outh=0;outh<21;outh++)
   {
    tablaout[outi][outh][0]=tabla[outi][outh][0];
   }
 }


//Now is time to start to reading the files sequenceA.txt and sequenceB.txt

string sequenceA, sequenceB;

fstream inputStreamSeqA;
inputStreamSeqA.open("sequenceA.txt");

const int LENGTH=50;//The sequences are no more than 50 elements.

int lenSeqA=0;
int lenSeqB=0;

inputStreamSeqA>>sequenceA;

//cout<<"Sequence A: "<<sequenceA<<endl;//Used to check sequenceA.txt

for(int iSeqA=0;iSeqA<LENGTH;iSeqA++)//Used to calculate the length of sequenceA
{
 lenSeqA=iSeqA+1;
 if(sequenceA[lenSeqA]=='\0')
  {
   break;
  }
}


fstream inputStreamSeqB;
inputStreamSeqB.open("sequenceB.txt");


inputStreamSeqB>>sequenceB;

//cout<<"Sequence B: "<<sequenceB<<endl;//Used to check sequenceB.txt

for(int iSeqB=0;iSeqB<LENGTH;iSeqB++)//Used to calculate the length of sequenceB
{
 lenSeqB=iSeqB+1;
 if(sequenceB[lenSeqB]=='\0')
  {
   break;
  }
}

//cout<<"Longitud del sequenceA es: "<<lenSeqA<<endl;//test length of sequenceA.txt
//cout<<"Longitud del sequenceB es: "<<lenSeqB<<endl;//test length of sequenceB.txt


//Passing the sequences A and B to arrays type char

char sequenceAchar[lenSeqA];

for(int m=0;m<lenSeqA;m++)
{
 sequenceAchar[m]=sequenceA[m];
}

sequenceAchar[lenSeqA]='\0';//************************************

//cout<<"SequenceAchar:"<<sequenceAchar<<endl;//Used for testing.

char sequenceBchar[lenSeqB];

for(int z=0;z<lenSeqB;z++)
{
 sequenceBchar[z]=sequenceB[z];
}

sequenceBchar[lenSeqA]='\0';//*************************************

//cout<<"SequenceBchar:"<<sequenceBchar<<endl;//Used for testing.
//cout<<endl;

//The project have a validation condition about the lenght of sequenceA and sequenceB

//Precondition:The length of each amino acid sequence to be processed must be not more
//than 50 characters or must have equal lenght to be processed.If they are not, print
//an error message.

//Post-condition:The lenght of both sequences were validated and will proceed to
//compute the project3 tasks.

if(lenSeqA==lenSeqB)
{
 //cout<<"Esta OK ve a la parte del procesamiento"<<endl;
 goto procesamiento;
}

else
{
 cerr<<"Length of sequenceA and sequenceB are not equal"<<endl;
 return 0;//goto salida;
}

procesamiento:

//cout<<"Estan aprobados para procesamiento"<<endl;

//OJO:Both sequences have the same length so we can process them
char graphout[80][80][80]={""};//********************************
int agraph[80]={0};
int bgraph[80]={0};
int cgraph=0;

//cout<<"Aqui se jode"<<endl;


//To pick up values from the modified table tabla is necessary to pass the letters that represent the aminoacids from the files sequenceA and sequenceB to values of type integer to be used as indexes for the table. 

for(int graph=0;graph<lenSeqA;graph++)
{
 
   if(sequenceAchar[graph]=='A'){
     agraph[graph]=1;}
   if(sequenceBchar[graph]=='A'){
     bgraph[graph]=1;}
   if(sequenceAchar[graph]=='R'){
     agraph[graph]=2;}
   if(sequenceBchar[graph]=='R'){
     bgraph[graph]=2;}
   if(sequenceAchar[graph]=='N'){
     agraph[graph]=3;}
   if(sequenceBchar[graph]=='N'){
     bgraph[graph]=3;}
   if(sequenceAchar[graph]=='D'){
     agraph[graph]=4;}
   if(sequenceBchar[graph]=='D'){
     bgraph[graph]=4;}
   if(sequenceAchar[graph]=='C'){
     agraph[graph]=5;}
   if(sequenceBchar[graph]=='C'){
     bgraph[graph]=5;}
   if(sequenceAchar[graph]=='Q'){
     agraph[graph]=6;}
   if(sequenceBchar[graph]=='Q'){
     bgraph[graph]=6;}
   if(sequenceAchar[graph]=='E'){
     agraph[graph]=7;}
   if(sequenceBchar[graph]=='E'){
     bgraph[graph]=7;}
   if(sequenceAchar[graph]=='G'){
     agraph[graph]=8;}
   if(sequenceBchar[graph]=='G'){
     bgraph[graph]=8;}
   if(sequenceAchar[graph]=='H'){
     agraph[graph]=9;}
   if(sequenceBchar[graph]=='H'){
     bgraph[graph]=9;}
   if(sequenceAchar[graph]=='I'){
     agraph[graph]=10;}
   if(sequenceBchar[graph]=='I'){
     bgraph[graph]=10;}
   if(sequenceAchar[graph]=='L'){
     agraph[graph]=11;}
   if(sequenceBchar[graph]=='L'){
     bgraph[graph]=11;}
   if(sequenceAchar[graph]=='K'){
     agraph[graph]=12;}
   if(sequenceBchar[graph]=='K'){
     bgraph[graph]=12;}
   if(sequenceAchar[graph]=='M'){
     agraph[graph]=13;}
   if(sequenceBchar[graph]=='M'){
     bgraph[graph]=13;}
   if(sequenceAchar[graph]=='F'){
     agraph[graph]=14;}
   if(sequenceBchar[graph]=='F'){
     bgraph[graph]=14;}
   if(sequenceAchar[graph]=='P'){
     agraph[graph]=15;}
   if(sequenceBchar[graph]=='P'){
     bgraph[graph]=15;}
   if(sequenceAchar[graph]=='S'){
     agraph[graph]=16;}
   if(sequenceBchar[graph]=='S'){
     bgraph[graph]=16;}
   if(sequenceAchar[graph]=='T'){
     agraph[graph]=17;}
   if(sequenceBchar[graph]=='T'){
     bgraph[graph]=17;}
   if(sequenceAchar[graph]=='W'){
     agraph[graph]=18;}
   if(sequenceBchar[graph]=='W'){
     bgraph[graph]=18;}
   if(sequenceAchar[graph]=='Y'){
     agraph[graph]=19;}
   if(sequenceBchar[graph]=='Y'){
     bgraph[graph]=19;}
   if(sequenceAchar[graph]=='V'){
     agraph[graph]=20;}
   if(sequenceBchar[graph]=='V'){
     bgraph[graph]=20;}
  
}

//Precondition: Comparing each character of sequenceA and sequenceB that have the
//same position to select the symbol for the similarity graph.

//Post-condition:Get the similarity graph based in the values of the table obtained
//from the file pam250matrix.csv 


//Once we have the values from the table tabla we represent them as |,.,:,x 

for(int final=0;final<lenSeqA;final++)
{
 if(sequenceBchar[final]==sequenceAchar[final])
  {
   tablaout[final][final][0]='|';
  }
 else if(tablaout[bgraph[final]][agraph[final]][0]=='0')
  {
   tablaout[final][final][0]='.';
  }
 else if(tablaout[bgraph[final]][agraph[final]][0]=='-')
  {
   tablaout[final][final][0]='x';
  }
 else
  {
   tablaout[final][final][0]=':';
  }
}

tablaout[lenSeqA][lenSeqA][0]='\0';
tablaout[lenSeqA][lenSeqA][lenSeqA]='\0';


//Now we can calculate dissimilarity score.

//Precondition: Read the quantity of ':' and 'x' in the similarity graph
//to compute the dissimilarity score.

//Post-condition: Compute the dissimilarity score as a value type double.


int colon=0;
int exes=0;
double dissimilarity=0.0;

for(int dissi=0;dissi<lenSeqA;dissi++)
{
 if(tablaout[dissi][dissi][0]==':')
  {
   colon=colon+1;
  }

 if(tablaout[dissi][dissi][0]=='x')
  {
   exes=exes+1;
  }
}

dissimilarity=((1.5*colon)+(3*exes))/(3*lenSeqA);

//cout<<"Dissimilarity score: "<<dissimilarity<<endl;

char secondline[lenSeqA];//The array second line will be used to send the info or line of symbols to the second line of the output file.

for(int linetwo=0;linetwo<lenSeqA;linetwo++)
{
 if(tablaout[linetwo][linetwo][0]=='|')
   {
    secondline[linetwo]='|';
   }
 if(tablaout[linetwo][linetwo][0]==':')
   {
    secondline[linetwo]=':';
   }
 if(tablaout[linetwo][linetwo][0]=='.')
   {
    secondline[linetwo]='.';
   }
 if(tablaout[linetwo][linetwo][0]=='x')
   {
    secondline[linetwo]='x';
   }
}

secondline[lenSeqA]='\0';

//Writting the info requested line by line in the output file

//Precondition: The similarity graph and the dissimilarity score were computed
//and must been write in the OUTPUT.TXT file.

//Post-condition: After run the program the OUTPUT.TXT file must have 4 lines:
//Fisrt line: sequenceA
//Second line: similarity graph
//Third line: sequenceB
//Fourth line: dissimilarity score.

ofstream outFile;

outFile.open("OUTPUT.TXT");
outFile<<sequenceAchar<<endl;
outFile<<secondline<<endl;
outFile<<sequenceBchar<<endl;
outFile<<"Dissimilarity score: "<<dissimilarity<<endl;

outFile.close();
   
    return 0;
}
