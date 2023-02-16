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

void Custom_Sort(vector<tuple<int,int,double>> &input);
double Maximum_Profit(vector<tuple<int,int,double>> &input, int max_weight);

int32_t main() 
{
	int size;
	cin>>size;
	vector<tuple<int,int,double>> input;
	for(int i = 0; i < size; ++i)
	{
		tuple<int,int,double> temp;
		int profit,weight = 0;
		cout<<"Enter the ["<<i + 1<<"] Profit & ["<<i + 1<<"] Weight : ";
		cin>>profit>>weight;
		double ratio = (double)profit /  (double)weight;
		temp = make_tuple(profit, weight, ratio);
		input.push_back(temp);
	}

	int max_weight = 0;

	cout<<"\nEnter the Maximum Weight : ";
	cin>>max_weight;

	cout<<endl;
	
	cout<<"\nTuples Before Sorting : "<<endl;
	
	cout<<endl;

	int indx_1 = 0;
	for(auto i : input)
	{
		cout<<"The ["<<indx_1 + 1<<"] Tuple is : ["<<get<0>(i)<<"]    ["<<get<1>(i)<<"]    ["<<get<2>(i)<<"]"<<endl;
		indx_1++;
	}

	Custom_Sort(input);

	cout<<endl;

	cout<<"Tuples After Sorting : "<<endl;

	cout<<endl;

	int indx_2 = 0;
	for(auto i : input)
	{
		cout<<"The ["<<indx_2 + 1<<"] Tuple is : ["<<get<0>(i)<<"]     ["<<get<1>(i)<<"]     ["<<get<2>(i)<<"]"<<endl;
		indx_2++;
	}

	double result = Maximum_Profit(input, max_weight);
	cout<<"\nThe Maximum Profit with the given Maximum Weight is : "<<result<<endl;

	return 0;
}

void Custom_Sort(vector<tuple<int,int,double>> &input)
{
	sort(input.begin(), input.end(), [&](tuple<int,int,double> temp_1, tuple<int,int,double> temp_2) {
			return get<2>(temp_1) > get<2>(temp_2);
			});
}

double Maximum_Profit(vector<tuple<int,int,double>> &input, int max_weight)
{
	double max_profit = 0;
	for(auto i : input)
	{
		int temp_profit = get<0>(i);
		int temp_weight = get<1>(i);
		
		if(max_weight - temp_weight >= 0)
		{
			max_profit += temp_profit;
		}
		else
		{
			max_profit += ((double) max_weight / (double) temp_weight) * (double) temp_profit;
			break;
		}
		max_weight -= temp_weight;
	}
	return max_profit;
}
