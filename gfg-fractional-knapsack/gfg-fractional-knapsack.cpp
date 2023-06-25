// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, [](Item x, Item y)
             { return ((x.value * 1.0) / x.weight > (y.value * 1.0) / y.weight); });

        double t = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (W == 0)
                break;

            int val = arr[i].value;
            int wgt = arr[i].weight;

            if (wgt <= W)
            {
                t += val;
                W -= wgt;
            }
            else
            {
                t = t + (val * 1.0) * W / wgt;
                break;
            }
        }
        return t;
    }
};
