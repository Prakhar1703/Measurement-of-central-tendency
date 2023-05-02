#include<bits/stdc++.h>
using namespace std;
void imean()
{
    cout<<"*************************************************************************"<<endl;
    cout<<"In case of individual observation : "<<endl;
    cout<<"\t \t \t x̄ : x1+x2+x3+ _ _ _ _ _ _ +xn"<<endl;
    cout<<"\t \t \t     -------------------------"<<endl;
    cout<<"\t \t \t                 n            "<<endl;
    cout<<"\t \t \t short cut method : a+1/n Σ(xi)"<<endl;
    cout<<"*************************************************************************"<<endl;
    int n;
    cout<<"enter the No of element : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element "<<i+1<<" : ";
        cin>>arr[i];
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    cout<<"In case of individual observation : "<<endl;;
    cout<<"\t \t \t x̄ : x1+x2+x3+ _ _ _ _ _ _ +xn"<<endl;
    cout<<"\t \t \t       -------------------------"<<endl;
    cout<<"\t \t \t                 n            "<<endl;     
    cout<<"for the mean of the given numbers are : ";
    cout<<"1/"<<n<<"(";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(i<n-1)
        {
            cout<<"+";
        }
    }
    cout<<")";
    cout<<endl;
    cout<<"Mean : "<<sum<<"/"<<n;
    cout<<endl;
    float a=sum/n;
    cout<<"Mean : "<<fixed<<setprecision(3)<<a<<endl;
    cout<<"*************************************************************************"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Mean : "<<endl;
        filestream<<"In case of individual observation : "<<endl;;
        filestream<<"\t \t \t x̄ : x1+x2+x3+ _ _ _ _ _ _ +xn"<<endl;
        filestream<<"\t \t \t       -------------------------"<<endl;
        filestream<<"\t \t \t                 n            "<<endl;     
        filestream<<"for the mean of the given numbers are : ";
        filestream<<"1/"<<n<<"(";
        for(int i=0;i<n;i++)
        {
            filestream<<arr[i];
            if(i<n-1)
            {
                filestream<<"+";
            }
        }
        filestream<<")";
        filestream<<endl;
        filestream<<"Mean : "<<sum<<"/"<<n;
        filestream<<endl;
        float a=sum/n;
        filestream<<"Mean : "<<fixed<<setprecision(3)<<a<<endl;
        filestream<<"*************************************************************************"<<endl;
        filestream.close();
    }
    else cout<<"file opening is fail.\n";
}
void fmean()
{
    cout<<"*************************************************************************"<<endl;
    cout<<"In case of frequency distribution : "<<endl;
    cout<<" x : x1,x2,x3,x4,_ _ _ _ _ _ _ ,xn\n";
    cout<<" f : f1,f2,f3,f4,_ _ _ _ _ _ _ ,fn\n";
    cout<<"\t \t \t x̄ : x1.f1+x2.f2+x3.f3+ _ _ _ _ _ _ +xn.fn"<<endl;
    cout<<"\t \t \t     -------------------------------------"<<endl;
    cout<<"\t \t \t     f1+f2+f3+f4+_ _ _ _ _ _ _ _ _ _+fn"<<endl;
    cout<<"x̄ = Σfi.xi/Σfi  or 1/N Σfixi.\n";
    cout<<"\t \t \t short cut method : a+(Σfi(xi-a))/N "<<endl;
    cout<<"*************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr1[n+1],arr2[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr1[i]=a;
        }
        else
        {
            arr1[i]=arr1[i-1]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr2[i]=(arr1[i]+arr1[i+1])/2;
    }
    int arr3[n];
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the fi element "<<i+1<<" : ";
        cin>>arr3[i];
    }
    cout<<"--------------------------------------------"<<endl;
    cout<<" Intervals \t xi \t fi \t fi.xi"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<" \t "<<arr3[i]*arr2[i]<<endl;
    } 
    cout<<"--------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Mean : \n";
        filestream<<"In case of frequency distribution : "<<endl;
        filestream<<" x : x1,x2,x3,x4,_ _ _ _ _ _ _ ,xn\n";
        filestream<<" f : f1,f2,f3,f4,_ _ _ _ _ _ _ ,fn\n";
        filestream<<"\t \t \t x̄ : x1.f1+x2.f2+x3.f3+ _ _ _ _ _ _ +xn.fn"<<endl;
        filestream<<"\t \t \t     -------------------------------------"<<endl;
        filestream<<"\t \t \t     f1+f2+f3+f4+_ _ _ _ _ _ _ _ _ _+fn"<<endl;
        filestream<<"x̄ = Σfi.xi/Σfi  or 1/N Σfixi.\n";
        filestream<<"\t \t \t short cut method : a+(Σfi(xi-a))/N "<<endl;
        filestream<<"*************************************************************************"<<endl;
        filestream<<"--------------------------------------------"<<endl;
        filestream<<" Intervals \t xi \t fi \t fi.xi"<<endl;
        for(int i=0;i<n;i++)
        {
            filestream<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<" \t "<<arr3[i]*arr2[i]<<endl;
        } 
        filestream<<"--------------------------------------------"<<endl;
        float sumfi=0,sumfixi=0;
        for(int i=0;i<n;i++)
        {
            sumfi=sumfi+arr3[i];
            sumfixi=sumfixi+(arr3[i]*arr2[i]);
        }
        filestream<<"The formula for the mean is : (Σfixi)/Σfi "<<endl;
        filestream<<"The value of Σfixi is : "<<sumfi<<endl;
        filestream<<"The value of Σfi is : "<<sumfixi<<endl;
        float b=sumfixi/sumfi;
        filestream<<" The Mean of the given observation is : "<<fixed<<setprecision(3)<<b<<endl;
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    float sumfi=0,sumfixi=0;
    for(int i=0;i<n;i++)
    {
        sumfi=sumfi+arr3[i];
        sumfixi=sumfixi+(arr3[i]*arr2[i]);
    }
    cout<<"The formula for the mean is : (Σfixi)/Σfi "<<endl;
    cout<<"The value of Σfixi is : "<<sumfi<<endl;
    cout<<"The value of Σfi is : "<<sumfixi<<endl;
    float b=sumfixi/sumfi;
    cout<<" The Mean of the given observation is : "<<fixed<<setprecision(3)<<b<<endl;
    
    cout<<"*************************************************************************"<<endl;
}
void cfmean()
{
    cout<<"*************************************************************************"<<endl;
    cout<<"In case of continuous frequency distribution : "<<endl;;
    cout<<"\t \t \t x̄ : a+(h(Σfi.ui)/N)"<<endl;
    cout<<"\t \t \t where u=(xi-a)/h "<<endl;
    cout<<"\t \t \t       N=Σfi "<<endl;
    cout<<"\t \t \t       h = length of interval ."<<endl;
    cout<<"*************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr10[n+1],arr20[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr10[i]=a;
        }
        else
        {
            arr10[i]=arr10[i-1]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr20[i]=(arr10[i]+arr10[i+1])/2;
    }
    float l;
    l=arr20[n/2];
    int arr30[n];
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\t enter the fi element "<<i+1<<" : ";
        cin>>arr30[i];
    }
    int arr40[n];
    for(int i=0;i<n;i++)
    {
        arr40[i]=(arr20[i]-l)/c;
    }
    cout<<"-------------------------------------------------------"<<endl;
    cout<<" Intervals \t xi \t fi \t ui \t fi.ui"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr10[i]<<" - "<<arr10[i+1]<<" \t "<<arr20[i]<<" \t "<<arr30[i]<<" \t "<<arr40[i]<<" \t "<<arr30[i]*arr40[i]<<endl;
    } 
    cout<<"-------------------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Mean : \n";
        filestream<<"In case of continuous frequency distribution : "<<endl;;
        filestream<<"\t \t \t x̄ : a+(h(Σfi.ui)/N)"<<endl;
        filestream<<"\t \t \t where u=(xi-a)/h "<<endl;
        filestream<<"\t \t \t       N=Σfi "<<endl;
        filestream<<"\t \t \t       h = length of interval ."<<endl;
        filestream<<"*************************************************************************"<<endl;
        filestream<<"------------------------------------------------------"<<endl;
        filestream<<" Intervals \t xi \t fi \t ui \t fi.ui"<<endl;
        for(int i=0;i<n;i++)
        {
            filestream<<" "<<arr10[i]<<" - "<<arr10[i+1]<<" \t "<<arr20[i]<<" \t "<<arr30[i]<<" \t "<<arr40[i]<<" \t "<<arr30[i]*arr40[i]<<endl;
        } 
        filestream<<"-------------------------------------------------------"<<endl;
        float sumfixi=0,sumfiuixi=0;
        for(int i=0;i<n;i++)
        {
            sumfixi=sumfixi+arr30[i];
            sumfiuixi=sumfiuixi+(arr30[i]*arr40[i]);
        }
        filestream<<"x̄ : a+(h(Σfi.ui)/N)"<<endl;
        filestream<<"The value of Σfi is : "<<sumfixi<<endl;
        filestream<<"The value of Σfi.ui is : "<<sumfiuixi<<endl;
        filestream<<"The value of a is : "<<l<<endl;
        float b=l+(c*((sumfiuixi)/sumfixi));
        filestream<<" The Mean of the given observation is : "<<fixed<<setprecision(3)<<b<<endl; 
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    float sumfixi=0,sumfiuixi=0;
    for(int i=0;i<n;i++)
    {
        sumfixi=sumfixi+arr30[i];
        sumfiuixi=sumfiuixi+(arr30[i]*arr40[i]);
    }
    cout<<"x̄ : a+(h(Σfi.ui)/N)"<<endl;
    cout<<"The value of Σfi is : "<<sumfixi<<endl;
    cout<<"The value of Σfi.ui is : "<<sumfiuixi<<endl;
    cout<<"The value of a is : "<<l<<endl;
    float b=l+(c*((sumfiuixi)/sumfixi));
    cout<<" The Mean of the given observation is : "<<fixed<<setprecision(3)<<b<<endl;
    cout<<"*************************************************************************"<<endl;
}
void imedian()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"In case of individual observation : "<<endl;;
    cout<<"\t \t \t x = x1,x2,x3,_ _ _ _ _ _ _ _ _ ,xn."<<endl;
    cout<<"\t \t \t n = number of observations ."<<endl;
    cout<<"\t \t \t then we sort all the elements given in the list in ascending order ."<<endl;
    cout<<"\t \t \t if the value of n is odd then median is : ((n+1)/2)th term in the list. "<<endl;
    cout<<"\t \t \t if the value of n is even then median is : ((n/2)th+((n/2)/2)th)/2 term in the list. "<<endl;
    cout<<"********************************************************************************************************"<<endl;
    int n;
    cout<<"enter the elements in your list : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element "<<i+1<<" : ";
        cin>>arr[i];
    }
    float temp,pass=0;
    cout<<endl;
    for(int i = 0; i<n; i++) 
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[i]) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"the list after the sorting is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Median : \n";
        filestream<<"In case of individual observation : "<<endl;;
        filestream<<"\t \t \t x = x1,x2,x3,_ _ _ _ _ _ _ _ _ ,xn."<<endl;
        filestream<<"\t \t \t n = number of observations ."<<endl;
        filestream<<"\t \t \t then we sort all the elements given in the list in ascending order ."<<endl;
        filestream<<"\t \t \t if the value of n is odd then median is : ((n+1)/2)th term in the list. "<<endl;
        filestream<<"\t \t \t if the value of n is even then median is : ((n/2)th+((n/2)/2)th)/2 term in the list. "<<endl;
        filestream<<"*************************************************************************"<<endl;
        filestream<<"the list after the sorting is : ";
        for(int i=0;i<n;i++)
        {
            filestream<<arr[i]<<" ";
        }
        if(n%2==0)
        {
        filestream<<endl<<"The given n is even then : Median=((n/2)th+((n/2)+1)th)/2."<<endl;
        float z=arr[((n/2)-1)];
        float y=arr[((n/2)+1)-1];
        filestream<<"(n/2)th term : "<<z<<endl;
        filestream<<"((n/2)+1)th term : "<<y<<endl;
        float k=(z+y)/2;
        filestream<<"The median of "<<n<<" observations are : "<<fixed<<setprecision(3)<<k<<endl;
        }
        else
        {
        filestream<<endl<<"The given n is odd then : "<<endl;
        filestream<<"Median = ((n+1)/2)th term .\n";
        float x=arr[(n)/2];
        float q=(n+1)/2;
        filestream<<"((n+1)/2)th term is "<<q<<"th term of the list ."<<endl;
        filestream<<"The "<<q<<"th term of the list is : "<<x<<endl;
        }
        filestream<<endl;
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    if(n%2==0)
    {
        cout<<"The given n is even then : Median=((n/2)th+((n/2)+1)th)/2."<<endl;
        float z=arr[((n/2)-1)];
        float y=arr[((n/2)+1)-1];
        cout<<"(n/2)th term : "<<z<<endl;
        cout<<"((n/2)+1)th term : "<<y<<endl;
        float k=(z+y)/2;
        cout<<"The median of "<<n<<" observations are : "<<fixed<<setprecision(3)<<k<<endl;
    }
    else
    {
        cout<<"The given n is odd then : "<<endl;
        cout<<"Median = ((n+1)/2)th term .\n";
        float x=arr[(n)/2];
        float q=(n+1)/2;
        cout<<"((n+1)/2)th term is "<<q<<"th term of the list ."<<endl;
        cout<<"The "<<q<<"th term of the list is : "<<x<<endl;
    }
    cout<<endl;
    cout<<"********************************************************************************************************"<<endl;
    
}
void fmedian()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"In case of frequency distribution : "<<endl;
    cout<<"\t \t \t x = x1,x2,x3,_ _ _ _ _ _ _ _ _ ,xn."<<endl;
    cout<<"\t \t \t f = f1,f2,f3,_ _ _ _ _ _ _ _ _ ,fn."<<endl;
    cout<<"\t \t \t N = Σfi ."<<endl;
    cout<<"\t \t \t Then we find (N+1)/2 ."<<endl;
    cout<<"\t \t \t Then we find cumulative frequency just >=(N+1)/2."<<endl;
    cout<<"\t \t \t Then the corresponding value is Median. "<<endl;
    cout<<"********************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr1[n+1],arr2[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr1[i]=a;
        }
        else
        {
            arr1[i]=arr1[i-1]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr2[i]=(arr1[i]+arr1[i+1])/2;
    }
    int arr3[n];
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the fi element "<<i+1<<" : ";
        cin>>arr3[i];
    }
    int arr4[n];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            arr4[i]=arr3[i];
        }
        else
        {
            arr4[i]=arr4[i-1]+arr3[i];
        }
    }  
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<" Intervals \t xi \t fi \t cf(cumulative frequency)"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<"\t\t"<<arr4[i]<<endl;
    } 
    cout<<"------------------------------------------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Median : \n";
        filestream<<"In case of frequency distribution : "<<endl;;
        filestream<<"\t \t \t x = x1,x2,x3,_ _ _ _ _ _ _ _ _ ,xn."<<endl;
        filestream<<"\t \t \t f = f1,f2,f3,_ _ _ _ _ _ _ _ _ ,fn."<<endl;
        filestream<<"\t \t \t N = Σfi ."<<endl;
        filestream<<"\t \t \t Then we find (N+1)/2 ."<<endl;
        filestream<<"\t \t \t Then we find cumulative frequency just >=(N+1)/2."<<endl;
        filestream<<"\t \t \t Then the corresponding value is Median. "<<endl;
        filestream<<"*************************************************************************"<<endl;
        filestream<<"------------------------------------------------------------------------------"<<endl;
        filestream<<" Intervals \t xi \t fi \t cf(cumulative frequency)"<<endl;
        for(int i=0;i<n;i++)
        {
            filestream<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<"\t\t"<<arr4[i]<<endl;
        } 
        filestream<<"------------------------------------------------------------------------------"<<endl;
        float sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr3[i];
        }
        filestream<<"The value of N(Σfi) is : "<<sum<<endl;
        float d=(sum+1)/2;
        int loc;
        filestream<<"The value of (N+1)/2 = "<<d<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr4[i]==d)
            {
                loc=i;
                break;
            }
            else if(arr4[i]>d)
            {
                loc=i;
                break;
            }
        }
        float fin;
        fin=arr2[loc];
        filestream<<"The cf(cumulative frequency)>=((n+1)/2) is : "<<arr4[loc]<<endl;
        filestream<<"Hence the Median is : "<<fixed<<setprecision(3)<<fin<<endl;
        filestream<<endl;
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr3[i];
    }
    cout<<"The value of N(Σfi) is : "<<sum<<endl;
    float d=(sum+1)/2;
    int loc;
    cout<<"The value of (N+1)/2 = "<<d<<endl;
    for(int i=0;i<n;i++)
    {
        if(arr4[i]==d)
        {
            loc=i;
            break;
        }
        else if(arr4[i]>d)
        {
            loc=i;
            break;
        }
    }
    float fin;
    fin=arr2[loc];
    cout<<"The cf(cumulative frequency)>=((n+1)/2) is : "<<arr4[loc]<<endl;
    cout<<"Hence the Median is : "<<fixed<<setprecision(3)<<fin<<endl;
    cout<<"********************************************************************************************************"<<endl;
}
void cfmedian()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"In case of continuous frequency distribution : "<<endl;;
    cout<<"\t \t \t Median : l+h((N/2)-C)/f ."<<endl;
    cout<<"\t \t  Where :  ."<<endl;
    cout<<"\t \t \t l = lower limit of median class ."<<endl;
    cout<<"\t \t \t h = width of median class."<<endl;
    cout<<"\t \t \t f = frequency fo median class."<<endl;
    cout<<"\t \t \t N = Σfi. "<<endl;
    cout<<"\t \t \t C = cumulative frequecy of class predicting the median class . "<<endl;
    cout<<"\t \t \t Median class : class corresponds to c.f. >= N/2 "<<endl;
    cout<<"********************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr1[n+1],arr2[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr1[i]=a;
        }
        else
        {
            arr1[i]=arr1[i-1]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr2[i]=(arr1[i]+arr1[i+1])/2;
    }
    int arr3[n];
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the fi element "<<i+1<<" : ";
        cin>>arr3[i];
    }
    int arr4[n];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            arr4[i]=arr3[i];
        }
        else
        {
            arr4[i]=arr4[i-1]+arr3[i];
        }
    }  
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<" Intervals \t xi \t fi \t cf(cumulative frequency)"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<"\t\t"<<arr4[i]<<endl;
    } 
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Median : \n";
        filestream<<"In case of continuous frequency distribution : "<<endl;;
        filestream<<"\t \t \t Median : l+h((N/2)-C)/f ."<<endl;
        filestream<<"\t \t  Where :  ."<<endl;
        filestream<<"\t \t \t l = lower limit of median class ."<<endl;
        filestream<<"\t \t \t h = width of median class."<<endl;
        filestream<<"\t \t \t f = frequency fo median class."<<endl;
        filestream<<"\t \t \t N = Σfi. "<<endl;
        filestream<<"\t \t \t C = cumulative frequecy of class predicting the median class . "<<endl;
        filestream<<"\t \t \t Median class : class corresponds to c.f. >= N/2 "<<endl;
        filestream<<"*************************************************************************"<<endl;
        filestream<<"------------------------------------------------------------------------------"<<endl;
        filestream<<" Intervals \t xi \t fi \t cf(cumulative frequency)"<<endl;
        for(int i=0;i<n;i++)
        {
            filestream<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<"\t\t"<<arr4[i]<<endl;
        } 
        filestream<<"------------------------------------------------------------------------------"<<endl;
        float sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr3[i];
        }
        filestream<<"The value of N(Σfi) is : "<<sum<<endl;
        float d=(sum)/2;
        filestream<<"The value of (N)/2 = "<<d<<endl;
        int loc;
        for(int i=0;i<n;i++)
        {
            if(arr4[i]==d)
            {
                loc=i;
                break;
            }
            else if(arr4[i]>d)
            {
                loc=i;
                break;
            }
        }   
        float fin,low,flo;
        fin=arr2[loc];
        filestream<<"The value of l is : "<<arr1[loc]<<endl;
        filestream<<"The value of h is : "<<c<<endl;
        filestream<<"The value of f is : "<<arr3[loc]<<endl;
        filestream<<"\t \t \t Median : l+h((N/2)-C)/f ."<<endl;
        filestream<<"\t \t \t "<<arr1[loc]<<"+"<<c<<"(("<<sum<<"/"<<"2)-"<<arr4[loc-1]<<")/"<<arr3[loc]<<endl;
        float fina;
        fina=arr1[loc]+c*(d-arr4[loc-1])/arr3[loc] ;
        filestream<<"\t \t \t Hence the median is : "<<fixed<<setprecision(3)<<fina<<endl;
        filestream<<endl;
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr3[i];
    }
    cout<<"The value of N(Σfi) is : "<<sum<<endl;
    float d=(sum)/2;
    cout<<"The value of (N)/2 = "<<d<<endl;
    int loc;
    for(int i=0;i<n;i++)
    {
        if(arr4[i]==d)
        {
            loc=i;
            break;
        }
        else if(arr4[i]>d)
        {
            loc=i;
            break;
        }
    }
    float fin,low,flo;
    fin=arr2[loc];
    cout<<"The value of l is : "<<arr1[loc]<<endl;
    cout<<"The value of h is : "<<c<<endl;
    cout<<"The value of f is : "<<arr3[loc]<<endl;
    cout<<"\t \t \t Median : l+h((N/2)-C)/f ."<<endl;
    cout<<"\t \t \t "<<arr1[loc]<<"+"<<c<<"(("<<sum<<"/"<<"2)-"<<arr4[loc-1]<<")/"<<arr3[loc]<<endl;
    float fina;
    fina=arr1[loc]+c*(d-arr4[loc-1])/arr3[loc] ;
    cout<<"\t \t \t Hence the median is : "<<fixed<<setprecision(3)<<fina<<endl;
    cout<<"********************************************************************************************************"<<endl;
}
void fmode()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"In case of continuous frequency distribution : "<<endl;
    cout<<"\t \t \t Mode : The value which occurs most frequenty in the list. "<<endl;
    cout<<"********************************************************************************************************"<<endl;
    int n;
    cout<<"enter the Number of elements of the given list : ";
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element "<<i+1<<" : ";
        cin>>arr1[i];
    }
    float temp,pass=0;
    cout<<endl;
    for(int i = 0; i<n; i++) 
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr1[j] < arr1[i]) 
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Mode : \n";
        filestream<<"In case of continuous frequency distribution : "<<endl;
        filestream<<"\t \t \t Mode : The value which occurs most frequenty in the list. "<<endl;
        filestream<<"********************************************************************************************************"<<endl;
        filestream<<"---------------------------------------------------------------------------------------------------"<<endl;
        filestream<<"the sorted list is : ";
        for(int i=0;i<n;i++)
        {
            filestream<<arr1[i]<<" ";
        }
        filestream<<endl;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr1[i+1]!=arr1[i])
            {
                count=count+1;
            }
        }
        int arr2[count],m=0;
        for (int i=0; i<n; i++)
        {
            int j;
            for (j=0; j<i; j++)
            {

                if (arr1[i] == arr1[j])
                break;
            }
            if (i == j)
            {
                if(m<count)
                {
                    arr2[m]=arr1[i];
                }
                m=m+1;
            } 
        }
        int arr3[count];
        for(int i=0;i<count;i++)
        {
            int s=arr2[i],sum=0;
            for(int j=0;j<n;j++)
            {
                if(s==arr1[j])
                {
                    sum=sum+1;
                }
            }
            arr3[i]=sum;
        }   
        filestream<<"The time of occurance of each element in the list : "<<endl;
        for(int i=0;i<count;i++)
        {   
            filestream<<"["<<arr2[i]<<":"<<arr3[i]<<"] ";
        }
        filestream<<endl;
        float max=arr3[0];
        for(int i=0;i<count;i++)
        {
            if(max<arr3[i])
            {
                max=arr3[i];
            }
        }
        int loc;
        for(int i=0;i<count ;i++)
        {
            if(max==arr3[i])
            {
                loc=i;
                break;
            }        
        }
        int carry=0;
        for(int i=0;i<count;i++)
        {
            if(arr3[i]==1)
            {
                carry=carry+1;
            }
        }
        if(carry==n)
        {
            filestream<<"the mode is not found because every element comes one time in the list.";
        }
        else
        {
            filestream<<"Hence the mode of the given list is : "<<arr2[loc]<<endl;
            filestream<<"It comes "<<max<<" times in the list .";
        }   
        filestream<<endl;
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"the sorted list is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr1[i+1]!=arr1[i])
        {
            count=count+1;
        }
    }
    int arr2[count],m=0;
    for (int i=0; i<n; i++)
    {
        int j;
        for (j=0; j<i; j++)
        {

           if (arr1[i] == arr1[j])
               break;
        }
        if (i == j)
        {
            if(m<count)
            {
                arr2[m]=arr1[i];
            }
            m=m+1;
        } 
    }
    int arr3[count];
    for(int i=0;i<count;i++)
    {
        int s=arr2[i],sum=0;
        for(int j=0;j<n;j++)
        {
            if(s==arr1[j])
            {
                sum=sum+1;
            }
        }
        arr3[i]=sum;
    }
    cout<<"The time of occurance of each element in the list : "<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"["<<arr2[i]<<":"<<arr3[i]<<"] ";
    }
    cout<<endl;
    int max=arr3[0];
    for(int i=0;i<count;i++)
    {
        if(max<arr3[i])
        {
            max=arr3[i];
        }
    }
    int loc;
    for(int i=0;i<count ;i++)
    {
        if(max==arr3[i])
        {
            loc=i;
            break;
        }
        
    }
    int carry=0;
    for(int i=0;i<count;i++)
    {
        if(arr3[i]==1)
        {
            carry=carry+1;
        }
    }
    if(carry==n)
    {
        cout<<"the mode is not found because every element comes one time in the list.";
    }
    else
    {
        cout<<"Hence the mode of the given list is : "<<arr2[loc]<<endl;
        cout<<"It comes "<<max<<" times in the list .";
    }
    cout<<endl;
    cout<<"********************************************************************************************************"<<endl;
    cout<<endl;
}
void cfmode()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"In case of continuous frequency distribution : "<<endl;;
    cout<<"\t \t \t Mode : l+((fm-f1)/(2*fm-f1-f2))*h ."<<endl;
    cout<<"\t \t  Where :  ."<<endl;
    cout<<"\t \t \t l = lower limit of model class ."<<endl;
    cout<<"\t \t \t h = width of model class."<<endl;
    cout<<"\t \t \t fm = frequency fo model class."<<endl;
    cout<<"\t \t \t f1 & f2 : frequency of the class preceding & succeding of the model class."<<endl;
    cout<<"\t \t \t Model class : class of maximum frequency. "<<endl;
    cout<<"********************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr1[n+1],arr2[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr1[i]=a;
        }
        else
        {
            arr1[i]=arr1[i-1]+c;
        }
    }
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the fi element "<<i+1<<" : ";
        cin>>arr2[i];
    }
    int max=arr2[0];
    for(int i=0;i<n;i++)
    {
        if(max<arr2[i])
        {
            max=arr2[i];
        }
    }
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<" Intervals \t  fi "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<endl;
    } 
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Mode : \n";
        filestream<<"In case of continuous frequency distribution : "<<endl;;
        filestream<<"\t \t \t Mode : l+((fm-f1)/(2*fm-f1-f2))*h ."<<endl;
        filestream<<"\t \t  Where :  ."<<endl;
        filestream<<"\t \t \t l = lower limit of model class ."<<endl;
        filestream<<"\t \t \t h = width of model class."<<endl;
        filestream<<"\t \t \t fm = frequency fo model class."<<endl;
        filestream<<"\t \t \t f1 & f2 : frequency of the class preceding & succeding of the model class."<<endl;
        filestream<<"\t \t \t Model class : class of maximum frequency. "<<endl;
        filestream<<"********************************************************************************************************"<<endl;
        filestream<<"----------------------------------------------------------------------------------------------"<<endl;
        filestream<<" Intervals \t  fi "<<endl;
        for(int i=0;i<n;i++)
        {
        filestream<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<endl;
        } 
        filestream<<"----------------------------------------------------------------------------------------------"<<endl;
        int loc;
        for(int i=0;i<n;i++)
        {
            if(max==arr2[i])
            {
                loc=i;
                break;
            }
        }
        float l=0,h=0,f=0,fm=0,f1=0,f2=0;
        l=arr1[loc];
        h=c;
        fm=arr2[loc];
        f1=arr2[loc-1];
        f2=arr2[loc+1];
        filestream<<"the value of l is : "<<l<<endl;
        filestream<<"the value of h is : "<<h<<endl;
        filestream<<"the value of fm is : "<<fm<<endl;
        filestream<<"the value of f1(preceding frequency of model class) is : "<<f1<<endl;
        filestream<<"the value of f2(successor frequency of model class) is : "<<f2<<endl;
        filestream<<"Mode : l+((fm-f1)/(2*fm-f1-f2))*h"<<endl;
        filestream<<"Mode : ("<<l<<"+"<<"(("<<fm<<"-"<<f1<<")/(2*"<<fm<<"-"<<f1<<"-"<<f2<<"))*"<<c<<")"<<endl;
        float fina;
        fina=(l+((fm-f1)/(2*fm-f1-f2))*c);
        filestream<<"Hence the Mode is : "<<fina <<endl;
        filestream<<endl;
        filestream<<"*************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    int loc;
    for(int i=0;i<n;i++)
    {
        if(max==arr2[i])
        {
            loc=i;
            break;
        }
    }
    float l=0,h=0,f=0,fm=0,f1=0,f2=0;
    l=arr1[loc];
    h=c;
    fm=arr2[loc];
    f1=arr2[loc-1];
    f2=arr2[loc+1];
    cout<<"the value of l is : "<<l<<endl;
    cout<<"the value of h is : "<<h<<endl;
    cout<<"the value of fm is : "<<fm<<endl;
    cout<<"the value of f1(preceding frequency of model class) is : "<<f1<<endl;
    cout<<"the value of f2(successor frequency of model class) is : "<<f2<<endl;
    cout<<"Mode : l+((fm-f1)/(2*fm-f1-f2))*h"<<endl;
    cout<<"Mode : ("<<l<<"+"<<"(("<<fm<<"-"<<f1<<")/(2*"<<fm<<"-"<<f1<<"-"<<f2<<"))*"<<c<<")"<<endl;
    float fina;
    fina=(l+((fm-f1)/(2*fm-f1-f2))*c);
    cout<<"Hence the Mode is : "<<fina <<endl;
    cout<<"********************************************************************************************************"<<endl;
}
void igeormetricmean()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"\t \t x : x1,x2,x3,............,xn\n";
    cout<<"\t \t G.M : (x1,x2,x3,......xn)^1/n\n";
    cout<<"\t \t G.M : 1/n*(log(x1)+log(x2)+log(x3)+........+log(xn))\n";
    cout<<"\t \t G.M : 1/n*Σlog(xi)\n";
    cout<<"\t \t G.M : Antilog(1/n*Σlog(xi))\n";
    cout<<"********************************************************************************************************"<<endl;
    
    int n;
    cout<<"enter the number of elements : ";
    cin>>n;
    float arr1[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element "<<i+1<<" : ";
        cin>>arr1[i];
    }
    float a;
    for(int i=0;i<n;i++)
    {
        a=arr1[i];
        arr1[i]=log(a);
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr1[i];
    }
    cout<<"G.M : Antilog(1/n*Σlog(xi))\n";
    cout<<"G.M : Antilog(1/"<<n<<"*"<<sum<<")"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Geometric Mean : \n";
        filestream<<"\t \t x : x1,x2,x3,............,xn\n";
        filestream<<"\t \t G.M : (x1,x2,x3,......xn)^1/n\n";
        filestream<<"\t \t G.M : 1/n*(log(x1)+log(x2)+log(x3)+........+log(xn))\n";
        filestream<<"\t \t G.M : 1/n*Σlog(xi)\n";
        filestream<<"\t \t G.M : Antilog(1/n*Σlog(xi))\n";
        filestream<<"********************************************************************************************************"<<endl;
        filestream<<"G.M : Antilog(1/n*Σlog(xi))\n";
        filestream<<"G.M : Antilog(1/"<<n<<"*"<<sum<<")"<<endl;
        sum=(sum)/n;
        float logbasee;
        logbasee= pow(2.718281828,sum);
        filestream<<"the Geometric mean for the given is : "<<logbasee<<endl;
    }
    else cout<<"file opening is fail.\n";
    sum=(sum)/n;
    float logbasee;
    logbasee= pow(2.718281828,sum);
    cout<<"the Geometric mean for the given is : "<<logbasee<<endl;
    cout<<"********************************************************************************************************"<<endl;
}
void fgeometricmean()
{
    cout<<"********************************************************************************************************"<<endl;
    cout<<"\t\t Geometric Mean in terms of frequency distribution : "<<endl;
    cout<<"\t \t x : x1,x2,x3,............,xn\n";
    cout<<"\t \t f : f1,f2,f3,............,fn\n";
    cout<<"\t \t G.M : (x1^f1.x2^f2.x3^f3.......xn^fn)^1/n\n";
    cout<<"\t \t G.M : 1/n*(log(x1)+log(x2)+log(x3)+........+log(xn))\n";
    cout<<"\t \t G.M : 1/n*Σlog(xi)\n";
    cout<<"\t \t G.M : Antilog(1/n*Σlog(xi))\n";
    cout<<"********************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr1[n+1],arr2[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr1[i]=a;
        }
        else
        {
            arr1[i]=arr1[i-1]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr2[i]=(arr1[i]+arr1[i+1])/2;
    }
    float l;
    l=arr2[n/2];
    int arr3[n];
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\t enter the fi element "<<i+1<<" : ";
        cin>>arr3[i];
    }
    float arr4[n];
    for(int i=0;i<n;i++)
    {
        arr4[i]=(arr2[i]-l)/c;
    }
    float q;
    for(int i=0;i<n;i++)
    {
        q=arr2[i];
        arr4[i]=log(q);
    }
    float arr5[n];
    for(int i=0;i<n;i++)
    {
        arr5[i]=arr2[i]*arr4[i];
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<" Intervals \t xi \t fi \t log(xi) \t fi.log(xi) "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<" \t "<<arr4[i]<<" \t "<<arr5[i]<<endl;
    } 
    cout<<"----------------------------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"Geometric Mean : \n";
        filestream<<"\t\t Geometric Mean in terms of frequency distribution : "<<endl;
        filestream<<"\t \t x : x1,x2,x3,............,xn\n";
        filestream<<"\t \t f : f1,f2,f3,............,fn\n";
        filestream<<"\t \t G.M : (x1^f1.x2^f2.x3^f3.......xn^fn)^1/n\n";
        filestream<<"\t \t G.M : 1/n*(log(x1)+log(x2)+log(x3)+........+log(xn))\n";
        filestream<<"\t \t G.M : 1/n*Σlog(xi)\n";
        filestream<<"\t \t G.M : Antilog(1/n*Σlog(xi))\n";
        filestream<<"********************************************************************************************************"<<endl;
        filestream<<"----------------------------------------------------------------"<<endl;
        filestream<<" Intervals \t xi \t fi \t log(xi) \t fi.log(xi) "<<endl;
        for(int i=0;i<n;i++)
        {
            filestream<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<" \t "<<arr4[i]<<" \t "<<arr5[i]<<endl;
        } 
        filestream<<"----------------------------------------------------------------"<<endl;
        float sumfilogxi=0,sumfi=0;
        for(int i=0;i<n;i++)
         {
            sumfilogxi += arr5[i];
            sumfi+=arr3[i];
        }
        sumfilogxi=(1/sumfi)*sumfilogxi;
        float logbasee;
        logbasee=pow(2.718281828,sumfilogxi);
        filestream<<"Hence the Geometric Mean is : "<<logbasee<<endl;
        filestream<<"********************************************************************************************************"<<endl;
    }
    else cout<<"file opening is fail.\n";
    float sumfilogxi=0,sumfi=0;
    for(int i=0;i<n;i++)
    {
        sumfilogxi += arr5[i];
        sumfi+=arr3[i];
    }
    sumfilogxi=(1/sumfi)*sumfilogxi;
    float logbasee;
    logbasee=pow(2.718281828,sumfilogxi);
    cout<<"Hence the Geometric Mean is : "<<logbasee<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
}
void harmonicmean()
{
    cout<<"********************************************************************************************************************"<<endl;
    cout<<"\t\t Harmonic mean : \n";
    cout<<"\t\t In case of Individual obervation : \n";
    cout<<"\t\t x : x1,x2,x3,_ _ _ _ _ _ _ _ _,xn.\n";
    cout<<"\t\t H.M. : (1/((1/n)*(Σ(1/xi)))) \n";
    cout<<"********************************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of elements to be enter(n) : ";
    cin>>n;
    int arr[n];
    float arr1[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value of x"<<i+1<<" : ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        float a;
        a=arr[i];
        arr1[i]=(1/a);
    }
    cout<<"--------------------------------------------------\n";
    cout<<"\t x \t 1/x \n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<arr[i]<<"\t  ";
        cout<<fixed<<setprecision(4)<<arr1[i]<<endl;
    }
    cout<<"--------------------------------------------------\n";
    ofstream filestream("mydata.txt",ios::app);
    if (filestream.is_open())
    {
        filestream<<"\t\t Harmonic mean : \n";
        filestream<<"\t\t In case of Individual obervation : \n";
        filestream<<"\t\t x : x1,x2,x3,_ _ _ _ _ _ _ _ _,xn.\n";
        filestream<<"\t\t H.M. : (1/((1/n)*(Σ(1/xi)))) \n";
        filestream<<"********************************************************************************************************************"<<endl;
        filestream<<"--------------------------------------------------\n";
        filestream<<"\t x \t   1/x \n";
        for(int i=0;i<n;i++)
        {
            filestream<<"\t "<<arr[i]<<"\t  ";
            filestream<<fixed<<setprecision(4)<<arr1[i]<<endl;
        }
        filestream<<"--------------------------------------------------\n";
        float sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr1[i];
        }
        filestream<<"the value of (Σ(1/xi)) : "<<sum<<endl;
        float fina;
        fina=(n/sum);
        filestream<<"the H.M is : "<<fina<<endl;
        filestream<<"********************************************************************************************************************"<<endl;

    }
    else cout<<"the file is not open .\n";
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr1[i];
    }
    cout<<"the value of (Σ(1/xi)) : "<<sum<<endl;
    float fina;
    fina=(n/sum);
    cout<<"the H.M is : "<<fina<<endl;
    cout<<"********************************************************************************************************************"<<endl;
}
void fharmonicmean()
{
    cout<<"********************************************************************************************************************"<<endl;
    cout<<"\t\t Harmonic mean : \n";
    cout<<"\t\t In case of frequency distribution : \n";
    cout<<"\t\t x : x1,x2,x3,_ _ _ _ _ _ _ _ _,xn.\n";
    cout<<"\t\t f : f1,f2,f3,_ _ _ _ _ _ _ _ _,fn.\n";
    cout<<"\t\t H.M. : (1/((1/N)*(Σ(fi/xi)))) \n";
    cout<<"\t\t where N : it is Σfi \n";
    cout<<"********************************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of elements to be enter(n) : ";
    cin>>n;
    int arr2[n],arr3[n];
    float arr4[n];
    float el,dif;
    cout<<"enter the first element of xi : ";
    cin>>el;
    cout<<"enter the difference between any two xi : ";
    cin>>dif;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            arr2[i]=el;
        }
        else
        {
            arr2[i]=arr2[i-1]+dif;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value of f"<<i+1<<" : ";
        cin>>arr3[i];
    }
    for(int i=0;i<n;i++)
    {
        float a,b;
        b=arr2[i];
        a=arr3[i];
        arr4[i]=a/b;
    }
    cout<<"--------------------------------------------------\n";
    cout<<"\t xi \t fi \t fi/xi \n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t  "<<arr2[i]<<"\t  "<<arr3[i]<<"\t";
        cout<<fixed<<setprecision(4)<<arr4[i]<<endl;
    }
    cout<<"--------------------------------------------------\n";
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"\t\t Harmonic mean : \n";
        filestream<<"\t\t In case of frequency distribution : \n";
        filestream<<"\t\t x : x1,x2,x3,_ _ _ _ _ _ _ _ _,xn.\n";
        filestream<<"\t\t f : f1,f2,f3,_ _ _ _ _ _ _ _ _,fn.\n";
        filestream<<"\t\t H.M. : (1/((1/N)*(Σ(fi/xi)))) \n";
        filestream<<"\t\t where N : it is Σfi \n";
        filestream<<"--------------------------------------------------\n";
        filestream<<"\t xi \t fi \t fi/xi \n";
        for(int i=0;i<n;i++)
        {
            filestream<<"\t  "<<arr2[i]<<"\t  "<<arr3[i]<<"\t";
            filestream<<fixed<<setprecision(4)<<arr4[i]<<endl;
        }
        filestream<<"--------------------------------------------------\n";
        float sum,sumfi;
        for(int i=0;i<n;i++)
        {
            sumfi=sumfi+arr3[i];
            sum=sum+arr4[i];
        }
        filestream<<"the value of N(Σfi) is  : "<<sumfi<<endl;
        filestream<<"the value of (Σ(1/xi)) : "<<sum<<endl;
        float fina;
        fina=(sumfi/sum);
        filestream<<"the H.M is : "<<fina<<endl;
        filestream<<"********************************************************************************************************************"<<endl;
    }
    else cout<<"the file is not opened.\n";
    float sum,sumfi;
    for(int i=0;i<n;i++)
    {
        sumfi=sumfi+arr3[i];
        sum=sum+arr4[i];
    }
    cout<<"the value of N(Σfi) is  : "<<sumfi<<endl;
    cout<<"the value of (Σ(1/xi)) : "<<sum<<endl;
    float fina;
    fina=(sumfi/sum);
    cout<<"the H.M is : "<<fina<<endl;
    cout<<"*****************************************************************************************"<<endl;
}
void cfharmonicmean()
{
    cout<<"********************************************************************************************************************"<<endl;
    cout<<"\t\t Harmonic mean : \n";
    cout<<"\t\t In case of continuous frequency distribution : \n";
    cout<<"\t\t x : x1,x2,x3,_ _ _ _ _ _ _ _ _,xn.\n";
    cout<<"\t\t f : f1,f2,f3,_ _ _ _ _ _ _ _ _,fn.\n";
    cout<<"\t\t H.M. : (1/((1/N)*(Σ(fi/xi)))) \n";
    cout<<"\t\t where N : it is Σfi \n";
    cout<<"********************************************************************************************************************"<<endl;
    int n;
    cout<<"enter the number of intervals : ";
    cin>>n;
    int arr1[n+1],arr2[n];
    float a,c;
    cout<<"enter the first interval lower limit : ";
    cin>>a;
    cout<<"enter the difference of any interval : ";
    cin>>c;
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            arr1[i]=a;
        }
        else
        {
            arr1[i]=arr1[i-1]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr2[i]=(arr1[i]+arr1[i+1])/2;
    }
    int arr3[n];
    cout<<"enter the elements of the fi(frequency) === "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the fi element "<<i+1<<" : ";
        cin>>arr3[i];
    }
    float arr4[n];
    for(int i=0;i<n;i++)
    {
        float a,b;
        b=arr2[i];
        a=arr3[i];
        arr4[i]=a/b;
    }
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<" Intervals \t xi \t fi \t fi.xi"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<" \t "<<arr4[i]<<endl;
    } 
    cout<<"-------------------------------------------------------------"<<endl;
    ofstream filestream("mydata.txt",ios::app);
    if(filestream.is_open())
    {
        filestream<<"\t\t Harmonic mean : \n";
        filestream<<"\t\t In case of continuous frequency distribution : \n";
        filestream<<"\t\t x : x1,x2,x3,_ _ _ _ _ _ _ _ _,xn.\n";
        filestream<<"\t\t f : f1,f2,f3,_ _ _ _ _ _ _ _ _,fn.\n";
        filestream<<"\t\t H.M. : (1/((1/N)*(Σ(fi/xi)))) \n";
        filestream<<"\t\t where N : it is Σfi \n";
        filestream<<"********************************************************************************************************************"<<endl;
        filestream<<"--------------------------------------------"<<endl;
        filestream<<" Intervals \t xi \t fi \t fi.xi"<<endl;
        for(int i=0;i<n;i++)
        {
            filestream<<" "<<arr1[i]<<" - "<<arr1[i+1]<<" \t "<<arr2[i]<<" \t "<<arr3[i]<<" \t "<<arr4[i]<<endl;
        } 
        filestream<<"--------------------------------------------"<<endl;
        float sum,sumfi;
         for(int i=0;i<n;i++)
        {
            sumfi=sumfi+arr3[i];
            sum=sum+arr4[i];
        }
        filestream<<"the value of N(Σfi) is  : "<<sumfi<<endl;
        filestream<<"the value of (Σ(fi/xi)) : "<<sum<<endl;
        float fina;
        fina=(sumfi/sum);
        filestream<<"the H.M is : "<<fina<<endl;
        filestream<<"*****************************************************************************************"<<endl;
    }
    else cout<<"the file is not open .\n";
    float sum,sumfi;
    for(int i=0;i<n;i++)
    {
        sumfi=sumfi+arr3[i];
        sum=sum+arr4[i];
    }
    cout<<"the value of N(Σfi) is  : "<<sumfi<<endl;
    cout<<"the value of (Σ(fi/xi)) : "<<sum<<endl;
    float fina;
    fina=(sumfi/sum);
    cout<<"the H.M is : "<<fina<<endl;
    cout<<"*****************************************************************************************"<<endl;
}
int main()
{
    int choice;
    while(choice!=6)
    {
        int s;
        cout<<"1.Mean\n2.Median\n3.Mode\n4.Geometric Mean\n5.Harmonic Mean\n6.Exit.\n";
        cout<<"enter the option you want to do : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Mean: "<<endl;
            cout<<"   1.In case of individual observation ."<<endl;
            cout<<"   2.In case of discrete frequency distribution ."<<endl;
            cout<<"   3.In case of continuous frequency distribution ."<<endl;
            cout<<"enter your choice : ";
            cin>>s;
            switch(s)
            {
                case 1: imean(); break;
                case 2: fmean(); break;
                case 3: cfmean(); break;
                case 4: cout<<"exit."; break;
            }
        }
        if(choice==2)
        {
            cout<<"Median : "<<endl;
            cout<<"   1.In case of individual observation ."<<endl;
            cout<<"   2.In case of discrete frequency distribution ."<<endl;
            cout<<"   3.In case of continuous frequency distribution ."<<endl;
            cout<<"enter your choice : ";
            cin>>s;
            switch(s)
            {
                case 1: imedian(); break;
                case 2: fmedian(); break;
                case 3: cfmedian(); break;
                case 4: cout<<"exit."; break;
            }
        }
        if(choice==3)
        {
            cout<<"Mode : The value which occurs most frequenty in the list. "<<endl;
            cout<<"   1.In case of discrete frequency distribution ."<<endl;
            cout<<"   2.In case of continuous frequency distribution ."<<endl;
            cout<<"enter your choice : ";
            cin>>s;
            switch(s)
            {
                case 1: fmode(); break;
                case 2: cfmode(); break;
                case 3: cout<<"exit."; break;
            }
        }
        if(choice==4)
        {
            cout<<"GEOMETRIC MEAN : \n";
            cout<<"1.In case of Individual obseravation. \n";
            cout<<"2.In case of frequency distribution. \n";
            cout<<"enter your choice : ";
            cin>>s;
            switch(s)
            {
                case 1: igeormetricmean(); break;
                case 2: fgeometricmean(); break;
                case 3: cout<<"exit."; break;
            }
        }
        if(choice==5)
        {
            cout<<"Harmonic Mean : "<<endl;
            cout<<"1.In case of Individual obseravation. \n";
            cout<<"2.In case of frequency distribution. \n";
            cout<<"3.In case of continuous frequency distrubution .\n";
            cout<<"enter your choice : ";
            cin>>s;
            switch(s)
            {
                case 1: harmonicmean(); break;
                case 2: fharmonicmean(); break;
                case 3: cfharmonicmean(); break;
                case 4: cout<<"exit."; break;
            }
        }
        if(choice ==6)
        {
            cout<<"exit";
            break;
        }
        else
        {
            cout<<"choose a correct choice : "<<endl;
        } 
    }
    return 0;
}
