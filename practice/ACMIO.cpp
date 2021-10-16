#include<bits/stdc++.h>
using namespace std;


void testt(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    vector<int> nums;
    while(ss >> x){
        nums.push_back(x);
    }
    cout<<*max_element(nums.begin(), nums.end());
}

void input1_c(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        int c =  a + b;
    }
}

void input2_N_c(){
    int n;
    int a, b;
    while(scanf("%d",&n) != EOF && (n!=0)){
        for(int i=0 ; i < n; i++ ){
            scanf("%d %d",&a, &b);
            printf("%d\n",a+b);
        }
    }
}

void input3_string_c(){
    char buf1[255], buf2[255];

    scanf("%s%s", buf1, buf2); // 空格分开
    gets(buf1); gets(buf1); //回车分开

    char c;
    while(c=getchar() && c != '\n'){ //一个char读

    }

}

void input3_string_cpp(){
    // istream& getline(char line[], int size, char endchar = '\n');
    char buf1[256];
    cin.getline(buf1);
}

void input1_from_file_c(){
    FILE *fin,*fout;
    int a,b;
    fin=fopen("in.txt","r");
    fout=fopen("out.txt","w");
    while(fscanf(fin,"%d %d",&a, &b) != EOF){
        fprintf(fout,"%d\n",a+b);
    }
    fclose(fin);
    fclose(fout);
}


#include<fstream>
void input1_from_file_cpp(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int a,b;
    while(fin>>a>>b){
        fout<<a+b<<endl;
    }
    fin.close();
    fout.close();

    string str;
    char str_buf[256];
    int size = 100;
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, str);
        }
        while(!fin.eof()){
            fin.getline(str_buf, 100);
        }
    }
}




int main(){



    return 0;
}





