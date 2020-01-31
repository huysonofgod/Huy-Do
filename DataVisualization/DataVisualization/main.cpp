#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
//FIXME: stream manipulation library
using namespace std;

int main()
{
   
   /* Type code here. */
   /* Overall flow of the program:
   
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2
   
   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces
   
   Print out data in table format
   
   Print out data in chart format
   */
   //Get the title for the data
   string titleData;
   string header1;
   string header2;
   vector <string> authorNameList;
   vector <int> numNovelList;
   string dataPoint;
   string authorName;
   
   cout<<"Enter a title for the data: " <<endl;
   getline(cin, titleData);
   cout << "You entered: " << titleData << endl;
    cout<<endl;
   
   //Get input header for col. header #1 & #2
   cout<< "Enter the column 1 header: "<< endl;
   getline(cin, header1);
   cout<< "You entered: " << header1 << endl;
    cout<<endl;
   //#2
   cout << "Enter the column 2 header: "<<endl;
   getline(cin, header2);
   cout << "You entered: " << header2 <<endl;
    cout<<endl;
   
    // Run the program until user put -1
    
    
    //
    while (true){
        
        cout << "Enter a data point (-1 to stop input): "<< endl;
        //get data point from user
        getline(cin, dataPoint);
        
        if(dataPoint == "-1"){
            break;
        }
       
        try{
            // count the comma in from the data point
            
            int comma =0;
            
            for(int i=0; i<dataPoint.length();++i){

                if(dataPoint[i] == ','){
                    comma++;
                    // throw error if there are more than 2 commas
                    
                }
              
            }
            if(comma == 0){
                throw 'a';
            }
            if(comma>1){
                throw 2;
            }
             
            
            //split the string
            int index = dataPoint.find_first_of(',');
            string nameAuthor = dataPoint.substr(0, index);
            string numNovel = dataPoint.substr(index +1);
            int num_novel = stoi(numNovel);
            
            authorNameList.push_back(nameAuthor);
            cout <<"Data string: " << nameAuthor<<endl;
            
            numNovelList.push_back(num_novel);
            cout<< "Data integer: " << num_novel <<endl;
        
        }
        // Catch exception if there are more than one comma
        catch(int e){
            cout << "Error: Too many commas in input.\n"<< endl;
        }
        // Catch exception if there are no comma
        catch (char a){
            cout << "Error: No comma in string.\n"<<endl;
        }
             
        // Catch exception if there are no integer
        catch (invalid_argument){
            cout << "Error: Comma not followed by an integer.\n" <<endl;
        }
             
    }
    cout<<endl;
    
    cout<<setw(33)<<right<<titleData<<endl;
    cout<<setw(20)<<left<<header1<<"|";
    cout<<setw(23)<<right<<header2<<endl;
    cout<<"--------------------------------------------"<<endl;
    for(unsigned int i=0;i<authorNameList.size();i++){
        cout<<setw(20)<<left<<authorNameList.at(i)<<"|";
        cout<<setw(23)<<right<<numNovelList.at(i);
        if(i==authorNameList.size()){
            break;
        }
        cout<<endl;
    }
    
    
    cout<<endl;
    
    for(unsigned int i=0; i<authorNameList.size();i++){
        cout<<setw(20)<<authorNameList.at(i)<<" ";
        int star =0;
        while(star<numNovelList.at(i)){
            cout << "*";
            star++;
        }
        cout<<endl;
    }
    
    
            
    
    
   return 0;
}
