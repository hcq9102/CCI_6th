/*
把1000个样本分成10组，每组100个，分别在10根试纸上测试

7天后：知道某组里有毒，试纸剩9根
样本100个，分10组，每组11个，最后一组1个
7天后，知道某组里有毒，试纸剩8根
样本11个，分9组，每组1个，最后一组2个
7天后，知道某组里有毒，试纸剩余7根
样本2个，分2组，每组1个
7天后，确定哪个有毒
最差情况28天。
*/

/*best:
如果把10根试纸看作10个bit，那么它一共能代表210=1024个数字，因此可以hold住1000个瓶子。

把1000个瓶子从1～1000编号，然后将其编号的二进制数字对应的1 bit滴到10根试纸里。

最后看哪3个bit是1，然后就能知道是哪个瓶子有问题了。

所以只要7天就能知道结果。

  //
假设有毒瓶子的编号是687。它的二进制表示是：1010101111。你需要按以下步骤进行测试：

向第1、3、5、6、8、9、10张试纸各滴一滴687号瓶子的水。
等待7天后，如果这些试纸结果呈阳性，那么根据这些试纸的位置，将其组合成一个二进制数1010101111，再将其转换为十进制，就是687。
通过这种方法，利用二进制编码和试纸组合，可以在最短的时间内找到有毒的瓶子
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <ctime>


int simulatePoisonDetection(int toxicBottle, int numTests) {
    // get the binary of toxic bottle
    std::bitset<10> toxicBinary(toxicBottle);  // 假设最多需要10位二进制表示

    // simulate the result
    std::vector<int> testResults(numTests, 0);
    for (int i = 0; i < numTests; ++i) {
        if (toxicBinary[i]) {
            testResults[i] = 1; // positive test
        } else {
            testResults[i] = 0; // neg
        }
    }

    // calculate the poison bottle
    std::bitset<10> detectedBinary;
    for (int i = 0; i < numTests; ++i) {
        detectedBinary[i] = testResults[i];
    }
    int detectedBottle = (int)detectedBinary.to_ulong();

    return detectedBottle;
}

int main() {
    srand(time(0));  // set random seed

    const int numBottles = 1000;
    const int numTests = 10;

    //  choose poison bottle number randomly
    int toxicBottle = rand() % numBottles + 1;
    
    // run the detect operation
    int detectedBottle = simulatePoisonDetection(toxicBottle, numTests);

    std::cout << "actual poison bottle number : " << toxicBottle << std::endl;
    std::cout << "detected poison bottle number: " << detectedBottle << std::endl;

    if (toxicBottle == detectedBottle) {
        std::cout << "detected SUCCESS" << std::endl;
    } else {
        std::cout << "detected fail" << std::endl;
    }


    return 0;
}



