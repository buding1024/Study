#include<iostream>
#include<set>

//set数据存放结构体
struct StudentInfo
{
    std::string name;
    int height;
    double weight;

    //重载"<"操作符，自定义排序规则
    bool operator < (const StudentInfo &a) const
    {
        //按照height由大到小排序
        return a.height < height;
    }

    //重载"=="操作符
    bool operator == (const StudentInfo &a) const
    {
        if(a.name == name && a.height == height && a.weight == weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//正向输出
void Positive_PrintSet(std::set<int> &st1)
{
    std::set<int>::iterator it = st1.begin();
    while (it != st1.end())
    {
        std::cout<<*it<<" ";
        it++;
    }
    std::cout<<std::endl;
}

//反向输出
void Reverse_PrintSet(std::set<int> &st1)
{
    std::set<int>::reverse_iterator rit = st1.rbegin();
    while (rit != st1.rend())
    {
        std::cout<<*rit<<" ";
        rit++;
    }
    std::cout<<std::endl;
}

//元素是结构体输出
void Reverse_PrintConSet(std::set<StudentInfo> &st1)
{
    std::set<StudentInfo>::iterator it = st1.begin();
    while (it != st1.end())
    {
        std::cout<<it->height<<" ";
        it++;
    }
    std::cout<<std::endl;
}
int main()
{
    int arr[] = {9, 8, 2, 10, 11, 3, 5, 7 ,6, 4, 12};

    //construct set
    std::set<int> st1;

    //insert
    int arr_size = sizeof(arr)/sizeof(int);
    for(int i = 0; i < arr_size; ++i)
    {
        st1.insert(arr[i]);
    }
    // Positive_PrintSet(st1);
    // Reverse_PrintSet(st1);

    //delete
    std::set<int>::iterator it = st1.begin();
    st1.erase(it);
    //st1.clear();

    //find 检索
    it = st1.find(7);
    if(it != st1.end())
    {
        std::cout<<*it<<std::endl;
    }
    else
    {
        std::cout<<"not found it"<<std::endl;
    }


    std::set<StudentInfo> s;
    StudentInfo info;
    info.name = "Jack";
    info.height = 179;
    info.weight = 68;
    s.insert(info);

    info.name = "Tom";
    info.height = 185;
    info.weight = 70;
    s.insert(info);

    info.name = "Rose";
    info.height = 177;
    info.weight = 89;
    s.insert(info);

    Reverse_PrintConSet(s);

    std::set<StudentInfo>::iterator sit = s.find(info);
    if(sit != s.end())
    {
        std::cout<<sit->name<<std::endl;
    }
    else
    {
        std::cout<<"not found it"<<std::endl;
    }

    sit = s.begin();
    while(sit != s.end())
    {
        if(*sit == info)
        {
            std::cout<<sit->name<<std::endl;
        }
        ++sit;
    }

    //max size
    //std::cout<<"max size"<<s.max_size()<<std::endl;
    return 0;
}
