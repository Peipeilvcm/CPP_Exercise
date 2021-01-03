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
int maxProfit(int k, vector<int>& prices) {
    if(prices.size()<=0 || k==0) return 0;
    //当k大于等于数组长度一半时, 问题就转换为了任意交易次数,此时采用买卖股票的最佳时机II,这里说是长度的一半是因为，每一笔交易都不能相互重叠
    if(2*k>=prices.size()) return maxProfitII(prices);
    //对于其他的k, 问题IV是对问题III的推广,在III中定义了两组买入和卖出时最大收益的变量, 在这里就是k组这样的变量
    vector<int> buy(k,INT_MIN);
    vector<int> sell(k,0);
    for(int i=0;i<prices.size();i++)
    {
        for(int j=k-1;j>=1;j--)
        {
            sell[j]=max(sell[j],buy[j]+prices[i]);//第j次卖出的最高收益为要么不操作要么在第j次买入后卖出
            buy[j]=max(buy[j],sell[j-1]-prices[i]);//第j次买入的最高收益为要么不操作要么在第j-1次卖出后买入
        }
        sell[0]=max(sell[0],buy[0]+prices[i]);
        buy[0]=max(buy[0],-prices[i]);
    }
    return sell[k-1];
}
int maxProfitII(vector<int>& prices)
{
    int res=0;
    for(int i=1;i<prices.size();i++)
    {
        int tmp=prices[i]-prices[i-1];
        if(tmp>0) res+=tmp;
    }
    return res;
}


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
