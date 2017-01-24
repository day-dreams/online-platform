# Online-platform

## Intro

this project will take a year for me to finish.

i will make this project from a echo server , to a great online social platform.

and i will make this in c++.

## Tips
during this project, i continue to find something interesting as follow:  
### c++中的赋值问题
左侧变量需要具有右侧变量的所有类型限定符。如：  
```cpp
const char *const_s="hello kitty";
char * s=const_s;//error! s没有const限定符；但是可以用-fpermissive通过编译
```
