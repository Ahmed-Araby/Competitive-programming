#include <bits/stdc++.h>
#define MAX_chars 27
using namespace std;
struct trie
{
    trie * childs[MAX_chars];
    bool isleaf;
    int cnt;

    trie()
    {
        for(int i=0; i<MAX_chars; i++)
            childs[i]=0;
        isleaf = 0;
        cnt = 0;
    }

    void add_word(char *word)
    {
        //cout<<"HER"<< endl;
        if(*word=='\0'){
            isleaf = 1;
            return ;
        }
        int index = *word - 'a';
        if(childs[index]==0)
        {
            childs[index] = new trie();
            childs[index]->cnt = 1;
            childs[index]->add_word(word+1);
        }
        else{
            childs[index]->cnt +=1;
            childs[index]->add_word(word+1);
        }
        return ;
    }

    int find_word(char *word)
    {
        if(*word=='\0')
            return isleaf?cnt:0;
        int index = *word - 'a';
        if(childs[index]==0)
            return 0;
        return childs[index]->find_word(word+1);
    }

    int find_prefix(char *word)
    {
        if(*word=='\0')
            return cnt;
        int index = *word - 'a';
        if(childs[index]==0)
            return 0;
        return childs[index]->find_prefix(word+1);
    }
};

int main()
{
    int n;
    cin>>n;
    trie root;
    for(int i=0; i<n; i++)
    {
        char com[10] , word[25];
        scanf("%s" , com);
        scanf("%s" , word);

        if(*com=='a')
            root.add_word(word);
        else{
            int cnt = root.find_prefix(word);
            cout<<cnt<< endl;
        }
    }
    return 0;
}
