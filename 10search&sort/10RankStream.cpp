// https://godbolt.org/z/6eodM9z8x

#include <bits/stdc++.h>
using namespace std;
// use map instead of unordered_map to maintain sorted order.


class RankStream{
    public:

        RankStream() : total_count(0){}
        

        //
        void track(int x){
            // Update the count of the number x
            if(mp.find(x) != mp.end()){
                mp[x]++;
            }else{
                mp[x] = 1;
            }
            total_count++;
        }

        int getRankOfNumber(int x){
            int rank = 0;

            for(auto &enty: mp){
                if(enty.first > x){
                    break;
                }
                rank += enty.second;
            }
            return rank == 0? 0: rank-1; // exclude itself
        }


    private:
        int total_count;
        map<int, int> mp; // num ->counts

};

// Example usage
int main() {
    RankStream rankStream;
    std::vector<int> numbers = {5, 1, 4, 4, 5, 9, 7, 13, 3};

    for (int num : numbers) {
        rankStream.track(num);
    }

    std::cout << "Rank of 1: " << rankStream.getRankOfNumber(1) << std::endl;  // Output: 0
    std::cout << "Rank of 3: " << rankStream.getRankOfNumber(3) << std::endl;  // Output: 1
    std::cout << "Rank of 4: " << rankStream.getRankOfNumber(4) << std::endl;  // Output: 3

    return 0;
}
