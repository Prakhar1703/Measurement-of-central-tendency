#include<bits/stdc++.h>
using namespace std;
void Binarytooctal()
{
    long long int Binarynumber; int r,arr[100],n=0;
    cout<<"Enter the Binary Number : ";
    cin>>Binarynumber;
    while(Binarynumber)
    {
        r=Binarynumber%1000;
        arr[n]=r;
        n=n+1;
        Binarynumber/=1000;
    }   
    for(int i=0;i<n;i++)
    {
        int arr1[3];
        int s=0;
        int a=arr[i],sum=0;
        while(a)
        {
            r = a%10;
            if(r==0 || r==1)
            {
                arr1[s]=r*pow(2,s);
                s=s+1;
                a=a/10;   
            }
            else
            {
                cout<<"Enter a valid Binary Number ."<<endl;
                break;
            }
        }
        for(int j=0;j<s;j++)
        {
            sum+=arr1[j];
        }
        arr[i]=sum;  
    }
    cout<<"The Octal number is : ";
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    cout<<endl;
}
void Binarytodecimal()
{
    long long int bin_number; int n=0,r=0;
    int arr[1000];
    cout<<"Enter the Binary Number : ";
    cin>>bin_number;
    while(bin_number)
    {
        if(r==0 || r==1)
        {
            r = bin_number%10;
            arr[n]=r*pow(2,n);
            n=n+1;
            bin_number=bin_number/10;   
        }
        else
        {
            cout<<"Enter a valid Binary Number ."<<endl;
            break;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    cout<<"The Decimal number of entered Binary Number is : "<<sum;
    cout<<endl;
}
void Binarytohexadecimal()
{
    long long int Binarynumber; int r,arr[100],n=0;
    cout<<"Enter the Binary Number : ";
    cin>>Binarynumber;
    while(Binarynumber)
    {
        r=Binarynumber%10000;
        arr[n]=r;
        n=n+1;
        Binarynumber/=10000;
    }   
    for(int i=0;i<n;i++)
    {
        int arr1[4];
        int s=0;
        int a=arr[i],sum=0;
        while(a)
        {
            r = a%10;
            if(r==0 || r==1)
            {
                arr1[s]=r*pow(2,s);
                s=s+1;
                a=a/10;   
            }
            else
            {
                cout<<"Enter a valid Binary Number ."<<endl;
                break;
            }
        }
        for(int j=0;j<s;j++)
        {
            sum+=arr1[j];
        }
        arr[i]=sum;  
    }
    char arr3[6]={'A','B','C','D','E','F'};
    cout<<"The Octal number is : ";
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==10)
        {
            cout<<arr3[0];
        }
        else if(arr[i]==11)
        {
            cout<<arr3[1];
        }
        else if(arr[i]==12)
        {
            cout<<arr3[2];
        }
        else if(arr[i]==13)
        {
            cout<<arr3[3];
        }
        else if(arr[i]==14)
        {
            cout<<arr3[4];
        }
        else if(arr[i]==15)
        {
            cout<<arr3[5];
        }
        else 
        {
            cout<<arr[i];
        }
    }
    cout<<endl;
}
void Octaltobinary()
{
    string arr[8]={"000","001","010","011","100","101","110","111"};
    string arr1[100]; int r=0,n=0;
    long long int Octal_number;
    cout<<"Enter the number : ";
    cin>>Octal_number;
    while(Octal_number)
    {
        if(r>7)
        {
            cout<<"Enter a valid Octal Number in the range 0 to 7 ."<<endl;
            break;
        }
        else
        {
            int s;
            r=Octal_number%10;
            arr1[n]=arr[r];
            n=n+1;
            Octal_number=Octal_number/10;
        }
    }
    cout<<"The Binary Number for the given Octal Number is : ";
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr1[i];
    }
    cout<<endl;
}
void Octaltodecimal()
{
    long long int octal_number ;
    cout<<"Enter the octal number : ";
    cin>>octal_number;
    int n=0,sum=0,r=0;
    while(octal_number)
    {
        r=octal_number%10;
        sum=sum+(r*pow(8,n));
        n=n+1;
        octal_number/=10;
    }
    cout<<"The Decimal number is : "<<sum<<endl;
}
void Octaltohexadecimal()
{
    long long int octal_number ;
    cout<<"Enter the octal number : ";
    cin>>octal_number;
    int n=0,sum=0,r=0;
    while(octal_number)
    {
        r=octal_number%10;
        sum=sum+(r*pow(8,n));
        n=n+1;
        octal_number/=10;
    }
    int i=0,arr[100];
    while(sum)
    {
        r=sum%16;
        arr[i]=r;
        i=i+1;
        sum/=16;
    }
    cout<<"The Hexadecimal Number is : ";
    for(int j=i-1;j>=0;j--)
    {
        if(arr[j]==10)
        {
            cout<<"A";
        }
        else if(arr[j]==11)
        {
            cout<<'B';
        }
        else if(arr[j]==12)
        {
            cout<<'C';
        }
        else if(arr[j]==13)
        {
            cout<<'D';
        }
        else if(arr[j]==14)
        {
            cout<<'E';
        }
        else if(arr[j]==15)
        {
            cout<<'F';
        }
        else 
        {
            cout<<arr[j];
        }
    }
    cout<<endl;

}
void Decimaltobinary()
{
    int Decimal_number;
    cout<<"Enter the number Decimal Number you want to convert : ";
    cin>>Decimal_number;
    int n=0,r=0,arr[1000];
    while(Decimal_number)
    {
        arr[n]=Decimal_number%2;
        Decimal_number=Decimal_number/2;
        n=n+1;
    }
    cout<<"The Binary Number is : ";
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    cout<<endl;
}
void Decimaltooctal()
{
    long long int decimal_number ;
    cout<<"Enter the Decimal number : ";
    cin>>decimal_number ;
    int r=0,i=0,arr[100];
    while(decimal_number)
    {
        r=decimal_number%8;
        arr[i]=r;
        i=i+1;
        decimal_number/=8;
    }
    cout<<"The Octal Number is : ";
    for(int j=i-1;j>=0;j--)
    {
        cout<<arr[j];
    }
    cout<<endl;
}
void Decimaltohexadecimal()
{
    long long int decimal_number ;
    cout<<"Enter the Decimal number : ";
    cin>>decimal_number ;
    int r=0,i=0,arr[100];
    while(decimal_number)
    {
        r=decimal_number%16;
        arr[i]=r;
        i=i+1;
        decimal_number/=16;
    }
    cout<<"The Hexadecimal Number is : ";
    for(int j=i-1;j>=0;j--)
    {
        if(arr[j]==10)
        {
            cout<<"A";
        }
        else if(arr[j]==11)
        {
            cout<<'B';
        }
        else if(arr[j]==12)
        {
            cout<<'C';
        }
        else if(arr[j]==13)
        {
            cout<<'D';
        }
        else if(arr[j]==14)
        {
            cout<<'E';
        }
        else if(arr[j]==15)
        {
            cout<<'F';
        }
        else 
        {
            cout<<arr[j];
        }
    }
    cout<<endl;
}
void Hexadecimaltobinary()
{
    string hexadecimalnumber;
    cout<<"Enter the Hexadecimal number (only capital alphabets): ";
    cin>>hexadecimalnumber;
    string arr1[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    string arr2[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    int s=hexadecimalnumber.length();
    string arr[s];
    for(int i=0;i<s;i++)
    {
        string a;int j=0;
        a=hexadecimalnumber[i];
        while(arr1[j]!=a)
        {
            j+=1;
        }
        arr[i]=arr2[j];
    }
    cout<<"The Binary Number is : ";
    for(int i=0;i<s;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}
void Hexadecimaltooctal()
{
    string hexadecimalnumber;
    cout<<"Enter the Hexadecimal number (only capital alphabets): ";
    cin>>hexadecimalnumber;
    string arr1[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    int s=hexadecimalnumber.length();
    int sum=0;
    for(int i=0;i<s;i++)
    {
        string a;int j=0;
        a=hexadecimalnumber[i];
        while(arr1[j]!=a)
        {
            j+=1;
        }
        sum=sum+(j*pow(16,s-i-1));
    }
    int r=0,i=0,arr[100];
    while(sum)
    {
        r=sum%8;
        arr[i]=r;
        i=i+1;
        sum/=8;
    }
    cout<<"The Octal Number is : ";
    for(int j=i-1;j>=0;j--)
    {
        cout<<arr[j];
    }
    cout<<endl;

}
void Hexadecimaltodecimal()
{
    string hexadecimalnumber;
    cout<<"Enter the Hexadecimal number (only capital alphabets): ";
    cin>>hexadecimalnumber;
    string arr1[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    int s=hexadecimalnumber.length();
    int sum=0;
    for(int i=0;i<s;i++)
    {
        string a;int j=0;
        a=hexadecimalnumber[i];
        while(arr1[j]!=a)
        {
            j+=1;
        }
        sum=sum+(j*pow(16,s-i-1));
    }
    cout<<"The Decimal Number is :" <<sum<<endl;
}
int main()
{
    int choice1,choice2 ;
    while(choice1!=5)
    {
        cout<<"1.Binary\n2.Octal\n3.Decimal\n4.Hexadecimal\n5.Exit\n";
        cout<<"enter the number system from which you want to convert : ";
        cin>>choice1;
        switch(choice1)
        {
            case 1:
                    {
                        while(choice2!=4)
                        {
                            cout<<"1.Octal\n2.Decimal\n3.Hexadecimal\n4.exit\n";
                            cout<<"enter the number system in which you want to convert : ";
                            cin>>choice2;
                            switch(choice2)
                            {
                                case 1: Binarytooctal();break;
                                case 2: Binarytodecimal();break;
                                case 3: Binarytohexadecimal();break;
                                case 4: return main();
                            }
                        }
                    }
            case 2:
                    {
                        while(choice2!=4)
                        {
                            cout<<"1.Binary\n2.Decimal\n3.Hexadecimal\n4.exit\n";
                            cout<<"enter the number system in which you want to convert : ";
                            cin>>choice2;
                            switch(choice2)
                            {
                                case 1: Octaltobinary();break;
                                case 2: Octaltodecimal();break;
                                case 3: Octaltohexadecimal();break;
                                case 4:return main();
                            }
                        }
                    }
            case 3:
                    {
                        while(choice2!=4)
                        {
                            cout<<"1.Binary\n2.Octal\n3.Hexadecimal\n4.exit\n";
                            cout<<"enter the number system in which you want to convert : ";
                            cin>>choice2;
                            switch(choice2)
                            {
                                case 1: Decimaltobinary();break;
                                case 2: Decimaltooctal();break;
                                case 3: Decimaltohexadecimal();break;
                                case 4: return main();
                            }
                        }
                    }
            case 4:
                    {
                        while(choice2!=4)
                        {
                            cout<<"1.Binary\n2.Octal\n3.Decimal\n4.exit\n";
                            cout<<"enter the number system in which you want to convert : ";
                            cin>>choice2;
                            switch(choice2)
                            {
                                case 1: Hexadecimaltobinary();break;
                                case 2: Hexadecimaltooctal();break;
                                case 3: Hexadecimaltodecimal();break;
                                case 4: return main();
                            }
                        }
                    }
            case 5: cout<<"exit."<<endl;
        }
    }
}
