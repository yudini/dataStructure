#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie{
    bool finish;  //끝나는 지점을 표시
    Trie * nextNode[26];  //26가지 알파벳에 대한 트라이 포인터 배열
    Trie(){
        finish=false;
        memset(nextNode,0,sizeof(nextNode));
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(nextNode[i]){
                delete nextNode[i];
            }
        }
    }

    void insert(const char* key){
        if(*key=='\0')
            finish=true;   //문자열이 끝나는 지점일 경우 표시
        else{
            int next=*key-'A';
            if(nextNode[next]==NULL)
                nextNode[next]=new Trie(); //탐색이 처음되는 지점일 경우 동적할당
            nextNode[next]->insert(key+1); //다음 문자 삽입
        }
        return;
    }

    Trie *find(const char* key){
        if(*key==0)
            return this;
        int next = *key -'A';
        if(nextNode[next]==NULL)//문자열에 없음
            return NULL;
        return nextNode[next]->find(key+1);//다음 문자로 탐색 진행
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Trie *trie = new Trie();
     
    trie->insert("HELLO");
    trie->insert("HELL");
    trie->insert("HALL");
    trie->insert("HALO");
    trie->insert("TRAVEL");

    cout<<trie->find("HELLO")<<endl;
    cout<<trie->find("HALO")<<endl;
    cout<<trie->find("TRAVELBEEEE")<<endl;
    cout<<trie->find("BEE")<<endl;

    delete trie;
}