# 一鍵正確關閉Spotify

## Introduction



- 常常聽到一半關閉程式後，想再打開Spotify就會跳出您正在開啟此程式的視窗(傻眼!!
打開工作管理員才發現有好多個spotify一直開啟中，
~~這時比較笨的方法就是一個一個砍掉~~ 


- 後來想到可以寫個簡單的C程式來取代這繁瑣的動作。

## Method

### tlhelp32.h


- 基本上我們都是使用此library，平常比較少用需要查資料。


- 以下為小程式用到的function

    - `CreateToolhelp32SnapShot`
       > Using CreateToolhelp32SnapShot function to get all processes.
    - `Process32First`
       > Using Process32First to get first process(module,thread).

    - `Process32Next`
       > Using Process32Next to get next process(module,thread).

- 一鍵正確關閉Spotify就按執行檔`Spotify_auto_closed.exe`即可

## Conclusion

之前都是手動把所有spotify關閉，有夠累!!
經由使用跟OS相關的Function來解決這繁瑣的動作。


