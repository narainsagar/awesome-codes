/*
....................... ASSIGNMENT NO # 01 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
*/

class BooleanModel{
    private:
          WordList Dictionary[36];  // dictionary of 36 lists from (a to z + 0 to 9)
          string docsList[NO_OF_FILES]; // contains all files names.. (*.txt)
          set<string> StopwordsList;
          int FilesCount;
    public: 
           BooleanModel(){   
                FilesCount = 0;
                ifstream swfile;
                char *fname=new char[100];
                fname = "Dataset-A1\\Stopword-List.txt";
              //  cout<<fname<<endl;
                swfile.open(fname);
                if(swfile){
                   //   cout<<"\nStopword-List\n";
                      while(!swfile.eof()){
                          string word;
                          swfile>>word;
                          for(int i=0;word[i]!='\0';i++)  
                          {
                               word[i]=static_cast<char>(tolower(word[i]));   
                          }
                          string Sword = removeSpecials(word);
                       //   cout<<Sword<<endl;
                          if(Sword!=""){
                                   if(!StopwordsList.count(Sword)){
                                         StopwordsList.insert(Sword);                
                                   }            
                          }
                      }
                }else cout<<"File not exist\n";
                swfile.close();
           }
           void FetchFiles(){
                string path = "Dataset-A1\\CorpusforBM\\";
                string searchPattern = "*.txt";
                string fullSearchPath = path + searchPattern;
                
                HANDLE hFind;
                WIN32_FIND_DATA FindData;
                
                hFind = FindFirstFile( fullSearchPath.c_str(), &FindData );
                
                if( hFind == INVALID_HANDLE_VALUE )
                {
                    cout << "Error searching directory\n";
                    // return -1;
                }
                else{
                      do
                      {
                            string filePath = path + FindData.cFileName;
                            ifstream Dfile(filePath.c_str());
                            if(Dfile){
                                docsList[FilesCount]=(string)(FindData.cFileName);
                            //    cout<<FindData.cFileName<<endl;
                                while(!Dfile.eof())
                                {      
                                      string word;
                                      Dfile>>word;
                                      for(int i=0;word[i]!='\0';i++)  
                                      {
                                           word[i]=static_cast<char>(tolower(word[i]));   
                                      }
                                      string Sword = removeSpecials(word);
                                      if(Sword!=""){
                                       //    cout<<Sword<<endl;
                                           if(StopwordsList.count(Sword)==0){
                                             //    docs[filesCount].insert(Sword);
                                                  Dictionary[int(Sword[0]-'a')].InsertSorted(Sword,FilesCount);
                                           }
                                      }
                                       
                                }
                                FilesCount++;
                            }
                            else
                            {
                                cout << "Problem opening file " << FindData.cFileName << "\n";
                            }
                            Dfile.close(); 
                      }while( FindNextFile(hFind, &FindData) > 0 );     
                }
                if( GetLastError() != ERROR_NO_MORE_FILES )
                {
                    cout << "Something went wrong during searching\n";
                }     
                return;
           } 
           
           bool ConvertToPostfixOrder(string Tokens[],int len){
                bool q_val=false;
                int j=0;
                Stack<string> op_st;
                string tok[len];
                for( int i=0;i<len;i++ ){
                     string str=Tokens[i];
                     if(str!="and" && str!="or" && str!="not"){ // is word.
                           tok[j++]=str; 
                           if(!op_st.isEmpty()){
                                 do{
                                         string op=op_st.Pop();
                                         tok[j++]=op;              
                                 }while(!op_st.isEmpty());              
                           }      
                     }
                     else{ // is operator
                           op_st.Push(str);
                           q_val=true;
                     }     
                }  
                if(j==len){
                     for( int k=0;k<j;k++ ) {
                          Tokens[k] = tok[k]; 
                      //    cout<<Tokens[k]<<" ";    
                     }     
                }
                return q_val;
           }
           void RunSingleQ(string  qry,int qn=1){
               string Tokens[50],word="";
               int result[10]={0,0,0,0,0,0,0,0,0,0};
               int result2[10]={0,0,0,0,0,0,0,0,0,0};
               int TokensCount = 0, qLen=qry.length();
               bool valid_Q=false;
               
               for(int i = 0; i<qLen; i++)
               {
                  qry[i] = static_cast<char>(tolower(qry[i]));
                  if(isspace(qry[i]) || ispunct(qry[i])|| i==qLen-1)
                  {
                       if(i==qLen-1) 
                             word += qry[i];  
                       Tokens[TokensCount++] = word;
                    //   cout<<word<<" ";
                       word = "";
                  }
                  else word += qry[i];
                }
                
                printline();
				cout<<"\nQuery Number = "<<qn<<"  ||  QUERY : ("<<qry<<")"<<endl<<endl;
				printline();
                
                if(ConvertToPostfixOrder(Tokens,TokensCount)) // convert token array into postfix order..
                {
                        Stack<Node*> tok_St; 
                        bool invalid_Q = false;
                        for( int k=0;k<TokensCount && !invalid_Q ;k++ ) {
                             //  cout<<Tokens[k]<<" ";  
                             string str=Tokens[k];
                             if(str!="and" && str!="or" && str!="not"){ // is word. X
                                    Node *node = Dictionary[((int)(str[0]-'a'))].Get(str);
                                    if(node==NULL){
                                         Node* node2=new Node(str);
                                         node=node2;   //all 0 - no doc 
                                    }  
                                    tok_St.Push(node);         
                             }
                             else if(str=="not"){
                                   if(!tok_St.isEmpty()){ 
                                       COPY(result,tok_St.Pop()->inDocs);
                                       NOT(result);
                                   }
                                   else invalid_Q = true; 
                                   Node* node2=new Node(str,result);
                                   if(node2!=NULL)
                                       tok_St.Push(node2);
                             }
                             else if(str=="and"){
                                  if(!tok_St.isEmpty()){
                                        COPY(result,tok_St.Pop()->inDocs);  
                                        if(!tok_St.isEmpty())
                                            AND(result,tok_St.Pop()->inDocs);
                                        else invalid_Q = true;              
                                  } 
                                  else invalid_Q = true; 
                                  Node* node2=new Node(str,result);
                                  if(node2!=NULL)
                                       tok_St.Push(node2);
                             }
                             else if(str=="or"){
                                  if(!tok_St.isEmpty()) {
                                          COPY(result,tok_St.Pop()->inDocs);
                                          if(!tok_St.isEmpty())
                                              OR(result,tok_St.Pop()->inDocs);  
                                          else invalid_Q = true;                     
                                  }   
                                  else invalid_Q = true;   
                                  Node* node2=new Node(str,result);
                                  if(node2!=NULL)
                                       tok_St.Push(node2);
                             }
                            COPY(result,result2);  // assign resultant to 0 again.
                        } 
                        if(!invalid_Q){
                              if(!tok_St.isEmpty()) {
                                     COPY(result,tok_St.Pop()->inDocs);               
                                     if(tok_St.isEmpty()){
                                           bool no_such=true;
        					               cout<<"\n..::QUERY RESULT::.\tDocID   = \tDoc Name\n";
        					               printline();
                        	               for( int k=0 ; k < NO_OF_FILES ; k++){
                        		                if(result[k] == 1){
       						                           cout<<"\t\t\t"<<k+1<<"\t=\t"<<docsList[k]<<endl;
                                                       no_such = false;
                                                }
                   	                       }
                        	               if(no_such) cout<<"\n\t\t\t NO SUCH DOCUMENT.\n";
                                    }  
                                    else cout<<"\n\t\t\tInvalid Query\n";  
                            }  
                            else cout<<"\n\t\t\tInvalid Query\n";               
                        }  
                        else cout<<"\n\t\t\tInvalid Query\n";                                           
                }
                else cout<<"\n\t\t\tInvalid Query\n"; 
                cout<<endl<<endl;
           } 
           void Execute(){
                ifstream qfile;
                int q=1;
                char *fname=new char[100];
                fname = "Dataset-A1\\QueryList.txt";
              //  cout<<fname<<endl;
                qfile.open(fname);
                if(qfile){
                      while(!qfile.eof()){
                          string  qry="";
                          qry = removeSpecials(qry);
                          getline(qfile,qry);
                          RunSingleQ(qry,q++);
                      }
                }
                else{
                   cout<<"file ["<<fname<<"] not exist.\n";     
                } 
                qfile.close();    
           }        
};
