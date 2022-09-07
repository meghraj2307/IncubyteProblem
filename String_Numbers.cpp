#include<bits/stdc++.h>
using namespace std;
vector<int> v;
class StringCalculator
{
	public:
		void excep(vector<int> v)
		{
			try
			{
				if(v[0]<0)
				{
					throw v;
				}
			}
			catch (vector<int> v)
			{
				int i;
				cout<<"Exception Occured : " ;
				for(int i=0;i<v.size();i++)
				{
					cout<<v[i]<<" ";
				}
			}
		}
		int add(string Numbers)
		{
			int sum=0,i=0;
			int final_sum=0;
			
			while(i<Numbers.size())
			{
				if(Numbers[i]=='-')
				{
					i++;
					while(i<Numbers.size() && (isdigit(Numbers[i]) || isalpha(Numbers[i])))
					{
						if(isdigit(Numbers[i]))
						{
							sum=sum*10+(Numbers[i]-'0');
						}
						else if(isalpha(Numbers[i]))
						{
							sum=sum*10+(Numbers[i]-'a'+1);
						}
						i++;
					}
					if(sum!=0)
					{
						sum*=(-1);
						v.push_back(sum);
						sum=0;
					}
				}
				else if(isdigit(Numbers[i]) || isalpha(Numbers[i]))
				{
					while(i<Numbers.size() && (isdigit(Numbers[i]) || isalpha(Numbers[i])))
					{
						if(isdigit(Numbers[i]))
						{
							sum=sum*10+(Numbers[i]-'0');
						}
						else if(isalpha(Numbers[i]))
						{
							sum=sum*10+(Numbers[i]-'a'+1);
						}						
						i++;
					}
					if(sum<=1000)
					{
						final_sum+=sum;
						sum=0;
					}
				}
				else
				{
					i++;
					continue;
				}
			}
			
			if(v.size())
			{
				excep(v);
			}
			else
			{
				return final_sum;
			}		
		}
	
		void answer(string S)
		{
			int k=add(S);
			
			cout<<k;
		}
};

int main()
{
	string str;
	
	getline(cin,str);
	
	StringCalculator obj;
	
	obj.answer(str);
}
