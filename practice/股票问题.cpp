// 1. 买卖股票最佳时机,最多只允许一笔交易

// 动态规划
// buy[i] = 第i天买入得最大收益，sell[i]=第i天卖出得最大收益
// buy[i] = max(buy[i-1], -price[i])
// sell[i] = max(sell[i-1], buy[i-1]+price[i])
int maxProfit(vector<int>& prices){
    int n = prices.size();
    if(n <= 1){
        return 0;
    }
    int buy = -prices[0], sell = 0;
    for(int i = 1; i < n; ++i){
        buy = max(buy, -prices[i]);
        sell = max(sell, prices[i]+buy);
    }
    return sell;
}


// 2. 买卖股票最佳时机,允许多次交易
// buy[i] = max(buy[i-1], sell[i-1]-price[i])
// sell[i] = max(sell[i-1], buy[i-1]+price[i])
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n <= 1){
        return 0;
    }
    int buy = -prices[0], sell = 0;
    for(int i = 1; i < n; ++i){
        buy = max(buy, sell-prices[i]);
        sell = max(sell, prices[i]+buy);
    }
    return sell;
}

// 3. 买卖股票最佳时机,允许两次次交易
// s1[i]表示第i天第一次买入的最大收益；
// s2[i]表示第i天第一次卖出的最大收益；
// s1[i]表示第i天第二次买入的最大收益；
// s2[i]表示第i天第二次卖出的最大收益；
// s1[i] = max(s1[i-1], - price[i]); 第一次买入更低价格的股或者不操作
// s2[i] = max(s2[i-1], s1[i-1] + price[i])；即第一次卖出或者不操作
// s3[i] = max(s3[i-1], s2[i-1] - price[i]); 第二次买入或者不操作
// s4[i] = max(s4[i-1], s3[i-1] + price[i])；即第二次卖出或者不操作
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n <= 1){
        return 0;
    }
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for(int i = 1; i < n; ++i){
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, prices[i]+buy1);
        buy2 = max(buy2, sell1-prices[i]);
        sell2 = max(sell2, prices[i]+buy2);
    }
    return sell2;
}

// 4. 买卖股票最佳时机,允许K次交易
// int maxProfit(int k, vector<int>& prices) {
//     int n = prices.size();
//     if(n <= 1){
//         return 0;
//     }
//     vector<int> buy(k, -prices[0]);
//     vector<int> sell(k, 0);

//     for(int i = 1; i < n; ++i){
//         for(int j = 0; j < k; ++j){
//             buy[j] = max(buy[j], sell[j-1]-prices[i]);
//             sell[j] = max(sell[j], prices[i]+buy[j]);
//         }
//         // buy1 = max(buy1, -prices[i]);
//         // sell1 = max(sell1, prices[i]+buy1);
//         // buy2 = max(buy2, sell1-prices[i]);
//         // sell2 = max(sell2, prices[i]+buy2);
//     }
//     return sell[k-1];
// }


// 5. 买卖股票最佳时机,含冷冻期，多次交易
int maxProfit(vector<int>& prices) {
    int buy=INT_MIN,sell=0,cool=0;
    for(int price : prices)
    {
        int pre_sell=sell;
        sell=buy+price;
        buy=max(buy,cool-price);
        cool=max(cool,pre_sell);
    }
    return max(sell,cool);  
}

// 6.买卖股票的最佳时机含手续费
 int maxProfit(vector<int>& prices, int fee) {//动态规划，buy表示当天买入股票的最大收益，sell表示当天卖出股票的最大收益
    int buy=INT_MIN,sell=0;
    for(int price : prices)
    {
        sell=max(sell,buy+price);
        buy=max(buy,sell-price-fee);  
    }
    return sell;        
}
