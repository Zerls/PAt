#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct node{
    int val;
    struct node *l,*r;
};
int iscomplete=1,flag=0;
node* rotateL(node * &root){
    node * t=root->r;
    root->r=t->l;
    t->l=root;
    return t;
}
node * rotateR(node * &root){
    node * t=root->l;
    root->l=t->r;
    t->r=root;
    return t;
}
node * rotateLR(node * &root){
    root->l=rotateL(root->l);
    return rotateR(root);
}
node* rotateRL(node * &root){
    root->r=rotateR(root->r);
    return rotateL(root);
}
int getHeight(node * root){
    if(root==NULL) return 0;
    int l=getHeight(root->l);
    int r=getHeight(root->r);
    return max(l,r)+1;//return max(l,r);
}
node * bulid(node * &root,int num){
    if(root==NULL){
        root=new node();
        root->val=num;
        root->l=root->r=NULL;
    }else if(num <root->val){
        root->l=bulid(root->l, num);
        if(getHeight(root->l)-getHeight(root->r) ==2){
            root= (root->l->val > num) ? rotateR(root):rotateLR(root);
        }
    }else{
        root->r=bulid(root->r, num);
        if(getHeight(root->l)-getHeight(root->r) ==-2){
            root= (root->r->val < num) ? rotateL(root):rotateRL(root);
        }
    }
    return root;
}
void bfs(node * root){
    int after=0;
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node * t=q.front();
        if(flag) printf(" ");
        if(!flag) flag=1;
        printf("%d",t->val);
        q.pop();
        if(t->l !=NULL) {
            q.push(t->l);
            if(after==1) iscomplete=0;
        }else{
            after=1;
        }
        if(t->r !=NULL) {
            q.push(t->r);
            if(after==1) iscomplete=0;
        }else{
            after=1;
        }
    }
}
int main(){
    int n,temp;
    node * root=NULL;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&temp);
        root=bulid(root,temp);
    }
    bfs(root);
    printf("\n%s\n",iscomplete ? "YES":"NO");
    return 0;
}
