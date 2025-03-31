#include <bits/stdc++.h>
using namespace std;

double integration(function<double(double)> func, int a, int b, int points)
{
    double ans = 0;

    if (points == 2)
    {
        double weight1 = 1.0;
        double weight2 = 1.0;
        double specialNode1 = -sqrt(1.0 / 3.0);
        double specialNode2 = sqrt(1.0 / 3.0);

        if (a == -1 && b == 1)
        {
            return weight1 * func(specialNode1) + weight2 * func(specialNode2);
        }

        double adjusted_node1 = ((b - a) / 2.0) * specialNode1 + (a + b) / 2.0;
        double adjusted_node2 = ((b - a) / 2.0) * specialNode2 + (a + b) / 2.0;
        double adjustment_factor = (b - a) / 2.0;

        ans = adjustment_factor * (weight1 * func(adjusted_node1) + weight2 * func(adjusted_node2));
    }
    else if (points == 3)
    {
        double weight1 = 5.0 / 9.0;
        double weight2 = 8.0 / 9.0;
        double weight3 = 5.0 / 9.0;
        double specialNode1 = -sqrt(3.0 / 5.0);
        double specialNode2 = 0.0;
        double specialNode3 = sqrt(3.0 / 5.0);

        if (a == -1 && b == 1)
        {
            return weight1 * func(specialNode1) + weight2 * func(specialNode2) + weight3 * func(specialNode3);
        }

        double adjusted_node1 = ((b - a) / 2.0) * specialNode1 + (a + b) / 2.0;
        double adjusted_node2 = ((b - a) / 2.0) * specialNode2 + (a + b) / 2.0;
        double adjusted_node3 = ((b - a) / 2.0) * specialNode3 + (a + b) / 2.0;
        double adjustment_factor = (b - a) / 2.0;

        ans = adjustment_factor * (weight1 * func(adjusted_node1) + weight2 * func(adjusted_node2) + weight3 * func(adjusted_node3));
    }
    else
    {
        return -1;
    }

    return ans;
}

int main()
{
    auto func = [](double x)
    {
        return sin(x) / x;
    };

    double answer = integration(func, 0, 1, 3);
    cout << fixed << setprecision(6) << answer << endl;

    return 0;
}
