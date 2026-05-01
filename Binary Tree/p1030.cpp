//二叉树
#include<bits/stdc++.h>
using namespace std;
string ino,posto;
void build(string in,string post){
    if(in.empty())return ;
    char root=post.back();
    cout<<root ;//父节点
    int k=in.find(root);
    build(in.substr(0,k),post.substr(0,k));//左子树
    build(in.substr(k+1,in.size()-k-1),post.substr(k,in.size()-k-1));//右子树。其实前面也就是in中的substr中的第二个元素可以不写，不写是默认遍历到尾部。而post中的最后一个节点作为父节点输出了，所以不要。
    //按照父左右也就是先序的顺序进行递归
}
int main (){
    cin>>ino>>posto;
    build(ino,posto);
    return 0;
}