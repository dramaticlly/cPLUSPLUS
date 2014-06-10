
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX_NODE_NUMBER 5000
#define MIN_NODE_NUMBER 0
#define INSERT_COUNT 5
#define MODIFY_COUNT 3
#define DELETE_COUNT 2
#define PRINT_COUNT 2

int checkArg(string line)
{
    int count=0;
    string cmd;
    stringstream ls1(line);
    do
    {
        ls1>>cmd;
        if(!ls1.fail())
        count++;
    }
    while(!ls1.eof());    
    return count;
}

int parser()
{ 
        
        string line;
        cout<<"> ";
        cout.flush();
        getline(cin,line);
        while(!cin.eof())
        {
	string cmd;
        int count=0;
        stringstream ls(line);
        ls>>cmd;
                
        if(cmd=="insertR")
        {
            if(!ls.fail())
            {
                count=checkArg(line);
                  string name;
                  double resist;
                  int nodeidF,nodeidL;
                  ls>>name;
                  ls>>resist;
		  ls>>nodeidF;
		  ls>>nodeidL;
                  if (ls.fail()&&!ls.eof())
                  { 
                  cout<<"Error: invalid argument"<<endl;
                  }                  
                  else if(resist<0)
		  {
			if(name=="all")
			{	
                  cout<<"Error: resistor name cannot be the keyword \"all\""<<endl;
			}
			else
                        	cout<<"Error: negative resistance"<<endl;
		  }	
                  else if((nodeidF>MAX_NODE_NUMBER||nodeidF<MIN_NODE_NUMBER)&&count>3)
                  {           
                  cout<<"Error: node "<<nodeidF<<" is out of permitted range 0-5000"<<endl;
                  }
                  else if((nodeidL>MAX_NODE_NUMBER||nodeidL<MIN_NODE_NUMBER)&&count>4)
                  {            
                  cout<<"Error: node "<<nodeidL<<" is out of permitted range 0-5000"<<endl;
                  }
                  else if(name=="all")
                  {
                  cout<<"Error: resistor name cannot be the keyword \"all\""<<endl;
                  }
                  else if (nodeidF==nodeidL)
			{
			      if(ls.eof()&&!ls.fail())
                        		cout<<"Error: both terminals of resistor connect to node "<<nodeidF<<endl;
				else if(!ls.eof())
				{
				string junk;
				ls>>junk;
				if(junk==""||junk==" "||junk=="\n")
					 cout<<"Error: both terminals of resistor connect to node "<<nodeidF<<endl;
				else if(!ls.fail())	
					 cout<<"Error: both terminals of resistor connect to node "<<nodeidF<<endl;
				else 				
				        cout<<"Error: invalid argument  2"<<endl;
				}
			}
                  else if(count>INSERT_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                  else if(count<INSERT_COUNT)
                        cout<<"Error: too few arguments"<<endl;
                  else if(!ls.fail()&&!ls.eof())
                  {
		  string junk;
	          ls>>junk;
		  if(junk!=" "&&junk!=""&&junk!="\n")
                 	 cout<<"Error: invalid argument"<<endl;	                                  else
                  {		         
                 cout.setf(ios::fixed);
                 cout.setf(ios::showpoint);
                 cout.precision(2);
                 cout<<"Inserted: resistor "<<name<<" "<<resist<<" Ohms "<<nodeidF<<" -> "<<nodeidL<<endl; 
		  }                                    
                 }
                  else
                  {		         
                 cout.setf(ios::fixed);
                 cout.setf(ios::showpoint);
                 cout.precision(2);
                 cout<<"Inserted: resistor "<<name<<" "<<resist<<" Ohms "<<nodeidF<<" -> "<<nodeidL<<endl; 
		 }       
                  
           }
        }
        else if(cmd=="modifyR")
        {
            string sname;
            double resist;
            count=checkArg(line);
	    ls>>sname;
	    if(ls.eof())
		cout<<"Error: too few arguments"<<endl;
           else  if(!ls.fail())
            {
                ls>>resist;
		if(ls.fail()&&!ls.eof())
		cout<<"Error: invalid argument"<<endl;
                else if(resist<0)
                 {if(!ls.eof())
			{
			string junk;
			ls>>junk;
			if(junk!=""&&junk!=" "&&junk!="\n")
			 cout<<"Error: invlid argument"<<endl;
			else 
			{
			if(ls.eof())
				cout<<"Error: invalid argument"<<endl;
			else{
			 cout.setf(ios::fixed);
                        cout.setf(ios::showpoint);
                        cout.precision(2);
                        cout<<"Modified: resistor "<<sname<<" to "<<resist<< " Ohms"<<endl;
			}
			}
			}

			else
		 cout<<"Error: negative resistance"<<endl;
		}
                else if(sname=="all")
                        cout<<"Error: resistor name cannot be the keyword \"all\""<<endl;
                else if(count>MODIFY_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                else if(count<MODIFY_COUNT)
                        cout<<"Error: too few arguments"<<endl;                
                else 
                {       if(ls.eof())
			{   
                        cout.setf(ios::fixed);
                        cout.setf(ios::showpoint);
                        cout.precision(2);
			if(resist==-0.00)
			resist=0.00;                    
                        cout<<"Modified: resistor "<<sname<<" to "<<resist<< " Ohms"<<endl;
               		 }
			else 	
			cout<<"Error: invalid argument"<<endl;
		}        
            }
	   else if(ls.fail()&&count<MODIFY_COUNT)
                    cout<<"Error: too few arguments"<<endl;                
        }
        
        else if(cmd=="printR")
        {            
            if(!ls.fail())
            {
            count=checkArg(line);
            string first;
            ls>>first;
                if(first=="all")                    
                {
                     if(count>PRINT_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                else if(count<PRINT_COUNT)
                        cout<<"Error: too few arguments"<<endl;          
                else if (count==PRINT_COUNT)
                        cout<<"Print: all resistors"<<endl;
                }
                else if(count>PRINT_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                else if(count<PRINT_COUNT)
                        cout<<"Error: too few arguments"<<endl;           
                else                                   
                        cout<<"Print: resistor "<<first<<endl;                
            }  
        }
                
        else if (cmd=="printNode")
        {
            string first;
            int nodeid;
            stringstream ss;
            bool end=false;
            ls>>first;
            count=checkArg(line);
            if(first!="all")
            {
                ss<<first;
                ss>>nodeid;
                if((ss.fail()&&count!=1)||!ss.eof())
                {
                  end=true;
                  cout<<"Error: invalid argument"<<endl;
                }
			
            }
            if(!ls.fail()&&!end)
            {                               
                if(first=="all")
                {
                    if(count>DELETE_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                    else if(count<DELETE_COUNT)
                        cout<<"Error: too few arguments"<<endl;     
                    else if(count==DELETE_COUNT)
                    cout<<"Print: all nodes"<<endl;
                }
                else if(nodeid>MAX_NODE_NUMBER||nodeid<MIN_NODE_NUMBER)                            
                        cout<<"Error: node "<<nodeid<<" is out of permitted range 0-5000"<<endl;

                else if(count>DELETE_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                else if(count<DELETE_COUNT)
                        cout<<"Error: too few arguments"<<endl;                                   
                else
			{
		 if(ls.eof()&&!ls.fail())                                   
                cout<<"Print: node "<<nodeid<<endl;
		  else 
		cout<<"Error: invalid argument"<<endl;
			} 
            }
                else if(ls.fail()&&count==1)
                cout<<"Error: too few arguments"<<endl;
            
        }
        
        else if(cmd=="deleteR")
        {
            string first;
            ls>>first;
            count=checkArg(line);
            if(!ls.fail())
            {
                if(first=="all")
                {
                    if(count>DELETE_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                    else if(count<DELETE_COUNT)
                        cout<<"Error: too few arguments"<<endl;
                    else if (count==DELETE_COUNT)
                    cout<<"Deleted: all resistors"<<endl;
                }
                else if(count>DELETE_COUNT)
                        cout<<"Error: too many arguments"<<endl;
                else if(count<DELETE_COUNT)
                       cout<<"Error: too few arguments"<<endl;         
                else
                    cout<<"Deleted: resistor "<<first<<endl;                    
            }
	    else if(ls.fail()&&count==1)	    
                       cout<<"Error: too few arguments"<<endl;         
        }        
        else
            cout<<"Error: invalid command"<<endl;        
        cout<<"> ";
        cout.flush();
        getline(cin,line);        
        }       
   return 0;   
}

int main() 
{  
    return parser();
}

