---
title: DPL 1B 0-1ナップザック問題
tags:
  - - Python
  - - 競技プログラミング
  - - 動的計画法
category:
  - - 競プロ初中級者100問
date: 2020-05-13 15:00:00
---

## この記事で使うアルゴリズム
**全探索**

## はじめに

カテゴリー[競プロ初中級者100問](https://kakedashi-engineer.appspot.com/categories/%E7%AB%B6%E3%83%97%E3%83%AD%E5%88%9D%E4%B8%AD%E7%B4%9A%E8%80%85100%E5%95%8F/)では、`Qiita`にて`@e869120`さんが[レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【中級編：目指せ水色コーダー！】](https://qiita.com/e869120/items/eb50fdaece12be418faa#2-2-2-12-%E5%80%8B%E3%81%AE%E5%9F%BA%E6%9C%AC%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%82%92%E3%83%9E%E3%82%B9%E3%82%BF%E3%83%BC%E3%81%99%E3%82%8B)としてまとめられている100問を`Python`で解いています。

全問題の一覧は[こちら](https://kakedashi-engineer.appspot.com/2020/05/08/light-blue/)です

## 問題
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

この問題は動的計画法を用いて解くことができます。

## 方針
`n`の最大値は20なので、計算量が`O(2^n)`であるビット全探索でも十分間に合います。

## コード

```python
N, W = map(int, input().split())
vw = []
for n in range(N):
    v, w = map(int,input().split())
    vw.append((v,w))
dp = [[0]*(W+1) for _ in range(N+1)]
for n in range(N):
    vn ,wn = vw[n]
    for w in range(W+1):
        if w-wn >= 0:
            dp[n+1][w] = max(dp[n][w-wn] + vn, dp[n][w])
        else:
            dp[n+1][w] = dp[n][w]
print (dp[N][W])
```

# 記事情報
- 投稿日：2020年5月13日
- 最終更新日：2020年5月13日