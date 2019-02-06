#include <iostream>
#include <cmath>
using namespace std;
struct node{
    int val;
    struct node *l,*r;
};
node * bulid(node * & root,int num){
    if(root==NULL){
        root= new node();
        root->val=num;
        root->l=root->r=NULL;
    }else if(abs(num) <= abs(root->val)){//else if(abs(num) < abs(root->val)){
        root->l=bulid(root->l, num);
    }else
        root->r=bulid(root->r, num);
    return root;
}
int getHeight(node * &root){
    if(root==NULL) return 0;
    int l=getHeight(root->l);
    int r=getHeight(root->r);
    return (root->val >0) ? max(l,r)+1: max(l,r);
}
bool judge1(node * &root){
    if(root==NULL) return true;
    if(root->val <0){
       if(root->l !=NULL && root->l->val <0) return false;
        if(root->r !=NULL && root->r->val <0) return false;
    }
    return judge1(root->l) && judge1(root->r);
}
//(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
bool judge2(node * &root){
    if(root==NULL) return true;
    int l=getHeight(root->l);
    int r=getHeight(root->r);
    if(l !=r) return false;
    return judge2(root->l) && judge2(root->r);
  //NP return  getHeight(root->l) == getHeight(root->r) ? true :false;
}
int main(){
    int k,n,temp;
    scanf("%d",&k);
    while (k--) {
        node * root=NULL;
        scanf("%d",&n);
        for (int i=0; i<n; ++i) {
            scanf("%d",&temp);
            root=bulid(root,temp);
        }
        if(root->val >0 && judge1(root)&&judge2(root)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
