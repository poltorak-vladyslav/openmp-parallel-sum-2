#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    int n = 500000;
    std::vector<int> array(n, 1);

    int num_threads = 4;

    while (n > 1) {
        int half_n = n / 2;
        int new_n = n / 2 + n % 2;

        #pragma omp parallel for num_threads(num_threads) schedule(static)
        for (int i = 0; i < half_n; i++) {
            int j = n - i - 1;
            array[i] += array[j];
        }

        n = new_n;
    }

    int result = array[0];
    std::cout << "Sum of elements: " << result << std::endl;

    return 0;
}
