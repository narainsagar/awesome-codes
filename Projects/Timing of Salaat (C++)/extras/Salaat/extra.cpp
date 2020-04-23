void printInBox(string str)
{
   int size=str.length();
   cout<<"\n";
   cout<<"\0xC9";
   for(int i=0;i<size;i++)
     cout<<"\0xCD";
   cout<<"\0xBB";
   cout<<"\n"; 	
   cout<<"\0xBA"; 
   cout<<"\0xC8";
   for(int i=0;i<size;i++)
     cout<<"\0xCD";
   cout<<"\0xBC";
}
