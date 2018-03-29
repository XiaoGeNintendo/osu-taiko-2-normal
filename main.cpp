#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <thread>
#include <conio.h>
//#include "D:\C++\test_lib_projects\testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>

bool debug=true;
/*
   Write In New Computer
    By XiaoGeNintendo
	     gwq2017
	Type:
*/

/*
void fo(int id){
	freopen((toString(id)+".txt").c_str(),"w",stdout);
}
*/

vector<pii> pos;
vector<int> t;
vector<int> type;

//128 128 red1
//128 256 red2
//256 128 blue1
//256 256 blue2
pii last;

void button(){
	while(true){
		char ch=getch();
		if(ch=='z'){
			
			
			cout<<"Get z @"<<clock()<<endl;
			if(last.first==0){
				pos.push_back(last=make_pair(128,128));
			}else{	
				if(last.first==256){
					pos.push_back(last=make_pair(last.first-128,last.second));
				}else{
					pos.push_back(last=make_pair(last.first,256-last.second+128));
				}
			}
			type.push_back(4);
			t.push_back(clock());
		}
		if(ch=='x'){
			cout<<"Get x @"<<clock()<<endl;
			if(last.first==0){
				pos.push_back(last=make_pair(256,256));
			}else{
				if(last.first==128){
					pos.push_back(last=make_pair(last.first+128,last.second));
				}else{
					pos.push_back(last=make_pair(last.first,256-last.second+128));
				}
			}
			type.push_back(8);
			t.push_back(clock());
		}
		if(ch=='c'){
			cout<<"Finished!"<<endl;
			
			cout<<"please visit log.txt"<<endl;
			freopen("log.txt","w",stdout);
			for(int i=0;i<pos.size();i++){
				cout<<pos[i].first<<","<<pos[i].second<<","<<t[i]<<","<<1<<","<<type[i]<<",0:0:0:0:"<<endl;
			}
			
			exit(0);
		} 
		if(ch=='v'){
			cout<<"[TEST] Now time:"<<clock()<<endl;
		}
	}
}

void crazy(){
	
	srand(time(0));
	
	cout<<"Crazy mode. Random don and ka. faster bpm makes crazier node."<<endl;
	
	int bpm,sl;
	cout<<"bpm:";
	cin>>bpm;
	
	int dp=60000/bpm;
	
	cout<<"song length of beats:";
	cin>>sl;
	for(int i=0;i<sl;i++){
		if(rand()%2){
			//dong
			if(last.first==0){
				pos.push_back(last=make_pair(128,128));
			}else{	
				if(last.first==256){
					pos.push_back(last=make_pair(last.first-128,last.second));
				}else{
					pos.push_back(last=make_pair(last.first,256-last.second+128));
				}
			}
			type.push_back(4);
			t.push_back(i*dp);
		}else{
			//ka
			
			if(last.first==0){
				pos.push_back(last=make_pair(256,256));
			}else{
				if(last.first==128){
					pos.push_back(last=make_pair(last.first+128,last.second));
				}else{
					pos.push_back(last=make_pair(last.first,256-last.second+128));
				}
			}
			type.push_back(8);
			t.push_back(i*dp);
			
		}
	}
	
	cout<<"Finished!"<<endl;
			
			cout<<"please visit log.txt"<<endl;
			freopen("log.txt","w",stdout);
			for(int i=0;i<pos.size();i++){
				cout<<pos[i].first<<","<<pos[i].second<<","<<t[i]<<","<<1<<","<<type[i]<<",0:0:0:0:"<<endl;
			}
			
			exit(0);
			
} 

void pattern(){
	
	srand(time(0));
	
	cout<<"Pattern mode. don and ka with pattern."<<endl;
	
	int bpm,sl;
	cout<<"bpm:";
	cin>>bpm;
	
	int dp=60000/bpm;
	
	cout<<"song length of beats:";
	cin>>sl;
	
	string pat;
	cout<<"pattern for the beat: D for don and K for ka and O for nothing. will repeat"<<endl;
	cin>>pat;
	
	
	for(int i=0;i<sl;i++){
		if(pat[i%pat.size()]=='D'){
			//dong
			if(last.first==0){
				pos.push_back(last=make_pair(128,128));
			}else{	
				if(last.first==256){
					pos.push_back(last=make_pair(last.first-128,last.second));
				}else{
					pos.push_back(last=make_pair(last.first,256-last.second+128));
				}
			}
			type.push_back(4);
			t.push_back(i*dp);
		}else{
			if(pat[i%pat.size()]=='O') continue;
			//ka
			
			if(last.first==0){
				pos.push_back(last=make_pair(256,256));
			}else{
				if(last.first==128){
					pos.push_back(last=make_pair(last.first+128,last.second));
				}else{
					pos.push_back(last=make_pair(last.first,256-last.second+128));
				}
			}
			type.push_back(8);
			t.push_back(i*dp);
			
		}
	}
	
	cout<<"Finished!"<<endl;
			
			cout<<"please visit log.txt"<<endl;
			freopen("log.txt","w",stdout);
			for(int i=0;i<pos.size();i++){
				cout<<pos[i].first<<","<<pos[i].second<<","<<t[i]<<","<<1<<","<<type[i]<<",0:0:0:0:"<<endl;
			}
			
			exit(0);
			
} 

 void random(){
	
	srand(time(0));
	
	cout<<"Random mode. Randomize everything!! p.s: too fast bpm may cause stacking problem."<<endl;
	
	int bpm,sl;
	cout<<"bpm:";
	cin>>bpm;
	
	int dp=60000/bpm;
	
	cout<<"song length of beats:";
	cin>>sl;
	

	
	for(int i=0;i<sl;i++){
		pos.push_back(make_pair(rand()%256+20,rand()%256+20));
		type.push_back(4+rand()%2*4);
		t.push_back(i*dp);
	}
	
	cout<<"Finished!"<<endl;
			
			cout<<"please visit log.txt"<<endl;
			freopen("log.txt","w",stdout);
			for(int i=0;i<pos.size();i++){
				cout<<pos[i].first<<","<<pos[i].second<<","<<t[i]<<","<<1<<","<<type[i]<<",0:0:0:0:"<<endl;
			}
			
			exit(0);
			
} 


 void snake(){
	
	srand(time(0));
	
	cout<<"Snake mode. Everything is near the last item!! p.s: too fast bpm may cause stacking problem."<<endl;
	
	int bpm,sl;
	cout<<"bpm:";
	cin>>bpm;
	
	int dp=60000/bpm;
	
	cout<<"song length of beats:";
	cin>>sl;
	

	pii last=make_pair(256,256);
	int dx[4]={-5,5,0,0},dy[4]={0,0,5,-5};
	
	for(int i=0;i<sl;i++){
		pos.push_back(last);
		type.push_back(4+rand()%2*4);
		t.push_back(i*dp);
		int r=rand()%4;
		last=make_pair(last.first+dx[r],last.second+dy[r]);
	}
	
	cout<<"Finished!"<<endl;
			
			cout<<"please visit log.txt"<<endl;
			freopen("log.txt","w",stdout);
			for(int i=0;i<pos.size();i++){
				cout<<pos[i].first<<","<<pos[i].second<<","<<t[i]<<","<<1<<","<<type[i]<<",0:0:0:0:"<<endl;
			}
			
			exit(0);
			
} 

int main(int argc,char* argv[]){
	cout<<"Osu taiko -> normal cpp project"<<endl;
	cout<<"Press Z for a red key and X for a blue key C for end.For testing V to call for a local time."<<endl;
	if(argc<2){
		cout<<" Usage: main <option>"<<endl;
		cout<<"option can be : "<<endl;
		cout<<" none - beat with your own"<<endl;
		cout<<" crazy - beat with random don and ka every beat. (auto)"<<endl;
		cout<<" pattern - beat with the pattern repeating."<<endl;
		cout<<" random - everything is a random!!"<<endl;
		cout<<" snake - beat with every beat like a snake (auto)"<<endl;
		return 1;
	} 
	
	//system(("java playsound \""+s+"\"").c_str());
	
	//system(("\""+s+"\"").c_str());
	
		string s=argv[1];
		
		if(s=="none"){
						
			thread t(button);
			
			t.join();
			return 0;
		}
		
		if(s=="crazy"){
			crazy();
			return 0;
		}
		
		if(s=="random"){
			random();
			return 0;
		}
		
		if(s=="pattern"){
			pattern();
			return 0;
		}
		
		if(s=="snake"){
			snake();
			return 0;
		}

	cout<<"Unrecognized option: "<<s<<endl;
	return 2;
}

