#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int len1 = 1;
//         int len2 = 1;
//         ListNode *p1 = l1;
//         ListNode *p2 = l2;
//         while(p1->next!=NULL)//获取l1的长度
//         {
//             len1++;
//             p1=p1->next;
//         }
//         while(p2->next!=NULL)//获取l2的长度
//         {
//             len2++;
//             p2=p2->next;
//         }
//         if(len1 > len2)
//         {
//             for(int i = 0; i < len1-len2; ++i)
//             {
//                 p2->next = new ListNode(0);
//                 p2 = p2->next;
//             }
//         }
//         else
//         {
//             for(int i = 0; i < len2-len1; ++i)
//             {
//                 p1->next = new ListNode(0);
//                 p1 = p1->next;
//             }
//         }
//         p1 = l1;
//         p2 = l2;
//         int flag = 0;
//         ListNode* l3 = new ListNode(-1);
//         ListNode* w = l3;
//         int i = 0;
//         while (p1!=nullptr && p2 != nullptr) 
//         {
//             i = flag + p1->val + p2->val;
//             w->next = new ListNode(i%10);
//             flag = i >= 10 ? 1 : 0;
//             w = w->next;
//             p1 = p1->next;
//             p2 = p2->next;
//         }
//         if(false)
//         {
//             w->next = new ListNode(1);
//             w = w->next;
//         }
//         return l3->next;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//记录l1的长度
        int len2=1;//记录l2的长度
        ListNode* p=l1;
        ListNode* q=l2;
        while(p->next!=NULL)//获取l1的长度
        {
            len1++;
            p=p->next;
        }
        while(q->next!=NULL)//获取l2的长度
        {
            len2++;
            q=q->next;
        }
        if(len1>len2)//l1较长，在l2末尾补零
        {
            for(int i=1;i<=len1-len2;i++)
            {
                q->next=new ListNode(0);
                q=q->next;
            }
        }
        else//l2较长，在l1末尾补零
        {
            for(int i=1;i<=len2-len1;i++)
            {
                p->next=new ListNode(0);
                p=p->next;
            }
        }
        p=l1;
        q=l2;
        bool count=false;//记录进位
        ListNode* l3=new ListNode(-1);//存放结果的链表
        ListNode* w=l3;//l3的移动指针
        int i=0;//记录相加结果
        while(p!=NULL&&q!=NULL)
        {
            i=count+p->val+q->val;
            w->next=new ListNode(i%10);
            count=i>=10?true:false;
            w=w->next;
            p=p->next;
            q=q->next;
        }
        if(count)//若最后还有进位
        {
            w->next=new ListNode(1);
            w=w->next;
        }
        return l3->next; 
    }
};

int main(int argc, char *argv[])
{
    int a[] = {2, 4, 3};
    int b[] = {5, 6, 4};
    ListNode *p = nullptr;
    ListNode* l1 = new ListNode(a[0]);
    ListNode* l2 = new ListNode(b[0]); 
    // std::cout << sizeof(a) / sizeof(a[0]) << std::endl;
    
    p = l1;
    for(int i = 1; i < (int)(sizeof(a)/sizeof(a[0])); ++i)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }

    p = l2;
    for(int i = 1; i < (int)(sizeof(b)/sizeof(b[0])); ++i)
    {
        p->next = new ListNode(b[i]);
        p = p->next;
    }
    // p = l2;
    // while (p!=nullptr)
    // {
    //     std::cout << p->val <<std::endl;
    //     p = p->next;
    // }
    Solution A;
    std::cout << (A.addTwoNumbers(l1, l2))->val << std::endl;
    //std::cout << "11" << std::endl;
    return 0;
}

// class Solution {
// public:
//     string tictactoe(vector< vector<int> >& moves) {

//         vector< vector<string> >pz(3, vector<string>(3,"-1") );
//         for(unsigned int i = 0; i < moves.size(); ++i){
//             pz[moves[i][0]][moves[i][1]] = i % 2 == 0? "A" : "B";
//         }
//         for(int i = 0; i < 3 && pz[i][0] != "-1"; ++i){
//             if(pz[i][0] == pz[i][1] && pz[i][1] == pz[i][2]){
//                 return pz[i][0];
//             }
//         }
//         for(int i = 0; i < 3 && pz[0][i] != "-1"; ++i){
//             if(pz[0][i] == pz[1][i] && pz[1][i] == pz[2][i])
//                 return pz[0][i];
//         }

//         if(pz[0][0] != "-1" && pz[0][0] == pz[1][1] && pz[1][1] == pz[2][2]){
//             return pz[0][0];
//         }
//         if(pz[0][2] != "-1" && pz[0][2] == pz[1][1] && pz[1][1] == pz[2][0]){
//             return pz[0][2];
//         }
//         for(unsigned int i = 0; i < pz.size(); ++i){
//             for(unsigned int j = 0; j < pz[i].size(); ++j){
//                 if(pz[i][j] == "-1"){
//                     return "Pending";
//                 }
//             }
//         }
//         return "Draw";
//        ;
//     }
// };
// int main(int argc, char const *argv[])
// {
//     vector< vector<int> > moves;
//     moves = { {0, 1}, {2, 0}, {1, 1}, {2, 2} };
//     Solution A;
//     std::cout << A.tictactoe(moves) << std::endl;
//     std::cout << "Hello World" << std::endl;
//     //[[0,0],[2,0],[1,1],[2,1],[2,2]];
//     return 0;
// }


// #include <iostream>
// #include <algorithm>
// #include <ctime>
// using namespace std;

// int main(int argc, char *argv[])
// {
//     int x = 10;
//     int y = 3;
//     int z ;

//     //以值传递的方式访问x,y所以x,y的值并没有发生改变
//     z = [=]()mutable throw() -> int { int n = x + y; x = y ; y = n; return n;}();
//     cout<<" x: "<<x<<" y: "<<y<<" z: "<<z<<endl;

//     //以引用的方式访问x,y所以x,y的值发生改变
//     z = [&]()mutable throw() -> int { int n = x + y; x = y ; y = n; return n;}();
//     cout<<" x: "<<x<<" y: "<<y<<" z: "<<z<<endl;

//     //如何向lambda表达式里面传递参数
//     int n = [] (int x, int y) { return x + y; }(5, 4);
//     cout<<" n: "<<n<<endl;

//     //像调用函数一样使用lambda表达式
//     auto f = [] (int x, int y) { return x + y; };
//     cout << f(21, 12) << endl;

//     //Lambda表达式与STL算法一起使用,输出数组
//     int a[10] = {0};
//     srand(time(NULL));
//     generate(a,a+10,[]()->int { return rand() % 100; });
//     cout<<"Before sort: "<<endl;
//     for_each(a, a+10, [&](int i){ cout<< i <<" "; });
//     cout<<endl;
//     cout<<"After sort"<<endl;
//     sort(a,a+10);
//     for_each(a, a+10, [&](int i){ cout<< i <<" "; });
//     cout<<endl;

//     //Lambda表达式的嵌套
//     int m = [](int x){ return [](int y) { return y * 2; }(x) + 3; }(5);
//     cout << m << endl;
//     return 0;
// }