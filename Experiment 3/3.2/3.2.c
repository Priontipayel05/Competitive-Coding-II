
#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int heights[], int n) {
    int *st = (int *)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];

        while (top != -1 && currentHeight < heights[st[top]]) {
            int height = heights[st[top--]];
            int width = (top == -1) ? i : i - st[top] - 1;
            int area = height * width;

            if (area > maxArea) {
                maxArea = area;
            }
        }

        if (i < n) {
            st[++top] = i;
        }
    }

    free(st);
    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);

    printf("Largest Rectangle Area: %d\n",
           largestRectangleArea(heights, n));

    return 0;
}
