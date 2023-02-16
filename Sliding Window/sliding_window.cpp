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


// Time Complexity :- O(n)
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

void Sliding_Window();

int32_t main() 
{
    //Calling the Sliding_Window function
    Sliding_Window();
    return 0;
}

void Sliding_Window()
{
    //Taking Input of Array Size
    ll arr_size;
    cout<<"\nEnter the Size of Array : ";
    cin>>arr_size;

    //Taking Input of Window Size
    ll win_size;
    cout<<"\nEnter the Window Size (In Most Problems (K value)) : ";
    cin>>win_size;

    if(win_size > arr_size)
    {
        cout<<"\nWindow Size Greater than Array Size";
        return;
    }

    cout<<endl;

    vector<ll> arr(arr_size);

    //Taking Input of Each Element of Array
    for (ll i = 0; i < arr_size; ++i)
    {
        cout<<"Enter ["<<i+1<<"]th Element : ";
        cin>>arr[i];
    }

    //Initializing two pointers

    ll indx_i = 0;            //-->First Pointer Starting from first ELement (0th Index)
    ll indx_j = 0;            //-->Second Pointer Starting from first ELement (0th Index)

    //Initializing the Maximum_Sum and Minimum_Sum Variables
    ll max_sum = INT_MIN;     
    ll min_sum = INT_MAX;

    //INitializing the Temporary Sum Variable 
    ll sum = 0;

    //In this while loop we will be traversing the Array till we get the Window Size

    /*

    Eg :- arr = [1,2,3,4,5] then

    arr elements :- 1 2 3 4 5 
    arr index    :- 0 1 2 3 4

    Suppose K (Window Size) = 3
    Then,
    First Iteration :- indx_i = 0 & indx_j = 0    -----> (We will add it to the Temporary Sum Variable and Increment indx_j)
    Second Iteration :- indx_i = 0 & indx_j = 1   -----> (We will add it to the Temporary Sum Variable and Increment indx_j)
    Third Iteration :- indx_i = 0 & indx_j = 2    -----> (We will add it to the Temporary Sum Variable and Increment indx_j)

    Now the we got the Window of are Required Size (0 1 2 = 3) 
    Hence the while loop will be terminated
      
    */
    while((indx_j - indx_i + 1) < win_size)
    {
        sum += arr[indx_j];
        indx_j++;
    }

    //Traversing for n-k+1 times

    /*

    Considering the above Example
    Eg :- arr = [1,2,3,4,5] then
    n-k+1 = 5-3+1 = 3
    here,
    n --> arr.size() --> Size of the Array
    k --> win_size   --> Size of the Window

    arr elements :- 1 2 3 4 5 
    arr index    :- 0 1 2 3 4

    First Iteration :- (0 1 2) Indexs
    Second Iteration :- (1 2 3) Indexs
    Third Iteration :- (2 3 4) Indexs

    n-k+1 ~= arr.size() - win_size + 1

    */
    for (ll i = 0; i < (arr.size() - win_size + 1); i++)
    {
        sum += arr[indx_j];
        max_sum = max(max_sum,sum);
        min_sum = min(min_sum,sum);
        sum -= arr[indx_i];
        indx_j++;
        indx_i++;
    }

    //Printing the Maximum & Minimum Sum of the Given Default Array
    cout<<"\nMaximum Sum with Window Size ["<<win_size<<"] is : "<<max_sum;
    cout<<"\nMinimum Sum with Window Size ["<<win_size<<"] is : "<<min_sum;
}
