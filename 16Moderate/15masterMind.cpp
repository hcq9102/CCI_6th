
//https://godbolt.org/z/x7ch5aPfx

#include <iostream>
#include <optional>
#include <algorithm> // for std::min and std::max
#include <bits/stdc++.h>
using namespace std;
/*
16.15 猜字游戏（Master Mind）：Master Mind 游戏玩法如下:

机器上有四个插槽，每个插槽将容纳一个球，其颜色可以是红色 (R)、黄色 (Y)、绿色 (G) 或蓝色 (B)。

例如，该机器可能有 RGGB（Slot #1是红色的，Slots #2 和 Slots #3 是绿色的，Slots #4 是蓝色的)。

假设你正在尝试猜测答案。例如，你可能会猜 YRGB。

当你猜对某个插槽上球的颜色时，你会得到一个“hit”。如果你猜的颜色存在，但是插槽的位置不对时，你会得到一个“伪命中”。注意，一个插槽被统计为 hit 后永远不可能被统计为 pseudo-hit。

例如，如果实际的答案是 RGBY，而你猜是 GGRR，那么你有一个 hit 和一个 pseudo-hit。编写一个方法，给定一个猜测和一个答案，返回 hit 次数和 pseudo-hit 次数。
//
hints:

完全命中（hit）：在计算伪命中之前，我们已经计算了完全命中的数量，并在此过程中记录了每个颜色的位置。完全命中的颜色不会再次用于伪命中的计算。
伪命中（pseudo-hit）：伪命中计算时，忽略了位置，只关注颜色的出现次数。在计算伪命中时，我们只关心猜测中每种颜色的数量与答案中相同颜色的数量，并取其较小值。
*/
std::pair<int, int> masterMind(string &str, string &guess){
    int hit = 0;
    int pseudo_hit = 0;

     if (str.length() != guess.length()) {
        throw std::invalid_argument("The length of guess and answer must be the same.");
    }
// Maps to count characters
    std::unordered_map<char, int> str_count; // color--freq
    std::unordered_map<char, int> guess_count;// color--freq

 // First pass: Calculate hits and populate frequency maps
    for(int i = 0; i<str.size(); i++){
        if(str[i] == guess[i]){//在计算伪命中之前，我们已经计算了完全命中的数量，并在此过程中记录了每个颜色的位置。完全命中的颜色不会再次用于伪命中的计算。
            hit++;
        }else{
            str_count[str[i]] ++;
            guess_count[guess[i]]++;
        }
    }

    // Second pass: Calculate pseudo-hits

    for (const auto& pair : guess_count){
        char color = pair.first;
        int guess_color_count = pair.second;
        int str_color_count = str_count[color];

        pseudo_hit += std::min(guess_color_count, str_color_count);

    }

    return {hit,pseudo_hit};

}

int main(){
    string str = "RGBY";
    string guess = "GGRR";

    auto res = masterMind(str, guess);

    std::cout << "hit:  " << res.first <<endl;
      std::cout << "pseudo_hit: " << res.second << std::endl;



    return 0;

}


