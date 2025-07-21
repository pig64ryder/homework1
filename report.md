# 51115128

第一題

## 解題說明

寫一個遞迴和非遞迴函數來算 Ackermann 函數 $ A(m, n) $

### 解題策略

1. 遞迴版本：
     規則是：如果 $ m = 0 $，回傳 $ n + 1 $; 如果 $ n = 0 $，回傳 $ A(m-1, 1) $; 否則用 $ A(m-1, A(m, n-1)) $ 
     比如 $ A(1, 2) $ 會等於4


2. 非遞迴版本：
     用迴圈來模擬遞迴的過程，這樣大數不會讓程式崩掉。

## 程式實作

以下為主要程式碼：

```cpp
#include <iostream>
using namespace std;

int a(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return a(m - 1, 1);
    return a(m - 1, a(m, n - 1));
}

int a_no_rec(int m, int n) {
    while (m > 0 || n > 0) {
        if (m == 0) return n + 1;
        if (n == 0) { m--; n = 1; continue; }
        n--; int temp = a(m, n); m--; n = temp;
    }
    return n + 1;
}

int main() {
    cout << "A(1, 2) = " << a(1, 2) << endl;
    cout << "A(1, 2) 非遞迴 = " << a_no_rec(1, 2) << endl;
    return 0;
}
```

## 測試與驗證

### 測試案例

| 測試案例 | (m, n) | 預期輸出 | 實際輸出 |
|----------|--------|----------|----------|
| 測試一   | (1, 2) | 4        | 4        |
| 測試二   | (2, 1) | 5        | 5        |
| 測試三   | (1, 1) | 3        | 3        |
| 測試四   | (0, 5) | 6        | 6        |

### 編譯與執行指令

```shell
$ g++ -std=c++17 -o ackermann ackermann.cpp
$ ./ackermann
A(1, 2) = 4
A(1, 2) 非遞迴 = 4
```

### 結論

1. 程式透過遞迴方式正確計算 Ackermann 函數值。

### 心得

1. 這次的遞迴函數和飛遞迴函數寫起來挺直觀的，就照著題目要求慢慢寫下來不會到太難


作業二

## 解題說明

寫個遞迴函數，算出集合 \( S \) 裡所有可能的子集合

### 解題策略

1. 每遇到一個元素，就選它或不選它，這樣一直下去直到跑完
2. 比如 \( S = \{a, b, c\} \) 會變成 \(\{\}, \{a\}, \{b\}, \{c\}, \{a, b\}, \{a, c\}, \{b, c\}, \{a, b, c\}\)
## 程式實作

以下為主要程式碼：

```cpp
#include <iostream>
#include <vector>
using namespace std;

void powerset(vector<char>& s, int i, vector<char>& curr, vector<vector<char>>& res) {
    if (i == s.size()) {
        res.push_back(curr);
        return;
    }
    powerset(s, i + 1, curr, res);
    curr.push_back(s[i]);
    powerset(s, i + 1, curr, res);
    curr.pop_back();
}

void print_set(vector<vector<char>>& res) {
    cout << "{ ";
    for (auto& subset : res) {
        cout << "{";
        for (char c : subset) cout << c;
        cout << "} ";
    }
    cout << "}" << endl;
}

int main() {
    vector<char> s = {'a', 'b', 'c'}, curr;
    vector<vector<char>> res;
    powerset(s, 0, curr, res);
    print_set(res);
}

```

## 效能分析

1. 時間複雜度：O(n × 2ⁿ)
      有 2ⁿ 個子集合
      每個子集合最多長度為 n
2. 空間複雜度：O(n × 2ⁿ)
      儲存所有子集合
      再加上遞迴用的暫存空間

## 測試與驗證

### 測試案例

| 測試案例 | 輸入集合       | 預期輸出長度 | 實際輸出長度 |
|----------|----------------|---------------|----------------|
| 測試一   | `{}`           | 1             | 1              |
| 測試二   | `{a}`          | 2             | 2              |
| 測試三   | `{a, b}`       | 4             | 4              |
| 測試四   | `{a, b, c}`    | 8             | 8              |


### 編譯與執行指令

```shell
g++ -o powerset main.cpp
./powerset
```

### 結論

1. 程式透過遞迴方式正確算出所有子集合

### 心得

1. 這次的遞迴函數比第一題還要複雜，我在寫的時候忘記curr.pop_back()這一步，導致curr沒有正確還原，導致結果錯誤，挺笨的