#include<string>
#include<vector>
#include<fstream>
#include <stdlib.h>
#include<iostream>
#include <sstream>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

struct Racer{
	long long id;
	long long score;
	long long start;
	long long end;
};

struct Bucket{
	vector<long long> bucket;
	int cnt;
	long long start;
	long long end;
};

void importData(string in_name, string out_name,  vector<Racer> &data, vector<Racer> &scoring)
{
	ifstream inFile, outFile;

	inFile.open(in_name.c_str());
	outFile.open(out_name.c_str());

	string line;

	//get total Number
	getline(inFile, line);

	int row = atoi(line.c_str());

	for(int i = 0; i < row; i++)
	{
		Racer temp;

		getline(inFile,line);

		istringstream stm(line);

		string word;

		stm >> word; temp.id = atoll(word.c_str());

		stm >> word; temp.start = atoll(word.c_str());

		stm >> word; temp.end = atoll(word.c_str());

		//cout<<temp.id<<" "<<temp.start<<" "<<temp.end<<endl;

		data.push_back(temp);

		line.clear();

		getline(outFile,line);

		istringstream stm2(line);

		stm2 >> word; temp.id = atoll(word.c_str());

		stm2 >> word; temp.score = atoll(word.c_str());

		scoring.push_back(temp);

	}

	inFile.close();
	outFile.close();
}

//comparator according to starting time
//ascending
bool comp_start(const Racer &r1, const Racer &r2)
{
	if( r1.start < r2.start ) return true;

	if( r1.start == r2.start ) return r1.id < r2.id;

	return false;
}

//comparator according to ending time
//ascending
bool comp_end(const Racer &r1, const Racer &r2)
{
	if( r1.end < r2.end ) return true;

	if( r1.end == r2.end ) return r1.id < r2.id;

	return false;
}

//comparator according to score
//ascending
bool comp_score(const Racer &r1, const Racer &r2)
{
	if( r1.score < r2.score ) return true;

	if( r1.score == r2.score ) return r1.id < r2.id;

	return false;
}

void init_buckets(vector<Bucket> &buckets, vector<Racer> &data)
{
	int n = data.size(), b = (int)sqrt(n), m = n / b;

	//sort the data according to the ending times
	sort(data.begin(), data.end(), comp_start);

	for(int i = 0; i < b; i++)
	{
		buckets.push_back(Bucket());
		buckets[i].cnt = 0;
		buckets[i].start = data[i*m].start;
		buckets[i].end = data[i*m + m - 1].start;
	}

	buckets[b-1].end = LLONG_MAX;
}

int get_count(vector<Bucket> &buckets, int l, int r, long long s)
{
	vector<long long>::iterator it = buckets[l].bucket.begin();

	int i = 0;

	for(; it != buckets[l].bucket.end(); it++){
		if(*it > s){
			buckets[l].bucket.insert(it,s);
			break;
		}
		i++;
	}

	if(it == buckets[l].bucket.end()) buckets[l].bucket.push_back(s);

	int cnt = buckets[l].bucket.size() - i - 1;

	for(i = l + 1; i <= r; i++) cnt += buckets[i].bucket.size();

	return cnt;
}

//binary search
int get_bucket(vector<Bucket> &buckets, long long time){
	int n = buckets.size();
	int l = 0, r = n - 1, m = 0;

	while(l <= r){
		m = (l + r) / 2;
		if(buckets[m].start <= time && buckets[m].end >= time){
			return m;
		}else if(buckets[m].start > time ){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}

	return m;
}

void printBuckets(vector<Bucket> &buckets);

void fill_buckets(vector<Bucket> &buckets, vector<Racer> &data)
{
	unsigned n = (int)(data.size());

	sort(data.begin(), data.end(), comp_end);

	long long s = 0, e = 0;

	unsigned i = 0, bs = 0, be = 0;

	for(i = 0; i < n; i++)
	{
		e = data[i].end; s = data[i].start;
		bs = get_bucket(buckets, s);
		be = get_bucket(buckets, e);
		data[i].score = get_count(buckets, bs, be, s);
	}

}

void printScore(vector<Racer> &data)
{
	unsigned int i = 0;

	for(i = 0; i < data.size(); i++)
	{
		cout<<data[i].id<<" "<<data[i].score<<endl;
	}
}

void printBuckets(vector<Bucket> &buckets){
	int n = buckets.size();
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cnt += buckets[i].bucket.size();
	}
	cout<<cnt<<endl;

}

void raceRater()
{
	//import data
	string in_name("C:/COMPUTER_SCIENCE/Coding Test/RacerRater_testcases/input002.txt");

	string out_name("C:/COMPUTER_SCIENCE/Coding Test/RacerRater_testcases/output002.txt");

	vector<Racer> data;

	vector<Racer> scoring; //used for testing

	importData(in_name, out_name, data, scoring);

	//initialize buckets
	vector<Bucket> buckets;
	init_buckets(buckets, data);

	//fill in the buckets and compute scores
	fill_buckets(buckets, data);
//
//	//sorting according to scores and ids
	sort(data.begin(), data.end(), comp_score);
////
////	//output
	printScore(data);

}

int main()
{
	raceRater();
}
