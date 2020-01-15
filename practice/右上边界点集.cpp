#include<iostream>
#include<cstdio>

#include<vector>
#include<string>
#include <algorithm>
//#include<map>
//#include<queue>
//#include<string>

using namespace std;

struct Point{
	int x;
	int y;
	Point(int x,int y):x(x),y(y){	}
};

bool cmp(const Point& a, const Point &b){
	if(a.x == b.x){
		return a.y <= b.y;
	}
	return a.x < b.x;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<Point> v(N,Point(0,0));
	for(int i=0;i<N;++i){
		scanf("%d%d",&v[i].x,&v[i].y);
	}
	
	vector<pair<int,int> > res;
	sort(v.begin(),v.end(),cmp);
	
	res.push_back(make_pair(v[N-1].x,v[N-1].y));
	int maxY = v[N-1].y;
	for(int i=N-2;i>=0;i--){
		if(v[i].y >= maxY){
			res.push_back(make_pair(v[i].x,v[i].y));
            maxY = v[i].y;
		}
	}
	for(int i=res.size()-1;i>=0;i--){
		printf("%d %d\n",res[i].first,res[i].second);
	}

	return 0;
}
