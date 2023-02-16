/*  
      *******                                        *                                  
    *       ***      *                             **                                   
   *         **     **                             **                                   
   **        *      **                             **                                   
    ***           ********            ***  ****    **            ****    **   ****      
   ** ***        ********     ****     **** **** * ** ****      * ***  *  **    ***  *  
    *** ***         **       * ***  *   **   ****  *** ***  *  *   ****   **     ****   
      *** ***       **      *   ****    **         **   ****  **    **    **      **    
        *** ***     **     **    **     **         **    **   **    **    **      **    
          ** ***    **     **    **     **         **    **   **    **    **      **    
           ** **    **     **    **     **         **    **   **    **    **      **    
            * *     **     **    **     **         **    **   **    **    **      **    
  ***        *      **     **    **     ***        **    **    ******      *********    
 *  *********        **     ***** **     ***        *****       ****         **** ***   
*     *****                  ***   **                ***                           ***  
*                                                                           *****   *** 
 **                                                                       ********  **  
                                                                          *      ****    
               _oo0oo_                                                                                                                   
              o8888888o 
              88" . "88 
              (| -_- |) 
              0\  =  /0 
            ___/`---'\___ 
          .' \\|     |// '. 
         / \\|||  :  |||// \ 
        / _||||| -:- |||||- \ 
       |   | \\\  -  /// |   | 
       | \_|  ''\---/''  |_/ | 
       \  .-\__  '-'  ___/-. / 
     ___'. .'  /--.--\  `. .'___ 
  ."" '<  `.___\_<|>_/___.' >' "". 
 | | :  `- \`.;`\ _ /`;.`/ - ` : | | 
 \  \ `_.   \_ __\ /__ _/   .-` /  / 
=====`-.____`.___ \_____/___.-`___.-'===== 
               `=---=' 
*/

/*

WRITTEN BY :-

   **        
     *****        
    *  ***        
       ***        
      *  **       
      *  **       
     *    **      
     *    **      
    *      **     
    *********     
   *        **    
   *        **    
  *****      **   
 *   ****    ** * MEYA CHAVAN
*     **      **  
*                 
 ** 

*/


// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl "\n";
#define debug(x) cout<< #x <<" "<< x <<endl;

void Print_Result(vector<ll> &numbers, vector<ll> &index);
void Two_Pointer();

int32_t main() 
{
    //Calling the Two_Pointer function
    Two_Pointer();
    return 0;
}

void Print_Result(vector<ll> &numbers, vector<ll> &index)
{
    if(numbers.size() == 0)
    {
        cout<<"\nNo Pairs Found";
        return;
    }

    //If the above condition is False then Print the Pairs
    cout<<"\nPairs Found :- ";
    for (ll i = 0; i < numbers.size(); ++i)
    {
        cout<<"|"<<numbers[i]<<"|";
        if(i < numbers.size() - 1)
        {
            cout<<"-";
        }
    }
    
    //Print the Index of the Pairs (Index will be According to the Sorted Array Index)
    cout<<"\nPairs Index :- ";
    for (ll i = 0; i < index.size(); ++i)
    {
        cout<<"|"<<index[i]<<"|";
        if(i < index.size() - 1)
        {
            cout<<"-";
        }
    }
}

void Two_Pointer()
{
    //Taking Input of Array Size
    ll arr_size;
    cout<<"\nEnter the Size of Array : ";
    cin>>arr_size;

    //Taking Input of Target (Sum of any two Elements in the Array)
    ll target;
    cout<<"\nEnter the Target (Sum of any two Elements in the Array) : ";
    cin>>target;

    cout<<endl;

    vector<ll> arr(arr_size);

    //Taking Input of Each Element of Array
    for (ll i = 0; i < arr_size; ++i)
    {
        cout<<"Enter ["<<i+1<<"]th Element : ";
        cin>>arr[i];
    }

    //Printing the Array without Sorting
    cout<<"\nArray Before Sorting :- ";

    for (ll i = 0; i < arr.size(); ++i)
    {
        cout<<"|"<<arr[i]<<"|";
        if(i < arr.size() - 1)
        {
            cout<<"-";
        }
    }

    cout<<endl;

    //Sorting the Array 
    sort(arr.begin(),arr.end());

    //Printing the Array after Sorting
    cout<<"\nArray After Sorting  :- ";

    for (ll i = 0; i < arr.size(); ++i)
    {
        cout<<"|"<<arr[i]<<"|";
        if(i < arr.size() - 1)
        {
            cout<<"-";
        }
    }

    //Printing the Index of Array (The Index will be same for Default and Sorted Array) 
    cout<<"\nIndex of Array       :- ";

    for (ll i = 0; i < arr.size(); ++i)
    {
        cout<<"|"<<i<<"|";
        if(i < arr.size() - 1)
        {
            cout<<"-";
        }
    }
    
    cout<<endl;

    //Initializing both the Pointers

    ll start_indx = 0;              //-->First Pointer Starting from 0th Index of Array
    ll end_indx = arr.size() - 1;   //-->Second Pointer Starting from last Index of Array (n-1)

    //Always Second Pointer (n-1) should be Greater than the First Pointer

    vector<ll> pairs;               //-->Initializing an Array to store the Pair of Elements if the Addition of both Elements is eqaul to the Target
    vector<ll> pairs_indx;          //-->Initializing an Array to store the Index of the Pairs Found

    while(end_indx > start_indx)
    {
        if(arr[start_indx] + arr[end_indx] > target)            //If Sum of Two Elements is Greater than Target then Decrease the Second Pointer
        {
            end_indx--;
        }
        else if(arr[start_indx] + arr[end_indx] < target)       //If Sum of Two Elements is Less than Target then Increase the First Pointer
        {
            start_indx++;
        }
        else
        {   
            //If both the above Conditions are False that means We Successfully Found the Pairs whose Sum is Equal to the given Target

            //Insert both the Intergers as well as their Index  
            pairs.push_back(arr[start_indx]);
            pairs.push_back(arr[end_indx]);
            pairs_indx.push_back(start_indx);
            pairs_indx.push_back(end_indx);
            end_indx--;
            start_indx++;
        }
    }

    //Calling the Print Function to Print the Result
    Print_Result(pairs,pairs_indx);
}
