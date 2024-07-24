      1.1 比 1.0 大 0.1，所以要利用这个多出来的0.1来识别是哪个瓶子。
      我们给瓶子编号从1-20，然后从瓶子中拿出和编号数量一样的药片，
      那么总重量 = 1 + 2 + 3 + ... + j * 1.1 + ... + 18 + 19 + 20。其中 1 <= j <= 20，j就是第几个药瓶。
      
      我们知道如果所有药片都是1克，那么总重量 = 1 + 2 + 3 + ... + 18 + 19 + 20 = 210，
      两者相减得到的就是多出来的 j * 0.1 克。那么只需将结果除以0.1就能得到j，即第几个药瓶。
----------------------------------------------------------
1. label the bottle from 1 to 20;
2. take k pills from the kth bottle:

  so the total weight is : actualWeight = 1 + 2 + 3 + ... + j * 1.1 + ... + 18 + 19 + 20。 
                                                  where 1 <= j <= 20，j is the jth bottles。

3. if all pills are 1g, the ideal total weight is   1 + 2 + 3 + ... + 18 + 19 + 20 = 210;
4. the dif between actualWeight and 210 is the overplus j*0.1.
5. so use the dif / 0.1 as the number of bottles j.
   
