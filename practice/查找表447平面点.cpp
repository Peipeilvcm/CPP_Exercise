#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

int dis(const pair<int,int> &pa,const pair<int,int> &pb){
	return (pa.first - pb.first)*(pa.first-pb.first) + 
			(pa.second-pb.second)*(pa.second-pb.second);
}

//447平面点 
int numberOfBoomerangs(vector<pair<int,int> >& points){
	int res = 0;
	for(int i=0;i<points.size();++i){
		unordered_map<int,int> record;
		for(int j=0;j<points.size();++j){
			if(i!=j){
				record[dis(points[i],points[j])]++;
			} 
		}
		
		//变量哈希表,并取值计算 
		for(unordered_map<int,int>::iterator it=record.begin();
				it!=record.end();it++){
			res += (it->second)*(it->second - 1);			
		}
	}
	return res;
}

int main(){
	
	return 0;
}
