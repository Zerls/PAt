//解题一
#include <iostream>
#include <vector>
using namespace std;
struct node{ int id,root,l,r,level; };
string s;
int n,m,isfull=1,root,a,b;
vector <int> post,in;
vector <node> tree(1005);
void dfs(int & nodes,int postr,int inl,int inr,int level,int index,int root){
    if(inl>inr) return;
    nodes=post[postr];
    int i=inl;
    while(i<=inr && in[i]!=post[postr]) i++;
    tree[nodes]={nodes,root,-1,-1,level};
    dfs((tree[nodes].l),postr-(inr-i+1),inl,i-1,level+1,index*2,nodes);
    dfs((tree[nodes].r),postr-1,i+1,inr,level+1,index*2+1,nodes);
}
void dfs2(int v){
    int flag1=1,flag2=1;
    if((tree[v].l==-1)) flag1=0;
    if((tree[v].r==-1)) flag2=0;
    if((flag1 && !flag2)||(flag2 && !flag1)){
        isfull=0;
        return;
    } else if(!flag1 && !flag2) return;    
    dfs2(tree[v].l);
    dfs2(tree[v].r);
}
int main(){
    scanf("%d",&n);
    in.resize(n+1);
    post.resize(n+1);
    for(int i=1;i<=n;++i) scanf("%d",&post[i]);
    for(int i=1;i<=n;++i) scanf("%d",&in[i]);
    dfs(root,n,1,n,0,1,post[n]);
    scanf("%d\n",&m);
    while(m--){
        getline(cin,s);
        if(s[s.size()-1]=='t'){
            sscanf(s.c_str() ,"%d is the root",&a);
            printf("%s\n",a==post[n]?"Yes":"No");
        }else if(s[s.size()-1]=='s'){
            sscanf(s.c_str() ,"%d and %d are siblings",&a,&b);
            int roota=tree[a].root;
            int rootb=tree[b].root;
            printf("%s\n",roota==rootb?"Yes":"No");
        }else if(s[s.size()-1]=='e'){
            dfs2(post[n]);
            printf("%s\n",isfull==1?"Yes":"No");
        }else if(s[s.size()-1]=='l'){
            sscanf(s.c_str() ,"%d and %d are on the same level",&a,&b);
            int levela=tree[a].level;
            int levelb=tree[b].level;
            printf("%s\n",levela==levelb?"Yes":"No");
        }else if(s.find("parent") != string::npos){
            sscanf(s.c_str() ,"%d is the parent of %d",&a,&b);    
            printf("%s\n",a==tree[b].root?"Yes":"No");
        }else if(s.find("left") != string::npos){
            sscanf(s.c_str() ,"%d is the left child of %d",&a,&b);    
            printf("%s\n",a==tree[b].l?"Yes":"No");
        }else if(s.find("right") != string::npos){
            sscanf(s.c_str() ,"%d is the right child of %d",&a,&b);    
            printf("%s\n",a==tree[b].r?"Yes":"No");
        }
    }
    return 0;
}

//解题二
#include <iostream>
#include <vector>
using namespace std;
struct node{ int id,root,l,r,level; };
string s;
int n,m,isfull=1,root,a,b;
vector <int> post,in;
vector <node> tree(1005);
void dfs(int & nodes,int postr,int inl,int inr,int level,int index,int root){
    if(inl>inr) return;
    nodes=post[postr];
    int i=inl;
    while(i<=inr && in[i]!=post[postr]) i++;
    tree[nodes]={nodes,root,-1,-1,level};
    dfs((tree[nodes].l),postr-(inr-i+1),inl,i-1,level+1,index*2,nodes);
    dfs((tree[nodes].r),postr-1,i+1,inr,level+1,index*2+1,nodes);
}
void dfs2(int v){
    int flag1=1,flag2=1;
    if((tree[v].l==0||tree[v].l==-1)) flag1=0;
    if((tree[v].r==0||tree[v].r==-1)) flag2=0;
    if((flag1 && !flag2)||(flag2 && !flag1)){
        isfull=0;
        return;
    } else if(!flag1 && !flag2) return;
    else{
        dfs2(tree[v].l);
        dfs2(tree[v].r);
    }
}
int main(){
    scanf("%d",&n);
    in.resize(n+1);
    post.resize(n+1);
    for(int i=1;i<=n;++i) scanf("%d",&post[i]);
    for(int i=1;i<=n;++i) scanf("%d",&in[i]);
    dfs(root,n,1,n,0,1,post[n]);
    scanf("%d\n",&m);
    while(m--){
        getline(cin,s);
        if(s[s.size()-1]=='t'){
            sscanf(s.c_str() ,"%d is the root",&a);
            printf("%s\n",a==post[n]?"Yes":"No");
        }else if(s[s.size()-1]=='s'){
            sscanf(s.c_str() ,"%d and %d are siblings",&a,&b);
            int roota=tree[a].root;
            int rootb=tree[b].root;
            printf("%s\n",roota==rootb?"Yes":"No");
        }else if(s[s.size()-1]=='e'){
            dfs2(post[n]);
            printf("%s\n",isfull==1?"Yes":"No");
        }else if(s[s.size()-1]=='l'){
            sscanf(s.c_str() ,"%d and %d are on the same level",&a,&b);
            int levela=tree[a].level;
            int levelb=tree[b].level;
            printf("%s\n",levela==levelb?"Yes":"No");
        }else if((int)s.find("parent")>=0){
            sscanf(s.c_str() ,"%d is the parent of %d",&a,&b);    
            printf("%s\n",a==tree[b].root?"Yes":"No");
        }else if((int)s.find("left")>=0){
            sscanf(s.c_str() ,"%d is the left child of %d",&a,&b);    
            printf("%s\n",a==tree[b].l?"Yes":"No");
        }else if((int)s.find("right")>=0){
            sscanf(s.c_str() ,"%d is the right child of %d",&a,&b);    
            printf("%s\n",a==tree[b].r?"Yes":"No");
        }
    }
    return 0;
}
