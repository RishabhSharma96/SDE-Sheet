//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool cmp(Item & i1, Item & i2){
        double ratio1 = ((double)i1.value/(double)i1.weight);
        double ratio2 = ((double)i2.value/(double)i2.weight);
        return ratio1 > ratio2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n , cmp);
        
        double price=0, weight=W;
        
        for(int i=0 ; i<n ; i++){
            if(arr[i].weight <= weight){
                weight -= arr[i].weight;
                price += arr[i].value;
            }
            else{
                price += (double)(((double)arr[i].value/(double)arr[i].weight)*(double)weight);
                break;
            }
        }
        return price;
    }
        
};