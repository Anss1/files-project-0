#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <Windows.h>
using namespace std;

int load_from_file(char file_name[],char my_string[])
{
    int i=0;
    char ch;
    fstream file(file_name);
    if(file.fail())
    {
        cerr<<"File is not exist!\n"<<endl;
        Sleep(2000);
        system("cls");
    }
    else
    {
        while(file.get(ch))
        {
            my_string[i]=ch;
            i++;
        }
    }

    file.close();
    cout<<"Loading finished successfully...\n"<<endl;
    Sleep(2000);
    system("cls");
    return i;
}
void create_file()
{
    char fn[50];
    cout<<"Enter the file name and its extension : ";
    cin.ignore();
    cin.getline(fn,50,'\n');
    system("cls");
    fstream file;
    file.open(fn,ios::out);
    file.close();
    cout<<"Your new file has been successfully created...\n"<<endl;
    Sleep(2000);
    system("cls");

}
void display(char str[],int mysize)
{
    cout<<"The loaded text : ";
    for(int i=0; i < mysize; i++)
        cout<<str[i];
    cout<<endl<<endl;
}

void input_to_file(int _choice,char filename[],char mystring[],int size2)
{
    if(_choice==1)
    {
        ofstream myfile;
        myfile.open(filename,ios::app |ios::out );
        myfile<<"\n";
        for( int i=0; i < size2; i++)
        {
            myfile<<mystring[i];
        }
        myfile.close();
        cout<<"Loaded text saved successfully...\n"<<endl;
        Sleep(2000);
        system("cls");
    }
    else if(_choice==2)
    {
        char _filename[50];
        cout<<"Enter the file name and its extension : ";
        cin.ignore();
        cin.getline(_filename,50,'\n');
        system("cls");
        ofstream myfile(_filename,ios::out);
        for( int i=0; i < size2; i++)
        {
            myfile<<mystring[i];
        }
        myfile.close();
        cout<<"Loaded text saved successfully...\n"<<endl;
        Sleep(2000);
        system("cls");
    }

}

void counter (char str[],int my_size, char a[])
{

    int word_c=0,char_c=0;
    for(int i=0; i < my_size; i++)
    {
        if(str[i]!='\n')
            char_c++;
        if((char_c!=0 && str[i]== ' ' && str[i-1]!='\n' && str[i-1]!=' ') || (str[i-1]!='\n' && str[i]=='\n' && str[i-1]!=' '))
            word_c++;
    }
    /*if((str[my_size-1]!='\n' && str[my_size]=='\n') || (str[my_size-1]!=' ' && str[my_size]==' '))
        word_c++;*/

    fstream inp;
    inp.open(a,ios::out | ios::app);
    inp<<endl<<endl<<char_c<<" Character"<<endl<<word_c<<" Word"<<endl;
    inp.close();

    char_c=0;
    word_c=0;
}
void searching (char my_str[],int str_size)
{
    unsigned int ind=0;
    char new_str[1000],word[50];
    cout<<"Enter your word to search : ";
    cin>>word;
    for(unsigned int y=0 ; y <strlen(word); y++)
        word[y]=tolower(word[y]);
    for(int i=0 ; i < str_size; i++)
        new_str[i]=tolower(my_str[i]);
// LOOP FOR SEARCHING ABOUT WORD ......................
    for(int x=0 ; x < str_size ; x++)
    {
        if(new_str[x]== word[ind])
        {
            ind++;
            for(int i=x+1 ; i < str_size; i++)
            {
                if(new_str[i] == word[ind])
                {
                    ind++;
                    if( ind == strlen(word) && ( new_str[i+1]==' ' || new_str[i+1]=='\n'))
                        break;
                }

                else
                {
                    ind=0;
                    break;
                }
            }
        }
    }
    if( ind == strlen(word))
        cout<<"\nWord is found in the file :)\n"<<endl;
    else
        cout<<"\nWord is not found in the file :(\n"<<endl;
    Sleep(2000);
    system("cls");
    ind=0;
}


void clearall (char file_n[])
{
    fstream onp;
    onp.open(file_n,ios::out);
    onp.close();
    cout<<"\nFile cleared successfully...\n"<<endl;
    Sleep(2000);
    system("cls");
}
void adding (char file_name2[])
{
    char new_c[1000];
    cout<<"Enter the content you want : ";
    fstream inp;
    inp.open(file_name2,ios::out | ios::app |ios::ate);
    cin.ignore();
    cin.getline(new_c,1000);
    inp<<"\n"<<new_c;
    inp.close();
    system("cls");
    cout<<"Content added successfully...\n\n";
    Sleep(2000);
    system("cls");
}
void replacing (char file_name3[],char my_new_str[])
{
    char word_1[50],word_2[50],*ptr;
    cout<<"Replacing : ";
    cin>>word_1;
    cout<<" With : ";
    cin>>word_2;
    ptr = strstr(my_new_str,word_1);
    strncpy(ptr,word_2,strlen(word_2));
    fstream inp;
    inp.open(file_name3,ios::out);
    inp<<my_new_str;
    inp.close();
}
void add_file(char currentfile[])
{
    int i=0;
    char name_f[50],content[1000],c;
    cout<<"Enter the file name and its extension : ";
    cin.ignore();
    cin.getline(name_f,50);
    fstream inp ;
    inp.open(name_f,ios::in);
    if(inp.fail())
    {
        cerr<<"File is not exist!\n"<<endl;
        Sleep(3000);
        system("cls");
    }
    else
    {
        while(inp.get(c))
        {
            content[i]=c;
            i++;
        }
    }
    inp.close();
    fstream onp;
    onp.open(currentfile,ios::out | ios::app | ios::ate);
    onp<<"\n"<<content;
    onp.close();
}

void ciphercontent (char content2[],int choose,int mysize)
{
    if(choose==1)
    {
        string a3,str3;

        for( int i3=0; i3 < mysize; i3++)
        {
            if((int(content2[i3]) > 109 && int(content2[i3]) <= 122) || (int(content2[i3]) > 77 && int(content2[i3]) <= 90))
            {
                a3=char(int(content2[i3])-13);
                str3.append(a3);
            }
            else if((int(content2[i3]) <= 109 && int(content2[i3]) >= 97) || (int(content2[i3]) <= 77 && int(content2[i3]) >= 65))
            {
                a3=char(int(content2[i3])+13);
                str3.append(a3);
            }
        }
        cout<<"\nThe Text after Encryption : "<<str3<<endl<<endl;
    }
//decipher.....................................................................................
    if(choose==2)
    {
        string a3,str3;


        for(int i3=0; i3 < mysize; i3++)
        {
            if((int(content2[i3]) > 109 && int(content2[i3]) <= 122) || (int(content2[i3]) > 77 && int(content2[i3]) <= 90) )
            {
                a3=char(int(content2[i3])-13);
                str3.append(a3);
            }
            else if((int(content2[i3]) <= 109 && int(content2[i3]) >= 97) || (int(content2[i3]) <= 77 && int(content2[i3]) >= 65) )
            {
                a3=char(int(content2[i3])+13);
                str3.append(a3);
            }
        }
        cout<<"\nThe Text After Encoding : "<<str3<<endl<<endl;
    }
}

void to_lower (char file_n[],char small_str[],int s)
{
    for(int i=0; i < s; i++)
    {
        small_str[i]=tolower(small_str[i]);
    }
    fstream small_f ;
    small_f.open(file_n,ios::out);
    for( int i=0; i < s; i++)
        {
            small_f<<small_str[i];
        }
    small_f.close();
    cout<<"Converted to lower successfully...\n\n";
    Sleep(2000);
    system("cls");
}
void to_upper (char file_na[],char big_str[],int ss)
{
    for(int i=0; i < ss ; i++)
    {
        big_str[i]=toupper(big_str[i]);
    }
    fstream big_f ;
    big_f.open(file_na,ios::out);
    for( int i=0; i < ss; i++)
        {
            big_f<<big_str[i];
        }
    big_f.close();
    cout<<"Converted to upper successfully...\n\n";
    Sleep(2000);
    system("cls");
}


int main()
{
    int sizee,choosing;
    char mynewstring[1000],fn[50];
    int val;

    cout<<"AHLAN YA USER YA HABIBI.\n\n"<<endl;
    while(1)
    {

        cout<<"What do you like to do today? \n\n";

        cout<<"1- Load an existing file.\n";
        cout<<"2- Create a new file.\n";
        cout<<"3- Display file content.\n";
        cout<<"4- Save the loaded text to the same file again or different one.\n";
        //**************************************************************
        cout<<"5- Count the words and the characters in the file.\n";
        cout<<"6- Search for a word in a file.\n";
        cout<<"7- Empty file content.\n";
        //******************************************************************
        cout<<"8- Add more content to the end of the file.\n";
        cout<<"9- Replace a word in the file with another word.\n";
        cout<<"10- Add another file to the end of the current file.\n";
        //******************************************************************
        cout<<"11- Encrypt and decrypt the file.\n";
        cout<<"12- Turn all the content file to lower case.\n";
        cout<<"13- Turn all the content file to upper case.\n";
        //*******************************************************************
        cout<<"14- End.\n\n";

        cout<<"Enter your choice : ";
        cin>>val;
        system("cls");

        if(val==1)
        {

            cout<<"Enter the file name and its extension : ";
            cin.ignore();
            cin.getline(fn,50,'\n');
            system("cls");
            sizee=load_from_file(fn,mynewstring);
        }
        if(val==2)
        {
            create_file();
        }
        if(val==3)
        {
            display(mynewstring,sizee);
        }
        if(val==4)
        {
            int choice;
            cout<<"What do you want ? \n\n";
            cout<<"1-To save the loaded text to the same file "<<endl;
            cout<<"2-To save the loaded text to another file\n\n "<<endl;
            cout<<"Enter your choice : ";
            cin>>choice;
            system("cls");
            input_to_file(choice,fn,mynewstring,sizee);
        }

        if(val==5)
        {
            counter(mynewstring,sizee,fn);
        }
        if(val==6)
        {
            searching(mynewstring,sizee);
        }
        if(val==7)
        {
            clearall(fn);
        }
        if(val==8)
        {
            adding(fn);
        }
        if(val==9)
        {
            replacing(fn,mynewstring);
        }
        if(val==10)
        {
            add_file(fn);
        }
        if(val==11)
        {
            cout<<"1- Cipher\n";
            cout<<"2- Decipher\n\n";
            cout<<"Enter your choice : ";
            cin>>choosing;
            system("cls");
            ciphercontent(mynewstring,choosing,sizee);
        }
        if(val==12)
        {
            to_lower(fn,mynewstring,sizee);
        }
        if(val==13)
        {
            to_upper(fn,mynewstring,sizee);
        }
        if(val==14)
        {
            cout<<"Program Ends...!"<<endl;
            break;
        }

    }

    return 0;
}
