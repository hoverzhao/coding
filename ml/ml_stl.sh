#!/bin/sh
# mlt raw " cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwfww cwf cwf cwfw cwf cwf cwf cwf cwfw cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cwf cww cwf cwf cwfw cwf cwf cwf cwf cwfw"

#array------------------------------------------------------------
mlt raw "array<int, 3> a {1, 2, 3}; a.front(); a.back(); "

#vector-----------------------------------------------------------
mlt raw "vector<vector<int>> a(n, vector<int>(m, 0)); "
mlt raw "a.pop_back() a.reserve() a.resize() a.capacity() a.size() a.erase(it) a.clear()) "
mlt raw "a.push_back(2); a.push_back(3); a.push_back({2, 3}); a.push_back(st{a, b}); "
mlt raw "a.emplace_back(2, 3); a.emplace_back(a, b) a.emplace(a.begin(), a, b); "
mlt raw "a.insert(a.end(), {2, 3}) "
#vector 插入后iterator位置发生变化, 必须重新赋值
mlt raw "i = v.insert(i, 8); i = v.erase(i); "
#vector erase不释放内存，使用下面方法释放内存
mlt raw "w.assign(u.begin() + 1, u.end()); w.assign(a, 100);"
mlt raw "v = vector<int>(v); "

#deque-----------------------------------------------------------
mlt raw "deque<int> a; a.push_front(2); a.push_back(2); a.pop_front(); "
mlt raw "a.insert(a.begin(), v.begin(), v.end()); "
mlt raw "a.erase(begin(a) + 1, begin(a) + 5); "

#list-----------------------------------------------------------
mlt raw "list<int> lst {3}; lst.push_back(2); lst.push_front(4); "
# 反转，排序，去重
mlt raw "lst.reverse(); lst.sort(); l.unique(); "
# 在第二个元素前，插入新双向链表
mlt raw "lst.splice(begin(lst) + 1, list<int>{7, 8, 9}); "
# la 1 2 3 4	lb 10 20 30
mlt raw "auto it = la.begin(); ++it; "
# la 1 10 20 30 2 3 4		lb = empty  it still point to 2 (5th elem)
mlt raw "la.splice(it, lb); "
# la 1 10 20 30 3 4		lb = 2		it is now invalid
mlt raw "la.splice(lb.begin(), la, it); "
# la 1 10 20 30 3 4		lb = 2		it points now to 30
mlt raw "it = la.begin(); advance(it, 3); "
# la 30 3 4 1 10 20 //把it到尾部元素，移动到链表头部
mlt raw "la.splice(la.begin(), la, it, la.end()); "

#forward list-----------------------------------------------------------
#no size() back() push_back() pop_back() insert()
mlt raw "lf.insert_after(lf.begin(), 5); lf.insert_after(before_begin(lf), 88); lf.erase_after(begin(l)); "

#set-----------------------------------------------------------
#元素:唯一、有序 2 8 9						2 7 9	it指向9
mlt raw "set<int> s {9, 2, 8}; s.insert(7); s.erase(8);"
mlt raw "unordered_set<int> s{9, 7, 6};"
mlt raw "it = s.find(7); if (it != s.end()) it = s.erase(it);"




#common-----------------------------------------------------------
#最小元素位置
mlt raw "int i = min_element(a.begin(), a.end()) - a.begin(); "
mlt raw "int i = distance(a.begin(), min_element(a.begin(), a.end)); "
#最小元素，最后一个最大元素位置
mlt raw "auto p = minmax_element(a.begin(), a.end()); "
mlt raw "int i = p.first - a.begin(); int j = p.second - a.begin();"

#下边界，返回第一个值为20的位置
#上边界，返回最后一个20后面的位置
mlt raw "sort(a.begin(), a.end()); "
mlt raw "int i = lower_bound(a.begin(), a.end(), 20) - a.begin(); "
mlt raw "int j = upper_bound(a.begin(), a.end(), 20) - a.begin(); "

mlt raw "#define sz(a) ((int)((a).size())) "
mlt raw "#define char unsigned char "
mlt raw "typedef long double ld "
mlt raw "const int INF = 2e9 "
mlt raw "const ll INF = 9e18; "

#vector 数组读入
mlt raw "vector<ll> a(n); for (ll &val : a) {cin >> val;}"
#数组前缀和写法
mlt raw "vector<ll> pref(n + 1, 0); for (int i = 0; i < n; i++) {pref[i + 1] = pref[i] + a[i];} "
#数组排序 从小到大
mlt raw "sort(a.begin(), a.end(), std::less<int>()); "
mlt raw "sort(a.begin(), a.end(), std::greater<int()); "
#求素数数量
mlt raw "int getPrimes(int a) { int ans = 0; for (int i = 2; i * i <= a; i++) {while (a % i == 0) {ans++; a /= i;} if (a > 1) ans++; return ans;} "
#将a拷贝到b, b要提前分配好
mlt raw "copy(a.begin(), a.end(), b.begin()); "
#填充0
mlt raw "fill(a.begin(), a.end(), 0); "
#替换a中值为0的元素
mlt raw "replace(a.begin(), a.end(), 0, 9); "
#替换a中值为奇数的元素
mlt raw "replace_if(a.begin(), a.end(), IsOdd, 0); "
#删除a中值为奇数的元素
mlt raw "remove_if(a.begin(), a.end(), IsOdd); "
#找到第一个奇数iterator
mlt raw "find_if(a.begin(), a.end(), IsOdd); "
#a中的每个值加1, 将结果保存到b, 倒数第二个参数是输出
mlt raw "b.resize(a.size); "
mlt raw "transform(a.begin(), a.end(), b.begin(), add_one); "
#a中的每个值 和b中对应的值相加，将结果保存到a .倒数第二个参数是输出
mlt raw "transform(a.begin(), a.end(), b.begin(), a.begin(), std::plus<int>()); "
#随机重新排列数组元素
mlt raw "unsigned int seed = chrono::system_clock::now().time_since_epoch().count(); "
mlt raw "shuffle(a.begin(), b.end(), default_random_engine(seed)); "
