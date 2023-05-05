# <center>并查集
## <center>1.1并查集的背景
<div style="display:none">
&nbsp是一个空格；
<font size=x>设置字体大小；
<center>是居中；
</div>
<font size=2>
&nbsp &nbsp &nbsp &nbsp  在历史上，分类的问题是一直伴随着人们的。在有了计算机后，我们该如何用计算机快速地区分元素的种类、判定一些元素是否属于同一个“等价类”呢？更具体一点，例如在图论中最小生成树的kruskal算法中，如何快速判断新加入的边和之前加入的边构成闭环了呢？处理这一类问题，便引入了并查集。



## <center><font size=5>1.2并查集的定义
<font size=2>• 并查集被认为是最简洁而优雅的数据结构之一，主要用于解决一些元素分组的问题。它管理一系列不相交的集合，并支持两种操作：

• 合并（Union）：把两个不相交的集合合并为一个集合。

• 查询（Find）：查询两个元素是否在同一个集合中。

<div align="center">
<img
src="1.PNG" ;
width="220px" ;
height="130px" ;
/> </div>

<font size=1><center>并查集的概念图
<font size=2>
</center>
<center>并查集类概念代码实现</center>

```cpp
class Union_Find {
private:
    short father[Maxsize];// 每一个节点的父亲节点[并查集多用数组作为载体]
    int element_NUM;//元素的个数
    ..........
public:
    UnionFind(int num) {
        element_NUM=num;
       }//简单的构造函数
    ~UnionFind() {}//析构函数
    ..........
    }
```

## <center>1.3并查集_初始化INITIALIZE</center>
• 最开始,在没有构建并查集的时候，我们无法分别各个元素所属的“等价类，此时不妨令他们自己是自己的根节点
<left>
```cpp
class Union_Find {
private:
    ..........
public:
    ..........
    void initialize()
    {
        for(int i=0;i<element_NUM;i++)
        father[i]=i;//每个节点令自己的节点号为自己根节点；
    }
    }
```
</left>
<div align="center">
<img
src="2.PNG" ;
width="220px" ;
height="130px" ;
/> </div>

## <center>1.4并查集_合并UNION
类似于生活中等价类的归并，不同的并查集是可以合成一个大的并查集的，如下图所示：
<div align="center">
<img
src="3.PNG" ;
width="200px" ;
height="130px" ;
>
<img
src="4.PNG" ;
width="200px" ;
height="130px" ;
/> </div>

## <center> 附录：参考文献以及图片来源

图片来源：https://zhuanlan.zhihu.com/p/93647900;