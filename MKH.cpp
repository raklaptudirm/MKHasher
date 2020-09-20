#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string divide(string str){
	string out[str.size()], div_tem;
	int count=0, list=0;
	div_tem=str[count];
	if (div_tem=="1"||div_tem=="0"){
		count++;
		div_tem=div_tem+str[count];
	}
	for (;count<str.size();count++){
		int temp, st;
		string arr;
		stringstream tempo(div_tem);
		tempo >> temp;
		st=floor(temp/2);
		stringstream store;
		store << st;
		store >> arr;
		out[list]=arr;
		list++;
		st=temp%2;
		stringstream newer;
		newer << st;
		newer >> div_tem;
		if ((count+1)!=str.size())
			div_tem=div_tem+str[count+1];
	}
	string output="";
	for (count=0;count<list;count++){
		output=output+out[count];
	}
	return output;
} 

string reverse(string str){
	string arr[str.size()], temp_str,out="";
	int count=(str.size()-1),list=0;
	for (;count!=-1;count--){
		arr[list]=str[count];
		list++;
	}
	for (count=0;count<list;count++){
		out=out+arr[count];
	}
	return out;
}

string toASCII(string str){
	int ascii, count;
	char tem;
	string store="", temp_str;
	for (count=0;count<str.size();count++){
		tem=str[count];
		ascii=(int)tem;
		stringstream as;
		as << ascii;
		as >> temp_str;
		for (ascii=0;ascii<(3-temp_str.size());ascii++){
			temp_str="0"+temp_str;
		}
		store=store+temp_str;
	}
	return store;
}

string tob2(string str){
	string b2="", rem;
	while (str!="0"&&str!="1"){
		if (str[str.size()-1]=='1'||str[str.size()-1]=='3'||str[str.size()-1]=='5'||str[str.size()-1]=='7'||str[str.size()-1]=='9')
			rem="1";
		else 
			rem="0";
		str=divide(str);
		b2=rem+b2;
	}
	b2=str+b2;
	return b2;
}

string addPadding(string str){
	string constant="11001";
	while ((str.size()%6)!=0){
		str=str+constant[(str.size()%6)-1];
	}
	return str;
}

string tob64(string str){
	string b2val[64]={"000000","000001","000010","000011","000100","000101","000110","000111","001000","001001","001010","001011","001100","001101","001110","001111","010000","010001","010010","010011","010100","010101","010110","010111","011000","011001","011010","011011","011100","011101","011110","011111","100000","100001","100010","100011","100100","100101","100110","100111","101000","101001","101010","101011","101100","101101","101110","101111","110000","110001","110010","110011","110100","110101","110110","110111","111000","111001","111010","111011","111100","111101","111110","111111"};
	string b64[64]={"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","$","?"};
	string blocks[str.size()], store="", ex;
	int count, list=0, count2=0;
	for (count=0;count<str.size();count++){
		store=store+str[count];
		if ((count+1)%6==0){
			blocks[list]=store;
			store="";
			list++;
		}
	}
	blocks[list]=store;
	list++;
	store="";
	for (count=0;count<list;count++){
		ex=blocks[count];
		for (count2=0;count2<64;count2++){
			if(ex==b2val[count2])
				break;
		}
		//cout << count2 << endl;
		store=store+b64[count2];
		//cout << store << endl;
	}
	return store;
}

int main(){
	string string_;
	cout << "Enter a string to hash: ";
	cin >> string_;
	string_=reverse(string_);
	string_=toASCII(string_);
	string_=tob2(string_);
	string_=addPadding(string_);
	string_=tob64(string_);
	cout << "Hash: " << string_;
	return 0;
}
